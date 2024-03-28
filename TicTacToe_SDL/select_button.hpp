//
//  select_buttons.hpp
//  TicTacToe_SDL
//
//  Created by Ryan Kumar on 27/3/24.
//

#pragma once

#include "player_select.hpp"
#include "texture.hpp"
#include "button.hpp"


class SelectButton : public Button
{
public:
    static constexpr float SCALE_FACTOR = 0.5;
    static constexpr float HEIGHT = 300*SCALE_FACTOR;
    static constexpr float WIDTH = 271*SCALE_FACTOR;

public:
    SelectButton();
    static Texture& get_texture();
    GameSelect get_selected();
    void set_selected(GameSelect select);
    float get_width() override;
    float get_height() override;
    void update() override;
    void render() override;

private:
    static Texture m_texture;
    SDL_Rect m_clip_x;
    SDL_Rect m_clip_o;
    GameSelect m_select;
};
