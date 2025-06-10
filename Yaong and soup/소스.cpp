#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>


#define ROOM_WIDTH	10 // �� ����
#define HME_POS		1 // Ȩ ������
#define BWL_PO		(ROOM_WIDTH - 2) // ���� ��ġ
#define MAX(a, b) ((a) > (b) ? (a) : (b))


void Status();
void PrintMood();
void RollDice();
void RoomPrint();
void Interact();
void MakeCP();
void Shop();
void Addtoy(const char toyname[]);
void RandomQuest();


char catname[10]; // ����� �̸�
char toylist[4][8]; // �峭�� ����


int soupnum; // ���� ����
int intimacy = 2; // ����� ģ�е�
int catpos = 1; // ������� ��ġ
int cp; // ťƮ ����Ʈ
int mood = 3; // ����� ���
int toynumber; // �峭�� ����
int Spos; // ��ũ��ó ��ġ
int Tpos; // Ĺ Ÿ�� ��ġ
int turn; // �� Ƚ��


bool rat = false;
bool razor = false;
bool scratcher = false;
bool cattower = false;


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

	while (true) {
		Status(); // ����â ǥ��
		
		

		PrintMood(); // ��� ������



		RollDice(); // �ֻ��� ������

		

		RoomPrint(); // �� ���



		Interact(); // ��ȣ�ۿ�



		MakeCP(); // CP ����



		Shop(); // ���� ����



		RandomQuest(); // ���� ����Ʈ �߻�

		turn++;

		Sleep(2500); system("cls");
		}
	return 0;
}



void Status() {
	printf("==================== ���� ���� ====================\n");
	printf("������� ���� ����: %d��\n", soupnum);
	printf("CP: %d ����Ʈ\n", cp);
	switch (mood) {
	case 0: {
		printf("%s�� ���(0~3): 0\n", catname);
		printf(" ����� �ſ� ���޴ϴ�.\n");
		break;
	}
	case 1: {
		printf("%s�� ���(0~3): 1\n", catname);
		printf(" �ɽ����մϴ�.\n");
		break;
	}
	case 2: {
		printf("%s�� ���(0~3): 2\n", catname);
		printf(" �Ļ��� �����ϴ�.\n");
		break;
	}
	case 3: {
		printf("%s�� ���(0~3): 3\n", catname);
		printf(" ������ �θ��ϴ�.\n");
		break;
	}

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
}



void PrintMood() {
	int dice = (rand() % 6) + 1;
	printf("6-%d: �ֻ��� ���� %d �����̸� �׳� ����� �������ϴ�.\n", intimacy, 6 - intimacy);
	printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
	if (dice > 6 - intimacy) {
		printf("%d��(��) ���Խ��ϴ�.\n", dice);
		printf("%s�� ����� �״���Դϴ�.\n", catname);
	}
	else if (dice <= 5) {
		printf("%d��(��) ���Խ��ϴ�.\n", dice);
		printf("%s�� ����� �������ϴ�: %d->%d\n", catname, mood, mood - 1);
		if (mood > 0) mood--;
	}
	Sleep(500);
}



void RollDice() {
	int dice = (rand() % 6) + 1;
	int souptype = rand() % 3;
	printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", catname);
	printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", (6 - intimacy));
	printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
	if (dice > (6 - intimacy)) {
		printf("%d��(��) ���Խ��ϴ�!\n", dice);
		printf("���� ������ �����Դϴ�.\n");
		if (catpos < ROOM_WIDTH - 2) {
			catpos++;
		}
	}
	else if (dice <= (6 - intimacy)) {
		printf("%d��(��) ���Խ��ϴ�!\n", dice);
		printf("�� ������ �̵��մϴ�.\n");
		if (catpos > 1) {
			catpos--;
		}
	}
	Sleep(500);

	if (catpos == Spos) {
		printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n", catname);
		printf("����� ���� ���������ϴ�: %d->%d\n", mood, mood + 1);
		if (mood < 3) mood++;
	}

	if (catpos == Tpos) {
		printf("%s��(��) ĹŸ���� �پ�ٴմϴ�.\n", catname);
		printf("����� ���� ���������ϴ�.\n", mood, mood + 2);
		if (mood < 2) mood = mood + 2;
	}

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
		else if (i == Spos - 1 && scratcher == true) {
			Spos = (rand() % 13) + 1;
			if (Spos == HME_POS - 1) Spos++;
			else if (Spos == BWL_PO) Spos--;
			else if (Spos == Tpos) Spos = Spos + ((rand() % 3) - 1);
			printf("S");
		}
		else if (i == Tpos - 1 && cattower == true) {
			Tpos = (rand() % 13) + 1;
			if (Tpos == HME_POS - 1) Tpos++;
			else if (Tpos == BWL_PO) Tpos--;
			else if (Tpos == Spos) Tpos = Tpos + ((rand() % 3) - 1);
			printf("T");
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



void Interact() {
	int move;
	int dice = (rand() % 6) + 1;
	printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n 0. �ƹ��͵� ���� ����\n 1. �ܾ� �ֱ�\n");
	for (int i = 0; i < 4; i++) {
		if (toylist[i][0] != '\0') {
			printf("%d. %s�� ����ֱ�\n", i + 2, toylist[i]);
		}
	}
	printf(">> ");
		while (true) {
		scanf_s("%d", &move);
		switch (move) {
		case 0: {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("%s�� ����� ���������ϴ�: %d -> %d\n", catname, mood, mood - 1);
			mood--;
			printf("5/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			if (dice > 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
				printf("���� ģ�е�: %d\n", intimacy);
			}
			else if (dice <= 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("������� ���谡 �������ϴ�.\n");
				if (intimacy > 0) {
					intimacy--;
				}
				printf("���� ģ�е�: %d\n", intimacy);
			}
			break;
		}
		case 1: {
			printf("%s�� ���� �ܾ��־����ϴ�.\n", catname);
			printf("%s�� ����� �״���Դϴ�: %d\n", catname, mood);
			printf("1/3�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			if (dice >= 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �������ϴ�.\n");
				if (intimacy < 4) {
					intimacy++;
				}
				printf("���� ģ�е�: %d\n", intimacy);
			}
			else if (dice < 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �״���Դϴ�.\n");
				printf("���� ģ�е�: %d\n", intimacy);
			}
			break;
		}
		case 2: {
			if (toylist[move - 2]) {
				printf(">> ");
				continue;
			} 
		}
		default:
			printf(">> ");
			continue;
		}
		break;
	}
		Sleep(500);
}



void MakeCP() {
	cp = (MAX(0, mood - 1) + intimacy);
	printf("%s�� ���(0~3): %d\n", catname, mood);
	printf("������� ģ�е�(0~4): %d\n", intimacy);
	printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", catname, cp);
	printf("���� CP: %d ����Ʈ\n", cp);
	Sleep(500);
}
	


void Shop() {
	int choice;
	printf("�������� ������ �� �� �ֽ��ϴ�.\n� ������ �����ұ��?");
	printf(" 0. �ƹ� �͵� ���� �ʴ´�.\n");
	if (!rat) {
		printf(" 1. �峭�� ��: 1 CP\n");
	}
	else {
		printf(" 1. �峭�� ��: 1 CP (ǰ��)\n");
	}
	if (!razor) {
		printf(" 2. ������ ������: 2 CP\n");
	}
	else {
		printf(" 2. ������ ������: 2 CP (ǰ��)\n");
	}
	if (!scratcher) {
		printf(" 3. ��ũ��ó: 4 CP\n");
	}
	else {
		printf(" 3. ��ũ��ó: 4 CP (ǰ��)\n");
	}
	if (!cattower) {
		printf(" 4. Ĺ Ÿ��: 6 CP\n");
	}
	else {
		printf(" 4. Ĺ Ÿ��: 6 CP (ǰ��)\n");
	}

	scanf_s("%d", &choice);

	switch (choice) {
	case 0: {
		printf("�ƹ� �͵� ���� �ʾҽ��ϴ�.\n");
		break;
	}
	case 1: {
		if (rat == true) {
			printf("�峭�� �㸦 �̹� �����߽��ϴ�.\n");
		}
		else {
			if (cp == 0) {
				printf("CP�� �����մϴ�.\n");
			}
			else if (cp >= 1) {
				cp -= 1;
				rat = true;
				printf("�峭�� �㸦 �����߽��ϴ�.\n");
				printf("���� cp: %d ����Ʈ\n", cp);
			}
		}
		break;
	}
	case 2: {
		if (razor == true) {
			printf("������ �����͸� �̹� �����߽��ϴ�.\n");
		}
		else {
			if (cp <= 1) {
				printf("CP�� �����մϴ�.\n");
			}
			else if (cp >= 2) {
				cp -= 2;
				razor = true;
				printf("������ �����͸� �����߽��ϴ�.\n");
				printf("���� cp: %d ����Ʈ\n", cp);
			}
		}
		break;
	}
	case 3: {
		if (scratcher == true) {
			printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
		}
		else {
			if (cp <= 3) {
				printf("CP�� �����մϴ�.\n");
			}
			else if (cp >= 4) {
				cp -= 4;
				scratcher = true;
				printf("��ũ��ó�� �����߽��ϴ�.\n");
				printf("���� cp: %d ����Ʈ\n", cp);
			}
		}
		break;
	}
	case 4: {
		if (cattower == true) {
			printf("Ĺ Ÿ���� �̹� �����߽��ϴ�.\n");
		}
		else {
			if (cp <= 5) {
				printf("CP�� �����մϴ�.\n");
			}
			else if (cp >= 6) {
				cp -= 6;
				cattower = true;
				Addtoy("Ĺ Ÿ��");
				printf("Ĺ Ÿ���� �����߽��ϴ�.\n");
				printf("���� cp: %d ����Ʈ\n", cp);
			}
		}
		break;
	}
	}
	Sleep(500);
}
void Addtoy(const char toyname[]) {
	for (int i = 0; i < 4; i++) {
		if (toylist[i][0] == '\0') {
			strcpy_s(toylist[i], sizeof(toyname), toyname); // strcpy �Ⱦ��� �ڵ尡 �ʹ� ���������� ����߽��ϴ�.
			break;
		}
	}
}



void RandomQuest() {
	int RandomNumber = (rand() % 10) + 1;
	int choose;
	if (turn == 3) {
		printf("!!���� ����Ʈ �߻�!!\n");
		printf("����! ���� ���߱�!\n");
		printf("����: 1~10������ ������ ���� �� �ϳ��� ��� ��Ȯ�ϰ� ����ٸ� CP +2��,\n���ڿ� +- 1 ���̰� ���ٸ� CP +1��,\n ���ڿ� +- 2 �̻� ���̰� ���ٸ� CP -1���Դϴ�.");
		printf("���� ����>> ");
		scanf_s("%d", &choose);
		if (RandomNumber == choose) {
			printf("���� ����: %d\n", RandomNumber);
			printf("��Ȯ�մϴ�! CP +2��!\n");
			cp = cp + 2;
		}
		else if (abs(RandomNumber - choose) == 1) {
			printf("���� ����: %d\n", RandomNumber);
			printf("+- 1 ���̷� �ƽ��� ������׿�Ф�... CP +1��!\n");
			cp++;
		}
		else {
			printf("���� ����: %d\n", RandomNumber);
			printf("2 �̻� ���̰� ���׿�... CP -1��!\n");
			cp--;
		}
	}
	Sleep(500);
}