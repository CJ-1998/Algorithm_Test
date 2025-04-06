/*
실패 버전
라면 큰 것 우선, 같은 라면 시 deadline 적은 것 선택
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    return a.second<b.second;
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

        pair<int,int> temp = make_pair(ramen, deadline);

        t.push_back(temp);
    }

    sort(t.begin(),t.end(),compare);

    // for(int i=0;i<t.size();i++){
    //     cout<<t[i].first<<" "<<t[i].second<<endl;
    // }
    
    int nowDay = 1;
    int maxRamen = 0;

    for(int i=0;i<t.size();i++){
        if(t[i].second>=nowDay){
            maxRamen+=t[i].first;
        }
        else{
            continue;
        }
        nowDay++;
    }

    cout<<maxRamen;

    return 0;
}