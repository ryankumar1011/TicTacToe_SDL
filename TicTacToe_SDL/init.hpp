//
//  init.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>

bool init();

bool load_media();

bool load_images();

bool load_fonts();

TTF_Font* load_font_from_file(const std::string& font_path, int font_size);

bool load_audio();

void close();


