//DISPLAY
/*
Por motivos desconhecidos, não é possivel carregar uma imagem bitmap para ser desenhada
quando o switch-case ou else if apontam para a struct pontos.
o erro retornado acontece em tempo de execução, e é o "BUS ERROR" ou "Erro de barramento"
Uma pesquisa retornou que este erro eh um erro muito raro que acontece quando o processador
não consegue terminar de executar uma instrução.

A solução temporaria foi carregar a imagem na struct Nave para conseguir carregar sem
"segmentation fault" ou "bus error"

também não é possivel carregar fontes da struct Pontos, ocorre segmentation fault
*/

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "routinas.hpp"
#include "display.hpp"
#include "tiro.hpp"

extern int _vidas;


void inicializa_pontos (Pontos* pontos, int x, int y) {
	pontos->pos_x_pontos = x;
	pontos->pos_y_pontos = y;
	pontos->pos_x_vidas = x + 600;
	pontos->pos_y_vidas = y;

	pontos->pontos = 100;

	pontos->bitmap[0] = al_load_bitmap("data/nave_1.png");
	pontos->bitmap[1] = al_load_bitmap("DESTRUIDO.png");

	if( pontos->bitmap[0] == NULL || pontos->bitmap[1] == NULL ) {
   	puts( "Erro ao carregar o arquivo data/nave.png");
   	exit(0);
	/*
	pontos->fonte = al_load_ttf_font("data/Lato.ttf", 48, 0);

	 if (pontos->fonte == NULL) {
        puts("Erro ao carregar o arquivo de fonte.");
        exit(0);
    }
	*/

	}
}

void desenha_pontos(Pontos* pontos, Nave* nave, Tiro*tiro) {
	int flags = 0;
	int pnt = 0;
	switch (_vidas) {
		case 1:
			al_draw_bitmap ( nave->bitmap[2], 720, 5, flags );
			break;
		case 2:
			al_draw_bitmap ( nave->bitmap[2], 720, 5, flags );
			al_draw_bitmap ( nave->bitmap[2], 745, 5, flags );
			break;
		case 3:
			al_draw_bitmap ( nave->bitmap[2], 720, 5, flags );
			al_draw_bitmap ( nave->bitmap[2], 745, 5, flags );
			al_draw_bitmap ( nave->bitmap[2], 770, 5, flags );
			break;
		case 0:
			al_draw_bitmap ( nave->bitmap[1], 720, 10, flags );
			al_draw_bitmap ( nave->bitmap[1], 745, 10, flags );
			al_draw_bitmap ( nave->bitmap[1], 770, 10, flags );
			break;
		default:
			al_draw_bitmap ( nave->bitmap[1], 720, 10, flags );
			al_draw_bitmap ( nave->bitmap[1], 745, 10, flags );
			al_draw_bitmap ( nave->bitmap[1], 770, 10, flags );
			break;
	}


	ALLEGRO_FONT *font = al_load_ttf_font("data/Lato.ttf",32,0 );

	pnt = tiro->score;

   al_draw_textf(font, al_map_rgb(255,255,255), 3, -5 ,ALLEGRO_ALIGN_LEFT, "Score: %d", pnt);
	al_draw_text(font, al_map_rgb(255,255,255), 600, -5 ,ALLEGRO_ALIGN_LEFT, "Vidas: ");

	al_destroy_font( font );


}

void processa_pontos(Pontos* pontos, Nave* nave, Tiro* tiro) {
	desenha_pontos(pontos, nave, tiro);
}

void finaliza_pontos(Pontos* pontos) {
	//al_destroy_bitmap( pontos->bitmap[0] );
	//al_destroy_bitmap( pontos->bitmap[1] );
}


