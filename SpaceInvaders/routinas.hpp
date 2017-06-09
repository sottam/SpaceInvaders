#ifndef ROUTINAS_H
#define ROUTINAS_H

#include "belt.hpp"
#include "nave.hpp"
#include "aliens.hpp"
#include "tiro.hpp"
#include "hitbox.hpp"
#include "display.hpp"
#include "zbuffer.hpp"

#define POS_INICIO_BELT 70
#define POS_INICIO_ALIEN 60

extern int _gamestate;
extern float _deltatime;

enum Estado { INTEIRO = 0, AVARIADO = 1, DESTRUIDO = 2 };


struct Space {
	int largura;
	int altura;
	Belt belt;
	Nave nave;
	Aliens aliens;
	Tiro tiro;
	Pontos pontos;
	ZBuffer zbuffer;
	ALLEGRO_EVENT_QUEUE* fila_eventos;
	ALLEGRO_TIMER* timer;
};



void inicializa_allegro( Space* space, Menu* menu, int x, int y, int largura, int altura );

void inicializa_jogo( Space* space);

void processa_jogo( Space* space );

void finaliza_jogo( Space* space);

#endif
