#include "login.h"

Login::Login()
{
    name = "";
    balanceText = "";

    enteringName = true;
    enteringBalance = false;
    finished = false;
}

void Login::Update()
{
    int key = GetCharPressed();

    while (key > 0)
    {
        if (enteringName)
        {
            if (key >= 32 && key <= 125 && name.length() < 20)
                name += (char)key;
        }
        else if (enteringBalance)
        {
            if (key >= '0' && key <= '9' && balanceText.length() < 10)
                balanceText += (char)key;
        }

        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (enteringName && !name.empty())
            name.pop_back();

        else if (enteringBalance && !balanceText.empty())
            balanceText.pop_back();
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        if (enteringName)
        {
            if (!name.empty())
            {
                enteringName = false;
                enteringBalance = true;
            }
        }
        else if (enteringBalance)
        {
            if (!balanceText.empty())
            {
                int balance = stoi(balanceText);

                player = Player(name, balance);

                finished = true;
            }
        }
    }
}

void Login::Draw()
{
    DrawText("CASINO LOGIN", 300, 70, 45, GOLD);

    DrawText("Press ENTER to Continue", 300, 620, 20, BLACK);

    if (enteringName)
    {
        DrawText("Enter Your Name", 330, 180, 30, BLACK);

        DrawRectangleRounded({250,250,500,55},0.3f,20,WHITE);

        DrawText(name.c_str(),270,265,30,BLACK);
    }

    else if (enteringBalance)
    {
        DrawText("Enter Your Balance",310,180,30,WHITE);

        DrawRectangleRounded({250,250,500,55},0.3f,20,WHITE);

        DrawText(balanceText.c_str(),270,265,30,BLACK);
    }
}

bool Login::isFinished() const
{
    return finished;
}

Player& Login::getPlayer()
{
    return player;
}