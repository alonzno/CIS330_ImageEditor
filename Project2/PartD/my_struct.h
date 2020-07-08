/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */
struct Shape;

typedef struct {
    double mx;
    double Mx;
    double my;
    double My;
}Rectangle;

typedef struct {
    double x;
    double y;
    double r;
}Circle;

typedef struct {
    double x1;
    double x2;
    double my;
    double My;
}Triangle;


enum ShapeType {
    TRIANGLE = 1,
    CIRCLE,
    RECTANGLE
};

union ShapeUnion {
    Circle c;
    Triangle t;
    Rectangle r;
};

struct FunctionTable {
    void (*GetBoundingBox)(struct Shape *, double *);
    double (*GetArea)(struct Shape *);
};

struct Shape {
    struct FunctionTable ft;
    enum ShapeType type;
    union ShapeUnion shape;
};


/*
void GetCircleBoundingBox(Circle *c , double *bbox);
void GetRectangleBoundingBox(Rectangle *r, double *bbox);
void GetTriangleBoundingBox(Triangle *t, double *bbox);

double GetCircleArea(Circle *c);
double GetRectangleArea(Rectangle *r);
double GetTriangleArea(Triangle *t);

void InitializeCircle(Circle *c, double x, double y, double r);
void InitializeRectangle(Rectangle *r, double mx, double Mx, double my, double My);
void InitializeTriangle(Triangle *t, double x1, double x2, double my, double My);
*/
