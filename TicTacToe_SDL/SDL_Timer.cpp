//
//  SDL_Timer.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 28/3/24.
//
#include "SDL_Timer.hpp"

SDLTimer::SDLTimer()
{
    m_start_ticks = 0;
    m_paused_ticks = 0;
    m_is_started = false;
    m_is_paused = false;
    
}
void SDLTimer::start()
{
    m_is_started = true;
    m_is_paused = false;
    
    m_start_ticks = SDL_GetTicks64();
    m_paused_ticks = 0;
    
}

void SDLTimer::pause()

{
    if (m_is_started && !(m_is_paused))
    {
        m_is_paused = true;
        m_paused_ticks = SDL_GetTicks64() - m_start_ticks; //the current time on clock
        m_start_ticks = 0;
    }
}

void SDLTimer::unpause()

{
    if (m_is_started && m_is_paused)
    {
        m_is_paused = false;
        m_start_ticks = SDL_GetTicks64() - m_paused_ticks;
        //since the amount that start ticks is behind SDL_GetTicks is the time on the clock, we just update start ticks to unpause the clock
        m_paused_ticks = 0;
        
    }
    
}

void SDLTimer::stop()
{
    m_is_started = false;
    m_is_paused = false;
    
    m_start_ticks = 0;
    m_paused_ticks = 0;
    
}

bool SDLTimer::is_paused()
{
    return m_is_paused;
}

bool SDLTimer::is_started()
{
    return m_is_started;
}

uint64_t SDLTimer::get_time()
{
    if (is_started())
    {
        if (is_paused()) return m_paused_ticks;
        else return SDL_GetTicks64() - m_start_ticks;
    }
    
    return 0;
}

SDLTimer::~SDLTimer()
{
    m_start_ticks = 0;
    m_paused_ticks = 0;
    m_is_started = false;
    m_is_paused = false;
    
}

