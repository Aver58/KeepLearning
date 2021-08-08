///* lines_intersect:  AUTHOR: Mukesh Prasad
// *
// *   This function computes whether two line segments,
// *   respectively joining the input points (x1,y1) -- (x2,y2)
// *   and the input points (x3,y3) -- (x4,y4) intersect.
// *   If the lines intersect, the output variables x, y are
// *   set to coordinates of the point of intersection.
// *
// *   All values are in integers.  The returned value is rounded
// *   to the nearest integer point.
// *
// *   If non-integral grid points are relevant, the function
// *   can easily be transformed by substituting floating point
// *   calculations instead of integer calculations.
// *
// *   Entry
// *        x1, y1,  x2, y2   Coordinates of endpoints of one segment.
// *        x3, y3,  x4, y4   Coordinates of endpoints of other segment.
// *
// *   Exit
// *        x, y              Coordinates of intersection point.
// *
// *   The value returned by the function is one of:
// *
// *        DONT_INTERSECT    0
// *        DO_INTERSECT      1
// *        COLLINEAR         2
// *
// * Error conditions:
// *
// *     Depending upon the possible ranges, and particularly on 16-bit
// *     computers, care should be taken to protect from overflow.
// *
// *     In the following code, 'long' values have been used for this
// *     purpose, instead of 'int'.
// *
// */
//
//#include <stdio.h>
//
//#define	DONT_INTERSECT    0
//#define	DO_INTERSECT      1
//#define COLLINEAR         2
//
// /**************************************************************
//  *                                                            *
//  *    NOTE:  The following macro to determine if two numbers  *
//  *    have the same sign, is for 2's complement number        *
//  *    representation.  It will need to be modified for other  *
//  *    number systems.                                         *
//  *                                                            *
//  **************************************************************/
//
//#define SAME_SIGNS( a, b )	\
//		(((long) ((unsigned long) a ^ (unsigned long) b)) >= 0 )
//
//int lines_intersect(int x1, int  y1,   /* First line segment */
//    int x2, int y2,
//    int x3, int y3,   /* Second line segment */
//    int x4, int y4,
//    int x,
//    int y         /* Output value:
//               * point of intersection */
//)
//long x1, y1, x2, y2, x3, y3, x4, y4, * x, * y;
//{
//    long a1, a2, b1, b2, c1, c2; /* Coefficients of line eqns. */
//    long r1, r2, r3, r4;         /* 'Sign' values */
//    long denom, offset, num;     /* Intermediate values */
//
//    /* Compute a1, b1, c1, where line joining points 1 and 2
//     * is "a1 x  +  b1 y  +  c1  =  0".
//     */
//
//    a1 = y2 - y1;
//    b1 = x1 - x2;
//    c1 = x2 * y1 - x1 * y2;
//
//    /* Compute r3 and r4.
//     */
//
//
//    r3 = a1 * x3 + b1 * y3 + c1;
//    r4 = a1 * x4 + b1 * y4 + c1;
//
//    /* Check signs of r3 and r4.  If both point 3 and point 4 lie on
//     * same side of line 1, the line segments do not intersect.
//     */
//
//    if (r3 != 0 &&
//        r4 != 0 &&
//        SAME_SIGNS(r3, r4))
//        return (DONT_INTERSECT);
//
//    /* Compute a2, b2, c2 */
//
//    a2 = y4 - y3;
//    b2 = x3 - x4;
//    c2 = x4 * y3 - x3 * y4;
//
//    /* Compute r1 and r2 */
//
//    r1 = a2 * x1 + b2 * y1 + c2;
//    r2 = a2 * x2 + b2 * y2 + c2;
//
//    /* Check signs of r1 and r2.  If both point 1 and point 2 lie
//     * on same side of second line segment, the line segments do
//     * not intersect.
//     */
//
//    if (r1 != 0 &&
//        r2 != 0 &&
//        SAME_SIGNS(r1, r2))
//        return (DONT_INTERSECT);
//
//    /* Line segments intersect: compute intersection point.
//     */
//
//    denom = a1 * b2 - a2 * b1;
//    if (denom == 0)
//        return (COLLINEAR);
//    offset = denom < 0 ? -denom / 2 : denom / 2;
//
//    /* The denom/2 is to get rounding instead of truncating.  It
//     * is added or subtracted to the numerator, depending upon the
//     * sign of the numerator.
//     */
//
//    num = b1 * c2 - b2 * c1;
//    *x = (num < 0 ? num - offset : num + offset) / denom;
//
//    num = a2 * c1 - a1 * c2;
//    *y = (num < 0 ? num - offset : num + offset) / denom;
//
//    return (DO_INTERSECT);
//} /* lines_intersect */
//
//int main()
//{
//    long int x1, x2, x3, x4, y1, y2, y3, y4;
//    long int x, y;
//
//    for (;;) {
//        printf("X1, Y1: ");
//        scanf("%ld %ld", &x1, &y1);
//        printf("X2, Y2: ");
//        scanf("%ld %ld", &x2, &y2);
//        printf("X3, Y3: ");
//        scanf("%ld %ld", &x3, &y3);
//        printf("X4, Y4: ");
//        scanf("%ld %ld", &x4, &y4);
//
//        switch (lines_intersect(x1, y1, x2, y2, x3, y3, x4, y4, &x, &y)) {
//        case DONT_INTERSECT:
//            printf("Lines don't intersect\n");
//            break;
//        case COLLINEAR:
//            printf("Lines are collinear\n");
//            break;
//        case DO_INTERSECT:
//            printf("Lines intersect at %ld,%ld\n", x, y);
//            break;
//        }
//    }
//} /* main */
//
//
//
//
//#include <algorithm>
//bool IsRectIntersect(const Rect& rc1, const Rect& rc2)
//{
//    return ((std::max(rc1.p1.x, rc1.p2.x) >= std::min(rc2.p1.x, rc2.p2.x))
//        && (std::max(rc2.p1.x, rc2.p2.x) >= std::min(rc1.p1.x, rc1.p2.x))
//        && (std::max(rc1.p1.y, rc1.p2.y) >= std::min(rc2.p1.y, rc2.p2.y))
//        && (std::max(rc2.p1.y, rc2.p2.y) >= std::min(rc1.p1.y, rc1.p2.y)));
//}
//
//bool IsLineSegmentIntersect(const LineSeg& ls1, const LineSeg& ls2)
//{
//    if (IsLineSegmentExclusive(ls1, ls2)) //排斥实验
//    {
//        return false;
//    }
//    //( P1 - Q1 ) ×'a1?( Q2 - Q1 )
//    double p1xq = CrossProduct(ls1.ps.x - ls2.ps.x, ls1.ps.y - ls2.ps.y,
//        ls2.pe.x - ls2.ps.x, ls2.pe.y - ls2.ps.y);
//    //( P2 - Q1 ) ×'a1?( Q2 - Q1 )
//    double p2xq = CrossProduct(ls1.pe.x - ls2.ps.x, ls1.pe.y - ls2.ps.y,
//        ls2.pe.x - ls2.ps.x, ls2.pe.y - ls2.ps.y);
//
//    //( Q1 - P1 ) ×'a1?( P2 - P1 )
//    double q1xp = CrossProduct(ls2.ps.x - ls1.ps.x, ls2.ps.y - ls1.ps.y,
//        ls1.pe.x - ls1.ps.x, ls1.pe.y - ls1.ps.y);
//    //( Q2 - P1 ) ×'a1?( P2 - P1 )
//    double q2xp = CrossProduct(ls2.pe.x - ls1.ps.x, ls2.pe.y - ls1.ps.y,
//        ls1.pe.x - ls1.ps.x, ls1.pe.y - ls1.ps.y);
//
//    //跨立实验
//    return ((p1xq * p2xq <= 0.0) && (q1xp * q2xp <= 0.0));
//}


#define  TRUE 1
#define  FALSE 0

struct point
{
    double x;
    double y;
};

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int Online(point P1, point P2, point Q)
{
    if ((Q.x - P1.x) * (P2.y - P1.y) == ((P2.x - P1.x) * (Q.y - P1.y))  //叉乘

        && (min(P1.x, P2.x) <= Q.x && Q.x <= max(P1.x, P2.x))
        //保证Q点坐标在P1P2之间
        && min(P1.y, P2.y) <= Q.y && Q.y <= max(P1.y, P2.y))
        return TRUE;
    else
        return FALSE;
}