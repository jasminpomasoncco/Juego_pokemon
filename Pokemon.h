#pragma once
#include<iostream>
using namespace System;
using namespace System::Drawing;
class Pokemon
{
public:
	Pokemon(int x, int y,
		int limimg, int ancho, int alto, int velo);
	~Pokemon();
	void dibujar(Graphics^ g, Bitmap^ img);
	virtual void mover(int anchof, int altof);
	void cambio_pokemon(int a, int b);
	bool colision(Rectangle rec);
	Rectangle getrec();
	virtual void movimiento_invalido(int a) {}
	int getdx();
	int getdy();
	int getx();
	int gety();
	void setx(int x);
	void sety(int y);

	void setdx(int dx);
	void setdy(int dy);
	void setn(int n);
	void setc(int c);

protected:
	int x, y, dx, dy, iteradorimg;
	int ancho, alto;
	int limimg, direccion;
	int aceleracion, velocidad;
	int n;
	int c;
};

Pokemon::Pokemon(int x, int y,
	int limimg, int ancho, int alto, int velocidad)
{
	n = 0;
	c = 0;
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->limimg = limimg;
	this->dx = dx;
	this->dy = dy;
	iteradorimg = 0;
	direccion = 0;
	aceleracion = 0;
	this->velocidad = velocidad;
}

Pokemon::~Pokemon()
{
}

void Pokemon::mover(int anchof, int altof) {


	if (x + dx<0 || x + dx + ancho>anchof)
	{
		movimiento_invalido(0);

	}
	if (y + dy < 0 || y + dy + alto>altof)
	{
		movimiento_invalido(1);

	}
	x += dx; y += dy;

}
void Pokemon::dibujar(Graphics^ g, Bitmap^ img) {
	//direccion = (direccion + 1) % 3;
	if (dy > 0) { direccion =0+c; }
	else {
		if (dx < 0) { direccion =1+c; }
		else {
			if (dx > 0) { direccion =2+c; }
			else {
				if (dy < 0) { direccion=3+c; }
				else { iteradorimg = 1; }
			}
		}
	}
	//w=a, h=Al
	Rectangle seccionshow = Rectangle(img->Width / limimg * (iteradorimg+n),
		img->Height / 8 * direccion, img->Width / limimg,
		img->Height / 8);
	Rectangle zoom = Rectangle(x, y, ancho, alto);

	g->DrawImage(img, zoom, seccionshow, GraphicsUnit::Pixel);
	
	iteradorimg = (iteradorimg + 1) % 3;

}

void Pokemon::cambio_pokemon(int a, int b) {
    

}

bool Pokemon::colision(Rectangle rec) {
	return getrec().IntersectsWith(rec);

}

Rectangle Pokemon::getrec()
{
	return Rectangle(x, y, ancho, alto);
}

int Pokemon::getdx() {
	return dx;
}
int Pokemon::getdy() {
	return dy;
}

int Pokemon::getx() {
	return x;
}
int Pokemon::gety() {
	return y;
}


void Pokemon::setx(int x) {
	this->x = x;
}

void Pokemon::sety(int y) {

	this->y = y;
}

void Pokemon::setdx(int dx) {
	this->dx = dx;
}

void Pokemon::setdy(int dy) {

	this->dy = dy;
}

void Pokemon::setn(int n) {
	this->n = n;
}

void Pokemon::setc(int c) {

	this->c = c;
}