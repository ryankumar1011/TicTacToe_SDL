//
//  global_vars.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include "select_button.hpp"
#include "player_select.hpp"
#include "texture.hpp"
#include <vector>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_DIAGONAL;

extern SDL_Window* gp_window;
extern SDL_Renderer* gp_renderer;

extern Player g_current_player;
extern bool g_menu_state;
extern std::vector<SelectButton> g_game_board;

extern Texture g_tictactoe_grid;

extern TTF_Font* gp_crayon_font;

extern Mix_Music* gp_background_music;
extern Mix_Chunk* gp_tictactoe_click;
extern Mix_Chunk* gp_button_click;
