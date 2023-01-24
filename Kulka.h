#pragma once
class Kulka
{
private:
	double x, y, r, wspolczynnikKierunkowyX, wspolczynnikKierunkowyY,
		xLewe, xPrawe, yGora, YDol;
public:
	Kulka();
	Kulka(int, int);
	~Kulka();
	double PobierzX();
	void UstawX(double);
	double PobierzY();
	void UstawY(double);
	double PobierzWspolczynnikX();
	void UstawWspolczynnikX(double);
	double PobierzWspolczynnikY();
	void UstawWspolczynnikY(double);
	System::Drawing::Point Ruch();
};

