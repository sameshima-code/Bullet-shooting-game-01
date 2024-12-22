#include"libOne.h"
#include"player.h"
#include"bullet.h"
#include"enemy.h"
#include"distance.h"
#include"enemy_bullet.h"
#include"result.h"

void gmain() {
	struct player p = {};
	//playerの球数.
	const int num_Player_Bullets = 5;
	struct BULLET_P b[num_Player_Bullets];
	struct enemy e;
	//敵の球数.
	const int num_Enemy_R_Bullets = 10;
	const int num_Enemy_L_Bullets = 10;
	const int num_large_bullet = 5;
	struct BULLET_R_E Reb[num_Enemy_R_Bullets];
	struct BULLET_L_E Leb[num_Enemy_L_Bullets];
	struct BULLET_large large[num_large_bullet];
	struct NUM_BULLET num;
	struct distance dis;
	struct DATA d;

	window(1920, 1080,full);
	angleMode(DEGREES);
	rectMode(CENTER);
	//colorMode(HSV);
	while (notQuit) {
		if (d.data == 1) {
			init_player(&p);
			init_bullet(b, num_Player_Bullets);
			init_enemy(&e);
			init_enemy_R_bullet(Reb, num_Enemy_R_Bullets);
			init_enemy_L_bullet(Leb, num_Enemy_L_Bullets);
			init_large_bullet(large, num_large_bullet);
			init_distance(&dis);
			d.data = 0;
		}
		//玉を発射.
		shoot_player_bullet(b, &p, num_Player_Bullets);
		shoot_enemy_R_bullet(Reb, num_Enemy_R_Bullets);
		shoot_enemy_L_bullet(Leb, num_Enemy_L_Bullets);
		shoot_large_bullet(large, &num, num_large_bullet);
		//玉、キャラを動かす.
		move_player(&p);
		move_bullet(b, num_Player_Bullets);
		move_enemy(&e);
		move_enemy_R_bullet(Reb, num_Enemy_R_Bullets,&num);
		move_enemy_L_bullet(Leb, num_Enemy_L_Bullets,&num);
		move_large_bullet(large, num_large_bullet, &num);
		//距離を求める.
		distance_hp_player(&p, &e);
		distance_enemy_bullet(b, num_Player_Bullets, &e, &num, &p);
		distance_Renemy_bullet_player(&p, Reb, num_Enemy_R_Bullets, &dis, &e, &num);
		distance_Lenemy_bullet_player(&p, Leb, num_Enemy_L_Bullets, &dis, &e, &num);
		distance_large_bullet_player(&p, large, num_Enemy_L_Bullets, &dis, &e, &num);
		//四角形を表示.
		clear(0);
		line();
		draw_player(&p);
		draw_player_hp(&p);
		draw_bullet(b, num_Player_Bullets);
		draw_enemy_hp(&e);
		draw_enemy(&e, &p, num_Enemy_R_Bullets);
		draw_enemy_R_bullet(Reb, num_Enemy_R_Bullets);
		draw_enemy_L_bullet(Leb, num_Enemy_L_Bullets);
		draw_large_bullet(large, num_large_bullet);
		if (e.HP == 0) {
			GAMECLEAR(&p, &e, &d);
		}
		if (p.HP == 0) {
			GAMEOVER(&p, &e, &d);
		}
	}
}