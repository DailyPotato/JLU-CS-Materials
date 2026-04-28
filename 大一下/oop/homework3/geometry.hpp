# ifndef GEOMETRY_HPP
# define GEOMETRY_HPP

# include "constants.hpp"
//使用枚举类型
enum GeometryShape{RECTANGLE,TRIANGLE};
double rectangleArea(const double& a, const double& b);
double triangleArea(const double& a, const double& b);
int& getRectCount();
int& getTriCount();
const int& getRectCountReadOnly();
const int& getTriCountReadOnly();
GeometryShape getGeometryOp(char* op);

//使用类型别名
//使用decltype推导函数类型
using GeometryFunc = decltype(rectangleArea)*;
extern GeometryFunc geometryFuncs[];

# endif