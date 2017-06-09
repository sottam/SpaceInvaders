#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


#include "routinas.hpp"
#include "menu.hpp"

int _gamestate = 0;
int _vidas = 3;
int _pontos = 0;
float _deltatime = 0;

int main(int argc, char **argv) {
	int largura = 800;
	int altura = 600;

	Space space;
	Menu menu;

	inicializa_allegro(&space, &menu, 200, 200, largura, altura);
	inicializa_jogo(&space);
	inicializa_menu(&menu);

	while (_gamestate >= 0) {
		if (_gamestate == 0) { // menu inicial
			
			processa_menu(&menu);
		}
		else if (_gamestate == 1) { //inicia game
			
			processa_jogo(&space);
		}
		else if (_gamestate == 2) { //vitoria
			
			processa_menu(&menu);
		}
		else if (_gamestate == 3) { //derrota
			
			processa_menu(&menu);
		}
		else if (_gamestate == 4) { // reinicia game
			inicializa_jogo(&space);
			processa_jogo(&space);
		}
	}

	finaliza_jogo(&space);
	finaliza_menu(&menu);

	return 0;
}
