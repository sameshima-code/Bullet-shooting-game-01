#pragma once
#include <libOne.h>
struct enemy {
	float positionx = 0;
	float positiony = 0;
	float vectorx = 0;
	float sizex = 0;
	float sizey = 0;
	float hpMax = 0;
	float hp = 0;
	float hp_positionx = 0;
	float hp_positiony = 0;
	float weight = 0;
	int HP = 0;
	COLOR alpha = { 0,0,0,0 };
	COLOR color = { 0,0,0,0 };
};
void init_enemy(struct enemy* e);
void move_enemy(struct enemy* e);
void draw_enemy(struct enemy* e, struct player* p, int numB);
void draw_enemy_hp(struct enemy* e);
