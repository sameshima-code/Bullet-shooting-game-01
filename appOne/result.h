#pragma once
struct DATA {
	int data = 1;
};
//void TITLE(struct enemy* e, struct player* p);
void GAMECLEAR(struct player* p,struct enemy* e, struct DATA* d);
void GAMEOVER(struct player* p,struct enemy* e, struct DATA* d);
