#ifndef	CLASS_H
#define CLASS_H

class object
{
public:
	object();
	~object();
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
private:
	int x;
	int y;
};

class field
{
public:
	field();
	~field();
	int GetW();
	int GetH();
	void SetW(int w);
	void SetH(int h);
private:
	int width, height;
};
#endif

