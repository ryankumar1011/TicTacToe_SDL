//
//  texture.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "texture.hpp"
#include "global_vars.hpp"
#include <SDL2_image/SDL_image.h>

Texture::Texture()
    {
        m_height = 0;
        m_width = 0;
        mp_texture = nullptr;
    }

bool Texture::load_from_file(const std::string& file_path)
{
    free();
    //If the Texture class already stores a loaded texture, this texture should be freed first
    
    SDL_Texture* p_loaded_texture = nullptr;
    SDL_Surface* p_loaded_surface = nullptr;
   
    p_loaded_surface = IMG_Load(file_path.c_str());
    
    if (p_loaded_surface == nullptr)
        {
            printf("Error loading surface with path %s. ERROR: %s\n.", file_path.c_str(), IMG_GetError());
        }
    
    else
       {
           p_loaded_texture = SDL_CreateTextureFromSurface(gp_renderer, p_loaded_surface);
           
           if (p_loaded_texture == NULL)
               
           {
               printf("Error loading texture with path %s, ERROR: %s\n", file_path.c_str(), SDL_GetError());
               
           }
           else
            {
               
               m_width = p_loaded_surface->w;
               m_height = p_loaded_surface->h;
            
            }
    
           SDL_FreeSurface(p_loaded_surface);
        }

    mp_texture = p_loaded_texture;

    return (p_loaded_texture != nullptr);
                
}

bool Texture::load_from_font(TTF_Font* p_loaded_font, const std::string& text, const SDL_Color& font_color)
{    
    SDL_Surface* p_loaded_surface = nullptr;
    SDL_Texture* p_font_texture = nullptr;

    p_loaded_surface = TTF_RenderText_Blended(p_loaded_font, text.c_str(), font_color);
    
    if (p_loaded_surface == nullptr)
    {
        printf("Error loading surface with text %s. ERROR: %s\n", text.c_str(), TTF_GetError());
    }
    
    else
    {
    p_font_texture = SDL_CreateTextureFromSurface(gp_renderer, p_loaded_surface);
    
    if (p_font_texture == nullptr)
        
    {
        printf("Error loading texture with text %s, ERROR: %s\n", text.c_str(), SDL_GetError());
        
    }
    else
     {
        
        m_width = p_loaded_surface->w;
        m_height = p_loaded_surface->h;
        
     }

     SDL_FreeSurface(p_loaded_surface);
    
 }

 mp_texture = p_font_texture;
    
 return (p_font_texture != nullptr);
    
}

int Texture::get_height()
{
    return m_height;
}

int Texture::get_width()
{
  return m_width;
}


void Texture::render(float x, float y, SDL_Rect* p_clip, float scale_factor)
{
    SDL_FRect render_area{};
    
    if (p_clip != nullptr)
    {
        render_area = {x, y, scale_factor*(p_clip->w), scale_factor*(p_clip->h)};
        SDL_RenderCopyF(gp_renderer, mp_texture, p_clip, &render_area);
    }
    else
    {
        render_area = {x, y, scale_factor*m_width, scale_factor*m_height};
        SDL_RenderCopyF(gp_renderer, mp_texture, p_clip, &render_area);
    }
    
}

void Texture::free()
{
    SDL_DestroyTexture(mp_texture);
    mp_texture = nullptr;
    m_width = 0;
    m_height = 0;
}

Texture::~Texture()
{
    free();
}

