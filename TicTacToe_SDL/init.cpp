//
//  init.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "init.hpp"
#include "menu_button.hpp"
#include "global_vars.hpp"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>


bool init()
{
    bool success{true};
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        
    {
        success = false;
        printf("Error initializing SDL. ERROR: %s\n", SDL_GetError());
    }
    
    else
        
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
            
        {
            printf("Warning: linear texture filtering not enabled\n");
        }
        
        if (Mix_Init(MIX_INIT_FLAC|MIX_INIT_MP3) != (MIX_INIT_FLAC|MIX_INIT_MP3))
        {
            success = false;
            printf("Error initializing SDL Mixer. ERROR: %s\n", Mix_GetError());
        }
        
        else
        {
            
            if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
                
            {
                printf("Error initializing SDL_Image. ERROR: %s\n", IMG_GetError());
                success = false;
            }
            
            else
            {
                
                if (TTF_Init() == -1)
                {
                    printf("Error initializing TTF. ERROR: %s\n", TTF_GetError());
                    success = false;
                }
                
                else
                {
                    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                    {
                        printf("Error initializing SDL_Mixer. ERROR: %s\n", Mix_GetError());
                        success = false;
                        
                    }
                    
                    else
                    {
                        SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &gp_window, &gp_renderer);
                        
                        if (gp_window == nullptr || gp_renderer == nullptr)
                        {
                            printf("Error initializing window and renderer. ERROR: %s\n", SDL_GetError());
                            success = false;
                            
                        }
                        
                        else SDL_SetRenderDrawColor(gp_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    
                }
            }
        }
    }
            
    return success;
}

bool load_media()
{
    bool success = true;
    
    if (!load_images()) success = false;
    if (!load_fonts()) success = false;
    if (!load_audio()) success = false;
        
    return success;
    
}

bool load_images()
{
    bool success = true;
    
    if (!g_tictactoe_grid.load_from_file("Images/TicTacToe_grid.png"))
    {
        success = false;
        printf("Failed to load TicTacToe grid png\n");
    }
    
    if (!MenuButton::get_texture().load_from_file("Images/menu_button.png"))
    {
        success = false;
        printf("Failed to load menu button png\n");
    }
    
    if (!SelectButton::get_texture().load_from_file("Images/O_X.png"))
    {
        success = false;
        printf("Failed to load O and X png\n");
    }
    
    return success;
}

bool load_fonts()
{
    bool success = true;

    gp_crayon_font = load_font_from_file("Fonts/pastel_crayon.ttf", 60);
    
    if (gp_crayon_font == nullptr)
    {
        success = false;
        printf("Failed to load crayon font\n");
    }
    
    return success;

}

TTF_Font* load_font_from_file(const std::string& font_path, int font_size)
{
    
    TTF_Font* p_font;
    
    p_font = (TTF_OpenFont(font_path.c_str(), font_size));
    
    if (p_font == nullptr)
    {
        printf("Failed to load font from TTF file with font path %s\n", font_path.c_str());
        
    }
    return p_font;
    
}

bool load_audio()
{
    bool success = true;
    
    gp_background_music = Mix_LoadMUS("Audio/background_music.mp3");
   
    if (gp_background_music == nullptr)
    {
        success = false;
        printf("Failed to load background music\n");
    }
    gp_tictactoe_click = Mix_LoadWAV("Audio/TicTacToe_click.wav");
    
    if (gp_tictactoe_click == nullptr)
    {
        success = false;
        printf("Failed to tictactoe click audio\n");
    }
    
    gp_button_click = Mix_LoadWAV("Audio/button_click.wav");
    
    if (gp_button_click == nullptr)
    {
        success = false;
        printf("Failed to load click audio\n");
    }
    
    return success;
}

void close()
{
    // Destroyed all LOADED surfaces and textures
    g_tictactoe_grid.free();
    
    //we need to close a font that is opened from TTF_OpenFont
    TTF_CloseFont(gp_crayon_font);

    Mix_FreeMusic(gp_background_music);
    Mix_FreeChunk(gp_button_click);
    Mix_FreeChunk(gp_tictactoe_click);
    
    // Destroy Windows and Renderer, set pointers to NULL
    SDL_DestroyWindow(gp_window);
    SDL_DestroyRenderer(gp_renderer);
    gp_window = nullptr;
    gp_renderer = nullptr;
    
    //Just like you initialize them, you have to quit SDL subsystems
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

