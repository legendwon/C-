/*
[1] 20명 학생의 점수(0~100)를 무작위로 생성한 후에 다음과 같이 그룹으로 분류한다.

각 그룹의 학생수 내림차순으로 해당 그룹명과 학생수를 출력하는 프로그램 작성.

(동일 학생수를 갖는 그룹들은 그룹의 알파벳 올림차순으로 출력)

         90이상: A,   80이상: B,    70이상: C,    60이상: D, .....,  10이상:I,    10미만: J

**출력 예시: B:5  C:4  A:3  F:3  G:3  H:1  J:1  D:0  E:0  I:0
*/


// 이제 배열을 사용할 수 있으니 사용해볼까요?

#include<stdio.h>
int main(){

    int STUDENT = 20;
    int score[20] = {0};
    char group[10] = {0};
    srand(time(NULL)); //시간을 seed로 넣어 난수 초기화

    for (int i=0; i< STUDENT; i++){
        int random = rand() % 101; //0~100 사이의 랜덤 숫자
        printf("DEBUG:%d\n",random); // 디버깅용
        score[i] = random;
        int index = (random == 100) ? 9 : random/10;
        group[index]++;
    }

    int good_score[10] = {0};

    for (int i=0; i<10; i++){
        
    }


}