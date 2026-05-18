#include <iostream>
using namespace std;

class Monster
{
public:
    Monster(int s,int hp,int d,int def):speed(s),hitpoint(hp),damage(d),defense(def){}
    bool thisFirst(Monster& other)
    {
        if(speed>other.speed)
        {
            return true;
        }
        else if(speed<other.speed)
        {
            return false;
        }
        else
        {
            if(hitpoint>other.hitpoint)
            {
                return true;
            }
            else if(hitpoint<other.hitpoint)
            {
                return false;
            }
            else
            {
                if(damage>other.damage)
                {
                    return true;
                }
                else if(damage<other.damage)
                {
                    return false;
                }
                else
                {
                    if(defense>other.defense)
                    {
                        return true;
                    }
                    else if(defense<other.defense)
                    {
                        return false;
                    }
                    else
                    {
                        cout<<"choose one first 1 or 0"<<endl;
                        int choice;
                        cin>>choice;
                        if(choice==1)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    int getHitpoint() const
    {
        return hitpoint;
    }
    void attack(Monster& other)
    {
        int damageDealt=max(1,2*damage-other.defense);
        other.hitpoint=min(0,other.hitpoint-damageDealt);
    }
    void fight(Monster& other)
    {
        bool thisFirstFlag=thisFirst(other);
        while(hitpoint>0&&other.hitpoint>0)
        {
            if(thisFirstFlag)
            {
                attack(other);
                if(other.hitpoint>0)
                {
                    other.attack(*this);
                }
            }
            else
            {
                other.attack(*this);
                if(hitpoint>0)
                {
                    attack(other);
                }
            }
        }
    }



private:
    int speed;
    int hitpoint;
    int damage;
    int defense;
};

int main()
{
    Monster cat(10, 100, 20, 5);
    Monster dog(10, 100, 20, 5);
    Monster mouse(5, 50, 10, 2);
    cat.fight(dog);
    if(cat.getHitpoint()>0)
    {
        cout<<"Cat wins!"<<endl;
    }
    else
    {
        cout<<"Dog wins!"<<endl;
    }
    cat.fight(mouse);
    if(cat.getHitpoint()>0)
    {
        cout<<"Cat wins!"<<endl;
    }
    else
    {
        cout<<"Mouse wins!"<<endl;
    }
    return 0;
}