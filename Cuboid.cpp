#include <iostream>
#include "Point3D.h"
#include "Shape3D.h"
#include "Cuboid.h"

//Konstruktor domyslny Cuboid.
Cuboid::Cuboid():ID_Cuboid(CuboidCount)
{
    maxVertexNumber=3;
    vertexNumber=0;
    vertex=new Point3D*[maxVertexNumber];
    ++CuboidCount;
    std::cout<<"Konstruktor domyslny Cuboid o ID: "<<ID_Cuboid<<std::endl;
}

//Destruktor Cuboid.
Cuboid::~Cuboid()
{
    delete[] vertex;
    --CuboidCount;
    std::cout<<"Destruktor Cuboid o ID: "<<ID_Cuboid<<std::endl;
}

//Metoda dodajaca Punkty3D do Cuboid.
void Cuboid::AddVertex(const Point3D& P)
{
    if(vertexNumber<maxVertexNumber)
    {
        vertex[vertexNumber]=new Point3D(P);
        ++vertexNumber;
    }
    else
    {
        std::cout<<"Wszystkie punkty Cuboid o ID: "<<ID_Cuboid<<" zostaly zdefiniowane"<<std::endl;
    }
}

//Metoda usuwajaca Punkty3D z Cuboid.
void Cuboid::RemoveVertex()
{
    if(vertexNumber>0)
    {
        vertex[vertexNumber]=NULL;
        --vertexNumber;
    }
    else
    {
        std::cout<<"Cuboid o ID: "<<ID_Cuboid<<" nie posiada juz wiecej punktow"<<std::endl;
    }
}

//Wyswietla informacje o Cuboid.
void Cuboid::Print()
{
    std::cout<<"Cuboid o ID: "<<ID_Cuboid<<std::endl;
    std::cout<<"i\tID\tPosition"<<std::endl;
    for ( int i=0; i<vertexNumber; ++i)
    {
        std::cout<<i<<"\t"<<*vertex[i]<<std::endl;
    }
}

//Przesuwa po kolei wszyskie punkty Cuboid o wektor [dx,dy,dz].
void Cuboid::Move(const double& dx, const double& dy, const double& dz)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->MovePoint3D(dx,dy,dz);
}

//Obraca po kolei wszystkie punkty Cuboid dooko³a osi X o k¹t fi.
void Cuboid::RotateX(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateXPoint3D(fi);
}

//Obraca po kolei wszystkie punkty Cuboid dooko³a osi Y o k¹t fi.
void Cuboid::RotateY(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateYPoint3D(fi);
}

//Obraca po kolei wszystkie punkty Cuboid dooko³a osi Z o k¹t fi.
void Cuboid::RotateZ(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateZPoint3D(fi);
}

//Obraca po kolei wszystkie punkty Cuboid dooko³a wektora [u,v,w] o k¹t fi.
void Cuboid::RotateE(const double& u, double& v, double& w, double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateEPoint3D(u,v,w,fi);
};

//Rzutuje po kolei wszystkie punkty Cuboid na plaszczyzne Ax+Bx+Cz+D=0.
Shape3D* Cuboid::Project(const double& A, const double& B, const double& C, const double& D)
{
    Shape3D* out=new Cuboid();

    for ( int i=0; i<vertexNumber; ++i)out->AddVertex(vertex[i]->ProjectPoint3D(A,B,C,D));
    return out;
}

Cuboid& Cuboid::operator =(Cuboid S)
{
    swap(*this, S);
    return *this;
}

void swap(Cuboid& first, Cuboid& second)
{
    std::swap(first.vertexNumber, second.vertexNumber);
    std::swap(first.vertex, second.vertex);
    std::swap(first.maxVertexNumber, second.maxVertexNumber);
}

//Inicjalizacja licznika obiektow Cuboid.
int Cuboid::CuboidCount=0;
