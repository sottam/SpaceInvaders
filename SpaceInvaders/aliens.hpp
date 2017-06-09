//aliens

#ifndef ALIENS_H
#define ALIENS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>




#define LINHA 5
#define COLUNA 12
#define VEL_ALIENS 100
#define DISTANCIA_X 55
#define DISTANCIA_Y 50 //70 na primeira linha
#define LARGURA_NAVE_ALIEN 40
#define ALTURA_NAVE_ALIEN  35


struct Aliens {
	float pos_x;
	float pos_y;
	int estado[LINHA][COLUNA];
	float v_x;
	int min_x, max_x, min_y, max_y;
	int atual;

	//Resultado_alien
	int i;
	int j;

	ALLEGRO_BITMAP* bitmap[6];

};

void inicializa_aliens(Aliens* aliens, int pos_x, int pos_y);

void move_aliens(Aliens* aliens);

void desenha_aliens(Aliens* aliens);

void processa_aliens(Aliens* aliens);

void finaliza_aliens(Aliens* aliens);


#endif
