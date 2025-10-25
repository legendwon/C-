/*
[3] 3줄의 문자열을 줄별로 입력받아 각 줄별로 단어 갯수와 평균 단어길이를 (소수 2째자리) 출력한 후, 
3줄 전체의 단어 갯수와 평균 단어길이를 (소수 2째자리) 출력하는 프로그램 작성


㈜ 각 줄의 입력 문자는 알파벳, blank, tab, CR(Carriage Return)로 구성되며 이들 간에 나타나는 순서와 빈도수는 제한 없음

 

* 다양한 형태의 입력 데이터로 test 할 것

* 입력예시:

abc bc  aaa  a  g mm  ‘\n’

     jksj j    k     lo jj    kk    ’\n’ 등등*/


#include <stdio.h>

int main(){
     //int letter =0;
     //int avg_letter =0;
     int all_letter =0;
     int avg_all_letter =0;
     int all_word = 0;
     char ch;
     int lines =3;
     

     for(int i=0; i<lines; i++){
          int letter =0;
          int avg_letter =0;
          int word =0;
          int SY = 0;
          printf("줄을 입력하시오:");
          while ((ch= getchar()) != '\n')
          {
               if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                    letter ++;
                    SY =1;

               }
               else if((ch == ' ') || ch =='\t'){
                    if(SY ==1)
                    {
                         word ++;
                         SY = 0;
                    }
                    else if(SY == 0){
                         
                    }

               }
               else if (ch == '\r'){
                    letter = 0;
                    word =0;
                    SY =0;
               }

          }
          if (SY ==1){
               word ++;
          }

          all_letter += letter;
          all_word += word;
          printf("단어의 갯수:%d\n",word);
          //word가 0일 수 있다는 것을 체크하고 넘어갈 것
          printf("평균 단어 길이:%.2lf\n",(double)letter / word);
     }

     printf("전체 단어 갯수: %d\n", all_word);
     printf("전체 평균 단어 길이%.2lf\n", (double)all_letter/ all_word);

}