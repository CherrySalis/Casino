#include <iostream>
using namespace std;
class Player
{
private:
    string name;
    int chips;

public:
    Player() {}
    Player(string n, int balance)
    {
        name = n;
        chips = balance / 100;
    }
    void display()
    {
        cout << "Welcome" << name;
        cout << "!\nYour chips:" << chips << endl;
    }
};

int main()
{
    string n;
    int balance;
    cout << "Enter your name:";
    cin >> n;
    cout << "\nEnter your balance:";
    cin >> balance;
    Player p1(n, balance);
    p1.display();
    int choice;
    do
    {
        cout << "\n    ======MAIN MENU======    \n";
        cout << "1.Blackjack" << endl;
        cout << "2.High Low" << endl;
        cout << "3.Slot Machine" << endl;
        cout << "4.Teen Patti" << endl;
        cout << "5.Horse Betting" << endl;
        cout << "6.Exit" << endl;
        cin >> choice;
    } while (choice != 6);
    switch (choice)
    {
    case 1:
        cout << "Blackjack Selected!!\n";
        break;
    case 2:
        cout << "High Low Selected!!\n";
        break;
    case 3:
        cout << "Slot Machine Selected!!\n";
        break;
    case 4:
        cout << "Teen Patti Selected!!\n";
        break;
    case 5:
        cout << "Horse Betting Selected!!\n";
        break;
    case 6:
        cout << "***INVALID CHOICE***\nEnter choice again:";
        break;
    }

    return 0;
}