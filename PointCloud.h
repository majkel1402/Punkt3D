
#include <iostream>
#include "Point3D.h"
#include "Shape3D.h"

class PointCloud:public Shape3D
{
private:

    Point3D** vertex;
    int maxVertexNumber;
    int vertexNumber;
    const int ID_PointCloud;
    static int PointCloudCount;

public:
    explicit PointCloud();
    ~PointCloud();
    void AddVertex(const Point3D& P);
    void RemoveVertex();
    void Print();
    void Move(const double& dx, const double& dy, const double& dz);
    void RotateX(const double& fi);
    void RotateY(const double& fi);
    void RotateZ(const double& fi);
    void RotateE(const double& u, double& v, double& w, double& fi);
    Shape3D* Project(const double& A, const double& B, const double& C, const double& D);
    PointCloud& operator =(PointCloud S);
    friend void swap(PointCloud& first, PointCloud& second);
};


