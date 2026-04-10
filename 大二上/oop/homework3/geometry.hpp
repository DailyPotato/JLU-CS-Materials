# ifndef GEOMETRY_HPP
# define GEOMETRY_HPP

# include "constants.hpp"
extern int rect_count;
extern int tri_count;
enum GeometryOp{RECTANGLE,TRIANGLE};
float rectangleArea(int a,int b);
float triangleArea(int a,int b);
GeometryOp getGeometryOp(char* op);
using GeometryFunc = double(*)(const double&, const double&);
extern GeometryFunc geometryFuncs[];

# endif