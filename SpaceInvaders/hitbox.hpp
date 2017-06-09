//HITBOX


#ifndef HITBOX_H
#define HITBOX_H

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "tiro.hpp"
#include "nave.hpp"
#include "routinas.hpp"
#include "aliens.hpp"

#define POS_TIRO_FORA 610

extern int _vidas;

void testa_tiro_nave_hit_belt(Tiro* tiro, Belt* belt);

void testa_tiro_nave_hit_aliens(Tiro* tiro, Aliens* aliens);

void testa_tiro_alien_hit_belt(Tiro* tiro, Belt* belt);

void testa_tiro_alien_hit_nave(Tiro* tiro, Nave* nave);

void level_up (Tiro* tiro, Nave* nave);

void processa_hitbox( Tiro* tiro, Belt* belt, Aliens* aliens, Nave* nave);


#endif
