#include <stdio.h>


int main(){
    //구조체를 활용해서 한 번 진행해보자.
    // 받아야할 것
    // 이름
    // 영어, 국어 점수

    typedef struct student
    {
        //char name[10];
        //버퍼 최소화
        char name[4];
        int korea;
        int english;
    } dongcheon;

    // 학생수 상수화
    const int N = 2;

    dongcheon a[10];

    for(int i=0; i<N; i++){
        printf("%d번째 학생의 이름을 입력하시오:", i+1);
        scanf("%3s",a[i].name);
        int c;
        while((c= getchar()) != '\n' && c != EOF) {}
        printf("%d번째 학생(%s)의 국어점수를 입력하시오:", i+1,a[i].name);
        scanf("%d",&a[i].korea);
        printf("%d번째 학생(%s)의 영어점수를 입력하시오:", i+1,a[i].name);
        scanf("%d",&a[i].english);
    }
    for(int i=0; i<N; i++){
        printf("%-10s%-10s%-10s\n", "NAME", "ENGLISH", "KOREAN");
        printf("%-10s%-10s%-10s\n", "", "SCORE", "SCORE"); 
    
        printf("%-10s%-10d%-10d\n", a[i].name, a[i].korea, a[i].english);
    }
}