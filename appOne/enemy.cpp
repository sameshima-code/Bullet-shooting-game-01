#include"libOne.h"
#include"player.h"
#include"enemy.h"
#include"enemy_bullet.h"

void init_enemy(struct enemy* e) {
	e->positionx = width / 2;
	e->positiony = 105;
	e->sizex = 300;
	e->sizey = 195;
	e->vectorx = 2;
	e->hpMax = 1099;
	e->hp = e->hpMax;
	e->hp_positionx = 20;
	e->hp_positiony = height / 2;
	e->weight = 40;
	e->HP = 1;
	e->alpha = { 255,255,255,0 };
}
void move_enemy(struct enemy* e) {
	e->positionx += e->vectorx;
	if (e->positionx < 150 || e->positionx>width - 150) {
		e->vectorx *= -1;
	}
}
void draw_enemy_hp(struct enemy* e) {
	fill(e->alpha);
	if (e->hp >= 0) {
		rect(e->hp_positionx, e->hp_positiony, e->weight, e->hp);
	}
}
void draw_enemy(struct enemy* e, struct player* p, int numB) {
	if (e->hp >= 0) {
		fill(e->alpha);
		rect(e->positionx, e->positiony, e->sizex, e->sizey);
	}
	else {
		if (p->HP != 0) {
			e->HP = 0;
		}
	}
}
	

