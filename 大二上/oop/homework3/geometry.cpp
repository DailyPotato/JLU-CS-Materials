# include "geometry.hpp"
# include "constants.hpp"
# include <string>
static int rect_count = 0;
static int tri_count = 0;
auto geoOp_count=sizeof(geometryFuncs)/sizeof(GeometryFunc);
auto pRECT = rectangleArea;
auto pTRI = triangleArea;
GeometryFunc geometryFuncs[] = {pRECT, pTRI};

double rectangleArea(const double& a, const double& b)
{
    return a*b;
}

double triangleArea(const double& a, const double& b)
{
    return a*b*HALF;
}

int& getRectCount()
{
    return rect_count;
}
int& getTriCount()
{
    return tri_count;
}

const int& getRectCountReadOnly()
{
    return rect_count;
}

const int& getTriCountReadOnly()
{
    return tri_count;
}

GeometryShape getGeometryOp(char* op)
{
    if(!strcmp(op,"rectangle"))
        return RECTANGLE;
    else
        return TRIANGLE;
}