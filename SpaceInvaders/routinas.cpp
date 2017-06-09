//routinas
//inicializacoes

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "routinas.hpp"

void inicializa_allegro(Space* space, Menu* menu, int x, int y, int largura, int altura) {

	ALLEGRO_DISPLAY *display = NULL;
	al_set_new_window_position(x, y);

	if (!al_init()) {
		fprintf(stderr, "Falha ao inicializar o Allegro!\n");
		exit(-1);
	}

	if (!al_init_primitives_addon()) {
		fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
		exit(-1);
	}

	if (!al_init_image_addon()) {
		fprintf(stderr, "Falha ao inicializar add-on de imagens.\n");
		exit(-1);
	}

	al_init_font_addon();
	al_init_ttf_addon();

	display = al_create_display(largura, altura);

	if (!display) {
		fprintf(stderr, "Falha ao criar o display!\n");
		exit(-1);
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "Falha ao inicializar o teclado.\n");
		exit(-1);
	}

	menu->fila_eventos = al_create_event_queue();
	if (!menu->fila_eventos) {
		fprintf(stderr, "Falha ao criar fila de eventos.\n");
		exit(-1);
	}

	al_register_event_source(menu->fila_eventos, al_get_keyboard_event_source());

	al_register_event_source(menu->fila_eventos, al_get_display_event_source(display));

	space->fila_eventos = al_create_event_queue();
	if (!space->fila_eventos) {
		fprintf(stderr, "Falha ao criar fila de eventos.\n");
		exit(-1);
	}

	al_register_event_source(space->fila_eventos, al_get_keyboard_event_source());

	al_register_event_source(space->fila_eventos, al_get_display_event_source(display));

	space->altura = altura;
	space->largura = largura;

	inicializa_zbuffer(&space->zbuffer, display,
		space->altura, space->largura,
		&space->belt, &space->nave,
		&space->aliens, &space->tiro,
		&space->pontos, menu);
}

void inicializa_jogo(Space* space) {

	inicializa_belt(&space->belt, POS_INICIO_BELT, 450);

	inicializa_nave(&space->nave, space->largura / 2, 590, 0, space->largura);

	inicializa_aliens(&space->aliens, POS_INICIO_ALIEN, 40);

	inicializa_tiro(&space->tiro, 600, 0);
}


void desenha_space(Space* space) {

	processa_zbuffer(&space->zbuffer);
}



void move_nave_space(Space* space, COMANDO direcao) {
	switch (direcao) {
	case ESQUERDA:
		if (space->nave.min_x > 0) {
			move_nave(&space->nave, ESQUERDA);
		}
		break;

	case DIREITA:
		if (space->nave.max_x < 799) {
			move_nave(&space->nave, DIREITA);
		}
		break;
	case PARAR:
		move_nave(&space->nave, PARAR);
		break;
	}
}

void processa_jogo(Space* space) {

	bool seta_direita_pressionada = false,
		seta_esquerda_pressionada = false;
	bool tiro = false;
	bool pause = false;
	float old_deltatime = al_get_time();

	while (_gamestate == 1 || _gamestate == 4) {

		old_deltatime = al_get_time();
		

		if (!al_is_event_queue_empty(space->fila_eventos)) {
			ALLEGRO_EVENT evento;
			al_wait_for_event(space->fila_eventos, &evento);

			if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT: seta_esquerda_pressionada = true; break;
				case ALLEGRO_KEY_SPACE: tiro = true; break;
				case ALLEGRO_KEY_RIGHT: seta_direita_pressionada = true; break;
				case ALLEGRO_KEY_P: pause = true; break;
				}
			else if (evento.type == ALLEGRO_EVENT_KEY_UP)
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT: seta_esquerda_pressionada = false; break;
				case ALLEGRO_KEY_SPACE: tiro = false; break;
				case ALLEGRO_KEY_RIGHT: seta_direita_pressionada = false; break;
				case ALLEGRO_KEY_P: pause = false; break;
				}

			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				_gamestate = -1;
				puts("Fechou no x.(jogo)");
				break;
			}

		}

		if (seta_direita_pressionada)
			move_nave_space(space, DIREITA);
		else if (seta_esquerda_pressionada)
			move_nave_space(space, ESQUERDA);
		else
			move_nave_space(space, PARAR);

		if (tiro == true) {
			atira_tiro(&space->tiro, &space->nave);
			tiro = false;
		}

		move_aliens(&space->aliens);

		atira_tiro_alien(&space->tiro, &space->aliens);

		processa_tiroteio(&space->tiro);

		processa_hitbox(&space->tiro, &space->belt, &space->aliens, &space->nave);

		desenha_space(space);

		_deltatime = al_get_time() - old_deltatime;
		printf("DeltaTime: %f \r", _deltatime);
	}
	al_flush_event_queue(space->fila_eventos);
}

void finaliza_jogo(Space* space) {

	al_destroy_event_queue(space->fila_eventos);

	finaliza_nave(&space->nave);
	finaliza_aliens(&space->aliens);
	finaliza_belt(&space->belt);
	finaliza_tiro(&space->tiro);
	finaliza_zbuffer(&space->zbuffer);
	//finaliza_pontos( &space-> pontos ); // Erro de ponteiro.
}


