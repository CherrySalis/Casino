#include "raylib.h"
#include "login.h"
#include "menu.h"

int main()
{
    InitWindow(1000,700,"Casino");
    SetTargetFPS(60);

    Login login;
    Menu menu;
    menu.LoadAssets();

    while (!WindowShouldClose())
    {
        if (!login.isFinished())
            login.Update();
        else
            menu.Update();

        if (login.isFinished() && menu.shouldExit())
            break;

        BeginDrawing();

        ClearBackground(SKYBLUE);

        if (!login.isFinished())
            login.Draw();
        else
        {
            menu.Draw();

            Player &player = login.getPlayer();
            DrawText(TextFormat("Welcome %s!", player.getName().c_str()), 30, 20, 30, WHITE);
            DrawText(TextFormat("Chips: %d", player.getChips()), 30, 60, 25, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}