/*
문제
    정렬된 두 묶음의 숫자 카드가 있다고 하자. 
    각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 
    이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.
    
    매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 
    이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 
    예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 
    (10 + 20) + (30 + 40) = 100번의 비교가 필요하다. 
    그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 
    (10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.

    N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000) 
    이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다. 
    숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수이다.

출력
    첫째 줄에 최소 비교 횟수를 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=0;
    cin>>cnt;

    // sort(v.begin(),v.end());

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<cnt;i++){
        int temp=0;
        cin>>temp;
        pq.push(temp);
    }

    int answer=0;
    while(pq.size()!=1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        pq.push(a+b);
        answer+=a+b;
    }

    // if(answer==v[0])
    //     answer=0;

    cout<<answer;

    return 0;
}

/*
배운 점:
    1. 우선순위 큐 사용법 
    2. 우선순위 큐 초기화 : priority_queue<int, vector<int>, greater<int>> pq;
    3. 우선순위 큐 삽입 : pq.push();
    4. 우선순위 큐 빼기 : pq.pop();
    5. 우선순위 큐 사용은 queue와 같이 사용하면 된다. 
    6. 우선순위 큐는 삽입하면 비교 함수에 따라 내부적으로 정렬이 된다.
*/