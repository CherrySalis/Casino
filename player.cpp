#include "player.h"
#include <iostream>

Player::Player()
{
    name = "";
    balance = 0;
    chips = 0;
}

Player::Player(const std::string& name, int balance)
{
    this->name = name;
    this->balance = balance;
    chips = balance / 100;
}

std::string Player::getName() const
{
    return name;
}

int Player::getBalance() const
{
    return balance;
}

int Player::getChips() const
{
    return chips;
}

void Player::setName(const std::string& name)
{
    this->name = name;
}

void Player::setBalance(int balance)
{
    this->balance = balance;
    chips = balance / 100;
}

void Player::addChips(int amount)
{
    chips += amount;
}

void Player::removeChips(int amount)
{
    if (chips >= amount)
        chips -= amount;
}

void Player::display() const
{
    std::cout << "Welcome " << name << "!\n";
    std::cout << "Your chips: " << chips << "\n";
}
