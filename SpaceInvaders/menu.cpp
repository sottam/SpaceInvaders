//menu


#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "menu.hpp"



void inicializa_menu(Menu* menu) {
	menu->pos_x_cursor = 101;
	menu->pos_y_cursor = 400;

	menu->bitmap[0] = al_load_bitmap("data/menu.jpg");
	//testando git
	menu->bitmap[1] = al_load_bitmap("data/cursor.png");
	//testando git

	if( menu->bitmap[0] == NULL || menu->bitmap[1] == NULL) {
   	puts( "Erro ao carregar o arquivo menu imagens");
   	exit(0);
	}

	menu->fonte[0] = al_load_ttf_font("data/lcd.ttf",32,0 );
	menu->fonte[1] = al_load_ttf_font("data/Lato.ttf",72,0 );
}

void move_cursor(Menu* menu, int direcao) {

	if (menu->pos_y_cursor == 400 && direcao == CIMA)
		menu->pos_y_cursor = 450;
	else if (menu->pos_y_cursor == 450 && direcao == BAIXO)
		menu->pos_y_cursor = 400;
	else if (direcao > 0)
		menu->pos_y_cursor -= 50;
	else if (direcao < 0)
		menu->pos_y_cursor += 50;
}

void desenha_menu(Menu* menu) {
	int flags = 0;

	al_draw_bitmap( menu->bitmap[0], 0, 0, flags );
	al_draw_bitmap( menu->bitmap[1],
						 menu->pos_x_cursor,
						 menu->pos_y_cursor, flags );
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 400 , ALLEGRO_ALIGN_LEFT, "Iniciar Jogo");
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 450 , ALLEGRO_ALIGN_LEFT, "Sair do  Jogo");
	al_draw_text(menu->fonte[1], al_map_rgb(255,0,0), 400, 150 , ALLEGRO_ALIGN_CENTER, "SPACE INVADERS");

	al_flip_display();

}

void desenha_menu_vitoria(Menu* menu) {
	int flags = 0;

	al_draw_bitmap( menu->bitmap[0], 0, 0, flags );
	al_draw_bitmap( menu->bitmap[1],
						 menu->pos_x_cursor,
						 menu->pos_y_cursor, flags );
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 400 , ALLEGRO_ALIGN_LEFT, "Reiniciar Jogo");
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 450 , ALLEGRO_ALIGN_LEFT, "Sair do  Jogo");
	al_draw_text(menu->fonte[1], al_map_rgb(0,255,0), 400, 150 , ALLEGRO_ALIGN_CENTER, "VOCE VENCEU !");

	al_flip_display();

}

void desenha_menu_derrota(Menu* menu) {
	int flags = 0;

	al_clear_to_color(FUNDO);

	al_draw_bitmap( menu->bitmap[0], 0, 0, flags );
	al_draw_bitmap( menu->bitmap[1],
						 menu->pos_x_cursor,
						 menu->pos_y_cursor, flags );
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 400 , ALLEGRO_ALIGN_LEFT, "Reiniciar Jogo");
	al_draw_text(menu->fonte[0], al_map_rgb(255,255,255), 140, 450 , ALLEGRO_ALIGN_LEFT, "Sair do  Jogo");
	al_draw_text(menu->fonte[1], al_map_rgb(255,0,0), 400, 150 , ALLEGRO_ALIGN_CENTER, "VOCE PERDEU !");

	al_flip_display();

}

void seleciona_menu(Menu* menu) {
	if (_gamestate == 0)
		desenha_menu( menu );
	else if (_gamestate == 2)
		desenha_menu_vitoria(menu);
	else if (_gamestate == 3)
		desenha_menu_derrota(menu);
}

void processa_menu( Menu* menu) {
	bool seta_cima_pressionada = false;
	bool seta_baixo_pressionada = false;
	bool selecionar = false;
	while( _gamestate == 0 || _gamestate == 2 || _gamestate == 3 ) {
		if( !al_is_event_queue_empty(menu->fila_eventos) ) {
			ALLEGRO_EVENT evento;
			al_wait_for_event( menu->fila_eventos, &evento );

			if( evento.type == ALLEGRO_EVENT_KEY_DOWN )
				switch( evento.keyboard.keycode ) {
					case ALLEGRO_KEY_UP: seta_cima_pressionada = true; break;
					case ALLEGRO_KEY_DOWN: seta_baixo_pressionada = true; break;
					case ALLEGRO_KEY_ENTER: selecionar = true; break;
					}
			else if( evento.type == ALLEGRO_EVENT_KEY_UP )
				switch( evento.keyboard.keycode ) {
					case ALLEGRO_KEY_UP: seta_cima_pressionada = false; break;
					case ALLEGRO_KEY_DOWN: seta_baixo_pressionada = false; break;
					case ALLEGRO_KEY_ENTER: selecionar = false; break;
					}

			if( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
				_gamestate = -1;
				puts("Fechou no x.(menu)");
				break;
			}
		}

			if( seta_cima_pressionada ) {
				move_cursor( menu, CIMA );
				//puts("Cima!");
            break;
			}
			else if( seta_baixo_pressionada ) {
				move_cursor( menu, BAIXO );
				//puts("Baixo!");
            break;
			}
			if(selecionar == true && menu->pos_y_cursor == 400) {
				if (_gamestate == 2 || _gamestate == 3 ) {
               puts("Reinicia!");
               _gamestate = 4;
               selecionar = false;
               break;
            }
            else {
               puts("Inicia!");
               _gamestate = 1;
               selecionar = false;
               break;
				}
			}

			if (selecionar == true && menu->pos_y_cursor == 450) {
				_gamestate = -1;
				puts("Sai caralho!");
				selecionar = false;
				break;
			}
		seleciona_menu(menu);
	}
	al_flush_event_queue(menu->fila_eventos);
}

void finaliza_menu(Menu* menu) {
	al_destroy_event_queue(menu->fila_eventos);

	al_destroy_bitmap( menu->bitmap[0] );
	al_destroy_bitmap( menu->bitmap[1] );

	al_destroy_font( menu->fonte[0] );
	al_destroy_font( menu->fonte[1] );

}
