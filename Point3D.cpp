#include <iostream>
#include <ostream>
#include <cmath>
#include "Point3D.h"

//Konstruktor domyslny klasy Punkt3D.
Point3D::Point3D():ID_Point3D(pointCount)
{
    std::cout<<"Konstruktor domyslny point3D ID:"<<ID_Point3D<<std::endl;
    Xp=0;
    Yp=0;
    Zp=0;
    ++pointCount;
}

//Konstruktor parametryczny klasy Punkt3D. Argumenty X,Y,Z definuja wspolrzedne Xp,Yp,Zp Punktu3D.
Point3D::Point3D(const double &X,const double &Y,const double &Z):ID_Point3D(pointCount)
{
    Xp=X;
    Yp=Y;
    Zp=Z;
    std::cout<<"Konstruktor parametryczny point3D ID:"<<ID_Point3D<<std::endl;
    ++pointCount;
}

//Konstruktor kopiujacy klasy Punkt3D.
Point3D::Point3D(const Point3D& P):ID_Point3D(pointCount)
{
    Xp=P.Xp;
    Yp=P.Yp;
    Zp=P.Zp;
    std::cout<<"Konstruktor kopiujacy Point3D ID:"<<ID_Point3D<<std::endl;
    ++pointCount;
}

//Destruktor klasy Punkt3D.
Point3D::~Point3D()
{
    std::cout<<"Destruktor Point3D ID:"<<ID_Point3D<<std::endl;
}

//Zwraca wspolrzedna Xp.
double Point3D::GetX()
{
    return Xp;
}

//Zwraca wspolrzedna Yp.
double Point3D::GetY()
{
    return Yp;
}

//Zwraca wspolrzedna Zp.
double Point3D::GetZ()
{
    return Zp;
}

//Ustawia wspolrzedna Xp.
void Point3D::SetX(double& x)
{
    Xp=x;
}

//Ustawia wspolrzedna Yp.
void Point3D::SetY(double& y)
{
    Yp=y;
}

//Ustawia wspolrzedna Zp.
void Point3D::SetZ(double& z)
{
    Zp=z;
}

//Przesuwa Punkt3D o wektor [dx,dy,dz].
void Point3D::MovePoint3D(const double &dx, const double &dy, const double &dz)
{
    Xp+=dx;
    Yp+=dy;
    Zp+=dz;
}

//Obraca Punkt3D dookola osi X o kat fi wykorzystujac macierz obrotu Rx.
void Point3D::RotateXPoint3D(const double &fi)
{
    const double s=sin(fi),c=cos(fi);
    double x,y,z;
    x=Xp;
    y=Yp*c-Zp*s;
    z=Yp*s+Zp*c;
    Xp=x;
    Yp=y;
    Zp=z;
}

//Obraca Punkt3D dookola osi Y o kat fi wykorzystujac macierz obrotu Ry.
void Point3D::RotateYPoint3D(const double &fi)
{
    const double s=sin(fi),c=cos(fi);
    double x,y,z;
    x=Xp*c+Zp*s;
    y=Yp;
    z=-Yp*s+Zp*c;
    Xp=x;
    Yp=y;
    Zp=z;
}

//Obraca Punkt3D dookola osi Z o kat fi wykorzystujac macierz obrotu Rz.
void Point3D::RotateZPoint3D(const double &fi)
{
    const double s=sin(fi),c=cos(fi);
    double x,y,z;
    x=Xp*c-Yp*s;
    y=Xp*s+Yp*c;
    z=Zp;
    Xp=x;
    Yp=y;
    Zp=z;
}

//Obraca Punkt3D dookola osi wyznaczonej przez wektor [u,v,w] o kat fi wykorzystujac parametry Eulera.
void Point3D::RotateEPoint3D(const double &u, const double &v, const double &w, const double &fi)
{
    const double l=sqrt(u*u+v*v+w*w),s=sin(fi/2.0);
    const double e0=cos(fi/2.0);
    const double e1=u/l*s,e2=v/l*s,e3=w/l*s;
    double x,y,z;
    x=(e0*e0+e1*e1-0.5)*Xp+(e1*e2-e0*e3)*Yp+(e1*e3+e0*e2)*Zp;
    y=(e2*e1+e0*e3)*Xp+(e0*e0+e2*e2-0.5)*Yp+(e2*e3-e0*e1)*Zp;
    z=(e3*e1-e0*e2)*Xp+(e3*e2+e0*e1)*Yp+(e0*e0+e3*e3-0.5)*Zp;
    Xp=2.0*x;
    Yp=2.0*y;
    Zp=2.0*z;
}

//Zwraca rzut Punktu3D na plaszczyzne okreslona wzorem Ax+By+Cz+D=0.
Point3D Point3D::ProjectPoint3D(const double &A, const double &B, const double &C, const double &D)
{
    double t=-(D+A*Xp+B*Yp+C*Zp)/(A*A+B*B+C*C);
    Point3D P(Xp+t*A,Yp+t*B,Zp+t*C);
    return P;
}

//Wyswietla informacje o Punkcie3D w formacie: ID (Xp,Yp,Zp).
void Point3D::PrintPoint3D()
{
    std::cout.precision( 2 );
    std::cout.setf( std::ios::fixed );
    std::cout<<"Punkt o ID:"<<ID_Point3D<<" ("<<Xp<<","<<Yp<<","<<Zp<<")"<<std::endl;
}

//Przeciazenie operatora << nasladujace dzialanie metody Print_Point3D().
std::ostream& operator<<(std::ostream& os, const Point3D& P)
{

    std::cout.precision( 2 );
    std::cout.setf( std::ios::fixed );

    os <<P.ID_Point3D<<"\t"<<" ("<<P.Xp<<","<<P.Yp<<","<<P.Zp<<")";
    return os;
}

//Przeciazenie operatora = zrownujace dwa Punkty3D.
Point3D& Point3D::operator =(const Point3D& P)
{
    if (this != &P)
    {
        Xp=P.Xp;
        Yp=P.Yp;
        Zp=P.Zp;
    }

    return *this;
}

//Inicjalizacja licznika obiektow typu Punkt3D.
int Point3D::pointCount=0;

