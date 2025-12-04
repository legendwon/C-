/*
#전역 변수 사용하지 말 것.

#모든 입출력은 main()에서 할 것

[3] 학생 10명의 학과명(2~9자, 학과명 모두가 동일/상이할 수 있음)과 학생이름(2~9자, 동일학과에는 동명이인 없음)을 
입력 받아, 학생이름 올림차순에 따라 학번을 부여한다. 
학번은 최대 2개 부분(학과 코드(학과명 처음 2자)+학생이름순번(동명이인은 같은 순번과 학과코드 부여, 
예 KS02 MS02)으로 구성되며 최소 2자리(예:01, 동명이인이 없는 경우)이며 최대 4자리(예:ZZ10, 동명이인이 있는 경우)이다
(즉, 동명이인은 학과코드 처음 2자를 추가하여 4자리로 부여함).
 학번 부여 후 학번, 학생이름과 학과명을 학번 올림차순으로 출력하는 프로그램을 작성

* 출력 예시:

01

03

IS02

MS02

.....
*/


#include <stdio.h>

// int main(void){
//     int arr[5] = {1,2,3,4,5};

//     int *ptr= arr;

//     printf("%d %d %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4));
// }

int main(){
    int num1= 1, num2 =2, num3 =3;
    int *arr[3] = {&num1, &num2, &num3};

    printf("%p\n", arr[0]);
    printf("%d\n", *arr[0]);

    char *strarr[3] = {"hi", "hing", "guri"};

    printf("%s\n",strarr[0]);
    printf("%c\n",*strarr[0]);


    int arr2d[2][3] = {
        {10,20,30},
        {40,50,60},
    };

    printf("%d %d\n",*arr2d[0],*arr2d[1]);

    int (*ptr)[3] = arr2d;

    int (*ptt)[2] = arr2d;

    printf("%d\n", ptr[0][0]);

    printf("%d\n", ptt[1][0]);


}