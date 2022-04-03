#include"game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void printboard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------扫雷游戏-----------\n");
	//打印列号
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷游戏-----------\n");
}


void Setmine(char mine[ROWS][COLS], int row, int col) {
	int count = COUNT;
	while (count) {
		//生成随机的下标
		int x = rand() % row+1;
		int y = rand() % col+1;
		if (mine[x][y]=='0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	//1.输入排查的坐标

	//2.检查座标处是不是雷
	  //（1）是雷-炸死-游戏结束
	 //（2）不是雷-统计坐标周围有几个雷-存储排查雷的信息到Show数组，游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-COUNT)
	{
		printf("请输入要排查的坐标：>");
		scanf("%d %d", &x, &y);//x-1~9 y-1~9
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1') {
				printf("很遗憾，你被炸死了\n");
				printboard(mine, row, col);
				break;
			}
			else
			{
				//统计坐标周围有几个雷
				int count=get_mine_count(mine, x, y);
				show[x][y] = count+'0';
				printboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("%恭喜你终于做完了这个垃圾的扫雷游戏你真的是，太棒了！！！\n");
	}
}

int get_mine_count(char mine[ROWS][COLS],int x, int y) {
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}