//
//  menu_button.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include "button_state.hpp"
#include "button.hpp"
#include "texture.hpp"
#include <SDL2/SDL.h>

class MenuButton : public Button
{
public:
    static constexpr float SCALE_FACTOR = 1;
    static constexpr float HEIGHT = 30*SCALE_FACTOR;
    static constexpr float WIDTH = 30*SCALE_FACTOR;

public:
    MenuButton();
    static Texture& get_texture();
    float get_width() override;
    float get_height() override;
    void update() override;
    void render() override;

private:
    static Texture m_texture;
};
