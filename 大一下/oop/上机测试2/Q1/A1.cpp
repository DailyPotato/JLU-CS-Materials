#include <iostream>

using namespace std;

class Box
{
public:
    Box(double l, double b, double h):length(l), breadth(b), height(h){}
    double getVolume()
    {
        return length * breadth * height;
    }
    double getSurfaceArea()
    {
        return 2 * (length * breadth + breadth * height + height * length);
    }
private:
    double length;
    double breadth;
    double height;
};

int main()
{
    Box box1(10.0, 20.0, 30.0);
    Box box2(5.0, 15.0, 25.0);

    std::cout << "Volume of box1: " << box1.getVolume() << std::endl;
    std::cout << "Surface Area of box1: " << box1.getSurfaceArea() << std::endl;

    std::cout << "Volume of box2: " << box2.getVolume() << std::endl;
    std::cout << "Surface Area of box2: " << box2.getSurfaceArea() << std::endl;

    return 0;
}