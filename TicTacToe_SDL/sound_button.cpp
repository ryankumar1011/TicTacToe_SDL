//
//  sound_button.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "sound_button.hpp"
#include "global_vars.hpp"


Texture& SoundButton::get_texture_on()
{
    return m_texture_on;
}

Texture& SoundButton::get_texture_off()
{
    return m_texture_off;
}

int SoundButton::get_width()
{
    return WIDTH;
}

int SoundButton::get_height()
{
    return HEIGHT;
}

void SoundButton::update()
{
    if (Mix_PlayingMusic() == 0)
    {
        m_sound = false;
    }
    else if  (Mix_PausedMusic() == 1)
    {
        m_sound = false;
    }
    else
    {
        m_sound = true;
    }
    
    if (m_state == MOUSE_PRESS_UP)
    {
        MusicHandler::play_click();
        MusicHandler::toggle_music();
        m_sound = !(m_sound);
        m_state = MOUSE_OVER;
    }
    
    update_hover_box();
}

void SoundButton::render()
{
    render_hover_box();
    
    if (m_sound)
    {
        m_texture_on.render(m_position.x, m_position.y, nullptr, SCALE_FACTOR);
    }
    else
    {
        m_texture_off.render(m_position.x, m_position.y, nullptr, SCALE_FACTOR);
    }
}
