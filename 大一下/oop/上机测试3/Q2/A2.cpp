#include <iostream>
using namespace std;

class Bike
{
private:
    int a;
};

class Player:private Bike
{
    int b;
};
int main()
{
    Player player;
    Bike*pb=(Bike*)(&player);
    return 0;
}