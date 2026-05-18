#include <iostream>
#include <string>
using namespace std;
int totalEquipment[6]={1,2,3,4,5,6};

enum class abilityScore
{
    Charisma,
    Reputation,
    AttackPower,
    Defence,
    Mana
};
class Hero
{
public:
    Hero(int c,int r,int ap,int d,int m):charisma(c),reputation(r),attackPower(ap),defence(d),mana(m)
    {
        for(int i=0;i<5;i++)
        {
            equipment[i]=0;
        }
    }
    int getAbility(abilityScore score)
    {
        switch(score)
        {
            case abilityScore::Charisma:
                return charisma;
            case abilityScore::Reputation:
                return reputation;
            case abilityScore::AttackPower:
                return attackPower;
            case abilityScore::Defence:
                return defence;
            case abilityScore::Mana:
                return mana;
        }
    }
    void equipEquipmentOn(int equipmentId,int slot)
    {
        if(equipmentId<1||equipmentId>6)
        {
            cout<<"Invalid equipment ID"<<endl;
            return;
        }
        if(slot<0||slot>4)
        {
            cout<<"Invalid slot number"<<endl;
            return;
        }
        equipment[slot]=totalEquipment[equipmentId-1];
        switch(equipmentId)
        {
            case 1:
                charisma+=10;
                break;
            case 2:
                reputation+=3;
                break;
            case 3:
                attackPower+=1;
                break;
            case 4:
                defence+=5;
                break;
            case 5:
                mana+=20;
                break;
            case 6:
                charisma+=1;
                reputation+=1;
                attackPower+=1;
                defence+=1;
                mana+=1;
                break;
        }
    }
    void disputeEquipmentOn(int slot)
    {
        if(slot<0||slot>4)
        {
            cout<<"Invalid slot number"<<endl;
            return;
        }
        int equipmentId=equipment[slot];
        if(equipmentId==0)
        {
            cout<<"No equipment to dispute"<<endl;
            return;
        }
        switch(equipmentId)
        {
            case 1:
                charisma-=10;
                break;
            case 2:
                reputation-=3;
                break;
            case 3:
                attackPower-=1;
                break;
            case 4:
                defence-=5;
                break;
            case 5:
                mana-=20;
                break;
            case 6:
                charisma-=1;
                reputation-=1;
                attackPower-=1;
                defence-=1;
                mana-=1;
                break;
        }
        equipment[slot]=0;
    }
private:
    int charisma;
    int reputation;
    int attackPower;
    int defence;
    int mana;
    int equipment[5];
};


int main()
{
    Hero Jack(10, 20, 30, 40, 50);
    cout << "Jack's initial Charisma: " << Jack.getAbility(abilityScore::Charisma) << endl;
    cout << "Jack's initial Reputation: " << Jack.getAbility(abilityScore::Reputation) << endl;
    cout << "Jack's initial Attack Power: " << Jack.getAbility(abilityScore::AttackPower) << endl;
    cout << "Jack's initial Defence: " << Jack.getAbility(abilityScore::Defence) << endl;
    cout << "Jack's initial Mana: " << Jack.getAbility(abilityScore::Mana) << endl;
    Jack.equipEquipmentOn(1, 0);
    Jack.equipEquipmentOn(3, 1);
    cout << "Jack's Charisma after equipping equipment 1: " << Jack.getAbility(abilityScore::Charisma) << endl;
    cout << "Jack's Attack Power after equipping equipment 3: " << Jack.getAbility(abilityScore::AttackPower) << endl;
    Jack.disputeEquipmentOn(0);
    cout << "Jack's Charisma after disputing equipment in slot 0: " << Jack.getAbility(abilityScore::Charisma) << endl;
    Jack.disputeEquipmentOn(1);
    cout << "Jack's Attack Power after disputing equipment in slot 1: " << Jack.getAbility(abilityScore::AttackPower) << endl;
    return 0;
}