#include"libOne.h"
#include"player.h"
#include"bullet.h"
#include"enemy.h"
#include"enemy_bullet.h"
#include"distance.h"
#include <math.h>

void init_distance(struct distance* dis) {
	dis-> disx = 0;
	dis-> disy = 0; 
	dis-> sqdisx = 0;
	dis-> sqdisy = 0;
	dis-> dis = 0;

}
void distance_enemy_bullet(struct BULLET_P* b, int numB, struct enemy* e, struct NUM_BULLET* B, struct player* p	) {
	for (int i = 0; i < numB; i++) {
		if (b[i].positionx < e->positionx + 150 && b[i].positionx > e->positionx - 150 && b[i].positiony < 105) {
			if (e->hp >= 0 && p->HP!=0) {
				e->hp -= 55;
				b[i].positionx += 3000;
				b[i].hp = 0;
			}
		}
	}
}
void distance_hp_player(struct player* p, struct enemy* e) {
	if (p->positionx < 60 && p->positiony < height/2 + e->hp/2) {
		e->alpha = { 255,255,255,144 };
	}
	else {
		e->alpha = { 255,255,255,255 };
	}
}
void distance_Renemy_bullet_player
(struct player* p, struct BULLET_R_E* Renemy, int numB,struct distance*dis, struct enemy* e, struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		dis->disx=Renemy[i].positionx - p->positionx ;
		dis->disy=Renemy[i].positiony - p->positiony ;
		dis->sqdisx = dis->disx * dis->disx;
		dis->sqdisy = dis->disy * dis->disy;
		dis->dis = Sqrt(dis->sqdisx + dis->sqdisy);
		if (dis->dis < 20) {
			if (e->HP == 1 && p->HP != 0) {
				B->sumNum += 1;
				Renemy[i].hp = 0;
				p->HP -= 1;
			}
		}
	}
}
void distance_Lenemy_bullet_player
(struct player* p, struct BULLET_L_E* Lenemy, int numB, struct distance* dis, struct enemy* e, struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		dis->disx = Lenemy[i].positionx - p->positionx;
		dis->disy = Lenemy[i].positiony - p->positiony;
		dis->sqdisx = dis->disx * dis->disx;
		dis->sqdisy = dis->disy * dis->disy;
		dis->dis = Sqrt(dis->sqdisx + dis->sqdisy);
		if (dis->dis < 20) {
			if (e->HP == 1&&p->HP!=0) {
				B->sumNum += 1;
				Lenemy[i].hp = 0;
				p->HP -= 1;
			}
		}
	}
}
void distance_large_bullet_player
(struct player* p, struct BULLET_large* Lbullet, int numB, struct distance* dis, struct enemy* e, struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		dis->disx = Lbullet[i].positionx - p->positionx;
		dis->disy = Lbullet[i].positiony - p->positiony;
		dis->sqdisx = dis->disx * dis->disx;
		dis->sqdisy = dis->disy * dis->disy;
		dis->dis = Sqrt(dis->sqdisx + dis->sqdisy);
		if (dis->dis < 60) {
			if (e->HP == 1 && p->HP != 0) {
				B->sumNum += 1;
				Lbullet[i].hp = 0;
				p->HP -= 1;
			}
		}
	}
}
