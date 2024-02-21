/*
문제:
    N개의 수 A1, A2, ..., AN과 L이 주어진다.
    Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 
    이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.

입력:
    첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000)
    둘째 줄에는 N개의 수 Ai가 주어진다. (-10^9 ≤ Ai ≤ 10^9)

출력:
    첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<utility>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N=0;
    int L=0;

    cin>>N>>L;

    vector<int> v;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    vector<int> answer;
    deque<pair<int,int>> dq;

    dq.push_back(make_pair(0,v[0]));
    answer.push_back(v[0]);

    for(int i=1;i<N;i++){
        if((i-dq.front().first)>=L){
            dq.pop_front();
        }

        while(true){
            if(dq.empty()) break;
            if(dq.back().second>v[i]){
                dq.pop_back();
            }
            else{
                break;
            }
        }
        dq.push_back(make_pair(i,v[i]));
        
        answer.push_back(dq.front().second);
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    return 0;
}

/*
배운 점:
    1. dequeue 사용법
    2. pair 사용법
    3. min_element, max_element 사용법
    4. *min_element(v.begin()+i, v.begin()+j)); 하면 i~j-1에서 최소값을 준다.
*/