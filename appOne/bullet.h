#pragma once
struct BULLET_P {
	float positionx, positiony, vectory, sizex, sizey;
	int hp;
};
void init_bullet(struct BULLET_P* b, int numB);
void shoot_player_bullet(struct BULLET_P* b, struct player* p, int numB);
void move_bullet(struct BULLET_P* b, int numB);
void draw_bullet(struct BULLET_P* b, int numB);
