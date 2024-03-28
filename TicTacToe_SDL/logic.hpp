//
//  logic.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include "player_select.hpp"

void render_board(int x, int y);

void reset_board();

bool check_board_full();

GameSelect get_repeating_field();
