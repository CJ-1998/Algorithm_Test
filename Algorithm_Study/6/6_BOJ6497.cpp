#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include <limits.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m=0;
    int n=0;
    cin>>m>>n;

    vector<vector<pair<int,int>>> graph;
    vector<int> visited;
    vector<int> unvisited;

    for(int i=0;i<m;i++){
        vector<pair<int,int>> temp;
        graph.push_back(temp);
        visited.push_back(0);
    }

    for(int i=0;i<n;i++){
        int start=0;
        int end=0;
        int meter=0;

        cin>>start>>end>>meter;
        pair<int,int> toEnd = make_pair(end,meter);
        pair<int,int> toStart = make_pair(start,meter);

        graph[start].push_back(toEnd);
        graph[end].push_back(toStart);
    }
    
    int temp1=0;
    int temp2=0;
    cin>>temp1>>temp2;

    visited[0]=1;
    int answer=0;

    for(int i=0;i<m;i++){
        int min = INT_MAX;
        int minIndex = 0;
        for(int j=0;j<graph[i].size();j++){
            if(graph[i][j].second<min){
                min = graph[i][j].second;
                minIndex = graph[i][j].first;
            }
        }
        visited[minIndex]=1;
        answer+=min;
    }

    cout<<answer;
    return 0;
}