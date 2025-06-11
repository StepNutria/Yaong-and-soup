#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>


#define ROOM_WIDTH	13 // 방 넓이
#define HME_POS		1 // 홈 포지션
#define BWL_PO		(ROOM_WIDTH - 2) // 냄비 위치
#define MAX(a, b) ((a) > (b) ? (a) : (b))


void Status();
void PrintMood();
void RollDice();
void SetPos();
void RoomPrint();
void Interact();
void MakeCP();
void Shop();
void Addtoy(int toy);
void RandomQuest();


char catname[10]; // 고양이 이름


int soupnum; // 수프 갯수
int intimacy = 2; // 고양이 친밀도
int catpos = 1; // 고양이의 위치
int cp; // 큐트 포인트
int mood = 3; // 고양이 기분
int toynumber; // 장난감 갯수
int Spos; // 스크래처 위치
int Tpos; // 캣 타워 위치
int turn; // 턴 횟수
int toyorder[2]; // 장난감 구매 순서
int toycount; // 장난감 구매 갯수


bool rat = false;
bool razor = false;
bool scratcher = false;
bool cattower = false;


int main() { // 이름 입력
	srand((unsigned int)time(NULL));
	printf("****야옹이와 수프****\n\n");
	printf("       /\\_/\\\n");
	printf(" /\\   / o o \\\n");
	printf("//\\\\  \\~(*)~/\n");
	printf("`   \\ /  ^  \\\n");
	printf("    | \\|| ||/\n");
	printf("\n\n야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", catname, 10);
	printf("\n야옹이의 이름은 %s입니다.", catname);
	Sleep(1000); system("cls");

	while (true) {
		Status(); // 상태창 표시
		
		

		PrintMood(); // 기분 나빠짐



		RollDice(); // 주사위 굴리기

		
		SetPos(); // 스크래처와 캣타워의 좌표 고정
		RoomPrint(); // 방 출력



		Interact(); // 상호작용



		MakeCP(); // CP 생산



		Shop(); // 상점 구매



		RandomQuest(); // 돌발 퀘스트 발생

		turn++;

		Sleep(2500); system("cls");
		}
	return 0;
}



void Status() {
	printf("==================== 현재 상태 ====================\n");
	printf("현재까지 만든 수프: %d개\n", soupnum);
	printf("CP: %d 포인트\n", cp);
	switch (mood) {
	case 0: 
		printf("%s이 기분(0~3): 0\n", catname);
		printf(" 기분이 매우 나쁩니다.\n");
		break;
	case 1: 
		printf("%s이 기분(0~3): 1\n", catname);
		printf(" 심심해합니다.\n");
		break;
	
	case 2: 
		printf("%s이 기분(0~3): 2\n", catname);
		printf(" 식빵을 굽습니다.\n");
		break;
	
	case 3: 
		printf("%s이 기분(0~3): 3\n", catname);
		printf(" 골골송을 부릅니다.\n");
		break;
	}

	switch (intimacy) {
	case 0:
		printf("집사와의 관계(0~4): 0\n");
		printf(" 곁에 오는 것조차 싫어합니다.\n");
		break;
	case 1:
		printf("집사와의 관계(0~4): 1\n");
		printf(" 간식 자판기 취급입니다.\n");
		break;
	case 2:
		printf("집사와의 관계(0~4): 2\n");
		printf(" 그럭저럭 쓸 만한 집사입니다.\n");
		break;
	case 3:
		printf("집사와의 관계(0~4): 3\n");
		printf(" 훌륭한 집사로 인정 받고 있습니다.\n");
		break;
	case 4:
		printf("집사와의 관계(0~4): 4\n");
		printf(" 집사 껌딱지입니다.\n");
		break;
	}

	printf("===================================================\n");
	Sleep(500);
}



void PrintMood() {
	int dice = (rand() % 6) + 1;
	printf("6-%d: 주사위 눈이 %d 이하이면 그냥 기분이 나빠집니다.\n", intimacy, 6 - intimacy);
	printf("주사위를 굴립니다. 또르르...\n");
	if (dice > 6 - intimacy) {
		printf("%d이(가) 나왔습니다.\n", dice);
		printf("%s의 기분이 그대로입니다.\n", catname);
	}
	else if (dice <= 5) {
		printf("%d이(가) 나왔습니다.\n", dice);
		printf("%s의 기분이 나빠집니다: %d->%d\n", catname, mood, mood - 1);
		if (mood > 0 && mood < 4) mood--;
	}
	Sleep(500);
}



void RollDice() {
	int souptype = rand() % 3;
	int distscratcher = abs(catpos - Spos);
	int distcattower = abs(catpos - Tpos);
	switch (mood) {
	case 0: 
		printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", catname);
		catpos++;
	case 1: 
		if (scratcher == false && cattower == false) {
			printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
			if (mood > 0 && mood < 4) mood--;
		}
		else if (scratcher == false && cattower == true) {
			printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", catname);
			catpos += (Tpos > catpos) ? 1 : -1;
		}
		else if (scratcher == true && cattower == false) {
			printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", catname);
			catpos += (Spos > catpos) ? 1 : -1;
		}
		else if (scratcher == true && cattower == true) {
			if (distscratcher < distcattower) {
				printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", catname);
				catpos += (Spos > catpos) ? 1 : -1;
			}
			else {
				printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", catname);
				catpos += (Tpos > catpos) ? 1 : -1;
			}
			}
	case 2: 
		printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", catname);
		break;
	case 3: 
		printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", catname);
		catpos++;
		break;
	}
	if (catpos == Spos) {
		printf("%s은(는) 스크래처를 긁고 놀았습니다.\n", catname);
		printf("기분이 조금 좋아졌습니다: %d->%d\n", mood, mood + 1);
		if (mood < 3 && mood > 0) mood++;
	}

	if (catpos == Tpos) {
		printf("%s은(는) 캣타워를 뛰어다닙니다.\n", catname);
		printf("기분이 제법 좋아졌습니다 %d->%d\n", mood, mood + 2);
		if (mood < 2 && mood > 0) mood = mood + 2;
	}

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
		else if (i == Spos - 1 && scratcher == true) {
			printf("S");
		}
		else if (i == Tpos - 1 && cattower == true) {
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
void SetPos() {
	do {
		Spos = (rand() % ROOM_WIDTH) + 1;
		Tpos = (rand() % ROOM_WIDTH) + 1;
	} while (Spos == Tpos || Spos == HME_POS - 1 || Spos == BWL_PO || Tpos == HME_POS - 1 || Tpos == BWL_PO);
}



void Interact() {
	int move;
	int dice = (rand() % 6) + 1;
	printf("어떤 상호작용을 하시겠습니까?\n 0. 아무것도 하지 않음\n 1. 긁어 주기\n");
	for (int i = 0; i < 2; i++) {
		if (toyorder[i] == 1) {
			printf(" %d. 장난감 쥐로 놀아 주기\n", i + 2);
		}
		else if (toyorder[i] == 2) {
			printf(" %d. 레이저 포인터로 놀아주기\n", i + 2);
		}
	}

	printf(">> ");
		while (true) {
		scanf_s("%d", &move);
		switch (move) {
		case 0: 
			printf("아무것도 하지 않습니다.\n");
			printf("%s의 기분이 나빠졌습니다: %d -> %d\n", catname, mood, mood - 1);
			mood--;
			printf("5/6의 확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			if (dice > 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
				printf("현재 친밀도: %d\n", intimacy);
			}
			else if (dice <= 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("집사와의 관계가 나빠집니다.\n");
				if (intimacy > 0) {
					intimacy--;
				}
				printf("현재 친밀도: %d\n", intimacy);
			}
			break;
		case 1:
			printf("%s의 턱을 긁어주었습니다.\n", catname);
			printf("%s의 기분은 그대로입니다: %d\n", catname, mood);
			printf("1/3의 확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			if (dice >= 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도가 높아집니다.\n");
				if (intimacy < 4) {
					intimacy++;
				}
				printf("현재 친밀도: %d\n", intimacy);
			}
			else if (dice < 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도는 그대로입니다.\n");
				printf("현재 친밀도: %d\n", intimacy);
			}
			break;
		case 2: 
			if (toyorder[0] == 1) {
				printf("장난감 쥐로 %s와 놀아 주었습니다.\n", catname);
				printf("%s의 기분이 조금 좋아졌습니다: %d->%d\n", catname, mood, mood + 1);
				if (mood > 0 && mood < 3) mood++;
				if (dice >= 4) intimacy++;
			}
			else if (toyorder[0] == 2) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", catname);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", catname, mood, mood + 2);
				if (mood > 0 && mood < 2) mood = mood + 2;
				if (dice >= 2) intimacy++;
			}
			break;
		case 3: 
			if (toyorder[1] == 1) {
				printf("장난감 쥐로 %s와 놀아 주었습니다.\n", catname);
				printf("%s의 기분이 조금 좋아졌습니다: %d->%d\n", catname, mood, mood + 1);
				if (mood > 0 && mood < 3) mood++;
				if (dice >= 4) intimacy++;
			}
			else if (toyorder[1] == 2) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", catname);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", catname, mood, mood + 2);
				if (mood > 0 && mood < 2) mood = mood + 2;
				if (dice >= 2) intimacy++;
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
	printf("%s의 기분(0~3): %d\n", catname, mood);
	printf("집사와의 친밀도(0~4): %d\n", intimacy);
	printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", catname, cp);
	printf("보유 CP: %d 포인트\n", cp);
	Sleep(500);
}
	


void Shop() {
	int choice;
	printf("상점에서 물건을 살 수 있습니다.\n어떤 물건을 구매할까요?\n");
	printf(" 0. 아무 것도 사지 않는다.\n");
	if (!rat) {
		printf(" 1. 장난감 쥐: 1 CP\n");
	}
	else {
		printf(" 1. 장난감 쥐: 1 CP (품절)\n");
	}
	if (!razor) {
		printf(" 2. 레이저 포인터: 2 CP\n");
	}
	else {
		printf(" 2. 레이저 포인터: 2 CP (품절)\n");
	}
	if (!scratcher) {
		printf(" 3. 스크래처: 4 CP\n");
	}
	else {
		printf(" 3. 스크래처: 4 CP (품절)\n");
	}
	if (!cattower) {
		printf(" 4. 캣 타워: 6 CP\n");
	}
	else {
		printf(" 4. 캣 타워: 6 CP (품절)\n");
	}

	printf(">> ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 0: {
		printf("아무 것도 사지 않았습니다.\n");
		break;
	}
	case 1: {
		if (rat == true) {
			printf("장난감 쥐를 이미 구매했습니다.\n");
		}
		else {
			if (cp == 0) {
				printf("CP가 부족합니다.\n");
			}
			else if (cp >= 1) {
				cp -= 1;
				rat = true;
				Addtoy(1);
				printf("장난감 쥐를 구매했습니다.\n");
				printf("보유 cp: %d 포인트\n", cp);
			}
		}
		break;
	}
	case 2: {
		if (razor == true) {
			printf("레이저 포인터를 이미 구매했습니다.\n");
		}
		else {
			if (cp <= 1) {
				printf("CP가 부족합니다.\n");
			}
			else if (cp >= 2) {
				cp -= 2;
				razor = true;
				Addtoy(2);
				printf("레이저 포인터를 구매했습니다.\n");
				printf("보유 cp: %d 포인트\n", cp);
			}
		}
		break;
	}
	case 3: {
		if (scratcher == true) {
			printf("스크래처를 이미 구매했습니다.\n");
		}
		else {
			if (cp <= 3) {
				printf("CP가 부족합니다.\n");
			}
			else if (cp >= 4) {
				cp -= 4;
				scratcher = true;
				printf("스크래처를 구매했습니다.\n");
				printf("보유 cp: %d 포인트\n", cp);
			}
		}
		break;
	}
	case 4: {
		if (cattower == true) {
			printf("캣 타워를 이미 구매했습니다.\n");
		}
		else {
			if (cp <= 5) {
				printf("CP가 부족합니다.\n");
			}
			else if (cp >= 6) {
				cp -= 6;
				cattower = true;
				printf("캣 타워를 구매했습니다.\n");
				printf("보유 cp: %d 포인트\n", cp);
			}
		}
		break;
	}
	}
	Sleep(500);
}

void Addtoy(int toy) {
	toyorder[toycount] = toy;
	toycount++;
}



void RandomQuest() {
	int RandomNumber = (rand() % 10) + 1;
	int choose;
	if (turn == 3) {
		printf("!!돌발 퀘스트 발생!!\n");
		printf("도전! 숫자 맞추기!\n");
		printf("설명: 1~10까지의 랜덤한 숫자 중 하나를 골라 정확하게 맞춘다면 CP +2점,\n숫자와 +- 1 차이가 난다면 CP +1점,\n숫자와 +- 2 이상 차이가 난다면 CP -1점입니다.\n");
		printf("나의 숫자>> ");
		scanf_s("%d", &choose);
		if (RandomNumber == choose) {
			printf("랜덤 숫자: %d\n", RandomNumber);
			printf("정확합니다! CP +2점!\n");
			cp = cp + 2;
		}
		else if (abs(RandomNumber - choose) == 1) {
			printf("랜덤 숫자: %d\n", RandomNumber);
			printf("+- 1 차이로 아쉽게 못맞췄네요ㅠㅠ... CP +1점!\n");
			cp++;
		}
		else {
			printf("랜덤 숫자: %d\n", RandomNumber);
			printf("2 이상 차이가 나네요... CP -1점!\n");
			cp--;
		}
	}
	Sleep(500);
}