#include <iostream>
#include "Point3D.h"
#include "Shape3D.h"
#include "PointCloud.h"

//Konstruktor domyslny PointCloud.
PointCloud::PointCloud():ID_PointCloud(PointCloudCount)
{
    maxVertexNumber=50;
    vertexNumber=0;
    vertex=new Point3D*[maxVertexNumber];
    ++PointCloudCount;
    std::cout<<"Konstruktor domyslny PointCloud o ID: "<<ID_PointCloud<<std::endl;
}

//Destruktor PointCloud.
PointCloud::~PointCloud()
{
    delete[] vertex;
    --PointCloudCount;
    std::cout<<"Destruktor PointCloud o ID: "<<ID_PointCloud<<std::endl;
}

//Metoda dodajaca Punkty3D do PointCloud.
void PointCloud::AddVertex(const Point3D& P)
{
    if(vertexNumber<maxVertexNumber)
    {
        vertex[vertexNumber]=new Point3D(P);
        ++vertexNumber;
    }
    else
    {
        std::cout<<"Osiagnieto max liczbe punktow w PointCloud o ID: "<<ID_PointCloud<<std::endl;
    }
}

//Metoda usuwajaca Punkty3D z PointCloud.
void PointCloud::RemoveVertex()
{

    if(vertexNumber>0)
    {
        vertex[vertexNumber]=NULL;
        --vertexNumber;
    }
    else
    {
        std::cout<<"PointCloud o ID: "<<ID_PointCloud<<" nie posiada juz wiecej punktow"<<std::endl;
    }

}

//Wyswietla informacje o PointCloud.
void PointCloud::Print()
{
    std::cout<<"PointCloud o ID: "<<ID_PointCloud<<std::endl;
    std::cout<<"i\tID\tPosition"<<std::endl;
    for ( int i=0; i<vertexNumber; ++i)
    {
        std::cout<<i<<"\t"<<*vertex[i]<<std::endl;
    }
}

//Przesuwa po kolei wszyskie punkty PointCloud o wektor [dx,dy,dz].
void PointCloud::Move(const double& dx, const double& dy, const double& dz)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->MovePoint3D(dx,dy,dz);
}

//Obraca po kolei wszystkie punkty PointCloud dooko³a osi X o k¹t fi.
void PointCloud::RotateX(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateXPoint3D(fi);
}

//Obraca po kolei wszystkie punkty PointCloud dooko³a osi Y o k¹t fi.
void PointCloud::RotateY(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateYPoint3D(fi);
}

//Obraca po kolei wszystkie punkty PointCloud dooko³a osi Z o k¹t fi.
void PointCloud::RotateZ(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateZPoint3D(fi);
}

//Obraca po kolei wszystkie punkty PointCloud dooko³a wektora [u,v,w] o k¹t fi.
void PointCloud::RotateE(const double& u, double& v, double& w, double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)vertex[i]->RotateEPoint3D(u,v,w,fi);
}

//Rzutuje po kolei wszystkie punkty PointCloud na plaszczyzne Ax+Bx+Cz+D=0.
Shape3D* PointCloud::Project(const double& A, const double& B, const double& C, const double& D)
{
    Shape3D* out=new PointCloud();

    for ( int i=0; i<vertexNumber; ++i)out->AddVertex(vertex[i]->ProjectPoint3D(A,B,C,D));
    return out;
}

PointCloud& PointCloud::operator =(PointCloud S)
{
    swap(*this, S);
    return *this;
}

void swap(PointCloud& first, PointCloud& second)
{
    std::swap(first.vertexNumber, second.vertexNumber);
    std::swap(first.vertex, second.vertex);
    std::swap(first.maxVertexNumber, second.maxVertexNumber);
}

//Inicjalizacja licznika obiektow PointCloud.
int PointCloud::PointCloudCount=0;
