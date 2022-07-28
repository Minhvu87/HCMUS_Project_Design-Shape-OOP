#pragma once
#include"Point.h"
#include"CShape.h"
#include<iostream>
#include<windows.h>
#include<windowsx.h>
using namespace std;
class CDaGiac:public CShape 
{
	protected:
		Point* DG = NULL;
		int size;
		int maxSize;
	public:
		CDaGiac(int n=0):size(0),maxSize(n){
			DG = new Point[maxSize];
		}
		virtual void move(double a, double b) {
			for (int i = 0; i < size; i++)
			{
				DG[i].move(a, b);
			}
		}
		virtual void draw(HDC hdc)const;
		virtual void Scale(double s);
		void addPoint(Point T);
};
