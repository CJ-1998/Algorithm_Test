/*
문제:
    수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
    즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력:
    첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)
    둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

출력:
    첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    int m=0;

    cin>>n>>m;

    vector<long> v;

    for(int i=0;i<n;i++){
        int temp=0;
        cin>>temp;
        v.push_back(temp);
    }

    vector<long> sum;
    sum.push_back(v[0]);

    for(int i=1;i<n;i++){
        long t=sum[i-1]+v[i];
        sum.push_back(t);
    }

    for(int i=0;i<sum.size();i++){
        sum[i]=sum[i]%m;
        //cout<<sum[i]<<endl;
    }

    long answer=0;
    sort(sum.begin(),sum.end());
    
    for(int i=0;i<sum.size();i++){
        if(sum[i]==0){
            answer++;
        }
    }

    vector<long> same(m,0);
    long first=sum[0];
    int cnt=0;

    for(int i=1;i<sum.size();i++){
        if(sum[i]==first){
            cnt++;
        }
        else{
            same.push_back(cnt+1);
            cnt=0;
            first=sum[i];
        }
    }
    same.push_back(cnt+1);

    // for(int i=0;i<sum.size();i++){
    //     same[sum[i]]++;
    // }

    for(int i=0;i<same.size();i++){
        same[i]=same[i]*(same[i]-1)/2;
    }

    for(int i=0;i<same.size();i++){
        answer+=same[i];
    }
    cout<<answer<<endl;

    return 0;
}

/*
배운 점:
    1. (A+B)%C == ((A%C)+(B%C))%C이다. 
        즉 구간 합의 나머지 연산은 특정 구간 수들의 나머지 연산 더해서 나머지 연산한 값과 같다는 것이다. 
    2. 구간 합 배열의 값을 M으로 나머지 연산했을 때 같은 값이 있는 곳 A, B가 있으면 A~B까지의 구간 합이 M으로 나눠 떨어진다는 것이다.
*/