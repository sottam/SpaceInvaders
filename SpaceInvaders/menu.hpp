//menu

#ifndef MENU_H
#define MENU_H

#define FUNDO al_map_rgb(0, 255, 0)

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "nave.hpp"
#include "tiro.hpp"

extern int _gamestate;


enum DIRECAO { CIMA = 1, BAIXO = -1 };

struct Menu {
	int pos_x_cursor;
	int pos_y_cursor;

	ALLEGRO_EVENT_QUEUE* fila_eventos;
	ALLEGRO_BITMAP* bitmap[2];
	ALLEGRO_FONT* fonte[2];
};

void inicializa_menu(Menu* menu);

void move_cursor(Menu* menu, int direcao);

void desenha_menu(Menu* menu);

void desenha_menu_vitoria(Menu* menu);

void desenha_menu_derrota(Menu* menu);

void seleciona_menu(Menu* menu);

void processa_menu(Menu* menu);

void finaliza_menu(Menu* menu);


#endif
