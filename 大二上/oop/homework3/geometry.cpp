# include "geometry.hpp"
# include "constants.hpp"
# include <string>
int rect_count = 0;
int tri_count = 0;

GeometryFunc geometryFuncs[] = {rectangleArea, triangleArea};

double rectangleArea(const double& a, const double& b)
{
    rect_count++;
    return a*b;
}

double triangleArea(const double& a, const double& b)
{
    tri_count++;
    return a*b*HALF;
}

GeometryOp getGeometryOp(char* op)
{
    if(!strcmp(op,"rectangle"))
        return RECTANGLE;
    else
        return TRIANGLE;
}