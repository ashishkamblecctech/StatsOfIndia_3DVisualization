#pragma once
#include "Point3D.h"

class GEOMETRY_API Line
{
public:
    Line(Point3D p1, Point3D p2);  
    Line(const Line& other);
    ~Line();
    Line& operator=(const Line&);

    Point3D& p1(); 
    Point3D& p2();

private:
    Point3D mP1;  
    Point3D mP2;
};
