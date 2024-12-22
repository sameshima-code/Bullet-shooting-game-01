#include <libOne.h>
#include"player.h"
#include"enemy.h"
#include"result.h"

void GAMECLEAR(struct player* p, struct enemy* e, struct DATA* d) {
	textSize(100);
	text("Game Clear", width / 2 - 100, height / 2 - 100);
	text("Press E", width / 2 - 100, height / 2 + 100);
	if (isTrigger(KEY_E)) {
		d->data = 1;
	}
}

void GAMEOVER(struct player* p, struct enemy* e, struct DATA* d) {
	textSize(100);
	text("Game Over", width / 2 - 100, height / 2 - 100);
	text("Press E", width / 2 - 100, height / 2 + 100);
	if (isTrigger(KEY_E)) {
		d->data = 1;
	}
}

