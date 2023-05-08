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

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];

int main(){

    arr[1]=0;
    
    int cnt=0;
    cin>>cnt;

    for(int i=2;i<=cnt;i++){
        int one=987654321;
        int two=987654321;
        int minus=987654321;

        if(i%3==0){
            one=1+arr[i/3];
        }
        if(i%2==0){
            two=1+arr[i/2];
        }
        
        minus=1+arr[i-1];
        

        int result=min(min(one,two),minus);
        arr[i]=result;
    }

    cout<<arr[cnt]<<endl;

    return 0;
}

/*
배운 점:
    1. top down 방식보다 bottom up 방식이 시간이 좀 더 빠를 수 있다고 한다. 
    2. 동적 프로그래밍에서는 작은 문제가 반복해서 일어나고 같은 문제는 구할 때마다 정답이 같다고 한다. 
    그래서 한번 계산한 작은 문제를 저장해 놓고 다시 사용한다고 한다. 
    이것이 memozation이다.
*/