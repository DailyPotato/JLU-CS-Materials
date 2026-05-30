#include <iostream>
using namespace std;

class Fruit
{
public:
    Fruit(int weight) : weight(weight) {}
    virtual void decreaseWeight() = 0;
    int getWeight()
    {
        return weight;
    }
    void setWeight(int weight)
    {
        this->weight = weight;
    }

private:
    int weight;
};

class Apple : public Fruit
{
public:
    Apple(int weight = 50) : Fruit(weight) {}
    void decreaseWeight()
    {
        setWeight(max(getWeight() - 4, 3 / 5 * 50));
    }
};
class Orange : public Fruit
{
public:
    Orange(int weight = 30) : Fruit(weight) {}
    void decreaseWeight()
    {
        setWeight(max(getWeight() - 3, 3 / 5 * 50));
    }
};
class Box
{
public:
    Box() : num(0)
    {
        fruits = new Fruit *[8];
    }
    ~Box()
    {
        delete[] fruits;
    }
    void addFruits(Fruit &f)
    {
        fruits[num++] = &f;
    }
    int appleNum()
    {
        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (dynamic_cast<Apple *>(fruits[i]) != nullptr)
            {
                count++;
            }
        }
        return count;
    }
    int orangeNum()
    {
        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (dynamic_cast<Orange *>(fruits[i]) != nullptr)
            {
                count++;
            }
        }
        return count;        
    }
    void printNumOfApple()
    {
        int count=appleNum();
        cout << count << endl;
    }
    void printNumOfOrange()
    {
        int count=orangeNum();
        cout << count << endl;
    }
    void printTotalWeightOfDecrease()
    {
        int total = 0;
        for (int i = 0; i < num; i++)
        {
            fruits[i]->decreaseWeight();
        }
        total+=4*appleNum()+3*orangeNum();
        cout << total << endl;
    }
    void printTotalWeight()
    {
        int total = 0;
        for (int i = 0; i < num; i++)
        {
            total += fruits[i]->getWeight();
        }
        cout << total << endl;
    }

private:
    Fruit **fruits;
    int num;
};

int main()
{
    Box box;
    Apple apple1, apple2;
    Orange orange1, orange2, orange3;
    box.addFruits(apple1);
    box.addFruits(apple2);
    box.addFruits(orange1);
    box.addFruits(orange2);
    box.addFruits(orange3);
    box.printNumOfApple();
    box.printNumOfOrange();
    box.printTotalWeightOfDecrease();
    box.printTotalWeight();
    return 0;
}