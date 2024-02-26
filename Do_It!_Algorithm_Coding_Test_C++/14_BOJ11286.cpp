/*
문제:
    절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.
        배열에 정수 x (x ≠ 0)를 넣는다. 
        배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 
        절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
    프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력:
    첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 
    다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
    만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, 
    x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 
    입력되는 정수는 -2^31보다 크고, 2^31보다 작다.

출력:
    입력에서 0이 주어진 회수만큼 답을 출력한다. 
    만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
*/

#include<iostream>
#include<queue>
#include<utility>
#include<cmath>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    int cnt=0;
    cin >> cnt;

    for(int i=0;i<cnt;i++){
        int temp=0;

        cin >> temp;

        if(temp==0){
            if(pq.empty()){
                cout << 0 << "\n";
                continue;
            }
            else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(make_pair(abs(temp), temp));
        }
    }

    return 0;
}

/*
개선할 점:
    1. 우선순위 큐에서 마지막에 비교 함수 직접 생성말고 greater<pair<int, int>>> 이렇게 해도 된다. 

배운 점:
    1. 우선순위 큐 사용 방법
    2. 비교 함수 사용 방법
*/