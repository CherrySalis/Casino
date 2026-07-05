#include "menu.h"
#include <iostream>
#include <filesystem>

using namespace std;

Menu::Menu()
{
    text[0] = "Blackjack";
    text[1] = "High Low";
    text[2] = "Slot Machine";
    text[3] = "Teen Patti";
    text[4] = "Horse Betting";
    text[5] = "Exit";

    for (int i = 0; i < 6; i++)
    {
        buttons[i] = {350.0f, 150.0f + i * 70.0f, 300.0f, 50.0f};
    }

    exitRequested = false;
    background = {0};
}

void Menu::LoadAssets()

{
    std::string appDir = GetApplicationDirectory();
    if (!appDir.empty() && appDir.back() != '/' && appDir.back() != '\\')
        appDir += '/';

    std::string path = appDir + "assets/background.jpg";
    background = LoadTexture(path.c_str());
    if (background.id == 0)
    {
        path = appDir + "Casino/assets/background.jpg";
        background = LoadTexture(path.c_str());
    }
    if (background.id == 0)
    {
        path = "Casino/assets/background.jpg";
        background = LoadTexture(path.c_str());
    }
    if (background.id == 0)
    {
        std::cout << "Failed to load menu background texture. Tried: " << path << std::endl;
    }
}

Menu::~Menu()
{
    if (background.id != 0)
        UnloadTexture(background);
}

void Menu::Update()
{
    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < 6; i++)
    {
        if (CheckCollisionPointRec(mouse, buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            switch (i)
            {
            case 0:
                cout << "Blackjack Selected\n";
                break;
            case 1:
                cout << "High Low Selected\n";
                break;
            case 2:
                cout << "Slot Machine Selected\n";
                break;
            case 3:
                cout << "Teen Patti Selected\n";
                break;
            case 4:
                cout << "Horse Betting Selected\n";
                break;
            case 5:
                exitRequested = true;
                break;
            }
        }
    }
}

bool Menu::shouldExit() const
{
    return exitRequested;
}

void Menu::Draw()
{
    if (background.id != 0)
    {
        DrawTexturePro(
            background,
            {0, 0, (float)background.width, (float)background.height},
            {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            {0, 0},
            0.0f,
            WHITE
        );
    }

    DrawText("CASINO", 368, 48, 50, BLACK);
    DrawText("CASINO", 370, 50, 50, BLACK);
    DrawText("CASINO", 372, 52, 50, GOLD);

    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < 6; i++)
    {
        Color color = SKYBLUE;
        if (CheckCollisionPointRec(mouse, buttons[i]))
            color = BLUE;

        DrawRectangleRounded(buttons[i], 0.3f, 20, color);
        DrawText(text[i].c_str(),
                 (int)buttons[i].x + 60,
                 (int)buttons[i].y + 13,
                 25,
                 BLACK);
    }
}
