/*
문제
    어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 
    그 수를 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. 
    min과 max가 주어지면, min보다 크거나 같고, 
    max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
    첫째 줄에 두 정수 min과 max가 주어진다.

출력
    첫째 줄에 min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수의 개수를 출력한다.

제한
    1 ≤ min ≤ 1,000,000,000,000
    min ≤ max ≤ min + 1,000,000
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min = 0;
    long long max = 0;

    cin>>min>>max;

    vector<long long> arr(max-min+1,0);

    long long answer = max-min+1;

    for(long long i=2;i*i<=max;i++){
        
        long long p = i*i;

        long long start_index = min/p;

        if(min%p!=0){
            start_index++;
        }
        
        for(long long j=start_index;p*j<=max;j++){
            arr[(int)((p*j)-min)]=1;
        }
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            answer--;
        }
    }

    cout<<answer;

    return 0;
}