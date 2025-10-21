/*
[3] 학생의 영어 및 국어 점수(0~100점의 자연수)와 이름(알파벳 1자)을 
아래와 같이 한줄에 하나씩 입력받아 다음과 같은 형태로 출력하는 프로그램 작성. (평균은 소숫점 2자리까지)

<입력 예시>: 은 입력 데이타

Eng: 87

Kor: 92

Name: S

<출력>

NAME     ENGLISH       KOREAN      TOTAL      AVERAGE

SCORE           SCORE         SCORE     SCORE

S             87                   92                 179           89.50
*/

#include <stdio.h>
#include <ctype.h>

static void dump_stdin_rest(const char *tag) {
    int ch;
    printf("<< %s: pending >> ", tag);
    while ((ch = getchar()) != '\n' && ch != EOF) {
        printf("%02X('%c') ", (unsigned char)ch, isprint(ch) ? ch : '.');
    }
    puts(ch == '\n' ? "[\\n consumed]" : "[EOF]");
}

int main(){
    int E =0;
    int K =0;
    char name;
    int t =0;
    float avg = 0;

    printf("ENG:");
    dump_stdin_rest("1");
    scanf("%d",&E);
    dump_stdin_rest("1");
    // 버퍼오버플로우 방지 추가
    printf("KOR:");
    scanf("%d",&K);
     dump_stdin_rest("2");
    printf("NAME:");
    scanf(" %c",&name);
      dump_stdin_rest("3");

    t = K + E;
    avg = t /2;

    printf("%-8s %12s %12s %12s %12s\n", "NAME", "ENGLISH", "KOREAN", "TOTAL", "AVERAGE");
    printf("%-8s %12s %12s %12s %12s\n", "",      "SCORE",   "SCORE",  "SCORE", "SCORE");
    // 구분선
    printf("---------------------------------------------------------------------\n");
    // 데이터 행
    printf("%-8c %12d %12d %12d %12.2f\n", name, E, K, t, avg);

}
