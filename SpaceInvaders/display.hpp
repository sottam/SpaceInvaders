//DISPLAY

#ifndef DISPLAY_H
#define DISPLAY_H

#define COR al_map_rgb(0, 255, 0)

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


#include "nave.hpp"
#include "tiro.hpp"

extern int _vidas;

struct Pontos {
	int pos_x_pontos, pos_y_pontos;
	int pos_x_vidas, pos_y_vidas;

	int pontos;

	ALLEGRO_FONT* fonte;
	ALLEGRO_BITMAP* bitmap[2];
};

void inicializa_pontos (Pontos* pontos, int x, int y);

void desenha_pontos(Pontos* pontos, Nave* nave, Tiro* tiro);

void processa_pontos(Pontos* pontos, Nave* nave, Tiro*tiro);

void finaliza_pontos(Pontos* pontos);

#endif
