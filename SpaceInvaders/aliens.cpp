//aliens

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "routinas.hpp"
#include "aliens.hpp"

void inicializa_aliens(Aliens* aliens, int pos_x_inicial, int pos_y_inicial) {
	aliens->pos_x = pos_x_inicial;
	aliens->pos_y = pos_y_inicial;

	aliens->bitmap[0] = al_load_bitmap("data/alien_0.png");
	aliens->bitmap[1] = al_load_bitmap("data/alien_1.png");
	aliens->bitmap[2] = al_load_bitmap("data/alien_2.png");
	aliens->bitmap[3] = al_load_bitmap("data/alien_3.png");
	aliens->bitmap[4] = al_load_bitmap("data/alien_4.png");
	aliens->bitmap[5] = al_load_bitmap("data/DESTRUIDO.png");

	if (aliens->bitmap[0] == NULL || aliens->bitmap[1] == NULL ||
		aliens->bitmap[2] == NULL || aliens->bitmap[3] == NULL ||
		aliens->bitmap[4] == NULL || aliens->bitmap[5] == NULL) {
		puts("Erro ao carregar o arquivo data/alien.png");
		exit(0);
	}

	for (int i = 0; i < LINHA; i++) {
		for (int j = 0; j < COLUNA; j++) {
			aliens->estado[i][j] = INTEIRO;

		}
	}

	aliens->v_x = VEL_ALIENS;
	aliens->min_x = pos_x_inicial;
	aliens->max_x = 100;
	aliens->min_y = pos_y_inicial;
	aliens->max_y = 100;

	aliens->i = 620;
	aliens->j = 620;
}

void move_aliens(Aliens* aliens) {
	//Modernizado em 09/06/17, uso de deltaTime
	if (aliens->pos_x < 0) {
		aliens->v_x = VEL_ALIENS;
		aliens->pos_y += 5;
	}
	if (aliens->pos_x > 150) {
		aliens->v_x = (VEL_ALIENS * -1);
		aliens->pos_y += 5;
	}
	
	aliens->pos_x += (aliens->v_x *_deltatime);
	
}

void desenha_aliens(Aliens* aliens) {
	int distancia_x = 0;
	int distancia_y = 0;
	int flags = 0;

	for (int i = 0; i < LINHA; i++) {
		if (i == 1)
			distancia_y += 20;
		for (int j = 0; j < COLUNA; j++) {
			if (aliens->estado[i][j] == INTEIRO) {
				al_draw_bitmap(aliens->bitmap[i],
					aliens->pos_x + distancia_x,
					aliens->pos_y + distancia_y, flags);
				distancia_x += DISTANCIA_X;
			}
			else {
				al_draw_bitmap(aliens->bitmap[5],
					aliens->pos_x + distancia_x,
					aliens->pos_y + distancia_y, flags);
				distancia_x += DISTANCIA_X;
			}
		}
		distancia_y += DISTANCIA_Y;
		distancia_x = 0;
	}
}

void processa_aliens(Aliens* aliens) {
	desenha_aliens(aliens);
}

void finaliza_aliens(Aliens* aliens) {
	al_destroy_bitmap(aliens->bitmap[0]);
	al_destroy_bitmap(aliens->bitmap[1]);
	al_destroy_bitmap(aliens->bitmap[2]);
	al_destroy_bitmap(aliens->bitmap[3]);
	al_destroy_bitmap(aliens->bitmap[4]);
	al_destroy_bitmap(aliens->bitmap[5]);
}

