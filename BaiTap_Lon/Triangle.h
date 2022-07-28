#pragma once
#include<iostream>
#include<windows.h>
#include"Point.h"
#include"CShape.h"
#include<math.h>
using namespace std;
class CTriangle:public CShape
{
private:
	Point A, B, C;
public:
	CTriangle(double xA, double yA, double xB,
		double yB, double xC, double yC) : A(xA, yA), B(xB, yB), C(xC, yC){}
	virtual void draw(HDC hdc) const {
		POINT apt[] = { A.getX(),A.getY(),B.getX(),B.getY(),C.getX(),C.getY() };
		Polygon(hdc, apt, 3);
	}
	virtual void move(double a, double b) {
		A.move(a, b);
		B.move(a, b);
		C.move(a, b);
	}
	virtual void Scale(double s) 
	{
		A.set(A.getX() * s, A.getY() * s);
		B.set(B.getX() * s, B.getY() * s);
		C.set(C.getX() * s, C.getY() * s);
	}
	
};