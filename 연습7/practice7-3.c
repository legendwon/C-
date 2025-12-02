/*
[3] 무작위로 생성된 20개의 자연수 (1~100, 중복없이 생성)를 올림차순으로 출력하되
 재귀적으로 (recursive) 정렬을 하는 프로그램을 작성
 */


 /*
[3] 무작위로 생성된 20개의 자연수 (1~100, 중복없이 생성)를 올림차순으로 출력하되
 재귀적으로 (recursive) 정렬을 하는 프로그램을 작성
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 중복 없이 20개의 무작위 숫자 생성 (1~100)
void rand_num(int arr[], int size){
    for(int i=0; i<size; i++){
        int temp = rand() % 100 + 1;
        
        
        int is_duplicate = 0;
        for(int j=0; j<i; j++){
            if(arr[j] == temp){
                is_duplicate = 1;
                break;
            }
        }
        
        if(is_duplicate){
            i--;  
        } else {
            arr[i] = temp;
        }
    }
}

void print_array(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[],int left, int mid, int right){
    int n1 = mid-left +1;
    int n2 = right-mid;
    int L[n1];
    int R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[left+i];
    }
    for (int j=0; j<n2; j++)
    {
        R[j] = arr[mid+1+j];
    }
    
    int i=0; int j=0; int k= left;

    while (i<n1 && j< n2)
    {
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while (i<n1)
    {
        arr[k++] = L[i++];
    }
    
    while (j<n2)
    {
        arr[k++] = R[j++];

    }

}



void merge_sort(int arr[], int left, int right){
    if (left<right){
        int mid = left + (right-left) /2;
        // 중간으로 나누고
        merge_sort(arr,left,mid);
        // 반으로 나눈 첫 번째
        merge_sort(arr,mid+1, right);
        // 반으로 나눈 두 번째
        merge(arr,left,mid,right);
        // merge를 한다.

        //재귀함수에 따르게 되면
        // 1/1 개가 되기 전까지 계속 나뉘게 될 것
        /*
        ex) 1,4,3,2,5
        -> 1,4,3
        -> 2,5
        */

    }
    
}

int main(){
    srand((unsigned)time(NULL));
    int arr[20] = {0};
    
    rand_num(arr, 20);
    
    //디버깅
    printf("=== 정렬 전 ===\n");
    print_array(arr, 20);
    

    merge_sort(arr, 0, 19);
    
    printf("\n=== 정렬 후 ===\n");
    print_array(arr, 20);
    
    return 0;
}