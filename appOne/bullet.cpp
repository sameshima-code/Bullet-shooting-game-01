#include"libOne.h"
#include"player.h"
#include"bullet.h"

void init_bullet(struct BULLET_P* b, int numB) {
	for (int i = 0; i < numB; i++) {
		b[i].positionx = -100;
		b[i].positiony = -100;
		b[i].sizex = 10;
		b[i].sizey = 15;
		b[i].vectory = -6;
		b[i].hp = 1;
	}
}
void shoot_player_bullet(struct BULLET_P* b, struct player* p, int numB) {
	if (isTrigger(KEY_SPACE)) {
		for (int i = 0; i < numB; i++) {
			if (b[i].hp == 0) {
				b[i].hp = 1;
				b[i].positionx = p->positionx;
				b[i].positiony = p->positiony + p->ofsY;
				i = numB;
			}
		}
	}
}
void move_bullet(struct BULLET_P* b, int numB) {
	for (int i = 0; i < numB; i++) {
		if (b[i].hp > 0) {
			b[i].positiony += b[i].vectory;
			//windoy‚ÌŠO‚©.
			if (b[i].positiony < -b[i].sizey) {
				b[i].hp = 0;
			}
		}
	}
}
void draw_bullet(struct BULLET_P* b, int numB) {
	for (int i = 0; i < numB; i++) {
		if (b[i].hp > 0) {
			fill(255);
			rect(b[i].positionx, b[i].positiony, b[i].sizex, b[i].sizey);
		}
	}
}
