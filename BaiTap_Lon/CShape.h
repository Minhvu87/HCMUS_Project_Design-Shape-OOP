#pragma once
#include<windows.h>
#include<stdio.h>
#include"Point.h"
#include<iostream>
using namespace std;
extern const double pi;
class CShape
{
public:
	virtual void draw(HDC hdc) const = NULL;
	virtual void move(double a, double b) = NULL;
	virtual void Scale(double s) = NULL;
};