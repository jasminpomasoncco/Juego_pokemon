#pragma once
#include"Pokemon.h"

class Pikachu : public Pokemon
{
public:
	Pikachu();
	~Pikachu();
	void movimiento_invalido(int a);

private:

};

Pikachu :: Pikachu()
	: Pokemon(rand() % 500, rand() % 500, 12,
		50, 50, 0)
{
	dx = 0;
	dy = 0;
}

Pikachu ::~Pikachu()
{

}
void Pikachu::movimiento_invalido(int a) {
	

	if (a == 1) {
		dy = 0;
		dy = -dy; dx = -dx;
	}
	else { dx = 0; }
}

