//nave

#ifndef NAVE_H
#define NAVE_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define LARGURA_NAVE 80
#define ALTURA_NAVE 50

#define NAVE_VELO 500

#define DELTA_X (-LARGURA_NAVE/2)
#define DELTA_Y (-ALTURA_NAVE)

extern int _vidas;

enum COMANDO { ESQUERDA = -1, DIREITA = 1, PARAR = 0 };

struct Nave {
	float pos_x, pos_y;
	int pos_x_original, pos_y_original;
	COMANDO direcao;
	float v_x;
	int min_x, max_x, min_y, max_y;
	int atual;
	int lim_inf;
	int lim_sup;
	int estado_nave;	
	ALLEGRO_BITMAP* bitmap[3];
};

void inicializa_nave( Nave* t, int x, int y, 
							 int lim_inf, int lim_sup );

void reset_nave(Nave* nave);

void finaliza_nave( Nave* nave );

void desenha_nave( Nave* nave);

void move_nave( Nave* nave, int direcao );

void processa_nave( Nave* nave );


#endif
