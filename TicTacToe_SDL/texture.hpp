//
//  texture.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>

class Texture
{
public:

    Texture();
    
    bool load_from_file(const std::string& texture_path);
    
    bool load_from_font(TTF_Font* ptr_loaded_font, const std::string& text, const SDL_Color& font_color);
        
    int get_height();
        
    int get_width();

    void render(float x = 0, float y = 0, SDL_Rect* p_clip = nullptr, float scale_factor = 1);
    
    void free();
    
    ~Texture();
    
private:
    
    SDL_Texture* mp_texture;
    
    int m_height;
    
    int m_width;
};
