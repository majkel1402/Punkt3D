#include <iostream>
#include "Point3D.h"
#include "Shape3D.h"
#include "Cuboid.h"

int Cuboid::CuboidCount=0;

Cuboid::Cuboid():ID_Cuboid(CuboidCount)
{
    maxVertexNumber=3;
    vertexNumber=0;
    vertex=new Point3D*[maxVertexNumber];
    ++CuboidCount;
    std::cout<<"Konstruktor domyslny Cuboid o ID: "<<ID_Cuboid<<std::endl;
}

Cuboid::~Cuboid()
{
    delete[] vertex;
    --CuboidCount;
    std::cout<<"Destruktor Cuboid o ID: "<<ID_Cuboid<<std::endl;
}

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

void Cuboid::Print()
{
    std::cout<<"Cuboid o ID: "<<ID_Cuboid<<std::endl;
    std::cout<<"i\tID\tPosition"<<std::endl;
    for ( int i=0; i<vertexNumber; ++i)
    {
        std::cout<<i<<"\t"<<*vertex[i]<<std::endl;
    }
}

void Cuboid::Move(const double& dx, const double& dy, const double& dz)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->Move_Point3D(dx,dy,dz);
}

void Cuboid::RotateX(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateX_Point3D(fi);
}

void Cuboid::RotateY(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateY_Point3D(fi);
}

void Cuboid::RotateZ(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateZ_Point3D(fi);
}

void Cuboid::RotateE(const double& u, double& v, double& w, double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateE_Point3D(u,v,w,fi);
};

Shape3D* Cuboid::Project(const double& A, const double& B, const double& C, const double& D)
{
    Shape3D* out=new Cuboid();

    for ( int i=0; i<vertexNumber; ++i)
    {
        out->AddVertex(vertex[i]->Project_Point3D(A,B,C,D));
    }
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
