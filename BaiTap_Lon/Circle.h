#pragma once
#include"Ellipse.h"
class CCircle : public CEllipse
{
public:
	CCircle(double xT = 300, double yT = 400, double r = 150) :
		CEllipse(xT, yT, r, r) {}
};