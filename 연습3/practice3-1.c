
/*
- ****조건문**
    
    **,**
    
    **반복문**
    
    **,**
    
    **배열은 사용하지 말 것*****
[1] 5자리이하 정수(0 ~ 99999)를 **하나의 정수형(%d)**으로 입력받아 **8진수로 변환하여 8진수로** 출력하는 프로그램 작성.

**(입력 및 출력에서 %o는 사용하지 말 것)**

- 입력(출력) 예시: 99999(303237) 333(515) 5(5) 0(0)
*/

#include <stdio.h>
#include <math.h>

int main(){
    int num =0;
    int a =0;
    int b =0;
    int c =0;
    int d =0;
    int e =0;
    int f =0;
    int eight_num =0;

    printf("숫자 입력:");
    scanf("%d",&num);

    int first = 3 << 15 ;
    int second = 7 << 12;
    int third = 7 << 9;
    int fourth = 7 << 6;
    int fifth = 7 << 3;
    int six = 7;


    a = num & first;
    b = num & second;
    c = num & third;
    d = num & fourth;
    e = num & fifth;
    f = num & six;


    a = a >> 15;
    b = b >> 12;
    c = c >> 9;
    d = d >> 6;
    e = e >> 3;

    /*
    printf("%o\n",a);
    printf("%o\n",b);
    printf("%o\n",c);
    printf("%o\n",d);
    printf("%o\n",e);
    printf("%o\n",f);
    */

    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d\n",e);
    printf("%d\n",f);

    


}