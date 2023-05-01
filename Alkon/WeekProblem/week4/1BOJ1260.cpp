/*
문제:
    그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
    단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
    정점 번호는 1번부터 N번까지이다.

입력:
    첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
    다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
    어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
    입력으로 주어지는 간선은 양방향이다.

출력:
    첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
    V부터 방문된 점을 순서대로 출력하면 된다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define NODE 1001

using namespace std;

vector<vector<int>> graph;
bool dfs_visit[NODE];

void dfs(int cur_node){
    if(dfs_visit[cur_node])
        return;

    dfs_visit[cur_node]=true;

    cout<<cur_node+1<<" ";

    for(int i=0;i<graph[cur_node].size();i++){
        dfs(graph[cur_node][i]);
    }
}

queue<int> q;
bool bfs_visit[NODE];
int cur_node;

void bfs(int start_node){
    q.push(start_node);
    bfs_visit[start_node]=true;

    while(!q.empty()){
        cur_node=q.front();
        q.pop();
        cout<<cur_node+1<<" ";

        for(int i=0;i<graph[cur_node].size();i++){
            if(!bfs_visit[graph[cur_node][i]]){
                q.push(graph[cur_node][i]);
                bfs_visit[graph[cur_node][i]]=true;
            }
        }
    }
}

int main(){

    int n, m;
    cin>>n>>m;

    int start;
    cin>>start;

    for(int i=0;i<n;i++){
        dfs_visit[i]=false;
        bfs_visit[i]=false;
    }

    for(int i=0;i<n;i++){
        vector<int> temp;
        graph.push_back(temp);
    }

    for(int i=0;i<m;i++){
        int temp1, temp2;
        cin>>temp1>>temp2;

        graph[temp1-1].push_back(temp2-1);
        graph[temp2-1].push_back(temp1-1);
    }

    for(int i=0;i<n;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(start-1);
    cout<<endl;
    bfs(start-1);
    cout<<endl;

    return 0;
}

/*
개선 사항:
    1. 그래프 담는 자료 구조를 vector<vector>가 아니라 vector<int> 배열로 하면 좋다. 

배운 점:
    1. DFS, BFS 개념
*/