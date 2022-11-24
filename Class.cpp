#include "Class.h"

object::object()
{
	this->x = 0;
	this->y = 0;
}

object::~object()
{

}

int object::GetX()
{
	return x;
}
int object::GetY()
{
	return y;
}
void object::SetX(int x)
{
	this->x = x;
}
void object::SetY(int y)
{
	this->y = y;
}

field::field()
{
	this->width = 0;
	this->height = 0;
}

field::~field()
{
	
}

int field::GetW()
{
	return width;
}
int field::GetH()
{
	return height;
}
void field::SetW(int w)
{
	this->width = w;
}
void field::SetH(int h)
{
	this->height = h;
}