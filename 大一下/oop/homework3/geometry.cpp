# include "geometry.hpp"
# include "constants.hpp"
# include <cstring>
static int rect_count = 0;
static int tri_count = 0;


//auto类型推导
auto pRECT = rectangleArea;
auto pTRI = triangleArea;


//使用函数指针数组
GeometryFunc geometryFuncs[] = {pRECT, pTRI};
auto geoOp_count=sizeof(geometryFuncs)/sizeof(GeometryFunc);


//引用形参与引用返回值综合
double rectangleArea(const double& a, const double& b)
{
    return a*b;
}

double triangleArea(const double& a, const double& b)
{
    return a*b*HALF;
}


//返回值为引用的函数
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