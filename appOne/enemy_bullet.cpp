#include"libOne.h"
#include"enemy_bullet.h"
#include<stdio.h>
#include <math.h>
#include<time.h>
#include<rand.h>
#include<windows.h>
void init_enemy_R_bullet(struct BULLET_R_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		e[i].positionx = 0;
		e[i].positiony = 0;
		e[i].sizex = 20;
		e[i].sizey = 20;
		e[i].vectorx = sin(e[i].deg) * 3;
		e[i].vectory = -cos(e[i].deg) * 3;
		e[i].deg = 0;
		e[i].hp = 0;
	}
}
void init_enemy_L_bullet(struct BULLET_L_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		e[i].positionx = 0;
		e[i].positiony = 0;
		e[i].sizex = 20;
		e[i].sizey = 20;
		e[i].vectorx = sin(e[i].deg) * 3;
		e[i].vectory = -cos(e[i].deg) * 3;
		e[i].deg = 0;
		e[i].hp = 0;
	}
}
void init_large_bullet(struct BULLET_large* e, int numB) {
	for (int i = 0; i < numB; i++) {
		e[i].positionx = 0;
		e[i].positiony = 0;
		e[i].sizex = 120;
		e[i].sizey = 120;
		e[i].vectorx = sin(e[i].deg);
		e[i].vectory = -cos(e[i].deg);
		e[i].deg = 0;
		e[i].hp = 0;
	}
}
void shoot_enemy_R_bullet(struct BULLET_R_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp == 0) {
			srand(time(0));
			e[i].hp = 1;
			e[i].positionx = width - 100;
			e[i].positiony = 100;
			e[i].deg += rand() % 360;
			e[i].deg += i * 10;
			e[i].vectorx = sin(e[i].deg) * 3;
			e[i].vectory = -cos(e[i].deg) * 3;
			i = numB;
		}
	}
}
void shoot_enemy_L_bullet(struct BULLET_L_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp == 0) {
			srand(time(0));
			e[i].hp = 1;
			e[i].positionx = 100;
			e[i].positiony = 100;
			e[i].deg += rand() % 360;
			e[i].deg += i * 15;
			e[i].vectorx = sin(e[i].deg) * 3;
			e[i].vectory = -cos(e[i].deg) * 3;
			i = numB;
		}
	}
}
void shoot_large_bullet(struct  BULLET_large* e, struct NUM_BULLET* B,int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp == 0 && B->sumNum>=10) {
			srand(time(0));
			e[i].hp = 1;
			e[i].positionx = width/2;
			e[i].positiony = 100;
			e[i].deg += rand() % 360;
			e[i].deg += i * 15;
			e[i].vectorx = sin(e[i].deg);
			e[i].vectory = -cos(e[i].deg);
			i = numB;		
			B->sumNum -= 10;
		}
	}
}
void move_enemy_R_bullet(struct BULLET_R_E* e, int numB, struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			e[i].positionx += e[i].vectorx;
			e[i].positiony += e[i].vectory;
			//windoy‚ÌŠO‚©.
			if (e[i].positiony < -e[i].sizey) {
				e[i].hp = 0;
				B->sumNum += 1;
			}
			else if(e[i].positionx < -e[i].sizex|| e[i].positionx > width ) {
				e[i].vectorx *= -1;
				e[i].positiony -= 30;
			}
			else if (e[i].positiony > height) {
				e[i].vectory *= -1;
			}
		}
	}
}
void move_enemy_L_bullet(struct BULLET_L_E* e, int numB ,struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			e[i].positionx += e[i].vectorx;
			e[i].positiony += e[i].vectory;
			//windoy‚ÌŠO‚©.
			if (e[i].positiony < -e[i].sizey) {
				e[i].hp = 0;
				B->sumNum += 1;
			}
			else if (e[i].positionx < -e[i].sizex || e[i].positionx > width) {
				e[i].vectorx *= -1;
				e[i].positiony -= 30;
			}
			else if (e[i].positiony > height) {
				e[i].vectory *= -1;
			}
		}
	}
}
void move_large_bullet(struct  BULLET_large* e, int numB, struct NUM_BULLET* B) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			e[i].positionx += e[i].vectorx;
			e[i].positiony += e[i].vectory;
			//windoy‚ÌŠO‚©.
			if (e[i].positiony < -e[i].sizey) {
				e[i].hp = 0;
				B->sumNum += 1;
			}
			else if (e[i].positionx < -e[i].sizex || e[i].positionx > width) {
				e[i].vectorx *= -1;
			}
			else if (e[i].positiony > height) {
				e[i].vectory *= -1;
			}
		}
	}
}
void draw_enemy_R_bullet(struct BULLET_R_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			rect(e[i].positionx, e[i].positiony, e[i].sizex, e[i].sizey);
		}
	}
}
void draw_enemy_L_bullet(struct BULLET_L_E* e, int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			rect(e[i].positionx, e[i].positiony, e[i].sizex, e[i].sizey);
		}
	}
}
void draw_large_bullet(struct  BULLET_large* e, int numB) {
	for (int i = 0; i < numB; i++) {
		if (e[i].hp > 0) {
			rect(e[i].positionx, e[i].positiony, e[i].sizex, e[i].sizey);
		}
	}
}
