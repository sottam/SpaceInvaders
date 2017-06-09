//nave

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "nave.hpp"
#include "routinas.hpp"


void inicializa_nave(Nave* nave, int x, int y, int lim_inf, int lim_sup) {
	nave->pos_x = x;
	nave->pos_y = y;
	nave->pos_x_original = x;
	nave->pos_y_original = y;

	nave->min_x = nave->pos_x + DELTA_X;
	nave->max_x = nave->pos_x - DELTA_X;
	nave->min_y = nave->pos_x + DELTA_Y;
	nave->min_y = nave->pos_y;
	nave->atual = 0;
	nave->v_x = 0;
	nave->direcao = PARAR;

	nave->lim_inf = lim_inf;
	nave->lim_sup = lim_sup;

	nave->estado_nave = INTEIRO;

	_vidas = 3;

	nave->bitmap[0] = al_load_bitmap("data/nave_0.png");
	nave->bitmap[1] = al_load_bitmap("data/DESTRUIDO.png");
	nave->bitmap[2] = al_load_bitmap("data/nave_1.png");

	if (nave->bitmap[0] == NULL || nave->bitmap[1] == NULL || nave->bitmap[2] == NULL) {
		puts("Erro ao carregar o arquivo data/nave.png");
		exit(0);
	}
}

void reset_nave(Nave* nave) {
	nave->pos_x = nave->pos_x_original;
	nave->pos_y = nave->pos_y_original;
}

void desenha_nave(Nave* nave) {
	int flags = 0;
	if (_vidas >= 0) {
		al_draw_bitmap(nave->bitmap[0],
			nave->pos_x + DELTA_X,
			nave->pos_y + DELTA_Y, flags);
	}
	else {
		al_draw_bitmap(nave->bitmap[1], //DESTRUIDA
			nave->pos_x + DELTA_X,
			nave->pos_y + DELTA_Y, flags);
	}

}

void move_nave(Nave* nave, int direcao) {
	//Modernizado em 09/06/17, uso de deltaTime
	if (direcao == ESQUERDA) {
		if (nave->v_x > 0)
			nave->v_x = 0;
		else
			nave->v_x += direcao * 200; //MULTIPLICADOR DA ACELERACAO
	}
	if (direcao == DIREITA) {
		if (nave->v_x < 0)
			nave->v_x = 0;
		else
			nave->v_x += direcao * 200; //MULTIPLICADOR DA ACELERACAO
	}
	if (direcao == PARAR)
		nave->v_x = 0;

	//limite de velocidade
	if (nave->v_x > NAVE_VELO)
		nave->v_x = NAVE_VELO;
	else if (nave->v_x < -NAVE_VELO)
		nave->v_x = -NAVE_VELO;
	//atualiza pos_x
	nave->pos_x += (nave->v_x * _deltatime);

	if (nave->pos_x > nave->lim_sup)
		nave->pos_x = nave->lim_sup;

	if (nave->pos_x < nave->lim_inf)
		nave->pos_x = nave->lim_inf;
}

void processa_nave(Nave* nave) {
	desenha_nave(nave);
}

void finaliza_nave(Nave* nave) {
	al_destroy_bitmap(nave->bitmap[0]);
	al_destroy_bitmap(nave->bitmap[1]);
}
