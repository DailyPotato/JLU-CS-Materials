#include <iostream>
using namespace std;

class Paginate
{
public:
    Paginate(int n, int m) : num(1), total(13) {}
    Paginate &setPage(int page, int total)
    {
        num = page;
        rangeStart = max(num / 5 * 5+1, 1);
        rangeEnd = min(total, num / 5 * 5 + 5);
        return *this;
    }
    Paginate &prev()
    {
        if (num > 1)
        {
            num--;
            setPage(num, total);
        }
        return *this;
    }
    Paginate &next()
    {
        if (num < total)
        {
            num++;
            setPage(num, total);
        }
        return *this;
    }
    Paginate &prevN()
    {
        if (num > 5)
        {
            num -= 5;
            setPage(num, total);
        }
        return *this;
    }
    Paginate &nextN()
    {
        if (num + 5 <= total)
        {
            num += 5;
            setPage(num, total);
        }
        return *this;
    }
    void show()
    {

        cout << "上页 ";
        if (rangeStart != 1)
        {
            cout << "1 ... ";
        }
        for (int i = rangeStart; i <= rangeEnd; ++i)
        {
            if (i == num)
            {
                cout << i << "+ ";
            }
            else
            {
                cout << i << " ";
            }
        }
        if (rangeEnd != total)
        {
            cout << "... " << total << " " << "下页"<< endl;
        }
    }

private:
    int num;
    int total;
    int rangeStart;
    int rangeEnd;
};

int main()
{
    Paginate pager(1, 13);
    for (int i = 1; i <= 13; ++i)
    {
        // i 当前页，13 总页数
        pager.setPage(i, 13).show();
    }
    cout << "start move...." << endl;
    pager.setPage(5, 13).show();
    pager.next().show();
    pager.prev().show();
    // 直接翻 5 页
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}