#include "Shape.h"

#include <iostream>

namespace {
const double PI = 3.14159;
}

Rectangle::Rectangle(double length, double width)
    : m_length(length), m_width(width)
{
    // 构造链：先构造 Shape 基类部分，再构造 Rectangle 派生类部分。
    std::cout << "Rectangle created" << std::endl;
}

Rectangle::~Rectangle()
{
    // 析构链：先运行 Rectangle 析构函数，再自动运行 Shape 虚析构函数。
    std::cout << "Rectangle destroyed" << std::endl;
}

double Rectangle::area() const
{
    return m_length * m_width;
}

bool Rectangle::isValid() const
{
    return m_length > 0 && m_width > 0;
}

Shape* Rectangle::clone() const
{
    // 虚拟拷贝用于 copy 命令：经由 Shape* 动态绑定到 Rectangle::clone，
    // 返回独立的新对象，调用者负责 delete。这里调用普通构造函数，
    // 因而复制出的对象也会输出构造调试信息。
    return new Rectangle(m_length, m_width);
}

Triangle::Triangle(double base, double height)
    : m_base(base), m_height(height)
{
    // 构造链：Shape 基类先完成，随后 Triangle 初始化自己的数据成员。
    std::cout << "Triangle created" << std::endl;
}

Triangle::~Triangle()
{
    // 通过 Shape* delete 时，虚析构保证先析构 Triangle 再析构 Shape。
    std::cout << "Triangle destroyed" << std::endl;
}

double Triangle::area() const
{
    return m_base * m_height / 2.0;
}

bool Triangle::isValid() const
{
    return m_base > 0 && m_height > 0;
}

Shape* Triangle::clone() const
{
    // 深拷贝：复制具体 Triangle 的全部状态，而不是只复制 Shape 基类部分。
    return new Triangle(m_base, m_height);
}

Circle::Circle(double radius)
    : m_radius(radius)
{
    // 构造链同样先基类后派生类，输出信息便于观察生命周期。
    std::cout << "Circle created" << std::endl;
}

Circle::~Circle()
{
    // 析构链与构造链顺序相反，体现继承下对象生命周期规则。
    std::cout << "Circle destroyed" << std::endl;
}

double Circle::area() const
{
    return PI * m_radius * m_radius;
}

bool Circle::isValid() const
{
    return m_radius > 0;
}

Shape* Circle::clone() const
{
    // 真实价值：调用者只保存 Shape*，仍能复制出 Circle 的真实派生对象。
    return new Circle(m_radius);
}
