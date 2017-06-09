//HITBOX

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


#include "hitbox.hpp"
#include "tiro.hpp"
#include "nave.hpp"
#include "routinas.hpp"
#include "aliens.hpp"

#define TAM_P_BELT 120

extern int _vidas;

void testa_tiro_nave_hit_belt(Tiro* tiro, Belt* belt) {
	int pos;
	for (int i = 0; i < LIMITE_TIROS; i++) {

		if (tiro->pos_y[i] < belt->pos_y + 90) {
			if (POS_INICIO_BELT <= tiro->pos_x[i] && tiro->pos_x[i] < POS_INICIO_BELT + TAM_P_BELT) {
				pos = ((tiro->pos_x[i] - POS_INICIO_BELT) / TAM_ROCK);
				if (belt->estado_belt[pos] < DESTRUIDO) {
					belt->estado_belt[pos] = belt->estado_belt[pos] + 1;
					tiro_hit_check(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT < tiro->pos_x[i] && tiro->pos_x[i] < POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT + TAM_P_BELT) {
				pos = (((tiro->pos_x[i] - (POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos == 0)
					pos += 4;
				else if (pos == 1)
					pos += 4;
				else if (pos == 2)
					pos += 4;
				else if (pos == 3)
					pos += 4;
				if (belt->estado_belt[pos] < DESTRUIDO) {
					belt->estado_belt[pos] = belt->estado_belt[pos] + 1;
					tiro_hit_check(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT < tiro->pos_x[i] && tiro->pos_x[i] < POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT + TAM_P_BELT) {
				pos = (((tiro->pos_x[i] - (POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos == 0)
					pos += 8;
				else if (pos == 1)
					pos += 8;
				else if (pos == 2)
					pos += 8;
				else if (pos == 3)
					pos += 8;
				if (belt->estado_belt[pos] < DESTRUIDO) {
					belt->estado_belt[pos] = belt->estado_belt[pos] + 1;
					tiro_hit_check(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT < tiro->pos_x[i] && tiro->pos_x[i] < POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT + TAM_P_BELT) {

				pos = (((tiro->pos_x[i] - (POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos == 0)
					pos += 12;
				else if (pos == 1)
					pos += 12;
				else if (pos == 2)
					pos += 12;
				else if (pos == 3)
					pos += 12;
				if (belt->estado_belt[pos] < DESTRUIDO) {
					belt->estado_belt[pos] = belt->estado_belt[pos] + 1;
					tiro_hit_check(tiro, i);
				}
			}
		}
	}
}

void testa_tiro_alien_hit_belt(Tiro* tiro, Belt* belt) {
	int pos_al_1;
	for (int i = 0; i < LIMITE_TIROS_ALIEN; i++) {
		if (tiro->pos_y_al[i] > belt->pos_y) {

			if (POS_INICIO_BELT <= tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 < POS_INICIO_BELT + TAM_P_BELT) {
				pos_al_1 = ((tiro->pos_x_al[i] + 18 - POS_INICIO_BELT) / TAM_ROCK);
				if (belt->estado_belt[pos_al_1] < DESTRUIDO) {
					belt->estado_belt[pos_al_1] = belt->estado_belt[pos_al_1] + 1;
					tiro_hit_check_alien(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT < tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 < POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT + TAM_P_BELT) {
				pos_al_1 = (((tiro->pos_x_al[i] + 18 - (POS_INICIO_BELT + TAM_P_BELT + DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos_al_1 == 0)
					pos_al_1 += 4;
				else if (pos_al_1 == 1)
					pos_al_1 += 4;
				else if (pos_al_1 == 2)
					pos_al_1 += 4;
				else if (pos_al_1 == 3)
					pos_al_1 += 4;
				if (belt->estado_belt[pos_al_1] < DESTRUIDO) {
					belt->estado_belt[pos_al_1] = belt->estado_belt[pos_al_1] + 1;
					tiro_hit_check_alien(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT < tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 < POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT + TAM_P_BELT) {
				pos_al_1 = (((tiro->pos_x_al[i] + 18 - (POS_INICIO_BELT + 2 * TAM_P_BELT + 2 * DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos_al_1 == 0)
					pos_al_1 += 8;
				else if (pos_al_1 == 1)
					pos_al_1 += 8;
				else if (pos_al_1 == 2)
					pos_al_1 += 8;
				else if (pos_al_1 == 3)
					pos_al_1 += 8;
				if (belt->estado_belt[pos_al_1] < DESTRUIDO) {
					belt->estado_belt[pos_al_1] = belt->estado_belt[pos_al_1] + 1;
					tiro_hit_check_alien(tiro, i);
				}
			}
			else if (POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT < tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 < POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT + TAM_P_BELT) {

				pos_al_1 = (((tiro->pos_x_al[i] + 18 - (POS_INICIO_BELT + 3 * TAM_P_BELT + 3 * DIST_ENTRE_BELT))) / TAM_ROCK);
				if (pos_al_1 == 0)
					pos_al_1 += 12;
				else if (pos_al_1 == 1)
					pos_al_1 += 12;
				else if (pos_al_1 == 2)
					pos_al_1 += 12;
				else if (pos_al_1 == 3)
					pos_al_1 += 12;
				if (belt->estado_belt[pos_al_1] < DESTRUIDO) {
					belt->estado_belt[pos_al_1] = belt->estado_belt[pos_al_1] + 1;
					tiro_hit_check_alien(tiro, i);
				}
			}
		}
	}
}

void testa_tiro_nave_hit_aliens(Tiro* tiro, Aliens* aliens) {
	int pos = 0;
	int delta_pos = 0;
	for (int i = 0; i < LIMITE_TIROS; i++) {

		if (tiro->pos_y[i] < aliens->pos_y + (5 * (DISTANCIA_Y)) + 30) {
			delta_pos = aliens->pos_x - POS_INICIO_ALIEN;
			pos = (tiro->pos_x[i] - POS_INICIO_ALIEN - delta_pos) / DISTANCIA_X;

			if (tiro->pos_x[i] > aliens->pos_x && tiro->pos_x[i] < aliens->pos_x + COLUNA*DISTANCIA_X) {
				if (aliens->estado[4][pos] < DESTRUIDO) {
					aliens->estado[4][pos] = DESTRUIDO;
					tiro_hit_check(tiro, i);
					tiro->score += 50;
				}
			}
		}
		if (tiro->pos_y[i] < aliens->pos_y + (4 * (DISTANCIA_Y)) + 30) {
			delta_pos = aliens->pos_x - POS_INICIO_ALIEN;
			pos = (tiro->pos_x[i] - POS_INICIO_ALIEN - delta_pos) / DISTANCIA_X;
			if (tiro->pos_x[i] > aliens->pos_x && tiro->pos_x[i] < aliens->pos_x + COLUNA*DISTANCIA_X) {
				if (aliens->estado[3][pos] < DESTRUIDO) {
					aliens->estado[3][pos] = DESTRUIDO;
					tiro_hit_check(tiro, i);
					tiro->score += 50;
				}
			}
		}
		if (tiro->pos_y[i] < aliens->pos_y + (3 * (DISTANCIA_Y)) + 30) {
			delta_pos = aliens->pos_x - POS_INICIO_ALIEN;
			pos = (tiro->pos_x[i] - POS_INICIO_ALIEN - delta_pos) / DISTANCIA_X;
			if (tiro->pos_x[i] > aliens->pos_x && tiro->pos_x[i] < aliens->pos_x + COLUNA*DISTANCIA_X) {
				if (aliens->estado[2][pos] < DESTRUIDO) {
					aliens->estado[2][pos] = DESTRUIDO;
					tiro_hit_check(tiro, i);
					tiro->score += 50;
				}
			}
		}
		if (tiro->pos_y[i] < aliens->pos_y + (2 * (DISTANCIA_Y)) + 30) {
			delta_pos = aliens->pos_x - POS_INICIO_ALIEN;
			pos = (tiro->pos_x[i] - POS_INICIO_ALIEN - delta_pos) / DISTANCIA_X;
			if (tiro->pos_x[i] > aliens->pos_x && tiro->pos_x[i] < aliens->pos_x + COLUNA*DISTANCIA_X) {
				if (aliens->estado[1][pos] < DESTRUIDO) {
					aliens->estado[1][pos] = DESTRUIDO;
					tiro_hit_check(tiro, i);
					tiro->score += 50;
				}
			}
		}
		if (tiro->pos_y[i] < aliens->pos_y + (1 * (DISTANCIA_Y)) + 30) {
			delta_pos = aliens->pos_x - POS_INICIO_ALIEN;
			pos = (tiro->pos_x[i] - POS_INICIO_ALIEN - delta_pos) / DISTANCIA_X;
			if (tiro->pos_x[i] > aliens->pos_x && tiro->pos_x[i] < aliens->pos_x + COLUNA*DISTANCIA_X) {
				if (aliens->estado[0][pos] < DESTRUIDO) {
					aliens->estado[0][pos] = DESTRUIDO;
					tiro_hit_check(tiro, i);
					tiro->score += 50;
				}
			}
		}
	}
}

void testa_tiro_alien_hit_nave(Tiro* tiro, Nave* nave) {
	int flags = 0;//não remover
	for (int i = 0; i < LIMITE_TIROS_ALIEN; i++) {

		if (tiro->pos_y_al[i] >= (nave->pos_y - 50) + 5) {

			if (((nave->pos_x - 40) + 38 < tiro->pos_x_al[i] + 18) && (tiro->pos_x_al[i] + 18 < (nave->pos_x - 40) + 41)) {
				_vidas -= 1;
				tiro_hit_check_alien(tiro, i);
				reset_nave(nave);
			}
		}

		else if ((tiro->pos_y_al[i] >= (nave->pos_y - 50) + 25)) {

			if ((nave->pos_x - 40) + 31 <= tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 <= (nave->pos_x - 40) + 48) {
				_vidas -= 1;
				tiro_hit_check_alien(tiro, i);
				reset_nave(nave);
			}
		}

		else if (tiro->pos_y_al[i] >= (nave->pos_y - 50) + 40) {

			if ((nave->pos_x - 40) + 20 <= tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 <= (nave->pos_x - 40) + 60) {
				_vidas -= 1;
				tiro_hit_check_alien(tiro, i);
				reset_nave(nave);
			}
		}

		else if (tiro->pos_y_al[i] >= (nave->pos_y - 50) + 45) {

			if ((nave->pos_x - 40) + 6 <= tiro->pos_x_al[i] + 18 && tiro->pos_x_al[i] + 18 < (nave->pos_x - 40) + 74) {
				_vidas -= 1;
				tiro_hit_check_alien(tiro, i);
				reset_nave(nave);
			}

		}
	}
}

void level_up(Tiro* tiro, Nave* nave) {
	if (tiro->score % 3000 == 0 && _vidas < 3 && tiro->score != tiro->score_last) {
		_vidas++;
		tiro->score_last = tiro->score;
		_gamestate = 2;
	}
	else if (_vidas < 0)
		_gamestate = 3;
}

void processa_hitbox(Tiro* tiro, Belt* belt, Aliens* aliens, Nave* nave) {
	testa_tiro_nave_hit_belt(tiro, belt);
	testa_tiro_nave_hit_aliens(tiro, aliens);
	testa_tiro_alien_hit_belt(tiro, belt);
	testa_tiro_alien_hit_nave(tiro, nave);
	level_up(tiro, nave);
}
