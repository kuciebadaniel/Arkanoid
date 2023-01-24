#include "Ramka.h"

Ramka::Ramka()
{

}

Ramka::~Ramka()
{

}

Ramka::Ramka(int lp, int pp, int g, int d)
{
	this->lewaGranicaPionowa = lp;
	this->prawaGranicaPionowa = pp;
	this->gornaGranica = g;
	this->dolnaGranica = d;
}

bool Ramka::CzyWyszloWLewo(double x)
{
	if (x <= lewaGranicaPionowa)
		return true;
	else return false;
}

bool Ramka::CzyWyszloWPrawo(double x)
{
	if (x >= prawaGranicaPionowa)
		return true;
	else return false;
}

bool Ramka::CzyWyszloWGore(double y)
{
	if (y <= gornaGranica)
		return true;
	else return false;
}

bool Ramka::CzyWyszloWDol(double y)
{
	if (y >= dolnaGranica)
		return true;
	else return false;
}