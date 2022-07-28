#include"windows.h"
#include"Point.h"
#include<math.h>
#include<iostream>
using namespace std;
void Point::draw(HDC hdc, COLORREF c)const
{
	SetPixel(hdc, int(x), int(y), c);
}
