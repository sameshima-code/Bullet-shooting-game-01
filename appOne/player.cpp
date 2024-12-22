#include"libOne.h"
#include"player.h"
#include <math.h>

void init_player(struct player* p) {
	p->positionx = width / 2;
	p->positiony = height - 150;
	p->sizex = 30;
	p->sizey = 40;
	p->vectorx = 3.5;
	p->vectory = 2.5;
	p->ofsY = -10;
	//player‚ÌHP«.
	p->HP = 2;
}
void line() {
	strokeWeight(0);
	fill(255);
	rect(width/2, 480, width, 5);
}
void move_player(struct player* p) {
	if (isPress(KEY_A)) {
		p->positionx -= p->vectorx;
	}
	if (isPress(KEY_D)) {
		p->positionx += p->vectorx;
	}
	if (isPress(KEY_W)) {
		p->positiony -= p->vectory;
	}
	if (isPress(KEY_S)) {
		p->positiony += p->vectory;
	}
	if (p->positionx > width) {
		p->positionx -= width;
	}
	if (p->positionx < 0) {
		p->positionx += width;
	}
	if (p->positiony < 500) {
		p->positiony += p->vectory;
	}
	if (p->positiony > height-20) {
		p->positiony -= p->vectory;
	}
}
void draw_player_hp(struct player* p) {
	for (int i = 0; i < p->HP; i++) {
		fill(255);
		circle(1890 - i*50, 60, 50);
	}
}
void draw_player(struct player* p) {
	rect(p->positionx, p->positiony, p->sizex, p->sizey);
}
