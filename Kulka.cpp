#include "Kulka.h"
#include "Ramka.h"
#include <math.h>

Kulka::Kulka()
{

}

Kulka::Kulka(int x, int y)
{
	this->x = x;
	this->y = y;
	this->r = sqrt(x * x + y * y);
	this->wspolczynnikKierunkowyX = 2;
	this->wspolczynnikKierunkowyY = 5;
	xLewe = x - 10;
	xPrawe = x + 10;
	yGora = y - 10;
	YDol = y + 10;
}

double Kulka::PobierzX()
{
	return x;
}

void Kulka::UstawX(double x)
{
	this->x = x;
}

double Kulka::PobierzY()
{
	return y;
}

void Kulka::UstawY(double y)
{
	this->y = y;
}

double Kulka::PobierzWspolczynnikX()
{
	return wspolczynnikKierunkowyX;
}

void Kulka::UstawWspolczynnikX(double w)
{
	wspolczynnikKierunkowyX = w;
}

double Kulka::PobierzWspolczynnikY()
{
	return wspolczynnikKierunkowyY;
}

void Kulka::UstawWspolczynnikY(double w)
{
	wspolczynnikKierunkowyY = w;
}

System::Drawing::Point Kulka::Ruch()
{
	return System::Drawing::Point(x, y);
}

Kulka::~Kulka()
{

}


