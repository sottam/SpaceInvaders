//cinturao

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "belt.hpp"
#include "routinas.hpp"


void inicializa_belt (Belt* belt, int x, int y) {
	belt->pos_x = x;
	belt->pos_y = y;
	belt->bitmap[0] = al_load_bitmap("data/belt_0.png");
   belt->bitmap[1] = al_load_bitmap("data/belt_1.png");
	belt->bitmap[2] = al_load_bitmap("data/belt_2.png");


	if( belt->bitmap[0] == NULL || belt->bitmap[1] == NULL || belt->bitmap[2] == NULL ) {
		puts( "Erro ao carregar o arquivo data/belt.png");
		exit(0);
	}

	for (int i = 0; i < NUM_BELT*TAM_BELT; i++ ) {
		belt->estado_belt[i] = INTEIRO;
	}
}

void desenha_belt(Belt* belt) {
	int flags = 0;
	int distancia_x = 0;
	int distancia_y = 0;
	int estado = 0;
	int cont_estado = 0;

	for( int i = 1; i <= NUM_BELT; i++) {
		for(int j = 1; j <= TAM_BELT; j++) {
				if (distancia_y == 0) {
					estado = (belt->estado_belt[cont_estado]);
					//printf("%d\n",estado);
					al_draw_bitmap( belt->bitmap[estado],
		  				 		 		 belt->pos_x + distancia_x,
		  				 		 		 belt->pos_y, flags);
					distancia_y = 10;
					distancia_x += TAM_ROCK;
					cont_estado++;
				}
				else {
					estado = (belt->estado_belt[cont_estado]);
					//printf("%d\n",estado);
					al_draw_bitmap( belt->bitmap[estado],
		  				 		 		 belt->pos_x + distancia_x,
		  				 		 		 belt->pos_y + distancia_y, flags);
					distancia_y = 0;
					distancia_x += TAM_ROCK;
					cont_estado++;
					//printf("%d\n",cont_estado);


				}
		}


		distancia_x += 60;
	}
}

void processa_belt(Belt* belt) {
	desenha_belt(belt);
}

void finaliza_belt(Belt* belt) {
	al_destroy_bitmap(belt->bitmap[0]);
	al_destroy_bitmap(belt->bitmap[1]);
	al_destroy_bitmap(belt->bitmap[2]);
}






