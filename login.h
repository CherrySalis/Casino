#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include "raylib.h"
#include "player.h"

class Login
{
private:
    std::string name;
    std::string balanceText;

    bool enteringName;
    bool enteringBalance;
    bool finished;

    Player player;

public:
    Login();

    void Update();
    void Draw();

    bool isFinished() const;

    Player& getPlayer();
};

#endif