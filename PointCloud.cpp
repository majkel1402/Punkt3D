#include <iostream>
#include "Point3D.h"
#include "Shape3D.h"
#include "PointCloud.h"

int PointCloud::PointCloudCount=0;

PointCloud::PointCloud():ID_PointCloud(PointCloudCount)
{
    maxVertexNumber=50;
    vertexNumber=0;
    vertex=new Point3D*[maxVertexNumber];
    ++PointCloudCount;
    std::cout<<"Konstruktor domyslny PointCloud o ID: "<<ID_PointCloud<<std::endl;
}

PointCloud::~PointCloud()
{
    delete[] vertex;
    --PointCloudCount;
    std::cout<<"Destruktor PointCloud o ID: "<<ID_PointCloud<<std::endl;
}

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

void PointCloud::Print()
{
    std::cout<<"PointCloud o ID: "<<ID_PointCloud<<std::endl;
    std::cout<<"i\tID\tPosition"<<std::endl;
    for ( int i=0; i<vertexNumber; ++i)
    {
        std::cout<<i<<"\t"<<*vertex[i]<<std::endl;
    }
}

void PointCloud::Move(const double& dx, const double& dy, const double& dz)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->Move_Point3D(dx,dy,dz);
}

void PointCloud::RotateX(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateX_Point3D(fi);
}

void PointCloud::RotateY(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateY_Point3D(fi);
}

void PointCloud::RotateZ(const double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateZ_Point3D(fi);
}

void PointCloud::RotateE(const double& u, double& v, double& w, double& fi)
{
    for ( int i=0; i<vertexNumber; ++i)
        vertex[i]->RotateE_Point3D(u,v,w,fi);
}

Shape3D* PointCloud::Project(const double& A, const double& B, const double& C, const double& D)
{
    Shape3D* out=new PointCloud();

    for ( int i=0; i<vertexNumber; ++i)
    {
        out->AddVertex(vertex[i]->Project_Point3D(A,B,C,D));
    }
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
