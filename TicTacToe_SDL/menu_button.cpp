//
//  menu_button.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "texture.hpp"
#include "menu_button.hpp"
#include "global_vars.hpp"

Texture MenuButton::m_texture;

MenuButton::MenuButton()
{
    m_position.x = 0;
    m_position.y = 0;
}

Texture& MenuButton::get_texture()
{
    return m_texture;
}

float MenuButton::get_width()
{
    return WIDTH;
}

float MenuButton::get_height()
{
    return HEIGHT;
}

void MenuButton::update()
{
    if (m_state == MOUSE_PRESS_DOWN)
    {
        Mix_PlayChannel(-1, gp_button_click, 0);
        
        g_menu_state = !g_menu_state;
        
        m_state = MOUSE_OVER;
    }
    update_hover_box();
}

void MenuButton::render()
{
    render_hover_box();
    m_texture.render(m_position.x, m_position.y, nullptr, SCALE_FACTOR);
}
