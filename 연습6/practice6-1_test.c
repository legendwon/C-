#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

int main() {
    int STUDENT = 20;
    int score[20];
    int group[10] = {0};  // group[0]=A, group[1]=B, ..., group[9]=J
    
    srand(time(NULL));
    
    printf("생성된 점수:\n");
    for (int i = 0; i < STUDENT; i++) {
        score[i] = rand() % 101;  // 0~100
        printf("%d ", score[i]);
        
        // 그룹 인덱스 계산
        int index;
        if (score[i] < 10) {
            index = 9;  // J그룹 (10미만)
        } else if (score[i] >= 90) {
            index = 0;  // A그룹 (90이상)
        } else {
            index = 9 - (score[i] / 10);  // 80이상->1(B), 70이상->2(C), ...
        }
        group[index]++;
    }
    printf("\n\n");
    
    // 정렬을 위한 임시 배열
    int sorted_count[10];  // 정렬된 학생 수
    int sorted_grade[10];  // 해당 그룹 인덱스
    
    // 초기화
    for (int i = 0; i < 10; i++) {
        sorted_count[i] = group[i];
        sorted_grade[i] = i;
    }
    
    // 버블 정렬: 학생 수 내림차순, 동일하면 그룹 인덱스 오름차순
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            // 학생 수가 더 작으면 교환 (내림차순)
            // 또는 학생 수가 같고 그룹 인덱스가 더 크면 교환 (오름차순)
            if (sorted_count[j] < sorted_count[j+1] || 
                (sorted_count[j] == sorted_count[j+1] && sorted_grade[j] > sorted_grade[j+1])) {
                // 학생 수 교환
                int temp = sorted_count[j];
                sorted_count[j] = sorted_count[j+1];
                sorted_count[j+1] = temp;
                
                // 그룹 인덱스 교환
                temp = sorted_grade[j];
                sorted_grade[j] = sorted_grade[j+1];
                sorted_grade[j+1] = temp;
            }
        }
    }
    
    // 결과 출력
    printf("결과: ");
    for (int i = 0; i < 10; i++) {
        printf("%c:%d", 'A' + sorted_grade[i], sorted_count[i]);
        if (i < 9) printf("  ");
    }
    printf("\n");
    
    return 0;
}