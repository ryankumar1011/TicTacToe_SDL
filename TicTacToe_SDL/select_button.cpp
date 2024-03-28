//
//  select_buttons.cpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#include "texture.hpp"
#include "select_button.hpp"
#include "global_vars.hpp"

Texture SelectButton::m_texture;

SelectButton::SelectButton()
{
    m_position.x = 0;
    m_position.y = 0;
    m_clip_x = {307,0,294,264};
    m_clip_o = {0,0,249,265};

    m_select = SelectNone;
}

Texture& SelectButton::get_texture()
{
    return m_texture;
}

float SelectButton::get_width()
{
    return WIDTH;
}

float SelectButton::get_height()
{
    return HEIGHT;
}

GameSelect SelectButton::get_selected()
{
    return m_select;
}

void SelectButton::set_selected(GameSelect select)
{
    m_select = select;
}

void SelectButton::update()
{
    if (m_state == MOUSE_PRESS_DOWN)
    {
        if (m_select == SelectNone)
        {
            Mix_PlayChannel(-1, gp_button_click, 0);
            
            if (g_current_player == Player1)
            {
                m_select = SelectX;
                g_current_player = Player2;
            }
            else
            {
                m_select = SelectO;
                g_current_player = Player1;
            }
            
            m_state = MOUSE_OVER;
        }
    }
    update_hover_box();
}

void SelectButton::render()
{
    render_hover_box();
    
    if (m_select == SelectX)
    {
        m_texture.render(m_position.x, m_position.y, &m_clip_x, SCALE_FACTOR);
    }
    else if (m_select == SelectO)
    {
        m_texture.render(m_position.x, m_position.y, &m_clip_o, SCALE_FACTOR);
    }
}
