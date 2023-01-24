#pragma once


public ref class Pasek abstract
{
protected:
	double x, y;
public:
	double PobierzX();
	void UstawX(double);
	double PobierzY();
	void UstawY(double);
	// metoda czysto virtualna - to ma byæ zdefiniowane w kalsach-dzeciach.
	virtual bool CzyOdbiloSie(double, double) = 0;
	virtual ~Pasek();
};

