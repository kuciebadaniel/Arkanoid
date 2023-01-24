#include "Blok.h"


Blok::Blok()
{
}

Blok::Blok(double x, double y)
{
	this->x = x;
	this->y = y;
}


Blok::~Blok()
{
}


bool Blok::CzyOdbiloSie(double xKulki, double yKulki)
{
	if ((xKulki <= x + 70 && xKulki >= x ) && (yKulki >= y && yKulki <= y + 30))
		return true;
	else return false;
}