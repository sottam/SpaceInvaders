//Buffer

#ifndef ZBUFFER_H
#define ZBUFFER_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "belt.hpp"
#include "nave.hpp"
#include "aliens.hpp"
#include "tiro.hpp"
#include "display.hpp"
#include "menu.hpp"


struct ZBuffer {
	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* buffer;
	ALLEGRO_BITMAP* fundo;
	Belt* belt;
	Nave* nave;
	Aliens* aliens;
	Tiro* tiro;
	Pontos* pontos;
	Menu* menu;

};

void inicializa_zbuffer(	ZBuffer* z, ALLEGRO_DISPLAY *display,
			  						int altura, int largura, Belt* belt,
									Nave* nave, Aliens* aliens,
									Tiro* tiro, Pontos* pontos,
									Menu* menu);

void finaliza_zbuffer( ZBuffer* z );

void processa_zbuffer( ZBuffer* z);


#endif
