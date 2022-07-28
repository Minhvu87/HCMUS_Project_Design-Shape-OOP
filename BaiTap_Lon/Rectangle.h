#pragma once
#include"Point.h"
#include"DaGiac.h"
#include"CShape.h"
#include<iostream>
#include<windows.h>
using namespace std;
class CRectangle :public CShape
{
	Point UL;
	double dai, rong;
public:
	CRectangle(double x,double y,double d,double r):UL(x,y),dai(d),rong(r){}
	virtual void draw(HDC hdc) const { Rectangle(hdc,UL.getX(), UL.getY(),
			UL.getX()+dai, UL.getY()+rong);}
	virtual void move(double a, double b) { UL.move(a, b); }
	virtual void Scale(double s) { rong *= s; dai *= s; 
	UL.move(rong * (1 - s) / 2, dai * (1 - s) / 2); }
	
};