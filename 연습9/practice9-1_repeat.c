/*
**#전역 변수 사용하지 말 것.**

**#모든 입출력은 main()에서 할 것**

[1] 30개의 점수(자연수:0~100)를 **무작위로 중복없이** 생성하여 내림차순으로 출력한 후, **이진탐색(binary search)**을 사용하여

사용자로부터 입력받은 한 점수의 **등수와 등수결정까지의 비교횟수**를 출력하는 프로그램을 작성(없으면 “NOT FOUND와 비교횟수” 출력)

**① 반복 방식**

**② 재귀호출 방식**
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int binary(int arr[], int target, int low, int high,int *p){
    while (low <= high)
    {
        int mid = (low+high) / 2 ;
        printf("범위: [%d ~ %d] | 중간값 인덱스: %d (값: %d)\n", low, high, mid, arr[mid]);

        if(arr[mid] == target){
            (*p)++;
            return mid+1;
        }
        else if (arr[mid]> target)
        {
            (*p)++;
            low = mid+1;
        }
        else if (arr[mid] < target)
        {
            (*p)++;
            high = mid -1;
        }
    }
    return -1;
}


int main(){
    int num[30];

    srand(time(NULL));

    // 30개의 자연수
    // 0-100 / 무작위/중복없이 / 생성

    for(int i=0; i<30; i++){ // 0-29까지
        int k =0;
        int random = rand() % 101; // 0-100을 생성하기 위해서
        for(int j=0; j<i; j++){
            if(num[j]== random){
                i --;
                k = 1;
                break;
            }       
        } // 0- i까지
        if(k==0) num[i] = random; // 저장
    }


    // 내림차순을 진행해볼까요?

    for(int i=0; i<30-1; i++){
        for(int j=i+1; j<30; j++){
            if(num[i]<num[j]){
                int temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
    // 내림차순 끝

    //사용자로부터 입력받은 한 점수의 등수와 등수 결정까지의 비교횟수를 출력하는 프로그램.

    int human =0;
    int count =0 ;
    int *p = &count;

    printf("inpur:");
    scanf("%d",&human);
    int final = binary(num, human, 0, 29,p);
    if(final == -1){
        printf("NOT FOUND\n");
    }
    else {
        printf("%d\n", final);
        printf("%d\n",*p);
    }

}