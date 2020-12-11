#include "testClass.h"

bool operator>(const testClass& c1, const testClass& c2)
{
	if (c1.x + c1.y> c2.x + c2.y) return true;
	else return false;
}

testClass::testClass(int x, int y)
{
	this->x = x;
	this->y = y;
}

testClass::testClass()
{


}
