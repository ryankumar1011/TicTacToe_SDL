//
//  logic.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "logic.hpp"
#include "init.hpp"
#include "texture.hpp"
#include "menu_button.hpp"
#include "global_vars.hpp"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>


void render_board(int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            g_game_board[j + i*3].render();
        }
    }
}

void reset_board()
{
    for (auto& field : g_game_board)
    {
        field.set_selected(SelectNone);
    }
}

bool check_board_full()
{
    for (auto& field : g_game_board)
    {
        if (field.get_selected() == SelectNone)
        {
            return false;
        }
    }
    return true;
}

GameSelect get_repeating_field()
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        GameSelect left = g_game_board[i*3].get_selected();
        GameSelect middle = g_game_board[i*3+1].get_selected();
        GameSelect right = g_game_board[i*3+2].get_selected();
        
        if ((left == middle) && (middle == right) && (left != SelectNone))
        {
            return left;
        }
    }
    //check columns
    for (int i = 0; i < 3; i++)
    {
        GameSelect top = g_game_board[i].get_selected();
        GameSelect middle = g_game_board[i+3].get_selected();
        GameSelect bottom = g_game_board[i+6].get_selected();
        
        if ((top == middle) && (middle == bottom) && (top != SelectNone))
        {
            return top;
        }
    }
    
    //check diagonals
   if ((g_game_board[0].get_selected() == g_game_board[4].get_selected()) && (g_game_board[4].get_selected() == g_game_board[8].get_selected()) && (g_game_board[0].get_selected() != SelectNone))
   {
       return g_game_board[0].get_selected();
       
   }
   if ((g_game_board[2].get_selected() == g_game_board[4].get_selected()) && (g_game_board[4].get_selected() == g_game_board[6].get_selected()) && (g_game_board[2].get_selected() != SelectNone))
   {
       return g_game_board[2].get_selected();
   }
    return SelectNone;
}
