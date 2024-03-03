/*
문제:
    수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.
        산술평균 : N개의 수들의 합을 N으로 나눈 값
        중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
        최빈값 : N개의 수들 중 가장 많이 나타나는 값
        범위 : N개의 수들 중 최댓값과 최솟값의 차이
    N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
    단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 
    입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력:
    첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
    둘째 줄에는 중앙값을 출력한다.
    셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
    넷째 줄에는 범위를 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    int n=0;
    cin>>n;
    
    vector<int> v(n);
    vector<int> cnt(8001);

    double sum=0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        if(v[i]>=0){    
            cnt[v[i]+4000]++;
        }
        else{
            cnt[(-1*v[i])-1]++;
        }
    }

    double avg=0;
    int middle=0;
    int freq=0;
    int range=0;

    sort(v.begin(),v.end());
    
    avg=sum/(double)n;
    avg=round(avg);
    
    if(avg==-0){
        avg=0;
    }

    int mid=(n-1)/2;
    middle=v[mid];
    range=v[n-1]-v[0];

    vector<int> freqVec;
    int max=0;
    for(int i=0;i<8001;i++){
        if(max<cnt[i]){
            max=cnt[i];
        }
    }

    // cout<<max<<endl;

    for(int i=0;i<8001;i++){
        if(cnt[i]==max){
            if(i<4000){
                freqVec.push_back(-1*(i+1));
            }
            else{
                freqVec.push_back(i-4000);
            }
        }
    }

    sort(freqVec.begin(),freqVec.end());
    // for(int i=0;i<freqVec.size();i++){
    //     cout<<freqVec[i]<<" ";
    // }
    // cout<<endl;

    if(freqVec.size()>1)
        freq=freqVec[1];
    else
        freq=freqVec[0];

    cout<<avg<<"\n"<<middle<<"\n"<<freq<<"\n"<<range<<"\n";

    return 0;
}