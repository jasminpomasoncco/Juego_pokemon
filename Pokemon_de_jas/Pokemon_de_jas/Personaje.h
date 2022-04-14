#pragma once
#include<iostream>
using namespace System;
using namespace System::Drawing;
class Personaje
{
public:
	Personaje(int x, int y,
		int limimg, int ancho, int alto, int velo);
	~Personaje();
	void dibujar(Graphics^g, Bitmap^img);
	virtual void mover(int anchof, int altof);
	bool colision(Rectangle rec);
	Rectangle getrec();
	virtual void movimiento_invalido(int a){}
	void setdx(int dx);
	void setdy(int dy);

protected:
	int x, y, dx, dy, iteradorimg;
	int ancho, alto;
	int limimg, direccion;
	int aceleracion, velocidad;
};

Personaje::Personaje(int x, int y, 
	int limimg, int ancho, int alto, int velocidad)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->limimg = limimg;
	dx = 0; dy = 0;
	iteradorimg = 0; direccion = 0;
	aceleracion = 0; 
	this->velocidad = velocidad;
}

Personaje::~Personaje()
{
}
void Personaje::mover(int anchof, int altof) {
//	if (velocidad <= aceleracion) {
		//aceleracion = 0;
		if (x + dx<0 || x + dx + ancho>anchof)
		{
			movimiento_invalido(0);
		

		}
		if (y + dy < 0 || y + dy+alto>altof)
		{
			movimiento_invalido(1);
			
		}
		x += dx; y += dy;

	//}
	//else { aceleracion++; }
}
void Personaje::dibujar(Graphics^g, Bitmap^img) {
	direccion = (direccion + 1) % 3;
	if (dy > 0) {	direccion+5;}
	else {
		if (dx < 0) { direccion+5; }
		else {
			if (dx > 0) { direccion+5; }
			else {
				if (dy < 0) { direccion+5; }
				else { iteradorimg = 1; }
			}
		}
	}

Rectangle seccionshow =Rectangle(img->Width / limimg * iteradorimg,
		img->Height / 4 * direccion, img->Width / limimg,
		img->Height / 4);
Rectangle zoom = Rectangle(x, y, ancho, alto);

g->DrawImage(img, zoom, seccionshow, GraphicsUnit::Pixel);

	iteradorimg = (iteradorimg + 1) % limimg;
	
}

bool Personaje::colision(Rectangle rec) {
	return getrec().IntersectsWith(rec);

}

Rectangle Personaje::getrec()
{
	return Rectangle(x, y, ancho, alto);
}

void Personaje::setdx(int dx) {
	this->dx = dx;
}

void Personaje::setdy(int dy) {

	this->dy = dy;
}
