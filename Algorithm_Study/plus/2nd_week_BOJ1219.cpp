#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> cityMoney;
vector<int> visited;

void dfs(int node){
    if(visited[node]==1){
        return ;
    }

    visited[node]=1;

    for(int i=0;i<graph[node].size();i++){
        dfs(graph[node][i].first);
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cityCount = 0;
    int start = 0;
    int end = 0;
    int trafficCount = 0;

    cin>>cityCount>>start>>end>>trafficCount;

    for(int i=0;i<cityCount;i++){
        vector<pair<int,int>> temp;
        graph.push_back(temp);
        visited.push_back(0);
    }

    for(int i=0;i<trafficCount;i++){
        int startCity=0;
        int endCity=0;
        int money=0;
        cin>>startCity>>endCity>>money;

        pair<int,int> tempPair = make_pair(endCity,money);

        graph[startCity].push_back(tempPair);
    }

    for(int i=0;i<cityCount;i++){
        int tempMoney=0;
        cin>>tempMoney;
        cityMoney.push_back(tempMoney);
    }

    dfs(start);

    if(visited[end]==0){
        cout<<"gg";
        return 0;
    }

    

    return 0;

}