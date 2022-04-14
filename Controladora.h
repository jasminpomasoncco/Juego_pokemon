#pragma once
#include"Pikachu.h"
#include"Personaje.h"
#include"Pokebola.h"
#include"Obstaculo.h"
#include<vector>

using namespace std;

class Controladora
{
public:
	Controladora(int anchof, int altof);
	~Controladora();
	bool ejecutar(Graphics^ g, Bitmap^ imgpokebola, Bitmap^ imgpokemones, Bitmap^ imgladrillo);
	void movimiento_pikachu(int direccion);
	void cambio_pikachu();
private:
	Pikachu* objpikachu;
	vector<Pokebola*>vecbola;
	vector<Obstaculo*>vecobs;
	int aux;
	int aux2;
	int num;
	int num2;
	int velo_nivel;

};

Controladora::Controladora(int anchof, int altof)
{
	velo_nivel = 1;
	num = 0;
	num2 = 0;
	aux = 0;
	aux2 = 0;
	objpikachu = new Pikachu();

	for (int i = 0; i < 10; i++) {
		vecbola.push_back(new Pokebola(anchof, altof));
	}
	for (int i = 0; i < 10; i++) {
		vecobs.push_back(new Obstaculo(anchof, altof));
	}
}

Controladora::~Controladora()
{
	while (vecbola.size())
	{
		delete vecbola.at(0);
		vecbola.erase(vecbola.begin());
	}
}

bool Controladora::ejecutar(Graphics^ g, Bitmap^ imgpokebola, Bitmap^ imgpokemones, Bitmap^ imgladrillo)
{
	aux = objpikachu->getdx();
	aux2= objpikachu->getdy();

	objpikachu->mover(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
	objpikachu->dibujar(g, imgpokemones);
	

	for (int i = 0; i < vecobs.size(); i++)
	{

		vecobs.at(i)->dibujar_bloque(g, imgladrillo);

		if (vecobs.at(i)->colision(objpikachu->getrec())) {
			objpikachu->setx(objpikachu->getx()-aux);
			objpikachu->sety(objpikachu->getx() - aux2);

		}

		if (vecobs.at(i)->colision(vecbola.at(i)->getrec())) {
			vecbola.at(i)->movimiento_invalido(0);
		}
	}

	for (int i = 0; i < vecbola.size(); i++)
	{
		vecbola.at(i)->mover
		(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		vecbola.at(i)->dibujar(g, imgpokebola);

		if (vecbola.at(i)->colision(objpikachu->getrec())) {
			velo_nivel++;
			num=num+3;
			if (num == 12) {
				num2 = 4;
				num = 0;
			}

			for (int i = 0; i < vecbola.size(); i++) {
                vecbola.at(i)->setdx(velo_nivel*5); vecbola.at(i)->setdy(velo_nivel*5);
			}
			
			objpikachu->setx(1);
			objpikachu->sety(1);
			objpikachu->setc(num2);
			objpikachu->setn(num);

		}



	}

	



if (velo_nivel == 9) return true;

	return false;

}

void Controladora::movimiento_pikachu(int direccion) {
	switch (direccion)
	{
	case 1: objpikachu->setdx(-10); break;
	case 2:  objpikachu->setdy(10); break;
	case 3: objpikachu->setdy(-10);  break;
	case 4: objpikachu->setdx(10);  break;
	case 5: objpikachu->setdx(0);  objpikachu->setdy(0);  break;


	default:
		break;
	}
}

void Controladora::cambio_pikachu() {



}