/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>
#include <stdlib.h>

void InitializeCircle(struct Shape * c, double r, double x, double y) {
    c -> shape.c.x = x;
    c -> shape.c.y = y;
    c -> shape.c.r = r;
    
    c -> ft.GetArea = GetCircleArea;
    c -> ft.GetBoundingBox = GetCircleBoundingBox;
}

void InitializeRectangle(struct Shape *r, double mx, double Mx, double my, double My) {
    r -> shape.r.mx = mx;
    r -> shape.r.Mx = Mx;
    r -> shape.r.my = my;
    r -> shape.r.My = My;
    
    r -> ft.GetArea = GetRectangleArea;
    r -> ft.GetBoundingBox = GetRectangleBoundingBox;
}

void InitializeTriangle(struct Shape *t, double x1, double x2, double my, double My) {
    t -> shape.t.x1 = x1;
    t -> shape.t.x2 = x2;
    t -> shape.t.my = my;
    t -> shape.t.My = My;
    
    t -> ft.GetArea = GetTriangleArea;
    t -> ft.GetBoundingBox = GetTriangleBoundingBox;
}

double GetCircleArea(struct Shape *c) {
    return 3.14159 * (c -> shape.c.r) * (c -> shape.c.r);
}

double GetRectangleArea(struct Shape *r) {
    return ((r -> shape.r.Mx) - (r -> shape.r.mx)) * ((r -> shape.r.My) - (r -> shape.r.my));
}

double GetTriangleArea(struct Shape *t) {
    return ((t -> shape.t.x2) - (t -> shape.t.x1)) * ((t -> shape.t.My) - (t -> shape.t.my)) / 2;
}

void GetCircleBoundingBox(struct Shape *c, double *bbox) {
    bbox[0] = (c -> shape.c.x) - (c -> shape.c.r);
    bbox[1] = (c -> shape.c.x) + (c -> shape.c.r);
    bbox[2] = (c -> shape.c.y) - (c -> shape.c.r);
    bbox[3] = (c -> shape.c.y) + (c -> shape.c.r);
}

void GetRectangleBoundingBox(struct Shape *r, double *bbox) {
    bbox[0] = (r -> shape.r.mx);
    bbox[1] = (r -> shape.r.Mx);
    bbox[2] = (r -> shape.r.my);
    bbox[3] = (r -> shape.r.My);
}

void GetTriangleBoundingBox(struct Shape *t, double *bbox) {
    bbox[0] = (t -> shape.t.x1);
    bbox[1] = (t -> shape.t.x2);
    bbox[2] = (t -> shape.t.my);
    bbox[3] = (t -> shape.t.My);
}
