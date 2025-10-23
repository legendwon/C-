/*
반복문

[1] 무작위로 생성된 자연수 n(10~20)의 factorial value(n!) 구하여 n과 n!을 출력하고
 n! 값을 8진수로 변환하여 8진수로 출력하는 프로그램 작성.

(%o 사용하지 말고 10진수를 8진수로 변환한 후 출력할것)
*/

// 무작위로 생성된 자연수
// 팩토리얼 구하기
// 8진수로 변환하기

#include <stdio.h>
#include <stdlib.h> // srand, rand를 사용하기 위한 헤더 파일
#include <time.h> // time을 활용하기 위해서

int main(){
    srand(time(NULL)); //시간을 seed로 넣어 난수 초기화
    int random = rand() % 10 + 10; //10~20 사이의 랜덤 숫자
    printf("DEBUG:%d\n",random); // 디버깅용도
    long long int factorial = 0; // 혹시 20!를 하면 넘치지 않을까?

    for (int i=random; i>0; i--){
        factorial *= i;
    }
    // n, n-1, n-2...와 같은 형식으로 곱해질 것
    printf("DEBUG:%d\n",factorial); // 디버깅용도

    //8진수로 변환하기

    
    

}


