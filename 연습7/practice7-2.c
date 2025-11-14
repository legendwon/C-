/*

[2] 무작위로 생성된 20개의 자연수 (1~100, 중복없이 생성)를 
// 생성하는 건 rand()~~

아래 조건에 맞게 4개의 그룹명(A, B, C, D)으로 분류한 후 
// 분류는 if로

각 그룹을 올림차순으로 정렬하여 출력한다.
// 올림차순으로 정렬~

각 그룹이 정렬되어 있다는 사실을 고려하여(merge sort 적용) 홀수 그룹들과 짝수그룹들을 각각 통합하여
올림차순으로 출력한다. 
// 올림차순으로 출력

마지막으로, 통합된 홀수그룹과 짝수그룹을 역시 정렬되어 있다는 사실을 고려하여
50개의 전체수를 올림차순으로 출력하는 프로그램 작성.
//또
 

A: 50미만의 홀수          B: 50이상의 홀수

C: 50미만의 짝수          D: 50이상의 짝수
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_num(int arr[20]){
    for(int i=0; i<20; i++){
        int temp = rand() % 100 +1;
        int is_duplicate = 0;
        for(int j=0; j<i; j++){
            if(arr[j] == temp){
                is_duplicate = 1;
                break;
            }
        }
        if(is_duplicate){
            i--;  // RE
        } else {
            arr[i] = temp;
        }
    }
    }
//랜덤으로 20개 생성띠

void classifi(int arr[20], int arr2[][20],int count[]){
    for(int i =0; i<20; i++){
        if(arr[i]<50 && arr[i]%2==1){
            arr2[0][count[0]++] = arr[i];
        }
        else if(arr[i]>=50 && arr[i]%2==1){
            arr2[1][count[1]++] = arr[i];
        }
        else if(arr[i]<50 && arr[i]%2==0){
            arr2[2][count[2]++] = arr[i];
        }
        else if(arr[i]>=50 && arr[i]%2==0){
            arr2[3][count[3]++] = arr[i];
        }
    }
}

/*
각 그룹을 올림차순으로 정렬하여 출력한다.
// 올림차순으로 정렬~
*/
void up_go(int arr[][20],int count,int size){ // 10개
    for(int i=0; i<size-1; i++){ //0<9 -> 0~8-> 9개
        for(int j=0; j<size-1-i; j++){ // 
            if(arr[count][j]>arr[count][j+1]){
                int temp = arr[count][j];
                arr[count][j] = arr[count][j+1];
                arr[count][j+1] = temp;
            }
        }// 1,2,3,4,0,0,0,0, 과 같은 형식일 것.
    }
}

void merge_sort(int arr[][20], int arr2[],int num1 , int num2,int arr3[],int *size){
    int A =0;
    int B =0;
    int hello =0;
    while(A<arr2[num1] && B<arr2[num2]){
        if(arr[num1][A]<arr[num2][B]){
            arr3[hello++] = arr[num1][A++];
        }
        else if(arr[num1][A]>arr[num2][B]){
            arr3[hello++] = arr[num2][B++];
        }
    }

    while(A < arr2[num1]){
        arr3[hello++] = arr[num1][A++];
    }
    while(B < arr2[num2]){
        arr3[hello++] = arr[num2][B++];
    }
    *size = hello;
}

int main(){
    srand((unsigned)time(NULL));
    int temp[20] ={0};
    int nums[4][20] ={0};
    // A.B,C,D : 0~19(최대20개)
   int count[4] ={0};

    rand_num(temp);

    classifi(temp, nums,count);

    for(int i=0; i<4; i++){
        up_go(nums,i,count[i]);
    }

    int hol[20] ={0};
    int hol_size =0;
    int jjak[20] = {0};
    int jjak_size =0;
    int final_num[20] = {0};
    int final_size =0;

   //홀수 먼저 정렬
   merge_sort(nums,count,0,1,hol,&hol_size); //홀수 끼리
   merge_sort(nums,count,2,3,jjak,&jjak_size); //짝수끼리


    int A = 0, B = 0, idx = 0;
    while(A < hol_size && B < jjak_size){
        if(hol[A] < jjak[B]){
            final_num[idx++] = hol[A++];
        } else {
            final_num[idx++] = jjak[B++];
        }
    }
    while(A < hol_size) final_num[idx++] = hol[A++];
    while(B < jjak_size) final_num[idx++] = jjak[B++];
    final_size = idx;

    printf("=== 최종 통합 (전체) ===\n");
    for(int i=0; i<final_size; i++) {
        printf("%d ", final_num[i]);
    }
    printf("\n");

    return 0;

}