#include"game.h"
#include<stdlib.h>
#include<time.h>
void game();
void menu() {
	printf("---------ɨ����Ϸ---------\n");
	printf("--------- 1.play ---------\n");
	printf("--------- 0.exit ---------\n");
	printf("--------------------------\n");
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();//ɨ����Ϸ
			printf("ɨ��\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}

void game() {
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');//��ʼ��Ϊ0
	Initboard(show, ROWS, COLS, '*');//��ʼ��Ϊ*
	//��ӡ����
	printboard(mine, ROW, COL);
	printboard(show, ROW, COL);
	//������
	Setmine(mine,ROW,COL);
	//�Ų���
	Findmine(mine, show,ROW, COL);


}