#include <iostream>
using namespace std;

class Wall
{
public:
    Wall() : color(0)
    {
        cout << "构造一面墙" << endl;
    }
    void Paint(int newColor)
    {
        color = newColor;
        cout << "用新颜色粉刷墙" << endl;
    }
    int GetColor() const
    {
        return color;
    }

private:
    int color;
};
class Door
{
public:
    Door() : openOrClose(false)
    {
        cout << "构造一扇门" << endl;
    }
    void Open()
    {
        if (!IsOpened())
        {
            openOrClose = true;
            cout << "门被打开了" << endl;
        }
        else
        {
            cout << "门开着呢！" << endl;
        }
    }
    void Close()
    {
        if (IsOpened())
        {
            openOrClose = false;
            cout << "门被关上了" << endl;
        }
        else
        {
            cout << "门关着呢！" << endl;
        }
    }
    bool IsOpened() const
    {
        return openOrClose;
    }

private:
    bool openOrClose;
};

class WallWithDoor:public Wall
{
public:
    WallWithDoor(){}
    void paint(int color)
    {
        Paint(color);
        if(color==1)
        {
            door->Close();
        }
        else if(color==2)
        {
            door->Open();
        }

    }
private:
    Door* door;
};