/*
문제:
    N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력:
    첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 
    다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
    다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
    다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
    모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.

출력:
    M개의 줄에 답을 출력한다. 
    존재하면 1을, 존재하지 않으면 0을 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int findNum(int num){

    int left=0;
    int right=arr.size()-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(arr[mid]==num){
            return 1;
        }else if(arr[mid]>num){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return 0;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    arr.resize(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int m=0;
    cin>>m;

    for(int i=0; i<m; i++){ 

        int num;
        cin>>num;

        cout<<findNum(num)<<'\n';

    }

    return 0;
}

/*
개선할 점:
    이진 탐색하는 것 굳이 함수로 안 빼도 되는 것 같다. 함수로 빼면 더 시간 늘어날지도 모르겠다. 

배운 점:
    1. 이분 탐색 탈출 조건은 left>right이다. 
    2. 시간초과 아슬하면 cin, cout 빨라지는 것 넣어야 한다.
*/