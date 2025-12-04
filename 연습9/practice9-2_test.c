/*
#전역 변수 사용하지 말 것.

#모든 입출력은 main()에서 할 것

[2] 입력받은 문자열(1~50자)내에 있는 substring(1~50자의 문자열로 입력받음)의 갯수를 출력한 후에 각각 문자열 내의 몇 번째 위치에서 발견되었는지를 출력하는 프로그램을 작성

(없으면 “NOT FOUND” 출력)

㈜ 입력 문자열은 blank, tab, 알파벳으로 구성되며 나타나는 순서와 빈도수는 제한 없음

* 입력예시: string: abbababb aba ab

substring:ab

* 출력예시: 5 ab found

1:[2] 1, 2:[5] 3:[7] 4:[11] 5:[16]

 
*/

#include <stdio.h>
#include <string.h>

int main(){

    char string[11];
    char substring[11];


    printf("string:");
    fgets(string,sizeof(string), stdin);
    // 디버깅 용도
    printf("%s\n",string);

    printf("%ld\n",strlen(string));

    printf("--- 버퍼 확인 시작 ---\n");
    
    char c;
    while(1) { // 무조건 계속 돌아라! (일단은)
        c = getchar(); // 1. 하나 꺼낸다
        
        // 2. 내용물 출력 (문자와 번호 동시 출력)
        printf("꺼낸 문자: '%c' (번호: %d)\n", c, c);

        // 3. 종료 조건: 엔터거나 EOF(입력 끝)면 탈출
        if(c == '\n' || c == EOF) {
            break;
        }
    }
    
    printf("--- 버퍼 확인 끝 ---\n");

    printf("%ld\n",strlen(string));

    // 1. 길이 재기
int len = strlen(string);

// 2. 마지막 글자가 '엔터'인지 확인!
if (len > 0 && string[len - 1] == '\n') {
    // 상황 A: 엔터가 잘 들어옴 -> 엔터를 지워줌
    string[len - 1] = '\0';
} 
else {
    // 상황 B: 엔터가 없음 (꽉 참) -> 버퍼에 남은 찌꺼기(엔터 포함) 청소
    while (getchar() != '\n'); 
}



    printf("--- 버퍼 확인 시작 ---\n");
    
    while(1) { // 무조건 계속 돌아라! (일단은)
        c = getchar(); // 1. 하나 꺼낸다
        
        // 2. 내용물 출력 (문자와 번호 동시 출력)
        printf("꺼낸 문자: '%c' (번호: %d)\n", c, c);

        // 3. 종료 조건: 엔터거나 EOF(입력 끝)면 탈출
        if(c == '\n' || c == EOF) {
            break;
        }
    }
    return 0;
}
