#include "Point.hpp"

static float get_triangle_a( Point a, Point b, Point c ) {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float res;

    x1 = a.getX().toFloat();
    y1 = a.getY().toFloat();

    x2 = b.getX().toFloat();
    y2 = b.getY().toFloat();

    x3 = c.getX().toFloat();
    y3 = c.getY().toFloat();

    res = (x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 )) / 2.0f;
    if (res < 0)
        return ( -res );
    return ( res );
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    float r_area = get_triangle_a( a, b, c );
    float p_area_1 = get_triangle_a( point, a, b );
    float p_area_2 = get_triangle_a( point, b, c );
    float p_area_3 = get_triangle_a( point, c, a );

    if ( p_area_1 <= 0 || p_area_2 <= 0 || p_area_3 <= 0 )
        return ( false );
    else if ( p_area_1 + p_area_2 + p_area_3 == r_area )
        return ( true );
    else
        return ( false );
}
