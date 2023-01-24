#pragma once
#include "Pasek.h"
public ref class Blok :public Pasek
{
public:
	Blok();
	Blok(double, double);
	~Blok();
	bool CzyOdbiloSie(double, double) override;
};

