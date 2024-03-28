//
//  SDL_Timer.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 28/3/24.
//

#pragma once

#include <SDL2/SDL.h>

class SDLTimer
{
    
public:
    
    SDLTimer();
    
    void start();
    
    void pause();
    
    void unpause();
    
    void stop();
    
    uint64_t get_time(); // this will get time since of program minus time since start
    
    bool is_paused();
    
    bool is_started();
    
    ~SDLTimer();
    
private:
    
    uint64_t m_start_ticks;
    
    uint64_t m_paused_ticks; // this is the different between time of program and time since start when paused
    
    bool m_is_paused;
    
    bool m_is_started;
};

