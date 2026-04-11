# ifndef GEOMETRY_HPP
# define GEOMETRY_HPP

# include "constants.hpp"
// extern int rect_count;
// extern int tri_count;
enum GeometryShape{RECTANGLE,TRIANGLE};
double rectangleArea(const double& a, const double& b);
double triangleArea(const double& a, const double& b);
int& getRectCount();
int& getTriCount();
const int& getRectCountReadOnly();
const int& getTriCountReadOnly();
GeometryShape getGeometryOp(char* op);
using GeometryFunc = decltype(rectangleArea)*;
extern GeometryFunc geometryFuncs[];

# endif