//buffer

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "zbuffer.hpp"

extern int _gamestate;

void inicializa_zbuffer(	ZBuffer* z, ALLEGRO_DISPLAY *display,
			  						int altura, int largura, Belt* belt,
									Nave* nave, Aliens* aliens, Tiro* tiro,
									Pontos* pontos, Menu* menu) {
    z->display = display;
    z->buffer = al_create_bitmap( largura, altura );
    z->fundo  = al_load_bitmap("data/space.jpg");

	 z->belt = belt;
	 z->nave = nave;
	 z->aliens = aliens;
	 z->tiro = tiro;
	 z->pontos = pontos;

	 z->menu = menu;

    if( z->fundo == NULL ) {
      puts( "Erro ao carregar o arquivo data/space.png");
      exit(0);
    }

}

void finaliza_zbuffer( ZBuffer*z ) {
    al_destroy_bitmap( z->fundo );
    al_destroy_bitmap( z->buffer );
    al_destroy_display( z->display );

}

void processa_zbuffer( ZBuffer* z ) {

	al_set_target_bitmap( z->buffer );
	al_draw_bitmap( z->fundo, 0, 0, 0 );

	if (_gamestate == 0 || _gamestate == 2 || _gamestate == 3) {
		seleciona_menu(z->menu);
	}

	if (_gamestate == 1 || _gamestate == 4) {
		processa_belt( z-> belt );

		processa_nave( z-> nave );

		processa_aliens( z-> aliens );

		processa_tiro( z-> tiro );

		processa_pontos( z-> pontos, z->nave, z->tiro);
	}


	al_set_target_backbuffer( z->display );
	al_draw_bitmap( z->buffer, 0, 0, 0 );
	al_flip_display();

}
