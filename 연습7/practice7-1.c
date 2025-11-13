/*
//전역변수는 사용하지 말고 인자 전달로 할 것


[1] 5명의 학생이 3번의 시험을 보았다. 
// 2차원 배열을 통해 [5][3] ->로 만든다.

// 추후 구조체를 통해서 한다면 더 깔끔하지 않을까?

각 학생의 이름(1자)을 입력 받고
// char을 통해 입력받는다.

3번의 시험 점수(0~100)는 무작위수로 중복없이 하나씩 생성(duplicated() 함수는 
생성된 하나의 무작위수의 중복 여부를 검토함)하여
//duplicate 함수를 통해  무작위 생성 및 중복 여부를 검토하면 될 듯 하다.
// 무작위 생성은 srand를 통해 한다.
// 중복 여부는 반복문을 통해서 검사하면 될 듯하다.

중간점수를 해당 학생의 최종 점수로 한다(mid_cal() 함수는 한 학생의 중간점수를 구함). 
// 해당 학생의 최종점수로 한다.
// 중간점수라고 했으니까 진짜 "중간" 점수를 말하는 것 같다.
// 오름차순으로 정리하고 가운데를 하면 되지 않을까?

5명 학생의 전체평균을 구하여(avg_cal() 함수는 전체평균을 구함)
// avg_cal()는 5명 학생의 전체 평균을 구한다.


석차순으로 (rank() 함수는 정렬하여 석차를 구함, 
// 정렬하여 석차를 구한다.

(동일 석차 존재)) 5명 각 학생의 석차, 이름, 
최종점수와 전체 학생의 평균을 출력하는 프로그램을 최소한 위의 함수들을 포함하여 작성
// 동일 석차가 존재하도록 print를 한다.
// 점수가 같으면 ++를 안 하면 될 것 같다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void duplicate(int arr[][4],int count){
    
    for(int i=1; i<4; i++){
        int temp = rand() % 100 +1;
        int j=0;
        for(j=1; j<i; j++){
            if(arr[count][j]== temp){
                i --;
                break;
            }
        }
        if (j==i)
            arr[count][i] = temp;

        }
    }




int main(){

    int student[6][4] = {0};
    srand((unsigned)time(NULL));

    for(int i=0; i<5; i++){
        char name;
        printf("이름(1글자)를 입력해주세요:");
        scanf(" %c",&name);
        student[i][0] = name; // 0 = 이름, 1,2,3 -> 점수
    }

    for (int i = 0; i < 5; i++)
    {
        duplicate(student,i);
    }

    //디버깅
    for (int i = 0; i < 5; i++)
    {
        printf("%c학생\n",student[i][0]);
        for(int j=1; j<4; j++){
            printf("%d\n",student[i][j]);
        }
    }
}


