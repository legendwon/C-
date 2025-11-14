/*
[4] 무작위로 생성된 20개의 자연수 (1~100)를 아래 조건에 맞게 2개의 그룹(A, B)으로 분류한 후 각 그룹을 올림차순으로 정렬하여 그룹명과 그룹내의 수들을 출력한다.

2개의 각 그룹이 정렬되어 있다는 사실을 이용하여(merge 적용, 즉 정렬된 그룹들을 통합하여 재정렬하지 말 것) 2개 그룹내 20개의 수들을 올림차순으로 출력하는 프로그램 작성.

** A: 홀수     B: 짝수

이상입니다.
*/

/*
[4] 무작위로 생성된 20개의 자연수 (1~100)를 아래 조건에 맞게 2개의 그룹(A, B)으로 분류한 후 
각 그룹을 올림차순으로 정렬하여 그룹명과 그룹내의 수들을 출력한다.
2개의 각 그룹이 정렬되어 있다는 사실을 이용하여(merge 적용, 즉 정렬된 그룹들을 통합하여 재정렬하지 말 것) 
2개 그룹내 20개의 수들을 올림차순으로 출력하는 프로그램 작성.
** A: 홀수     B: 짝수
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 0
#define B 1
#define NUM 20
#define GROUP 2

int main(void)
{
    int group[GROUP][NUM], avail[GROUP]={0,};
    int merge[NUM], avail_m=0;
    int num, i, j, k, tmp;
    
    // 난수 생성기 초기화
    srand((unsigned)time(NULL));
    
    printf("========== 무작위 숫자 생성 및 분류 ==========\n");
    // 20개의 무작위 숫자 생성 및 홀수/짝수 분류
    for(i=0; i<NUM; i++)
    {
        num = rand() % 100 + 1;  // 1~100 사이의 숫자
        printf("%d ", num);
        
        if(num % 2)  // 홀수
            group[A][avail[A]++] = num;
        else  // 짝수
            group[B][avail[B]++] = num;
    }
    printf("\n\n");
    
    // 각 그룹을 버블 정렬로 오름차순 정렬
    printf("========== 각 그룹 정렬 ==========\n");
    for(k=0; k<GROUP; k++)  // k:0 홀수 그룹, k:1 짝수 그룹
    {
        for(i=0; i<avail[k]-1; i++)  // 정렬
        {
            for(j=i+1; j<avail[k]; j++)
            {
                if(group[k][i] > group[k][j])
                {
                    tmp = group[k][i];
                    group[k][i] = group[k][j];
                    group[k][j] = tmp;
                }
            }
        }
    }
    
    // 정렬된 각 그룹 출력
    for(k=0; k<GROUP; k++)  // 각 정렬된 그룹 출력
    {
        printf("Group_%c (%d개): ", 'A'+k, avail[k]);
        for(i=0; i<avail[k]; i++)
            printf("%d ", group[k][i]);
        printf("\n");
    }
    printf("\n");
    
    // MERGE: 정렬된 두 그룹을 병합
    printf("========== Merge 알고리즘 적용 ==========\n");
    int current_a=0, current_b=0;
    
    // 두 그룹 모두 남아있는 경우
    while(current_a < avail[A] && current_b < avail[B])
    {
        if(group[A][current_a] > group[B][current_b])
            merge[avail_m++] = group[B][current_b++];
        else
            merge[avail_m++] = group[A][current_a++];
    }
    
    // 첫 번째 그룹이 끝난 경우, 두 번째 그룹의 나머지 복사
    if(current_a >= avail[A])
    {
        for(i=current_b; i<avail[B]; i++)
            merge[avail_m++] = group[B][i];
    }
    // 두 번째 그룹이 끝난 경우, 첫 번째 그룹의 나머지 복사
    else if(current_b >= avail[B])
    {
        for(i=current_a; i<avail[A]; i++)
            merge[avail_m++] = group[A][i];
    }
    
    // 최종 병합된 리스트 출력
    printf("Merged List (전체 %d개, 오름차순):\n", avail_m);
    for(i=0; i<avail_m; i++)
    {
        printf("%d ", merge[i]);
        if((i+1) % 10 == 0)  // 10개씩 줄바꿈
            printf("\n");
    }
    printf("\n");
    
    return 0;
}
