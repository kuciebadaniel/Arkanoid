#pragma once
class Ramka
{
private: 
	int lewaGranicaPionowa, prawaGranicaPionowa, gornaGranica, dolnaGranica;
public:
	Ramka();
	Ramka(int, int, int, int);
	~Ramka();
	bool CzyWyszloWLewo(double);
	bool CzyWyszloWPrawo(double);
	bool CzyWyszloWGore(double);
	bool CzyWyszloWDol(double);
};

