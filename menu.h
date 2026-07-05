#ifndef MENU_H
#define MENU_H

#include <string>
#include "raylib.h"

class Menu
{
public:
    Menu();
    ~Menu();

    void LoadAssets();
    void Update();
    void Draw();
    bool shouldExit() const;

private:
    std::string text[6];
    Rectangle buttons[6];
    bool exitRequested;
    Texture2D background;
};

#endif