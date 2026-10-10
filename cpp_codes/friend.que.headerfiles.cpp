//

Point3d.h:

// Header file that defines the Point3d class

#ifndef POINT3D_H
#define POINT3D_H

class Vector3d; // forward declaration for class Vector3d for function moveByVector()

class Point3d
{
    private:
        double m_x{};
        double m_y{};
        double m_z{};

    public:
        Point3d(double x, double y, double z);

        void print() const;
        void moveByVector(const Vector3d& v); // forward declaration above needed for this line
};

#endif

//


Point3d.cpp:

// Member functions of the Point3d class defined here

#include "Point3d.h" // Point3d class defined here
#include "Vector3d.h" // for the parameter of the function moveByVector()

#include <iostream>

Point3d::Point3d(double x, double y, double z)
  : m_x{x}, m_y{y}, m_z{z}
{}

void Point3d::moveByVector(const Vector3d& v)
{
    // Add the vector components to the corresponding point coordinates
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

void Point3d::print() const
{
    std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

//

Vector3d.h:

// Header file that defines the Vector3d class

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
    private:
        double m_x{};
        double m_y{};
        double m_z{};

    public:
        Vector3d(double x, double y, double z);

        void print() const;
        friend void Point3d::moveByVector(const Vector3d& v);
};

#endif

//

Vector3d.cpp:

// Member functions of the Vector3d class defined here

#include "Vector3d.h" // Vector3d class defined in this file

#include <iostream>

Vector3d::Vector3d(double x, double y, double z)
  : m_x{x}, m_y{y}, m_z{z}
{}

void Vector3d::print() const
{
    std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

//

main.cpp:

#include "Vector3d.h"
#include "Point3d.h"

int main()
{
    Point3d p { 1.0, 2.0, 3.0 };
    Vector3d v { 2.0, 2.0, -3.0 };

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}

//