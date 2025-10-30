#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

// Merge 함수: 두 배열을 병합하면서 정렬
void merge(int count[], int grade[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // 왼쪽 부분 배열의 크기
    int n2 = right - mid;      // 오른쪽 부분 배열의 크기
    
    // 임시 배열 생성
    int L_count[n1], R_count[n2];
    int L_grade[n1], R_grade[n2];
    
    // 왼쪽 부분 배열 복사
    for (int i = 0; i < n1; i++) {
        L_count[i] = count[left + i];
        L_grade[i] = grade[left + i];
    }
    
    // 오른쪽 부분 배열 복사
    for (int j = 0; j < n2; j++) {
        R_count[j] = count[mid + 1 + j];
        R_grade[j] = grade[mid + 1 + j];
    }
    
    // 병합 과정
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        // 학생 수가 더 크면 왼쪽 선택 (내림차순)
        // 또는 학생 수가 같고 그룹 인덱스가 더 작으면 왼쪽 선택 (오름차순)
        if (L_count[i] > R_count[j] || 
            (L_count[i] == R_count[j] && L_grade[i] < R_grade[j])) {
            count[k] = L_count[i];
            grade[k] = L_grade[i];
            i++;
        } else {
            count[k] = R_count[j];
            grade[k] = R_grade[j];
            j++;
        }
        k++;
    }
    
    // 왼쪽 배열의 남은 요소 복사
    while (i < n1) {
        count[k] = L_count[i];
        grade[k] = L_grade[i];
        i++;
        k++;
    }
    
    // 오른쪽 배열의 남은 요소 복사
    while (j < n2) {
        count[k] = R_count[j];
        grade[k] = R_grade[j];
        j++;
        k++;
    }
}

// Merge Sort 함수
void mergeSort(int count[], int grade[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // 왼쪽 절반 정렬
        mergeSort(count, grade, left, mid);
        
        // 오른쪽 절반 정렬
        mergeSort(count, grade, mid + 1, right);
        
        // 병합
        merge(count, grade, left, mid, right);
    }
}

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
    int sorted_count[10];  // 정렬될 학생 수
    int sorted_grade[10];  // 해당 그룹 인덱스
    
    // 초기화
    for (int i = 0; i < 10; i++) {
        sorted_count[i] = group[i];
        sorted_grade[i] = i;
    }
    
    // Merge Sort 호출
    mergeSort(sorted_count, sorted_grade, 0, 9);
    
    // 결과 출력
    printf("결과: ");
    for (int i = 0; i < 10; i++) {
        printf("%c:%d", 'A' + sorted_grade[i], sorted_count[i]);
        if (i < 9) printf("  ");
    }
    printf("\n");
    
    return 0;
}