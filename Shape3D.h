#ifndef __MY_CLASS_SHAPE3D__
#define __MY_CLASS_SHAPE3D__

#include "Point3D.h"
class Shape3D:public Point3D
{
private:
    const int ID_Shape3D;
    static int shapeCount;
public:
    explicit Shape3D();
    ~Shape3D();
    virtual void AddVertex(const Point3D& P)=0;
    virtual void RemoveVertex()=0;
    virtual void Print()=0;
    virtual void Move(const double& dx, const double& dy, const double& dz)=0;
    virtual void RotateX(const double& fi)=0;
    virtual void RotateY(const double& fi)=0;
    virtual void RotateZ(const double& fi)=0;
    virtual void RotateE(const double& u, double& v, double& w, double& fi)=0;
    virtual Shape3D* Project(const double& A, const double& B, const double& C, const double& D)=0;
};




#endif // __MY_CLASS_SHAPE3D__


