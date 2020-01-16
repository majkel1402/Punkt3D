#ifndef __MY_CLASS_POINT3D__
#define __MY_CLASS_POINT3D__

#include <vector>
#include <ostream>



class Point3D
{
private:
    double Xp,Yp,Zp;
    const int ID_Point3D;
    static int pointCount;
public:
    explicit Point3D();
    explicit Point3D(const double &x,const double &y,const double &z);
    Point3D(const Point3D& P);
    ~Point3D();
    double GetX();
    double GetY();
    double GetZ();
    void SetX(double& x);
    void SetY(double& y);
    void SetZ(double& z);
    void Move_Point3D(const double &dx, const double &dy, const double &dz);
    void RotateX_Point3D(const double &fi);
    void RotateY_Point3D(const double &fi);
    void RotateZ_Point3D(const double &fi);
    void RotateE_Point3D(const double &u, const double &v, const double &w, const double &fi);
    Point3D Project_Point3D(const double &A, const double &B, const double &C, const double &D);
    void Print_Point3D();
    friend std::ostream& operator << (std::ostream& os, const Point3D& P);
    Point3D& operator =(const Point3D& P);

};


#endif // __MY_CLASS_POINT3D__

