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
#include <string.h>

void buffer(char arr[]){
     int len = strlen(arr);

    if(len > 0 && arr[len-1] == '\n'){
        arr[len-1] = '\0';
    } // 만약 마지막에 \n가 있다면?

    else{
        while(getchar() !='\n'); // 엔터가 나올때까지 먹어치움.
    }

    // 현상태: str까지 입력받은 상태   
}


int main(){
    struct student
    {
        char major[10];
        char name[10];
        char st_num[5];
    };
    // student리는 구조체를 선언하였고

    struct student student[10];
    // 배열을 10개로 진행함.

    for(int i=0; i<10; i++){
        printf("%d번째 학과를 입력해주세요:\n",i+1);
        // 학과명을 받습당
        do{
            printf("2~9자리입니다.:");
            fgets(student[i].major, sizeof(student[i].major), stdin);
            buffer(student[i].major);
            printf("\n");

        }while(strlen(student[i].major)<2);
        //printf("학생이름을 입력해주세요");
    

        int hello;
        do{
            hello =0;
            printf("%d번째 학생이름을 입력해주세요:",i+1);
            fgets(student[i].name, sizeof(student[i].name), stdin);
            buffer(student[i].name);
            printf("\n");

            if(i>0){
                for(int j=0; j<i; j++ ){
                    if(((strcmp(student[i].major,student[j].major)==0 ))&& (strcmp(student[i].name , student[j].name)==0) ){
                        hello =1;
                        break;
                    }
                }
            }

        }while(strlen(student[i].name)<2 || (hello ==1) );
    }
        
        struct student temp; // 임시저장용도로

        // 학생이름 올림차순에 따라 학번을 부여한다. 
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                if(strcmp(student[i].name, student[j].name)>0){
                    temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }
        // 이진탐색 버전으로 할 수 있을 것 같은데..!! -> 미안 이건 찾는 거였지 미안미안...

        int number =0;

        for(int i=0; i<10; i++){
            if(i ==0 || strcmp(student[i].name, student[i-1].name) != 0){
                number ++;
            }

            // 만약 앞사람과 이름이 같다면..? 증가 ㄴㄴ
            int repeat =0;

            if(i>0 && strcmp(student[i].name,student[i-1].name) == 0){
                repeat = 1;
            }

            // 뒷사람하고도 이름이 같다면...?
            if(i<9 && strcmp(student[i].name, student[i+1].name)==0){
                repeat = 1;
            }

            if(repeat == 0){
                if(number<10){
                    student[i].st_num[0] = '0';
                    student[i].st_num[1] = number + '0';
                    student[i].st_num[2] = '\0';
                }
            else{
                if(number<10){
                sprintf(student[i].st_num, "%c%c%02d", student[i].major[0],student[i].major[1], number);
            }
        }
    }
        
            else{
                sprintf(student[i].st_num, "%c%c%d", student[i].major[0],student[i].major[1], number);
            }
        }
        


      // 학번 올림차순에 따라 학번을 부여한다. 
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                if(strcmp(student[i].st_num, student[j].st_num)>0){
                    temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }

    for(int i=0; i<10; i++){
        printf("%s,%s,%s", student[i].name, student[i].major, student[i].st_num);
        printf("\n");
    }

}







    
    