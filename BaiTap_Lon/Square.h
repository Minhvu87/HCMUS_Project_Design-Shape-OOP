#pragma once
#include"Point.h"
#include"CShape.h"
#include"Rectangle.h"
class CSquare :public CRectangle
{
public:
	CSquare(double x, double y, double c) :CRectangle(x, y, c, c) {};
};