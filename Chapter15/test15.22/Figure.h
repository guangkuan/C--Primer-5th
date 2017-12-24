#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

class Figure
{
public:
    Figure(double, double);

protected:
    double xSize, ySize;
};

class Figure_2D : public Figure
{
public:
    Figure_2D(double, double);
    virtual double area() = 0;
    virtual double pcirimeter() = 0;
};

class Figure_3D : public Figure
{
public:
    Figure_3D(double, double, double);
    virtual double cubage() = 0;

protected:
    double zSize;
};

class Rectangle : public Figure_2D
{
public:
    Rectangle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Circle : public Figure_2D
{
public:
    Circle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Sphere : public Figure_3D
{
public:
    Sphere(double, double);
    virtual double cubage();
};

class Cone : public Figure_3D
{
    Cone(double, double, double);
    virtual double cubage();
};


#endif // FIGURE_H_INCLUDED
