/*[2] 다음의 서울에서 제주 일일 항공편 스케줄을 참고하여 
사용자로부터 입력받은 시간 전후로 가장 가까운 항공편의 
출도착 시간을 출력하는 프로그램 작성

출발           도착

8:00 a.m. 10:16 a.m.

9:43 a.m. 11:52 a.m.

11:19 a.m. 1:31 p.m.

12:47 p.m. 3:00 p.m.

2:00 p.m. 4:08 p.m.

3:45 p.m. 5:55 p.m.

7:00 p.m. 9:20 p.m.

9:45 p.m. 11:58 p.m.

입력예시: 19:50

출력예시: 7:00 p.m. 9:20 p.m.*/

#include <stdio.h>
# include <stdlib.h>

int main(){
    int hour =0;
    int minute = 0;

    printf("ex)19:50 입력: ");
    scanf("%d : %d",&hour,&minute);
    
    //DEBUG
    printf("%d,%d\n",hour, minute);

    //19로 입력을 받았다면, PM으로 돌리는 작업을 해야하는데
    // 차라리 PM인 것들을 모두 1N시 이렇게 바꾸는 게 나을 듯

    // 1차로 가장 가까운 항공편이라는 기준이 무엇일까?
    // 시간이 가장 가까운 것 아님..ㅇㅇ
    // 시간은 분 단위로 환산할 수 있음.
    // 00:00기준으로 단위가 분 인것으로 모두 치환이 가능할 것임.
    
    int a = 60*8;
    int b = 60*9 + 43;
    int c = 60*11 + 19;
    int d = 60*12+ 47;
    int e = 60* 14;
    int f = 60*15 + 45;
    int g = 60* 19;
    int h = 60* 21+ 45;

    int customer = 60*hour + minute;

    a = abs(customer-a);
    b = abs(customer-b);
    c = abs(customer-c);
    d = abs(customer-d);
    e = abs(customer-e);
    f = abs(customer-f);
    g = abs(customer-g);
    h = abs(customer-h);

    int final1 =0;
    int final2 =0;
    int final3 =0;
    int final4 =0;

    if(a>b){
        final1 = b;
    }
    else{
        final1=a;
    }

    if(c>d){
        final2 = d;
    }
    else{
        final2=c;
    }

    if(e>f){
        final3 = f;
    }
    else{
        final3=e;
    }

    if(g>h){
        final4=h;
    }
    else{
        final4 = g;
    }
    
    if (final1>final2)
    {
        final1 = final2;
    }
    else{
        final1 = final1;
    }
    
    if (final3>final4)
    {
        final2 = final4;
    }
    else{
        final2 = final3;
    }
    
    if(final1>final2){
        final1 = final2;
    }
    else{
        final1 = final1;
    }

    if (final1== a){
        printf("8:00 a.m.");
    }
    else if (final1 ==b)
    {
        printf("9:43 a.m.");
    }
    else if (final1 ==c)
    {
        printf("11:19 a.m.");
    }
    else if (final1 ==d)
    {
        printf("12:47 p.m.");
    }
    else if (final1 ==e)
    {
        printf("2:00 p.m.");
    }
    else if (final1 ==f)
    {
        printf("3:45 p.m.");
    }
    else if (final1 ==g)
    {
        printf("7:00 p.m.");
    }
    else if (final1 ==h)
    {
        printf("9:45 p.m.");
    }
    
}