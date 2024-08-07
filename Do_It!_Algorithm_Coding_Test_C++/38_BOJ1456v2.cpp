/*
문제
    어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.
    두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

입력
    첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다.

출력
    첫째 줄에 총 몇 개가 있는지 출력한다.
*/

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    long start=0;
    long end=0;
    cin>>start>>end;
    int count=0;

    vector<int> v(sqrt(end)+1,1);

    v[0]=0;
    v[1]=0;

    vector<int> temp;

    for(int i=2;i<=sqrt(end);i++){
        if(v[i]!=0){
            for(int j=i+i;j<=sqrt(end);j=j+i){
                v[j]=0;
            }
        temp.push_back(i);
        }
    }

    for(int i=0;i<temp.size();i++){
        long t=temp[i];
        while((double)temp[i]<=(double)end/(double)t){
            if((double)temp[i]>=(double)start/(double)t)
                count++;
            t=t*temp[i];    
        }
    }

    cout<<count;

    return 0;
}

/*
1차 틀린 이유:
    1. start~end 사이 소수 다 구해서 거기에서 제곱, 세제곱... 해서 end보다 작은 것 구함 -> 5324~894739는 0개 나옴
    2. 2~end 제곱근 사이 소수 구한 후 제곱, 세제곱... 해서 end보다 작은 것 구함 -> 5324~894739에서 5324보다 작은 것도 개수 더함
    3. 2~end 제곱근 사이 소수 구한 후 제곱, 세제곱... 해서 start~end 범위에 있는 것 구함 -> 시간 초과, 에라토스테네스의 체 공부해야 할 것 같음

1차 푼 시간:
    43m40s

배운 점:
    1. 에라토스테네스 채 
    2. 곱하기, 나누기의 속도 차이
*/