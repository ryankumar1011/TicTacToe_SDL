//
//  global_vars.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "global_vars.hpp"
#include "texture.hpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int SCREEN_DIAGONAL = sqrt((SCREEN_WIDTH*SCREEN_WIDTH) + (SCREEN_HEIGHT*SCREEN_HEIGHT));

SDL_Window* gp_window = nullptr;
SDL_Renderer* gp_renderer = nullptr;

Player g_current_player{Player1};
bool g_menu_state{true};
std::vector<SelectButton> g_game_board;

//Textures
Texture g_tictactoe_grid;

//Fonts
TTF_Font* gp_crayon_font = nullptr;

//Chunks and music from SDL mixer
Mix_Music* gp_background_music = nullptr;
Mix_Chunk* gp_tictactoe_click = nullptr;
Mix_Chunk* gp_button_click = nullptr;




