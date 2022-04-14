#pragma once
#include<iostream>
#include"Personaje.h"
using namespace::Drawing;

class Pokebola : public Personaje
{
public:

	Pokebola(int anchof, int altof);
	~Pokebola();
	virtual void movimiento_invalido(int a);
private:

};

Pokebola::Pokebola(int anchof, int altof)
	:Personaje(rand()%(anchof-80), rand() % (altof - 80),
		1, rand()%20+50, rand()%20+50, 0.5)
{
	do {
		dx = rand() % 10;
		dy = rand() % 10;
	} while (dx == 0 && dy == 0);
}

Pokebola::~Pokebola() {

}

void Pokebola::movimiento_invalido(int a) {
	if (a == 1) {
		dy = -dy;
	}
	else { dx = -dx; }
}
