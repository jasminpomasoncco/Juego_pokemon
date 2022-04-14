#pragma once
#include<iostream>
#include"Personaje.h"
using namespace::Drawing;

class Bala : public Personaje
{
public:

	Bala(int anchof, int altof);
	~Bala();
	virtual void movimiento_invalido(int a);

	void dibujar_bloque(Graphics^ g, Bitmap^ img);

private:

};

Bala::Bala(int anchof, int altof)
	:Personaje(rand() % (anchof - 80), rand() % (altof - 80),
		1, 30, 30, 0)
{
	dx = 0; dy = 0;
}

Bala::~Bala() {

}

void Bala::movimiento_invalido(int a) {
	/*if (a == 1) {
		dy = -dy;
	}
	else { dx = -dx; }*/
}
void Bala::dibujar_bloque(Graphics^ g, Bitmap^ img)
{

	Rectangle seccionshow = Rectangle(0, 0, img->Width,
		img->Height);
	Rectangle zoom = Rectangle(x, y, ancho, alto);

	g->DrawImage(img, zoom, seccionshow, GraphicsUnit::Pixel);
}