#include <cstdio>

using namespace std;

int main(){
    int answer=0;

    int num=0;
    scanf("%d",&num);

    int temp=0;
    //temp는 가져간 바둑돌의 총 합이다.
    bool check=false;
    //푸앙이 차례가 false이다. 
    int i=1;
    //i는 늘어나는 바둑돌이다. 

    while(true){
        temp+=i;
        i++;
        check=!check;
        //1턴 진행하고 check가 바뀌어서 다음 사람 턴으로 간 것이다.

        if(temp+i>=num){
        //다음 턴에 문제가 생기면 

            if(!check){
            //다음 턴이 푸앙이인 경우
                if(temp+i==num){
                    break;
                }
                else{
                    answer=temp+i-num;
                    break;
                }
            }       
            else{
            //다음 턴이 친구인 경우
                if(temp+i==num){
                    answer=++i;
                    break;
                }
                else{
                    break;
                }
            } 
        }
    }

    printf("%d",answer);

    return 0;
}