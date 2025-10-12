/*㈜ 반복문과 배열은 사용하지 마시오.

[1] 4칙연산(덧셈, 뺄셈, 곱셈, 나눗셈)과 비트연산(AND, OR, XOR)을 지원하는
 가상의 계산기에서 단일의 수식(1개의 연산자)을 입력 받아 해당 계산 결과를 출력하는 프로그램 작성

㈜ 4칙연산 결과의 정수는 정수로(예: 7, 24, 0), 실수는 소숫점 2째자리까지(예: 3.74, 0.68),
 비트연산 결과는 16진수 형태로(예: 0X6E, 0X4) 출력
**입력형식 예시: 18/9 (혹은 18*3, 18/0, 18&81, 45^88 등등)

*/

#include <stdio.h>

int main(){
    float num1 =0;
    char cal1 =0;
    float num2 =0;

    printf("계산을 입력하시오: ");
    scanf("%f %c %f",&num1,&cal1,&num2);

    switch (cal1)
    {
    case '+':{
        float r = num1 + num2;
        if (r == (int)r){
            printf("%d\n", (int)r);
        }
        else{
            printf("%.2f\n", r);
        }
        break;
    }
    case '-':{
        float r = num1 - num2;
        if (r == (int)r){
            printf("%d\n", (int)r);
        }
        else{
            printf("%.2f\n", r);
        }
        break;
    }
    case '*':{
        float r = num1 * num2;
        if (r == (int)r){
            printf("%d\n", (int)r);
        }
        else{
            printf("%.2f\n", r);
        }
        break;
    }
    case '/':{
       float r = num1 / num2;
        if (r == (int)r){
            printf("%d\n", (int)r);
        }
        else{
            printf("%.2f\n", r);
        }
        break;
    }
    case '&':{
        int r = (int)num1&(int)num2;
        printf("0x%x",r);
        break;
    }
    case '^':{
        int r = (int)num1^(int)num2;
        printf("0x%x",r);
        break;
    }
    case '|':{
        int r = (int)num1|(int)num2;
        printf("0x%x",r);
        break;
    }
    default:{
        break;
    }
    
    }
}