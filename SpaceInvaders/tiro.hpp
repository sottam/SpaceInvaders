//tiro

#ifndef TIRO_H
#define TIRO_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "nave.hpp"
#include "aliens.hpp"

#define VEL_TIRO 300
#define LIMITE_TIROS 2
#define LIMITE_TIROS_ALIEN 3

enum Estado_tiro { na_tela = 0, fora_tela = 1 };

struct Tiro {
	int v_y;
	int lim_inf;
	int lim_sup;

	int canhao_y; //variavel usada para corrigir a posição de saida do tiro de acordo com o sprite

	int score;
	int score_last;

	//nave
	int tiros[10];
	float pos_x[10];
	float pos_y[10];
	int tiros_na_tela;

	//aliens
	int tiros_al[10];
	float pos_x_al[10];
	float pos_y_al[10];
	int tiros_alien_na_tela;

	//Resultado_alien
	int i;
	int j;

	ALLEGRO_BITMAP* bitmap[2];
};

//ambos
void inicializa_tiro(Tiro* tiro, int lim_inf, int lim_sup);

void finaliza_tiro(Tiro* tiro);

void processa_tiroteio(Tiro* tiro);

void processa_tiro(Tiro* tiro);

//nave

void atira_tiro(Tiro* tiro, Nave* nave);

void desenha_tiro(Tiro* tiro);

void tiro_hit_check(Tiro* tiro, int i);

void tiro_fora_tela_check(Tiro* tiro);

void move_tiro(Tiro* tiro);

//alien

void atira_tiro_alien(Tiro* tiro, Aliens* aliens);

void tiro_aleatorio(Aliens* aliens, Tiro* tiro);

void desenha_tiro_alien(Tiro* tiro);

void tiro_hit_check_alien(Tiro* tiro, int i);

void tiro_fora_tela_check_alien(Tiro* tiro);

void move_tiro_alien(Tiro* tiro);

#endif
