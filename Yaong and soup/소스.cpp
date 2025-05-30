#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH	10 // 방 넓이
#define HME_POS		1 // 홈 포지션
#define BWL_PO		(ROOM_WIDTH - 2) // 냄비 위치

void RollDice();
void RoomPrint();
void Status();
void Interact();

char catname[10]; // 고양이 이름
int soupnum = 0; // 수프 갯수
int intimacy = 2; // 고양이 친밀도
int catpos = 1; // 고양이의 위치

 
int main() { // 이름 입력
	srand((unsigned int)time(NULL));
	printf("****야옹이와 수프****\n\n");
	printf("       /\\_/\\\n");
	printf(" /\\  / o o \\\n");
	printf("//\\\\  \\~(*)~/\n");
	printf("`   \\ /     ^ /\n");
	printf("    | \\|| ||\n");
	printf("\n\n야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", catname, 10);
	printf("\n야옹이의 이름은 %s입니다.", catname);
	Sleep(1000); system("cls");

	while (1) {
		Status(); // 상태창 표시
		
		

		RollDice(); // 주사위 굴리기

		

		RoomPrint(); // 방 출력



		Interact(); // 상호작용

		Sleep(2500); system("cls");
		}
	return 0;
}



void RollDice() {
	int dice = (rand() % 6) + 1;
	int souptype = rand() % 3;
	printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", catname);
	printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", (6 - intimacy));
	printf("주사위를 굴립니다. 또르륵...\n");
	if (dice >= (6 - intimacy)) {
		printf("%d이(가) 나왔습니다!\n", dice);
		printf("냄비 쪽으로 움직입니다.\n");
		if (catpos < ROOM_WIDTH - 2) {
			catpos++;
		}
	}
	else if (dice < (6 - intimacy)) {
		printf("%d이(가) 나왔습니다!\n", dice);
		printf("집 쪽으로 이동합니다.\n");
		if (catpos > 1) {
			catpos--;
		}
	}
	Sleep(500);
	if (catpos == BWL_PO) {
		switch (souptype) {
		case 0:
			printf("%s이(가) 감자 수프를 만들었습니다!\n", catname);
			break;
		case 1:
			printf("%s이(가) 양송이 수프를 만들었습니다!\n", catname);
			break;
		case 2:
			printf("%s이(가) 브로콜리 수프를 만들었습니다!\n", catname);
			break;
		}
		soupnum++;
		printf("현재까지 만든 수프 : %d\n", soupnum);
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
	printf("==================== 현재 상태 ====================\n");
	printf("현재까지 만든 수프: %d개\n", soupnum);
	switch (intimacy) {
	case 0: {
		printf("집사와의 관계(0~4): 0\n");
		printf(" 곁에 오는 것조차 싫어합니다.\n");
		break;
	}
	case 1: {
		printf("집사와의 관계(0~4): 1\n");
		printf(" 간식 자판기 취급입니다.\n");
		break;
	}
	case 2: {
		printf("집사와의 관계(0~4): 2\n");
		printf(" 그럭저럭 쓸 만한 집사입니다.\n");
		break;
	}
	case 3: {
		printf("집사와의 관계(0~4): 3\n");
		printf(" 훌륭한 집사로 인정 받고 있습니다.\n");
		break;
	}
	case 4: {
		printf("집사와의 관계(0~4): 4\n");
		printf(" 집사 껌딱지입니다.\n");
		break;
	}
	}
	printf("===================================================\n");
	Sleep(500);
}



void Interact() {
	int move;
	int dice = (rand() % 6) + 1;
	printf("어떤 상호작용을 하시겠습니까?   0. 아무것도 하지 않음  1. 긁어 주기\n>> ");
	while (1) {
		scanf_s("%d", &move);
		switch (move) {
		case 1: {
			printf("%s의 턱을 긁어주었습니다.\n", catname);
			printf("2/6의 확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			if (dice > 2) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도가 높아집니다.\n");
				if (intimacy < 4) {
					intimacy++;
				}
				printf("현재 친밀도: %d\n", intimacy);
			}
			else if (dice <= 2) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도는 그대로입니다.\n");
				printf("현재 친밀도: %d\n", intimacy);
			}
			break;
		}
		case 0: {
			printf("아무것도 하지 않습니다.\n");
			printf("4/6의 확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			if (dice > 4) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
				printf("현재 친밀도: %d\n", intimacy);
			}
			else if (dice <= 4) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도가 떨어집니다.\n");
				if (intimacy > 0) {
					intimacy--;
				}
				printf("현재 친밀도: %d\n", intimacy);
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
	