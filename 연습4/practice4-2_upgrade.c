/*㈜ 반복문과 배열은 사용하지 마시오.

[2] 다음의 서울에서 제주 일일 항공편 스케줄을 참고하여 
사용자로부터 입력받은 시간 전후로 가장 가까운 항공편의 
출도착 시간을 출력하는 프로그램 작성

출발           도착

8:00 a.m. 10:16 a.m.

9:43 a.m. 11:52 a.m.

11:19 a.m. 1:31 p.m.

12:47 p.m. 3:00 p.m.

2:00 p.m. 4:08 p.m.

3:45 p.m. 5:55 p.m.

7:00 p.m. 9:20 p.m.

9:45 p.m. 11:58 p.m.

입력예시: 19:50

출력예시: 7:00 p.m. 9:20 p.m.*/

#include <stdio.h>

int main(void) {
    int hour, minute;
    printf("ex)19:50 입력: ");
    if (scanf("%d:%d", &hour, &minute) != 2) return 0;

    int t = hour * 60 + minute;  // 분으로

    // 24시간으로
    int d1 = 8*60 + 0;    
    int d2 = 9*60 + 43;   
    int d3 = 11*60 + 19;  
    int d4 = 12*60 + 47;  
    int d5 = 14*60 + 0;   
    int d6 = 15*60 + 45;  
    int d7 = 19*60 + 0;   
    int d8 = 21*60 + 45;  


    int m12 = (d1 + d2) / 2;
    int m23 = (d2 + d3) / 2;
    int m34 = (d3 + d4) / 2;
    int m45 = (d4 + d5) / 2;
    int m56 = (d5 + d6) / 2;
    int m67 = (d6 + d7) / 2;
    int m78 = (d7 + d8) / 2;

    // 가장 가까운 출발편 선택 
    int choice;
    if      (t < m12) choice = 1;
    else if (t < m23) choice = 2;
    else if (t < m34) choice = 3;
    else if (t < m45) choice = 4;
    else if (t < m56) choice = 5;
    else if (t < m67) choice = 6;
    else if (t < m78) choice = 7;
    else              choice = 8;

    switch (choice) {
        case 1: printf("8:00 a.m. 10:16 a.m.\n"); break;
        case 2: printf("9:43 a.m. 11:52 a.m.\n"); break;
        case 3: printf("11:19 a.m. 1:31 p.m.\n"); break;
        case 4: printf("12:47 p.m. 3:00 p.m.\n"); break;
        case 5: printf("2:00 p.m. 4:08 p.m.\n"); break;
        case 6: printf("3:45 p.m. 5:55 p.m.\n"); break;
        case 7: printf("7:00 p.m. 9:20 p.m.\n"); break;
        case 8: printf("9:45 p.m. 11:58 p.m.\n"); break;
    }
    return 0;
}
