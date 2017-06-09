//tiro

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "tiro.hpp"
#include "nave.hpp"
#include "routinas.hpp"
#include "aliens.hpp"
#include "hitbox.hpp"

void inicializa_tiro(Tiro* tiro, int lim_inf, int lim_sup) {

	tiro->lim_sup = lim_sup;
	tiro->lim_inf = lim_inf;
	tiro->v_y = VEL_TIRO;

	tiro->tiros_na_tela = 0;
	tiro->tiros_alien_na_tela = 0;

	tiro->score = 0;
	tiro->score_last = 0;

	tiro->canhao_y = 0;

	//nave
	for (int i = 0; i < 10; i++)
		tiro->tiros[i] = fora_tela;

	for (int i = 0; i < 10; i++)
		tiro->pos_x[i] = 5;

	for (int i = 0; i < 10; i++)
		tiro->pos_y[i] = POS_TIRO_FORA;

	//alien
	for (int i = 0; i < 10; i++)
		tiro->tiros_al[i] = fora_tela;

	for (int i = 0; i < 10; i++)
		tiro->pos_x_al[i] = 5;

	for (int i = 0; i < 10; i++)
		tiro->pos_y_al[i] = POS_TIRO_FORA;

	tiro->bitmap[0] = al_load_bitmap("data/tiro_alien.png");
	tiro->bitmap[1] = al_load_bitmap("data/tiro_player.png");


	if (tiro->bitmap[0] == NULL || tiro->bitmap[1] == NULL) {
		puts("Erro ao carregar o arquivo data/tiro.png");
		exit(0);
	}
}

void tiro_aleatorio(Aliens* aliens, Tiro* tiro) {
	int i;
	int j;
	i = rand() % LINHA;
	j = rand() % COLUNA;
	if (aliens->estado[i][j] == INTEIRO) {
		aliens->i = i;
		aliens->j = j;
	}
	else {
		aliens->i = 620;
		aliens->j = 620;
	}
	switch (aliens->i) {
	case 0:
		tiro->canhao_y = ALTURA_NAVE_ALIEN + 35; break;
	case 1:
		tiro->canhao_y = ALTURA_NAVE_ALIEN + 10; break;
	case 2:
		tiro->canhao_y = ALTURA_NAVE_ALIEN + 10; break;
	case 3:
		tiro->canhao_y = ALTURA_NAVE_ALIEN + 5; break;
	case 4:
		tiro->canhao_y = ALTURA_NAVE_ALIEN; break;
	default:
		tiro->canhao_y = ALTURA_NAVE_ALIEN + 620; break;
	}

}

void atira_tiro(Tiro* tiro, Nave* nave) {
	if (tiro->tiros_na_tela < LIMITE_TIROS && _vidas >= 0) {
		for (int i = 0; i < 10; i++) {
			if (tiro->tiros[i] == fora_tela) {
				tiro->tiros[i] = na_tela;
				tiro->pos_x[i] = nave->pos_x;
				tiro->pos_y[i] = nave->pos_y;
				break;
			}
		}
		tiro->tiros_na_tela += 1;
	}
}

void atira_tiro_alien(Tiro* tiro, Aliens* aliens) {
	//puts("tiro alien");
	//printf("tiros alien na tela: %d\n", tiro->tiros_alien_na_tela);
	if (tiro->tiros_alien_na_tela < LIMITE_TIROS_ALIEN) {
		for (int i = 0; i < LIMITE_TIROS_ALIEN; i++) {
			if (tiro->tiros_al[i] == fora_tela) {
				tiro_aleatorio(aliens, tiro);
				tiro->tiros_al[i] = na_tela;
				tiro->pos_x_al[i] = (aliens->pos_x + 55 * aliens->j + (LARGURA_NAVE_ALIEN / 2));
				tiro->pos_y_al[i] = (aliens->pos_y + (45 * aliens->i) + tiro->canhao_y);
				tiro->tiros_alien_na_tela += 1;
				break;
			}
		}
	}
}

void desenha_tiro(Tiro* tiro) {
	int flags = 0;
	for (int i = 0; i < 10; i++)
		if (tiro->tiros[i] == na_tela)
			al_draw_bitmap(tiro->bitmap[1],
				tiro->pos_x[i] - 1,
				tiro->pos_y[i] - 60, flags);
}

void desenha_tiro_alien(Tiro* tiro) {
	int flags = 0;
	for (int i = 0; i < 10; i++)
		if (tiro->tiros_al[i] == na_tela)
			al_draw_bitmap(tiro->bitmap[0],
				tiro->pos_x_al[i] - 1,
				tiro->pos_y_al[i], flags);
}

void tiro_hit_check(Tiro* tiro, int i) {
	tiro->tiros[i] = fora_tela;
	tiro->pos_y[i] = POS_TIRO_FORA;
	tiro->tiros_na_tela -= 1;
}

void tiro_hit_check_alien(Tiro* tiro, int i) {
	tiro->tiros_al[i] = fora_tela;
	tiro->pos_y_al[i] = POS_TIRO_FORA;
	tiro->tiros_alien_na_tela -= 1;
}

void tiro_fora_tela_check(Tiro* tiro) {
	for (int i = 0; i < 10; i++)
		if (tiro->pos_y[i] <= 0) {
			tiro->tiros[i] = fora_tela;
			tiro->pos_y[i] = POS_TIRO_FORA;
			tiro->tiros_na_tela -= 1;
		}
}

void tiro_fora_tela_check_alien(Tiro* tiro) {
	for (int i = 0; i < 10; i++)
		if (tiro->pos_y_al[i] >= 600) {
			tiro->tiros_al[i] = fora_tela;
			tiro->pos_y_al[i] = POS_TIRO_FORA;
			tiro->tiros_alien_na_tela -= 1;
		}
}

void move_tiro(Tiro* tiro) {
	for (int i = 0; i < 10; i++)
		if (tiro->tiros[i] == na_tela)
			tiro->pos_y[i] -= VEL_TIRO * _deltatime;//Modernizado em 09/06/17, uso de deltaTime
}

void move_tiro_alien(Tiro* tiro) {
	for (int i = 0; i < 10; i++)
		if (tiro->tiros_al[i] == na_tela) {
			tiro->pos_y_al[i] += VEL_TIRO * _deltatime;//Modernizado em 09/06/17, uso de deltaTime
		}
}

void processa_tiroteio(Tiro* tiro) {
	move_tiro(tiro);
	tiro_fora_tela_check(tiro);
	move_tiro_alien(tiro);
	tiro_fora_tela_check_alien(tiro);
}

void processa_tiro(Tiro* tiro) {
	desenha_tiro(tiro);
	desenha_tiro_alien(tiro);
}

void finaliza_tiro(Tiro* tiro) {
	al_destroy_bitmap(tiro->bitmap[0]);
	al_destroy_bitmap(tiro->bitmap[1]);
}
