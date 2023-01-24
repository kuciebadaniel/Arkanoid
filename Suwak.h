#include "Pasek.h"
#pragma once


public ref class  Suwak :public Pasek
{
public:
	Suwak();
	Suwak(double, double);
	~Suwak();
	bool CzyOdbiloSie(double, double) override;
	void Wypisz();
};

