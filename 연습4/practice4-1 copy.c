/*㈜ 반복문과 배열은 사용하지 마시오.

[1] 4칙연산(덧셈, 뺄셈, 곱셈, 나눗셈)과 비트연산(AND, OR, XOR)을 지원하는
 가상의 계산기에서 단일의 수식(1개의 연산자)을 입력 받아 해당 계산 결과를 출력하는 프로그램 작성

㈜ 4칙연산 결과의 정수는 정수로(예: 7, 24, 0), 실수는 소숫점 2째자리까지(예: 3.74, 0.68),
 비트연산 결과는 16진수 형태로(예: 0X6E, 0X4) 출력
**입력형식 예시: 18/9 (혹은 18*3, 18/0, 18&81, 45^88 등등)

*/

#include <stdio.h>

int main(void) {
    int hour, minute;
    printf("ex)19:50 입력: ");
    if (scanf("%d:%d", &hour, &minute) != 2) return 0;

    int t = hour * 60 + minute;  // 입력 시각(분)

    // 출발 시각(분) — 24시간 기준
    int d1 = 8*60 + 0;    // 08:00
    int d2 = 9*60 + 43;   // 09:43
    int d3 = 11*60 + 19;  // 11:19
    int d4 = 12*60 + 47;  // 12:47
    int d5 = 14*60 + 0;   // 14:00
    int d6 = 15*60 + 45;  // 15:45
    int d7 = 19*60 + 0;   // 19:00
    int d8 = 21*60 + 45;  // 21:45

    // 도착 시각은 그대로 문자열로 출력 예정
    // 경계(midpoint) 계산
    int m12 = (d1 + d2) / 2;
    int m23 = (d2 + d3) / 2;
    int m34 = (d3 + d4) / 2;
    int m45 = (d4 + d5) / 2;
    int m56 = (d5 + d6) / 2;
    int m67 = (d6 + d7) / 2;
    int m78 = (d7 + d8) / 2;

    // 가장 가까운 출발편 선택 (동점일 땐 앞 편 선택됨)
    int choice;
    if      (t < m12) choice = 1;
    else if (t < m23) choice = 2;
    else if (t < m34) choice = 3;
    else if (t < m45) choice = 4;
    else if (t < m56) choice = 5;
    else if (t < m67) choice = 6;
    else if (t < m78) choice = 7;
    else              choice = 8;

    // 선택된 편의 출/도착 출력
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
