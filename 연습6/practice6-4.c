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

// Merge 함수
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 임시 배열
    int L[n1], R[n2];
    
    // 데이터 복사
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // 병합
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 남은 요소 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort 함수
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 두 정렬된 배열을 merge
void mergeGroups(int A[], int sizeA, int B[], int sizeB) {
    int i = 0, j = 0;
    
    printf("\nMerged (A + B): ");
    
    // 두 배열을 비교하면서 작은 것부터 출력
    while (i < sizeA && j < sizeB) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }
    
    // A 배열의 남은 요소 출력
    while (i < sizeA) {
        printf("%d ", A[i]);
        i++;
    }
    
    // B 배열의 남은 요소 출력
    while (j < sizeB) {
        printf("%d ", B[j]);
        j++;
    }
    
    printf("\n");
}

int main() {
    int numbers[20];
    int groupA[20];  // 홀수 그룹
    int groupB[20];  // 짝수 그룹
    int countA = 0, countB = 0;
    
    srand(time(NULL));
    
    printf("생성된 20개의 수:\n");
    
    // 20개의 랜덤 수 생성 및 그룹 분류
    for (int i = 0; i < 20; i++) {
        numbers[i] = rand() % 100 + 1;  // 1~100
        printf("%d ", numbers[i]);
        
        if (numbers[i] % 2 == 1) {
            groupA[countA++] = numbers[i];  // 홀수
        } else {
            groupB[countB++] = numbers[i];  // 짝수
        }
    }
    printf("\n\n");
    
    // 그룹 A를 Merge Sort로 정렬
    if (countA > 0) {
        mergeSort(groupA, 0, countA - 1);
    }
    
    // 그룹 B를 Merge Sort로 정렬
    if (countB > 0) {
        mergeSort(groupB, 0, countB - 1);
    }
    
    // 그룹 A 출력
    printf("Group A (홀수): ");
    for (int i = 0; i < countA; i++) {
        printf("%d ", groupA[i]);
    }
    printf("\n");
    
    // 그룹 B 출력
    printf("Group B (짝수): ");
    for (int i = 0; i < countB; i++) {
        printf("%d ", groupB[i]);
    }
    printf("\n");
    
    // Merge: 정렬된 두 그룹을 합치기
    mergeGroups(groupA, countA, groupB, countB);
    
    return 0;
}