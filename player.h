#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player
{
private:
    std::string name;
    int balance;
    int chips;
public:
    Player();
    Player(const std::string& name, int balance);
    void setName(const std::string& name);
    void setBalance(int balance);
    std::string getName() const;
    int getBalance() const;
    int getChips() const;
    void addChips(int amount);
    void removeChips(int amount);
    void display() const;
};
#endif