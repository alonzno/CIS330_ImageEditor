/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>
#include <stdlib.h>

void InitializeCircle(Circle * c, double r, double x, double y) {
    c -> x = x;
    c -> y = y;
    c -> r = r;
}

void InitializeRectangle(Rectangle *r, double mx, double Mx, double my, double My) {
    r -> mx = mx;
    r -> Mx = Mx;
    r -> my = my;
    r -> My = My;
}

void InitializeTriangle(Triangle *t, double x1, double x2, double my, double My) {
    t -> x1 = x1;
    t -> x2 = x2;
    t -> my = my;
    t -> My = My;
}

double GetCircleArea(Circle *c) {
    return 3.14159 * (c -> r) * (c -> r);
}

double GetRectangleArea(Rectangle *r) {
    return ((r -> Mx) - (r -> mx)) * ((r -> My) - (r -> my));
}

double GetTriangleArea(Triangle *t) {
    return ((t -> x2) - (t -> x1)) * ((t -> My) - (t -> my)) / 2;
}

void GetCircleBoundingBox(Circle *c, double *bbox) {
    bbox[0] = (c -> x) - (c -> r);
    bbox[1] = (c -> x) + (c -> r);
    bbox[2] = (c -> y) - (c -> r);
    bbox[3] = (c -> y) + (c -> r);
}

void GetRectangleBoundingBox(Rectangle *r, double *bbox) {
    bbox[0] = (r -> mx);
    bbox[1] = (r -> Mx);
    bbox[2] = (r -> my);
    bbox[3] = (r -> My);
}

void GetTriangleBoundingBox(Triangle *t, double *bbox) {
    bbox[0] = (t -> x1);
    bbox[1] = (t -> x2);
    bbox[2] = (t -> my);
    bbox[3] = (t -> My);
}
