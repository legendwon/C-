/*
[1] 20명 학생의 점수(0~100)를 무작위로 생성한 후에 다음과 같이 그룹으로 분류한다.

각 그룹의 학생수 내림차순으로 해당 그룹명과 학생수를 출력하는 프로그램 작성.

(동일 학생수를 갖는 그룹들은 그룹의 알파벳 올림차순으로 출력)

         90이상: A,   80이상: B,    70이상: C,    60이상: D, .....,  10이상:I,    10미만: J

**출력 예시: B:5  C:4  A:3  F:3  G:3  H:1  J:1  D:0  E:0  I:0
*/

// 이제 배열을 사용할 수 있으니 사용해볼까요?


void merge(int arr[],int grade[],int left, int mid, int right){
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
            grade[k++] = i++;
        }
        else{
            arr[k++] = R[j++];
            grade[k++] = j++;
        }
    }

    while (i<n1)
    {
        arr[k++] = L[i++];
         grade[k++] = i++;
    }
    
    while (j<n2)
    {
        arr[k++] = R[j++];
        grade[k++] = j++;

    }

}

void mergesort(int arr[],int grade[] int left, int right){
    if(left<right){
        int mid = left + (right-left) /2;
        mergesort(arr,grade,left,mid);
        mergesort(arr,grade,mid+1, right);
        merge(arr,grade,left,mid,right);

    }
}


#include<stdio.h>
#include <time.h> 
#include <stdlib.h> // srand, rand를 사용하기 위한 헤더 파일
int sorted[20];
int main(){

    int grade[10];

    for (int i=0; i<<10; i++){
        grade[i] =i; // i =0 -> 0이 들어가는데, F라고 생각, i=9 -> A라고 생각
    }


    int STUDENT = 20;
    int score[20] = {0}; //성적
    int group[10] = {0}; //학생들
    int original_group[10];
    srand(time(NULL)); //시간을 seed로 넣어 난수 초기화

    for (int i=0; i< STUDENT; i++){
        int random = rand() % 101; //0~100 사이의 랜덤 숫자
        printf("DEBUG:%d\n",random); // 디버깅용
        score[i] = random;
        int index = (random == 100) ? 9 : random/10;
        group[index]++; // index = 9 이면 90점 이상 친구들
    }

    for(int i=0; i<10; i++){
    original_group[i] = group[i];
  }

    mergesort(group,grade 0, 9);

    for(int i=0; i<10; i++){
    printf("%d\n", group[i]);
  }
  // group[9] => 90점 이상, 즉, A를 의미함.

    /*
    // merge sort를 통해서 하고 싶은데, 일단 사실 잘 이해가 가지 않는다.
    // 그래서 일단 merge sort의 수도 코드를 따라하도록 하자.
    // function mergesort(list,left, right)
        middle = (left+right) /2 -> 중간 지점을 구하고
        mergesort(list, left, mid) -> 전반부를 정렬하고
        -> 또 mergesort가 있으므로 크기가 1이 될 때까지 계속 반복될 것이다.
        mergesort(list, mid+1, right)-> 똑같이 후반부를 정렬하고
        merge(list, left, mid, right) -> 합병한다.
    */


}