//Cinturao

#ifndef BELT_H
#define BELT_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



#define TAM_BELT 4
#define NUM_BELT 4
#define TAM_ROCK 30 // x e y, isto é, imagem quadrada
#define DIST_ENTRE_BELT 60

struct Belt {
	int pos_x, pos_y;
	int estado_belt[16];	
	ALLEGRO_BITMAP* bitmap[3];
};

void inicializa_belt (Belt* belt, int x, int y);

void desenha_belt(Belt* belt);

void processa_belt(Belt* belt);

void finaliza_belt(Belt* belt);

#endif
