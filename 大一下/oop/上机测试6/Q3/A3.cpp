#include <iostream>

using namespace std;

class Monster
{
public:
    Monster(int hp, int dam, int def) : hitpoint(hp), damage(dam), defense(def) {}
    void fight(Monster &other)
    {
        while (this->hitpoint > 0 && other.hitpoint > 0)
        {
            this->attack(other);
            if (other.hitpoint > 0)
                other.attack(*this);
        }
    }
    virtual void attack(Monster &) = 0;
    int getHitpoint() const
    {
        return hitpoint;
    }
    void setHitpoint(int hp)
    {
        hitpoint = hp;
    }
    int getDamage() const
    {
        return damage;
    }
    int getDefense() const
    {
        return defense;
    }

private:
    int hitpoint;
    int damage;
    int defense;
};

class mstCat : public Monster
{
public:
    mstCat(int h, int d, int def) : Monster(h, d, def) {}
    void attack(Monster &other)
    {
        cout << "meo!" << endl;
        other.setHitpoint(max(0, other.getHitpoint() - max(1, (this->getDamage() * 2 - other.getDefense()))));
    }
};
class mstDog : public Monster
{
public:
    mstDog(int h, int d, int def) : Monster(h, d, def) {}
    void attack(Monster &other)
    {
        cout << "wang!" << endl;
        other.setHitpoint(max(0, other.getHitpoint() - max(2, 2 * (this->getDamage() - other.getDefense() + 5))));
    }
};
int main()
{
    mstCat cat(100, 20, 5);
    mstDog dog(120, 15, 10);
    cat.fight(dog);
    cout << "cat hp:" << cat.getHitpoint() << endl;
    cout << "dog hp:" << dog.getHitpoint() << endl;
    return 0;
}