#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand 함수를 위한 헤더 파일  
#include <time.h> //씨드값 시간으로 두기위해
#include <malloc.h>  //동적 메모리 확보를 위해

int* answer;   //컴퓨터의 볼을 저장할 포인터 변수 선언
int* player;   //사용자의 볼을 저장할 포인터 변수 선언
int ct = 1;    //횟수는 1로 시작
int strike = 0, ball = 0;  //strike 및 ball은 0으로 시작
int i, j, q;               //반복을 위한 변수 선언
int * con;                 //저장 및 계속하기위한 포인터 변수 선언
int w = 0, l = 0;          //win,lose 는 0부터 시작
int level;                 //level 선언
int trial = 1;             // 횟수는 1부터 시작
FILE* wpf;                 //파일 포인터 선언
FILE* rpf;                 //파일 포인터 선언

void new_append() {
    printf("1.새로시작 2.불러오기 : ");
    scanf("%d", &q);
    if (q == 1) {
        wpf = fopen("C:\\프로그래밍 공부\\a.txt", "w");
    }
    if (q == 2) {
        if (rpf == NULL)
        {
            wpf = fopen("C:\\프로그래밍 공부\\a.txt", "w");
            printf("저장된 데이터가 없으므로 새로 시작합니다.\n");
        }
        else {
            rpf = fopen("C:\\프로그래밍 공부\\a.txt", "r+");
            printf("현재 플래이어는 %d승 %d패입니다.\n", w, l);
        }
    }
}

//q의 값에 의해서 새로운 파일을 열지 기존의 파일을 사용할지 설정
//만약에 불러오기를 사용했을 때 비어있을경우(NULL) 새로운 파일을 만들어 시작


void initiliaze()
{
    srand((unsigned int)time(NULL));
    printf("난이도 설정-> ");
    scanf("%d", &level);
    answer = (int*)malloc(sizeof(int) * level);
    player = (int*)malloc(sizeof(int) * level);
    for (i = 0; i < level; i++)
    {
        answer[i] = (rand() % 9) + 1;
        for (j = 0; j < i; j++)
        {
            if (answer[i] == answer[j])
            {
                i--;
                break;
            }
        }
    }
    int strike = 0, ball = 0, out = 0;
}
    //난이도 설정을 위한 입력값 넣기
    //answer,player값을 동적할당 시키기
    //정답 배열 초기화 (랜덤 함수로 임의의 값 넣기)
    // 주의: 정답 배열에는 중복된 값을 넣을 수 없다
    // strike, ball, out 으로 초기화 하기


void get_input(int* player, int ct) {
    printf("[%d회차 숫자야구]\n", ct + 1);
    for (i = 0; i < level; i++)
    {
        printf("%d번째 숫자 입력 : ", i + 1);
        scanf("%d", &player[i]);
    }
    for (i = 0; i < level; i++)
    {
        if (player[i] < 1 || player[i] > 9)
        {
            printf("범위 외의 숫자를 입력하시면 안됩니다.\n");
        }

        else if (player[i] == player[i + 1] || player[i] == player[i + 2] || player[i] == player[i + 3])
        {
            printf("중복된 숫자를 입력하시면 안됩니다.\n");
        }

    }
}
    //난이도에 따른 배열에 입력 및 중복확인
    // 입력값을 받아오는 함수   
    // 주의: 1에서 9까지의 입력만 받아와야 함
    // 주의: 중복된 숫자를 받을 수 없음


void compare_answer_player(int* answer, int* player, int ct)
{
    strike = 0;
    ball = 0;
    for (i = 0; i < level; i++)
    {
        for (j = 0; j < level; j++)
        {
            if (answer[i] == player[j])
                if (i == j)
                {
                    strike++;

                }
                else
                {
                    ball++;
                }
        }
    }
    printf("[결과]스트라이크 : %d, 볼 : %d\n\n", strike, ball);
}
    // answer와 player 배열을 비교하는 코드 넣기
    // 1) 숫자, 자리수 모두 같으면 strike + 1
    // 2) 숫자만 같고 자리는 다르면 ball + 1


int print_and_check_result() {

    if (strike == level)
    {
        return 1;

    }
    if (ball <= level)
    {
        return 0;
    }
}

    // 전역변수 strike, ball을 프린트 해주고 
    // strike가 3이면 return 1, 아직 진행중이면 return 0




void main()
{
    int player[3];

    //사용자가 정답을 입력할 배열 생성  

    while (1) {
        new_append();
        initiliaze();
        printf("%d번째 시도\n", trial++);
        printf("1회에서 9회까지 시도할 수 있습니다");
        while (1) {
            for (int ct = 0; ct < 9; ++ct) {


                printf("\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) :\n ", level);

                get_input(player, ct);

                compare_answer_player(answer, player, ct);

                int victory = print_and_check_result();


                if (victory) {
                    printf("승리 했습니다!\n\n\n");
                    w = w + 1;
                    printf("%d승%d패\n\n\n\n", w, l);
                    break;
                }
                //이겼을 경우 승리수를 1추가 및 승패표시

                if (ct == 8) {
                    printf("9회가 마무리 되었습니다. You lose!\n\n\n");
                    l = l + 1;
                    printf("%d승%d패\n\n\n\n", w, l);
                    break;
                }
                //졌을 경우 패배수를 1추가 및 승패표시
            }
            printf("1.계속하기/2.저장 후 계속/3.저장 후 종료/4.저장하지 않고 종료 :  ");
            scanf("%d", &con);
            if (con == 1) {
            }
            if (con == 2) {
                rpf = fopen("C:\\프로그래밍 공부\\a.txt", "r+");
                fprintf(rpf, "%d승 %d패", w, l);
            }
            if (con == 3) {
                rpf = fopen("C:\\프로그래밍 공부\\a.txt", "r+");
                fprintf(rpf, "%d승 %d패", w, l);
                return 0;
            }
            if (con == 4) {
                return 0;
            }
            //con:1이면 계속 진행하기 위해 공란
            //con:2이면 r+를 이용하여 저장하고 계속 진행
            //con:3이면 r+를 이용하여 저장하고 return 0;로 종료
            //con:3이면 return 0;로 종료
        }
     }       
    fclose(rpf);       //파일 닫기
    fclose(wpf);       //파일 닫기
    free(answer);      //동적할당 메모리 해제
    free(player);      //동적할당 메모리 해제
}
