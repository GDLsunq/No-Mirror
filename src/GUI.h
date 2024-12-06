#pragma once

namespace GUI
{
    inline bool isVisible = false;
    inline bool canToggle = false;
    inline bool toggled = false;


    void toggle();

    void render();
}