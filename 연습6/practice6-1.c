/*
[1] 20명 학생의 점수(0~100)를 무작위로 생성한 후에 다음과 같이 그룹으로 분류한다.

각 그룹의 학생수 내림차순으로 해당 그룹명과 학생수를 출력하는 프로그램 작성.

(동일 학생수를 갖는 그룹들은 그룹의 알파벳 올림차순으로 출력)

         90이상: A,   80이상: B,    70이상: C,    60이상: D, .....,  10이상:I,    10미만: J

**출력 예시: B:5  C:4  A:3  F:3  G:3  H:1  J:1  D:0  E:0  I:0
*/


// 이제 배열을 사용할 수 있으니 사용해볼까요?

void merge(int list[], int left, int mid, int right){
    int i,j,k,l;
    i= left;
    j = mid+1;
    k= left;

    while (i<=mid && j<=right)
    {
        if(list[i]<=list[j])
            sorted[k++]= list[i++];
        else
            sorted[k++] = list[j++];
    }
    // 남아 있는 값들을 일괄 복사
    if(i>mid){
        for(l=j; l<=right; l++)
        sorted[k++] = list[l];
    }
  // 남아 있는 값들을 일괄 복사
    else{
        for(l=i; l<=mid; l++)
        sorted[k++] = list[l];
    }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
    
}

void merge_sort(int list[], int left, int right){
    int mid;

    if (left <right){
        mid = (left + right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}



#include<stdio.h>
#include <time.h> 
int sorted[20];
int main(){


    int STUDENT = 20;
    int score[20] = {0};
    int group[10] = {0};
    srand(time(NULL)); //시간을 seed로 넣어 난수 초기화

    for (int i=0; i< STUDENT; i++){
        int random = rand() % 101; //0~100 사이의 랜덤 숫자
        printf("DEBUG:%d\n",random); // 디버깅용
        score[i] = random;
        int index = (random == 100) ? 9 : random/10;
        group[index]++;
    }

    merge_sort(group, 0, 9);
    for(int i=0; i<9; i++){
    printf("%d\n", group[i]);
  }


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