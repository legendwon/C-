/*
[2] 학생수를 모르는 학생들의 중간 시험 성적과 기말시험 성적을 입력 받아(50~100점, 입력의 끝은 ^Z로 함)

다음과 같은 결과를 출력하는 프로그램을 작성. (소숫점 2자리까지 출력)

    1) 각 학생의 성적 향상율과 전체 학생의 평균 성적향상율 ((기말-중간)/중간, 단위:%)

    2) 각 성적 향상율 구간의 해당 학생수

    3) 최대 성적 향상율 구간(들)과 해당 학생수(동일 학생수 구간은 모두 출력)

** 구간 A(0%미만)   B(~30%미만)    C(30%이상~80%미만)    D(80%이상~100%미만)      E(100%이상)

**출력 예시:

No1: 120.00%

No.2: -26.78%

No3: 46.12%

Total_Avg: 46.45%

Range: A: 2   B: 5   C:5   D:3

Max_range: B:5   C:5
*/


#include<stdio.h>
int main(){

    int scope[5] = {0,};
    int total =0;
    int num =0;

    while(1){

        int mid =0;
        int final =0;
        int rate =0;
        num ++;
        if (scanf("%d/%d",&mid,&final)== EOF){
            printf("\nbye\n");
            break;
        }

        rate = (float)(final-mid)/ mid *100;
        total += rate;
        printf("No.%d: .2f",num, rate);

        if(rate<0) scope[0]++;
        else if (rate<30) scope[1]++;
        else if (rate<80) scope[2]++;
        else if (rate<100) scope[3]++;
        else range[4] ++;
    }


    printf("toal: %.2f\n", total/num);

    for(i=0; i<5; i++){
        printf("%d: %d\n",'A'++i,scope[i]);
    }

   // 최댓값 찾기
    int max = scope[0];
    for(int i=0; i<5-1; i++){
        for(int j=i+1; j<5; j++){
            if(scope[i] < scope[j]){
                max = scope[j];
            }
        }
    }
    
    // 최댓값 구간 출력
    printf("Max_range: ");
    for(int i=0; i<5; i++){
        if(scope[i] == max){
            printf("%c:%d   ", 'A'+i, scope[i]);
        }
    }
}
