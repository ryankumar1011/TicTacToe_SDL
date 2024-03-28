//
//  main.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//


#include "menu_button.hpp"
#include "select_button.hpp"
#include "logic.hpp"
#include "texture.hpp"
#include "init.hpp"
#include "SDL_Timer.hpp"
#include "global_vars.hpp"
#include <string>
#include <iostream>

//SDL libraries:
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

//This project is written quickly so some of the logic is written directly into the main loop. Also sorry there might be some magic numbers in the code :<
//Also some files like menu_button and texture are reused from my other projects

int main(int argc, char* args[])
{
    if (!init())
    {
        printf("Error initializing. ERROR: %s\n", SDL_GetError());
    }
    else
    {
        
        if (!load_media())
        {
            printf("Error loading media. ERROR: %s\n", SDL_GetError());
        }
        
        else
        {
            MenuButton menu_button;
            menu_button.set_position(5, 5);
            
            Texture menu;
            menu.load_from_font(gp_crayon_font, "Tic Tac Toe", {0xFF, 0xFF, 0xFF});

            int board_position_x = 150;
            int board_position_y = 0;
            
            SelectButton selectbutton1;
            SelectButton selectbutton2;
            SelectButton selectbutton3;
            SelectButton selectbutton4;
            SelectButton selectbutton5;
            SelectButton selectbutton6;
            SelectButton selectbutton7;
            SelectButton selectbutton8;
            SelectButton selectbutton9;
            
            selectbutton1.set_position(34 + board_position_x,board_position_y + 24);
            selectbutton2.set_position(231 + board_position_x,board_position_y + 24);
            selectbutton3.set_position(421 + board_position_x,board_position_y + 24);
            selectbutton4.set_position(34 + board_position_x,board_position_y + 230);
            selectbutton5.set_position(231 + board_position_x,board_position_y + 230);
            selectbutton6.set_position(421 + board_position_x,board_position_y + 230);
            selectbutton7.set_position(34 + board_position_x,board_position_y + 420);
            selectbutton8.set_position(231 + board_position_x,board_position_y + 420);
            selectbutton9.set_position(421 + board_position_x,board_position_y + 420);
            
            g_game_board.push_back(selectbutton1);
            g_game_board.push_back(selectbutton2);
            g_game_board.push_back(selectbutton3);
            g_game_board.push_back(selectbutton4);
            g_game_board.push_back(selectbutton5);
            g_game_board.push_back(selectbutton6);
            g_game_board.push_back(selectbutton7);
            g_game_board.push_back(selectbutton8);
            g_game_board.push_back(selectbutton9);
            
            int frame{0};
            int frame_rate {};
            double previous_time{};
            double change_in_time{};
            const int CAPPED_FRAME_RATE {60};
            const int MINIMUM_LOOP_TICKS {1000/CAPPED_FRAME_RATE};
            
            SDLTimer game_timer;
            game_timer.start();
            SDLTimer cap_timer;
            
            bool quit = false;
            SDL_Event event;
            
            //main game loop
            while (quit != true)
            {
                cap_timer.start();
                
                //handle events
                while (SDL_PollEvent(&event) != 0)
                {
                    if (event.type == SDL_QUIT)
                        
                    {
                        quit = true;
                    }
                    
                    menu_button.handle_event(event);
                    
                    if (!g_menu_state)
                    {
                        for (auto& select_button : g_game_board)
                        {
                            select_button.handle_event(event);
                        }
                    }
                }
                
                //updating
                
                menu_button.update();
            
                for (auto& select_button : g_game_board)
                {
                    select_button.update();
                }
                
                //rendering
                
                SDL_SetRenderDrawColor(gp_renderer, 0xD4, 0xD4, 0xD4, 0xFF);
                SDL_RenderClear(gp_renderer);
                
                menu_button.render();
                
                if (g_menu_state)
                {
                    menu.render((SCREEN_WIDTH - menu.get_width())/2, (SCREEN_HEIGHT - menu.get_height())/2);
                }
                
                else
                {
                    g_tictactoe_grid.render(board_position_x, board_position_y);
                    
                    render_board(board_position_x, board_position_y);
                }
                
                SDL_RenderPresent(gp_renderer);
                
                //logic (this should ideally be with updating)
                
                if (get_repeating_field() == SelectX)
                {
                    std::cout << "Player 1 wins\n";
                    SDL_Delay(3000); //wait 2 seconds when game finishes
                    reset_board();
                }
                else if (get_repeating_field() == SelectO)
                {
                    std::cout << "Player 2 wins\n";
                    SDL_Delay(3000);
                    reset_board();
                }
                else if (check_board_full())
                {
                    std::cout << "Its a tie\n";
                    SDL_Delay(3000);
                    reset_board();
                }
                
                //waiting to keep a specific frame rate (for performance)
                change_in_time = (game_timer.get_time()/1000.0f) - previous_time;
                previous_time = (game_timer.get_time()/1000.0f);
                frame_rate = 1.0/change_in_time;
                
                if (frame_rate > 10000) frame_rate = 0;
                
                if (cap_timer.get_time() < MINIMUM_LOOP_TICKS)
                {
                    SDL_Delay((MINIMUM_LOOP_TICKS - cap_timer.get_time()));
                }
            }
        }
    }
    close();
    return 0;
}
