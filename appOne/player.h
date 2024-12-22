#pragma once
struct player {
	float positionx = 0;
	float positiony = 0;
	float vectorx = 0;
	float vectory = 0;
	float sizex = 0;
	float sizey = 0;
	float ofsY = 0;
	int HP = 0;
};
void init_player(struct player* p);
void line();
void move_player(struct player* p);
void draw_player(struct player* p);
void draw_player_hp(struct player* p);