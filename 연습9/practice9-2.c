/*
#전역 변수 사용하지 말 것.

#모든 입출력은 main()에서 할 것

[2] 입력받은 문자열(1~50자)내에 있는 substring(1~50자의 문자열로 입력받음)의 갯수를 출력한 후에 각각 문자열 내의 몇 번째 위치에서 발견되었는지를 출력하는 프로그램을 작성

(없으면 “NOT FOUND” 출력)

㈜ 입력 문자열은 blank, tab, 알파벳으로 구성되며 나타나는 순서와 빈도수는 제한 없음

* 입력예시: string: abbababb aba ab

substring:ab

* 출력예시: 5 ab found

1:[2] 2:[5] 3:[7] 4:[11] 5:[16]

 
*/

#include <stdio.h>
#include <string.h>

void buffer(char arr[]){
     int len = strlen(arr);

    if(len > 0 && arr[len-1] == '\n'){
        arr[len-1] = '\0';
    } // 만약 마지막에 \n가 있다면?

    else{
        while(getchar() !='\n'); // 엔터가 나올때까지 먹어치움.
    }

    // 현상태: str까지 입력받은 상태

    
}


int main(){

    char str[51]; // 50개 입력받고 + \n까지 고려함.
    char substr[51]; // 위에와 똑같
    

    printf("string:");
    fgets(str, sizeof(str), stdin); // str 배열에, strlen(str) -> 51인데 51-1만큼 입력을 받을거에여, stdin은 키보드
    // 디버깅 용도
    printf("%s\n", str);
    // 어떻게 입력받은 것을 마무리할 것인가?
    //50개를 다 입력하고 버퍼를 치면 50글자는 배열로 + /0이 됨 /n은 버퍼에 남는다.
    // 그래서 30개정도 하고 그러면 배열에 ~~~ \n \0으로 남게 됨.

    buffer(str);

    printf("substring:");
    fgets(substr, sizeof(substr), stdin);
    buffer(substr);


    // 비교를 들어가야하는데....

    int len_str = strlen(str);
    int len_substr = strlen(substr);
    int count =0;
    int location[50] ={0};
   


    for(int i=0; i<len_str; i++){
         int match =1;
        for(int j=0; j<len_substr; j++){
            if(str[i+j] != substr[j]){
                match =0;
                break;
            } 
        }

        if(match ==1){
            location[count] = i+len_substr;
            count ++;
        }
    }


    if(count >0){
        printf("%d %s found\n", count, substr);

         for(int i=0; i<count; i++){
        printf("%d:[%d] ",i+1, location[i]);
    }
        printf("\n");
    }

    else{
        printf("NOT FOUND\n");
    }


}
