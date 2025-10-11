#include <stdio.h>


int main(){
    printf("한 학생의 영어 및 국어 점수(0~100점의 자연수)와 이름(알파벳 1자)을 순서대로 한줄에 입력하시오");
    char a[10];
    int first_korean =0;
    int first_english =0 ;
    //scanf("%3s",a);
    scanf("%d %d %1s",&first_english, &first_korean, a);
    int c;
    while((c= getchar()) != '\n' && c != EOF) {}
    
    printf("%-10s%-10s%-10s\n", "NAME", "ENGLISH", "KOREAN");
    printf("%-10s%-10s%-10s\n", "", "SCORE", "SCORE"); 
    
    printf("%-10s%-10d%-10d\n", a, first_english, first_korean);
    
}