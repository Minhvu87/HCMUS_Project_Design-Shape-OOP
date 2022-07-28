#include"DaGiac.h"
#include"CShape.h"
using namespace std;
void CDaGiac::Scale(double s){
	for (int i = 0; i < size;i++){
		DG[i].set((DG[i].getX()) * s, (DG[i].getY()) * s);
	}
}
void CDaGiac::draw(HDC hdc)const{
	POINT* apt = new POINT[size+1];
	for (int i = 0; i < size; i++) {
		apt[i].x = DG[i].getX();
		apt[i].y = DG[i].getY();
	}
	Polygon(hdc, apt, size);
	//*/
}
void CDaGiac::addPoint(Point T) {
	DG[size] = T;
	size++;
}
