#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH	10 // �� ����
#define HME_POS		1 // Ȩ ������
#define BWL_PO		(ROOM_WIDTH - 2) // ���� ��ġ

void RollDice();
void RoomPrint();
void Status();
void Interact();

char catname[10]; // ����� �̸�
int soupnum = 0; // ���� ����
int intimacy = 2; // ����� ģ�е�
int catpos = 1; // ������� ��ġ

 
int main() { // �̸� �Է�
	srand((unsigned int)time(NULL));
	printf("****�߿��̿� ����****\n\n");
	printf("       /\\_/\\\n");
	printf(" /\\  / o o \\\n");
	printf("//\\\\  \\~(*)~/\n");
	printf("`   \\ /     ^ /\n");
	printf("    | \\|| ||\n");
	printf("\n\n�߿����� �̸��� ���� �ּ���: ");
	scanf_s("%s", catname, 10);
	printf("\n�߿����� �̸��� %s�Դϴ�.", catname);
	Sleep(1000); system("cls");

	while (1) {
		Status(); // ����â ǥ��
		
		

		RollDice(); // �ֻ��� ������

		

		RoomPrint(); // �� ���



		Interact(); // ��ȣ�ۿ�

		Sleep(2500); system("cls");
		}
	return 0;
}



void RollDice() {
	int dice = (rand() % 6) + 1;
	int souptype = rand() % 3;
	printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", catname);
	printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", (6 - intimacy));
	printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
	if (dice >= (6 - intimacy)) {
		printf("%d��(��) ���Խ��ϴ�!\n", dice);
		printf("���� ������ �����Դϴ�.\n");
		if (catpos < ROOM_WIDTH - 2) {
			catpos++;
		}
	}
	else if (dice < (6 - intimacy)) {
		printf("%d��(��) ���Խ��ϴ�!\n", dice);
		printf("�� ������ �̵��մϴ�.\n");
		if (catpos > 1) {
			catpos--;
		}
	}
	Sleep(500);
	if (catpos == BWL_PO) {
		switch (souptype) {
		case 0:
			printf("%s��(��) ���� ������ ��������ϴ�!\n", catname);
			break;
		case 1:
			printf("%s��(��) ����� ������ ��������ϴ�!\n", catname);
			break;
		case 2:
			printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", catname);
			break;
		}
		soupnum++;
		printf("������� ���� ���� : %d\n", soupnum);
	}
	Sleep(500);
}



void RoomPrint() {
	printf("\n");
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n#");
	for (int i = 0; i < ROOM_WIDTH - 2; i++) {
		if (i == HME_POS - 1) {
			printf("H");
		}
		else if (i == BWL_PO - 1) {
			printf("B");
		}
		else {
			printf(" ");
		}
	}
	printf("#\n");
	printf("#");
	for (int i = 0; i < ROOM_WIDTH - 2; i++) {
		if (i == catpos - 1) {
			printf("C");
		}
		else {
			printf(" ");
		}
	}
	printf("#\n");
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n");
	Sleep(500);
}



void Status() {
	printf("==================== ���� ���� ====================\n");
	printf("������� ���� ����: %d��\n", soupnum);
	switch (intimacy) {
	case 0: {
		printf("������� ����(0~4): 0\n");
		printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n");
		break;
	}
	case 1: {
		printf("������� ����(0~4): 1\n");
		printf(" ���� ���Ǳ� ����Դϴ�.\n");
		break;
	}
	case 2: {
		printf("������� ����(0~4): 2\n");
		printf(" �׷����� �� ���� �����Դϴ�.\n");
		break;
	}
	case 3: {
		printf("������� ����(0~4): 3\n");
		printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
		break;
	}
	case 4: {
		printf("������� ����(0~4): 4\n");
		printf(" ���� �������Դϴ�.\n");
		break;
	}
	}
	printf("===================================================\n");
	Sleep(500);
}



void Interact() {
	int move;
	int dice = (rand() % 6) + 1;
	printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ����  1. �ܾ� �ֱ�\n>> ");
	while (1) {
		scanf_s("%d", &move);
		switch (move) {
		case 1: {
			printf("%s�� ���� �ܾ��־����ϴ�.\n", catname);
			printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			if (dice > 2) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �������ϴ�.\n");
				if (intimacy < 4) {
					intimacy++;
				}
				printf("���� ģ�е�: %d\n", intimacy);
			}
			else if (dice <= 2) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �״���Դϴ�.\n");
				printf("���� ģ�е�: %d\n", intimacy);
			}
			break;
		}
		case 0: {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			if (dice > 4) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
				printf("���� ģ�е�: %d\n", intimacy);
			}
			else if (dice <= 4) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �������ϴ�.\n");
				if (intimacy > 0) {
					intimacy--;
				}
				printf("���� ģ�е�: %d\n", intimacy);
			}
			break;
		}
		default:
			printf(">> ");
			continue;
		}
		break;
	}
}
	