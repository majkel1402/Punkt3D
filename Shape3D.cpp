#include "Shape3D.h"
#include <iostream>

Shape3D::Shape3D():ID_Shape3D(shapeCount)
{

    std::cout<<"Konstruktor domyslny Shape3D ID:"<<ID_Shape3D<<std::endl;
    ++shapeCount;
}

Shape3D::~Shape3D()
{
    std::cout<<"Destruktor Shape3D ID:"<<ID_Shape3D<<std::endl;
    --shapeCount;
}

int Shape3D::shapeCount=0;


