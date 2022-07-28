#pragma once
#include "Point.h"
#include"CShape.h"
#include<windows.h>
#include<iostream>
using namespace std;

class CEllipse :public CShape
{
	Point T;
	double xR, yR;
public:
	CEllipse(double x, double y, double a, double b) 
		: T(x, y), xR(a), yR(b) {}
	virtual void move(double a, double b) { T.move(a, b);  }
	virtual void Scale(double s) { xR *= s; yR *= s; }
	virtual void draw(HDC hdc) const { Ellipse(hdc, T.getX()-xR, T.getY()-yR, T.getX() + xR, T.getY() + yR); }
};

