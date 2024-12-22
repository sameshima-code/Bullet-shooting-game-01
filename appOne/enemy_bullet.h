#pragma once
struct BULLET_R_E {
	float positionx, positiony,vectorx, vectory, sizex, sizey, deg;
	int hp;
};
struct BULLET_L_E {
	float positionx, positiony, vectorx, vectory, sizex, sizey, deg;
	int hp;
};
struct BULLET_large {
	float positionx, positiony, vectorx, vectory, sizex, sizey, deg;
	int hp;
};
struct NUM_BULLET {
	int sumNum = 0;
};
void init_enemy_R_bullet(struct BULLET_R_E* e, int numB);
void init_enemy_L_bullet(struct BULLET_L_E* e, int numB);
void init_large_bullet(struct BULLET_large* e, int numB);
void shoot_enemy_R_bullet(struct BULLET_R_E* e,  int numB);
void shoot_enemy_L_bullet(struct BULLET_L_E* e,  int numB);
void shoot_large_bullet(struct  BULLET_large* e, struct NUM_BULLET* B, int numB);
void move_enemy_R_bullet(struct BULLET_R_E* e, int numB, struct NUM_BULLET* B);
void move_enemy_L_bullet(struct BULLET_L_E* e, int numB, struct NUM_BULLET* B);
void move_large_bullet(struct  BULLET_large* e, int numB, struct NUM_BULLET* B);
void draw_enemy_R_bullet(struct BULLET_R_E* e, int numB);
void draw_enemy_L_bullet(struct BULLET_L_E* e, int numB);
void draw_large_bullet(struct  BULLET_large* e, int numB);
