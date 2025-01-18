/*
문제
    N×M크기의 직사각형이 있다. 
    각 칸에는 한 자리 숫자가 적혀 있다. 
    이 직사각형에서 꼭짓점에 쓰여 있는 수가 
    모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 
    이때, 정사각형은 행 또는 열에 평행해야 한다.

입력
    첫째 줄에 N과 M이 주어진다. 
    N과 M은 50보다 작거나 같은 자연수이다. 
    둘째 줄부터 N개의 줄에 수가 주어진다.

출력
    첫째 줄에 정답 정사각형의 크기를 출력한다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=0;
    int m=0;

    cin>>n>>m;

    vector<vector<int>> arr;

    for(int i=0;i<n;i++){
        vector<int> temp;
        string t="";
        cin>>t;
        for(int j=0;j<m;j++){
            temp.push_back(t[j]-'0');
        }
        arr.push_back(temp);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> answer;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                if(arr[i][j]==arr[i][k]){
                    int len = k-j+1;
                    if(i+len-1<n){
                        if(arr[i][j]==arr[i+len-1][j]&&arr[i][j]==arr[i+len-1][k]){
                            answer.push_back(len*len);
                        }
                    }
                }
            }
        }
    }

    // for(int i=0;i<answer.size();i++){
    //     cout<<answer[i]<<endl;
    // }

    if(answer.size()==0){
        cout<<1;
    }

    else{
        sort(answer.begin(),answer.end(),greater<int>());

        cout<<answer[0]; 
    }

    return 0;
}

/*
풀이 방법 :
    50*50이 최대라 싹 돌아도 50^4라 2차원 배열 다 돌았음
*/