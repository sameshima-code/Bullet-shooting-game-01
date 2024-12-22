#pragma once
struct distance {
	float disx, disy, sqdisx, sqdisy, dis;
};
void init_distance(struct distance* dis);
void distance_enemy_bullet(struct BULLET_P* b, int numB, struct enemy* e, struct NUM_BULLET* B, struct player* p);
void distance_hp_player(struct player* p, struct enemy* e);
void distance_Renemy_bullet_player
(struct player* p, struct BULLET_R_E* Renemy, int numB, struct distance* dis, struct enemy* e,struct NUM_BULLET* B);
void distance_Lenemy_bullet_player
(struct player* p, struct BULLET_L_E* Lenemy, int numB, struct distance* dis, struct enemy* e, struct NUM_BULLET* B);
void distance_large_bullet_player
(struct player* p, struct BULLET_large* Lbullet, int numB, struct distance* dis, struct enemy* e, struct NUM_BULLET* B);

