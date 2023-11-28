#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n=cards.size();
    int firstCards=n/3;
    int want=n+1;
    int answer = 0;
    int c=coin;

    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(cards[i]);
    }

    vector<int> myCard;
    for(int i=0;i<firstCards;i++){
        myCard.push_back(q.front());
        q.pop();
    }

    while(true){
        answer++;
        if(myCard.empty()){
            break;
        }
        int temp1=q.front();
        q.pop();
        int find1=want-temp1;

    }

    return answer;
}