#include "Suwak.h"


Suwak::Suwak()
{
}

Suwak::~Suwak()
{
}

Suwak::Suwak(double x, double y)
{
	this->x = x;
	this->y = y;
}

bool Suwak::CzyOdbiloSie(double xKulki, double yKulki)
{
	if ((xKulki <= x + 50 && xKulki >= x - 50) && (yKulki >= y && yKulki <= y + 10))
		return true;
	else return false;
}

void Suwak::Wypisz() {}
