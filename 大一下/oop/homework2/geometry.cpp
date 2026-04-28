# include "geometry.hpp"
# include "constants.hpp"

int rect_count = 0;
int tri_count = 0;


float rectangleArea(int a,int b)
{
    rect_count++;
    return float(a*b);
}

float triangleArea(int a,int b)
{
    tri_count++;
    return float(a*b*HALF);
}