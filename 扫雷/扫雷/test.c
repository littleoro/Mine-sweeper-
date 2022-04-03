#include"game.h"
#include<stdlib.h>
#include<time.h>
void game();
void menu() {
	printf("---------扫雷游戏---------\n");
	printf("--------- 1.play ---------\n");
	printf("--------- 0.exit ---------\n");
	printf("--------------------------\n");
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();//扫雷游戏
			printf("扫雷\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}

void game() {
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');//初始化为0
	Initboard(show, ROWS, COLS, '*');//初始化为*
	//打印棋盘
	printboard(mine, ROW, COL);
	printboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	//排查雷
	Findmine(mine, show,ROW, COL);


}