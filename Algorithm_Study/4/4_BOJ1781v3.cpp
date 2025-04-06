/*
실패 버전
deadline 짧은 것 우선, 같은 deadline 시 라면 큰 것 선택
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=0;
    cin>>n;

    vector<pair<int,int>> t;

    for(int i=0;i<n;i++){
        int deadline=0;
        int ramen=0;

        cin>>deadline>>ramen;

        pair<int,int> temp = make_pair(deadline, ramen);

        t.push_back(temp);
    }

    sort(t.begin(),t.end(),compare);

    queue<pair<int,int>> q;

    for(int i=0;i<t.size();i++){
        q.push(t[i]);
    }
    
    int nowDay = 1;
    int maxRamen = 0;

    int index = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

    while(true){
        if(q.empty()&&pq.empty()){
            break;
        }
        if(q.front().first==nowDay){
            pq.push(q.front());
            q.pop();
        }
        else{
            if(!pq.empty()){
                maxRamen+=pq.top().second;
                while(!pq.empty()){
                    pq.pop();
                }
            }
            nowDay++;           
        }
    }

    cout<<maxRamen;

    return 0;
}