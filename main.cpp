#include <iostream>
#define M_PI 3.14159265358979323846

#include "Point3D.h"
#include "Shape3D.h"
#include "PointCloud.h"
#include "Cuboid.h"

using namespace std;

int main()
{
    cout<<"\n"<<"--------Point3D--------"<<endl;
    Point3D A(1,0,0);
    Point3D B=A;
    Point3D C;
    C=B;
    cout<<"\n"<<"-----------------------"<<endl;

    cout<<"\n"<<"--------Point3D-Funkcje--------"<<endl;
    cout<<"\n"<<"Point3D.Print()"<<endl;
    A.Print_Point3D();
    B.Print_Point3D();
    C.Print_Point3D();
    cout<<"\n"<<"Point3D.Move()"<<endl;
    B.Print_Point3D();
    B.Move_Point3D(1,0,1);
    B.Print_Point3D();
    cout<<"\n"<<"Point3D.Rotate()"<<endl;
    C.Print_Point3D();
    C.RotateZ_Point3D(M_PI/2);
    C.Print_Point3D();
    cout<<"\n"<<"Point3D.Project()"<<endl;
    A.Print_Point3D();
    Point3D D(A.Project_Point3D(0,0,1,-4));
    D.Print_Point3D();
    cout<<"\n"<<"-----------------------"<<endl;

    cout<<"\n"<<"--------Shape3D--------"<<endl;
    cout<<"\n"<<"Shape3D*"<<endl;
    Shape3D* tab[4];
    tab[0]=new PointCloud();
    tab[1]=new PointCloud();
    tab[2]=new Cuboid();
    tab[3]=new Cuboid();
    cout<<"\n"<<"-----------------------"<<endl;

    cout<<"\n"<<"--------Shape3D-Funkcje-PointCloud------"<<endl;
    cout<<"\n"<<"PointCloud*->Print()"<<endl;
    tab[0]->Print();
    cout<<"\n"<<"PointCloud*->AddVertex()"<<endl;
    tab[0]->AddVertex(A);
    cout<<"\n"<<"PointCloud*->AddVertex()"<<endl;
    tab[0]->AddVertex(B);
    cout<<"\n"<<"PointCloud*->Print()"<<endl;
    tab[0]->Print();
    cout<<"\n"<<"PointCloud*->Project()"<<endl;
    tab[1]=tab[0]->Project(10,10,10,10);
    cout<<"\n"<<"PointCloud*->Print()"<<endl;
    tab[1]->Print();
    cout<<"\n"<<"PointCloud*->RemoveVertex()"<<endl;
    tab[0]->RemoveVertex();
    cout<<"\n"<<"PointCloud*->RemoveVertex()"<<endl;
    tab[0]->RemoveVertex();
    cout<<"\n"<<"PointCloud*->RemoveVertex()"<<endl;
    tab[0]->RemoveVertex();
    cout<<"\n"<<"PointCloud*->Print()"<<endl;
    tab[0]->Print();
    cout<<"\n"<<"-----------------------"<<endl;

    cout<<"\n"<<"--------Shape3D-Funkcje-Cuboid------"<<endl;
    cout<<"\n"<<"Cuboid*->Print()"<<endl;
    tab[2]->Print();
    cout<<"\n"<<"Cuboid*->AddVertex()"<<endl;
    tab[2]->AddVertex(A);
    cout<<"\n"<<"Cuboid*->AddVertex()"<<endl;
    tab[2]->AddVertex(B);
    cout<<"\n"<<"Cuboid*->AddVertex()"<<endl;
    tab[2]->AddVertex(C);
    cout<<"\n"<<"Cuboid*->AddVertex()"<<endl;
    tab[2]->AddVertex(D);
    cout<<"\n"<<"Cuboid*->Print()"<<endl;
    tab[2]->Print();
    cout<<"\n"<<"Cuboid*->Project()"<<endl;
    tab[3]=tab[2]->Project(10,10,10,10);
    cout<<"\n"<<"Cuboid*->Print()"<<endl;
    tab[3]->Print();
    cout<<"\n"<<"-----------------------"<<endl;
    return 0;
}
