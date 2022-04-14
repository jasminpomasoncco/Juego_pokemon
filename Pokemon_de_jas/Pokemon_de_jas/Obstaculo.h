#pragma once
#include<iostream>
#include"Personaje.h"
using namespace::Drawing;

class Obstaculo : public Personaje
{
public:

	Obstaculo(int anchof, int altof);
	~Obstaculo();
	virtual void movimiento_invalido(int a);
	void dibujar_bloque(Graphics^ g, Bitmap^ img);
	
private:

};

Obstaculo::Obstaculo(int anchof, int altof)
	:Personaje(rand() % (anchof - 80), rand() % (altof - 80),
		1, rand() % 20 + 50, rand() % 20 + 50, 0)
{
	dx = 0; dy = 0;
}

Obstaculo::~Obstaculo() {

}

void Obstaculo::movimiento_invalido(int a) {
	/*if (a == 1) {
		dy = -dy;
	}
	else { dx = -dx; }*/
}
void Obstaculo::dibujar_bloque(Graphics^ g, Bitmap^ img)
{

	Rectangle seccionshow = Rectangle(0,0, img->Width ,
		img->Height );
	Rectangle zoom = Rectangle(x, y, ancho, alto);

	g->DrawImage(img, zoom, seccionshow, GraphicsUnit::Pixel);
}


