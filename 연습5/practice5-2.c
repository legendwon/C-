/*
[2] 입력 갯수를 알수 없는(가변 갯수의)) 양수 분수(5/3 형식으로 입력 받을 것)들을 
입력 받아 합을 계산후 약분하여 가분수와 대분수 형식으로 각각 출력하되,

합이 정수이면 정수만 출력하는 프로그램 작성. (^Z 사용할 것)

 

*입력 예시: 9/4 10/4 11/3 9/3, 3/4 3/9 7/0 14/7 등등

*출력 예시: 3+1/4, 13/4,   2+1/2, 5/2,   2 등등
*/

// 가변갯수 -> 반복문
// 조건 -> s

// crtl z는 get_s함수를 통해 검사

// 유클리드 알고리즘을 사용하여 GCD 를 계산하는 함수
int computeGCD(int a, int b) {
    // 양수로 변환
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    // 유클리드 알고리즘
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


#include <stdio.h>
int main(){

    int sum_a =0;
    int sum_b =0;
    int count =0;
    while (1)
    {
        int a = 0;
        int b =0;
        printf("입력을 하시오: 종료(crtl+z or D):");
        count ++;
        if (scanf("%d/%d",&a,&b)== EOF){
            printf("\nbye\n");
            break;
        }
        else{
            // 교수님은 여기서 더 간간하게 하셔다.
            // 항상 예외도 생각할 것
            if (count ==1){
                sum_a = count * a;
                sum_b = count * b;
            }
            
            else{
                sum_a = sum_a * b + b*sum_b;
                sum_b = sum_b * b;
            }
        }
        
    }

    //어쩃든 받긴 받는다.
    //이제 깔끔하게 해야한다.
    printf("%d/%d\n",sum_a,sum_b); //디버깅 용도

    //how to 깔끔?
    //최대 공약수로 나눈다.
    //유클리드 정리가 있다고 한다.

    int GCD =computeGCD(sum_a,sum_b);

    int clean_a = sum_a / GCD;
    int clean_b = sum_b /GCD;

    printf("%d/%d\n",clean_a,clean_b);

}
