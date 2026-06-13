#ifndef SHAPE_H
#define SHAPE_H

// 图形抽象基类：用纯虚函数定义所有图形共同遵守的接口。
// Shape 禁止直接实例化，CalculatorApp 通过 Shape* 管理具体派生类。
class Shape {
public:
    virtual ~Shape() = default; // 虚析构保证 delete 基类指针时先析构派生类再析构基类。

    // 拷贝控制：题目要求所有类禁止拷贝，避免对象切片和所有权混乱。
    // 如果基类允许拷贝，拷贝构造应设为 protected 或 public，派生类拷贝构造
    // 在初始化列表中调用 Shape(other)，赋值时先调用 Shape::operator=(other)。
    // 本题通过 clone() 进行多态深拷贝，因此禁止普通拷贝不影响 copy 命令。
    Shape(const Shape&) = delete; // 禁止拷贝基类，防止对象切片。
    Shape& operator=(const Shape&) = delete; // 禁止基类赋值，避免只赋值 Shape 部分。

    virtual double area() const = 0;
    virtual bool isValid() const = 0;
    virtual Shape* clone() const = 0; // 虚拟拷贝：只知道 Shape* 时复制真实派生类型。

protected:
    Shape() = default;
};

// Rectangle 是一种 Shape，公有继承表达 is-a 关系；派生类复用基类接口，
// 只覆盖可变的面积、合法性和拷贝行为，体现垂直复用。
class Rectangle : public Shape {
public:
    Rectangle(double length, double width);
    ~Rectangle() override;

    Rectangle(const Rectangle&) = delete; // 普通拷贝禁止，统一通过 clone() 深拷贝。
    Rectangle& operator=(const Rectangle&) = delete; // 禁止赋值，避免绕开多态拷贝约定。

    double area() const override;
    bool isValid() const override;
    Shape* clone() const override;

private:
    double m_length;
    double m_width;
};

// Triangle 是一种 Shape，公有继承让 Triangle* 可向上转换为 Shape*。
class Triangle : public Shape {
public:
    Triangle(double base, double height);
    ~Triangle() override;

    Triangle(const Triangle&) = delete; // 禁止拷贝避免复制对象时绕开多态接口。
    Triangle& operator=(const Triangle&) = delete; // 禁止赋值，copy 命令统一使用 clone()。

    double area() const override;
    bool isValid() const override;
    Shape* clone() const override;

private:
    double m_base;
    double m_height;
};

// Circle 是一种 Shape，新增图形只需增加派生类，不影响已有图形代码。
class Circle : public Shape {
public:
    explicit Circle(double radius);
    ~Circle() override;

    Circle(const Circle&) = delete; // 普通拷贝禁止，copy 命令统一使用 clone()。
    Circle& operator=(const Circle&) = delete; // 禁止赋值，避免派生对象状态被随意覆盖。

    double area() const override;
    bool isValid() const override;
    Shape* clone() const override;

private:
    double m_radius;
};

#endif
