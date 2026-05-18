#include <iostream>
#include <utility>
using namespace std;

enum class Suit
{
    Spade,
    Heart,
    Diamond,
    Club
};

enum class Rank
{
    Two=2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{

public:
    Card(int id,Suit s,Rank r,unsigned int iobc,double w,double h,pair<double,double> ltc):ID(id),suit(s),rank(r),IdOfBackCard(iobc),width(w),height(h),leftTopCorner(ltc){}
    Card(const Card& other):ID(other.ID),suit(other.suit),rank(other.rank),IdOfBackCard(other.IdOfBackCard),width(other.width),height(other.height),leftTopCorner(other.leftTopCorner){}
    bool isSameSuit(const Card& other) const
    {
        return suit == other.suit;
    }
    bool isSameRank(const Card& other) const
    {
        return rank == other.rank;
    }
    bool isSuitOf(Suit s) const
    {
        return suit == s;
    }
    bool isRankOf(Rank r) const
    {
        return rank == r;
    }
    void setPosition(double x, double y)
    {
        leftTopCorner = make_pair(x, y);
    }
    pair<double, double> getRightBottomPosition() const
    {
        return make_pair(leftTopCorner.first + width, leftTopCorner.second - height);
    }
private:

    int ID;
    Suit suit;
    Rank rank;
    unsigned int IdOfBackCard;
    double width;
    double height;
    pair<double,double> leftTopCorner;
};

int main()
{
    Card card1(1,Suit::Spade,Rank::Ace,0,2.5,3.5,{0.0,0.0});
    Card card2(2,Suit::Heart,Rank::King,0,2.5,3.5,{0.0,0.0});

    cout << "Card 1 and Card 2 have the same suit: " << card1.isSameSuit(card2) << endl;
    cout << "Card 1 and Card 2 have the same rank: " << card1.isSameRank(card2) << endl;
    cout<< "Card 1 is of suit Spade: " << card1.isSuitOf(Suit::Spade) << endl;
    cout << "Card 1 is of rank Ace: " << card1.isRankOf(Rank::Ace) << endl;
    cout<<"Card 1 is of suit Heart: "<<card1.isSuitOf(Suit::Heart)<<endl;
    cout<<"Card 1 is of rank King: "<<card1.isRankOf(Rank::King)<<endl;
    card1.setPosition(10.0, 20.0);
    pair<double,double> rightBottom = card1.getRightBottomPosition();
    cout << "Card 1 right bottom position: (" << rightBottom.first << ", " << rightBottom.second << ")" << endl;

    return 0;
}