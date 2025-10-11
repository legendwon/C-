#include <stdio.h>


int main(){
    printf("첫번쨰 학생의 이름을 입력하시오");
    char a[10];
    //scanf("%s",a,sizeof(a));
    scanf("%3s",a);
    int c;
    while((c= getchar()) != '\n' && c != EOF) {}
    // '\n' 개행 버퍼 전까지 읽음
    // EOF -> 읽을 문자가 없거나 오류 전까지 읽음.
    // 다 읽으면? 입력 버퍼가 비워짐.
    // 읽고 아무 행동도 안 함.
    // "abc"는 괜찮은데, "abcd" 즉 4글자 이상을 입력하면 버퍼오버플로우 발생.
    // 어떻게 해결할 수 있을까?
    printf("첫번쨰 학생의 국어 점수를 입력하시오");
    int first_korean = 0;
    scanf("%d", &first_korean);
    printf("첫번쨰 학생의 영어 점수를 입력하시오");
    int first_english = 0;
    scanf("%d", &first_english);

    printf("두번쨰 학생의 이름을 입력하시오");
    char b[10];
    //scanf("%s",b,sizeof(b));
    scanf("%3s",b);
    printf("두번쨰 학생의 국어 점수를 입력하시오");
    int second_korean = 0;
    scanf("%d", &second_korean);
    printf("두번쨰 학생의 영어 점수를 입력하시오");
    int second_english = 0;
    scanf("%d", &second_english);

    printf("%s %d %d\n",a,first_korean, first_english);
    printf("%s %d %d",b,second_korean, second_english);
}