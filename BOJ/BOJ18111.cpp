/*
실패. 문제 풀이 중

현재 미구현 부분
1. 0<=땅의 높이<256
2. 1 7 10
    65 64 64 64 63 62 0
    정답 : 148 56 
이 부분에서 무한 루프 걸린다. 
로직을 다시 잘 생각하고 짜봐야 할 것 같다.  
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){

    int m, n, b;
    cin>>m>>n>>b;

    vector<vector<int>> v;

    for(int i=0;i<m;i++){
        vector<int> temp;
        v.push_back(temp);
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }

    int high = 0;
    int hignNum = 0;
    int highCnt = 0;
    int low = 257;
    int lowNum = 0;
    int lowCnt = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]>high){
                high = v[i][j];
            }

             if(v[i][j]<low){
                low = v[i][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]<high){
                lowNum++;
                lowCnt+=high-v[i][j];
            }

            if(v[i][j]>low){
                hignNum++;
                highCnt+=v[i][j]-low;
            }
        }
    }

    int time=0;
    int height=0;

    if(b>=lowCnt){
        if(lowCnt<=2*highCnt){
            time = lowCnt;
            height = high;
        }
        else{
            time = 2*highCnt;
            height = low;
        }
    }
    else{
        // time=2*highCnt;
        // height=low;

        int iterCnt=0;
        int tempHigh=high;
        while(true){
            iterCnt++;
            int highest=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(v[i][j]==tempHigh){
                        highest++;
                        v[i][j]--;
                    }
                }
            }

            lowCnt-=(m*n)-highest;
            if(lowCnt<=b+highest){
                time+=(highest*2)+lowCnt;
                height=tempHigh-1;
                break;
            }
            else{
                time+=(highest*2)+b+highest;
                lowCnt+=b+highest;
                tempHigh--;
                b=0;
            }
        }

    }

    cout<<time<<" "<<height;

    return 0;
}