/*
(아직 못 품)
문제:
    정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
        X가 3으로 나누어 떨어지면, 3으로 나눈다.
        X가 2로 나누어 떨어지면, 2로 나눈다.
        1을 뺀다.
    정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 
    연산을 사용하는 횟수의 최솟값을 출력하시오

입력:
    첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

출력:
    첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000001];

int one(int num){
    int answer=0;

    if(num==1){
        return 0;
    }

    if(arr[num]!=0){
        return arr[num];
    }
    
    if(num%6==0){
        answer+=min(min(one(num/3),one(num/2)),one(num-1))+1;
        if(arr[num/6]>answer){
            arr[num/6]=answer;
        }
        return answer;
    }
    else if(num%3==0){
        answer+=min(one(num/3),one(num-1))+1;
        if(arr[num/3]>answer){
            arr[num/3]=answer;
        }
        return answer;
    }
    else if(num%2==0){
        answer+=min(one(num-1),one(num/2))+1;
        if(arr[num/2]>answer){
            arr[num/2]=answer;
        }
        return answer;
    }
    else{
        answer+=one(num-1)+1;
        if(arr[num-1]>answer){
            arr[num-1]=answer;
        }
        return answer;
    }

}

int main(){
    int num=0;
    scanf("%d",&num);
    printf("%d",one(num));
    return 0;
}