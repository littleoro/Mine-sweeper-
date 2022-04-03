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
	printf("------ɨ����Ϸ-----------\n");
	//��ӡ�к�
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
	printf("------ɨ����Ϸ-----------\n");
}


void Setmine(char mine[ROWS][COLS], int row, int col) {
	int count = COUNT;
	while (count) {
		//����������±�
		int x = rand() % row+1;
		int y = rand() % col+1;
		if (mine[x][y]=='0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	//1.�����Ų������

	//2.������괦�ǲ�����
	  //��1������-ը��-��Ϸ����
	 //��2��������-ͳ��������Χ�м�����-�洢�Ų��׵���Ϣ��Show���飬��Ϸ����
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-COUNT)
	{
		printf("������Ҫ�Ų�����꣺>");
		scanf("%d %d", &x, &y);//x-1~9 y-1~9
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1') {
				printf("���ź����㱻ը����\n");
				printboard(mine, row, col);
				break;
			}
			else
			{
				//ͳ��������Χ�м�����
				int count=get_mine_count(mine, x, y);
				show[x][y] = count+'0';
				printboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("%��ϲ���������������������ɨ����Ϸ������ǣ�̫���ˣ�����\n");
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