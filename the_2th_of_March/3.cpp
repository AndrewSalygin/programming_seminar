#include <iostream>
#include <cmath>

using namespace std;
struct point
{
    double x, y, z;
    point(double a, double b);
    point(double a, double b, double c);
};

point::point(double a, double b)
{
    x = a; y = b;
}

point::point(double a, double b, double c)
{
    x = a; y = b; z = c;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double distance(double x1, double y1, double z1, double x2,
                 double y2, double z2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) +
                 (z1 - z2)*(z1 - z2));
}
double distance(point *p1, point *p2)
{
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) +
                (p1->y - p2->y)*(p1->y - p2->y));
}
double distance(point *p1, point *p2, point *p3)
{
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) +
                (p1->y - p2->y)*(p1->y - p2->y) +
                (p1->z - p2->z)*(p1->z - p2->z));
}

int main()
{
    double x1, y1, x2, y2, x3, y3, z3,
            x4, y4, z4;
    cout << "Введите координаты первой точки (x, y):" << '\n';
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки (x, y):" << '\n';
    cin >> x2 >> y2;
    cout << "Введите координаты третьей точки (x, y, z):" << '\n';
    cin >> x3 >> y3 >> z3;
    cout << "Введите координаты четвёртой точки (x, y, z):" << '\n';
    cin >> x4 >> y4 >> z4;

    point *p1 = new point(x1, y1);
    point *p2 = new point(x2, y2);
    point *p3 = new point(x3, y3, z3);
    point *p4 = new point(x4, y4, z4);

    return 0;
}


