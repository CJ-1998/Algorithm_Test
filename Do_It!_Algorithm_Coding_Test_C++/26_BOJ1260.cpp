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

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> dfsCheck;
vector<int> bfsCheck;

void dfs(int start){
    if(dfsCheck[start]==1){
        return;
    }

    dfsCheck[start]=1;

    cout<<start+1<<" ";

    for(int i=0;i<graph[start].size();i++){
        dfs(graph[start][i]);
    }
}

void bfs(int start){
    queue<int> bfsQueue;

    bfsQueue.push(start);

    while(!bfsQueue.empty()){
        int temp=bfsQueue.front();
        if(bfsCheck[temp]==1){
            bfsQueue.pop();
            continue;
        }

        bfsQueue.pop();
        bfsCheck[temp]=1;

        cout<<temp+1<<" ";

        for(int i=0;i<graph[temp].size();i++){
            bfsQueue.push(graph[temp][i]);
        }
    }
}

int main(){

    int node=0;
    int edge=0;
    int start=0;

    cin>>node>>edge>>start;

    for(int i=0;i<node;i++){
        vector<int> temp;
        graph.push_back(temp);
        dfsCheck.push_back(0);
        bfsCheck.push_back(0);
    }

    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for(int i=0;i<node;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(start-1);
    cout<<endl;
    bfs(start-1);


    return 0;
}

/*
배운 점:
    1. BFS 양방향일 때 이미 지난 것 체크하는 부분 있어야 한다. 없으면 무한 루프 나온다. 
*/