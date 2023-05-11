/*
문제:
    오늘도 서준이는 깊이 우선 탐색(DFS) 수업 조교를 하고 있다. 
    아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
    N개의 정점과 M개의 간선으로 구성된 무방향 그래프(undirected graph)가 주어진다. 
    정점 번호는 1번부터 N번이고 모든 간선의 가중치는 1이다. 
    정점 R에서 시작하여 깊이 우선 탐색으로 노드를 방문할 경우 노드의 방문 순서를 출력하자.
    깊이 우선 탐색 의사 코드는 다음과 같다. 
    인접 정점은 오름차순으로 방문한다.

입력:
    첫째 줄에 정점의 수 N (5 ≤ N ≤ 100,000), 간선의 수 M (1 ≤ M ≤ 200,000), 시작 정점 R (1 ≤ R ≤ N)이 주어진다.
    다음 M개 줄에 간선 정보 u v가 주어지며 정점 u와 정점 v의 가중치 1인 양방향 간선을 나타낸다. 
    (1 ≤ u < v ≤ N, u ≠ v) 모든 간선의 (u, v) 쌍의 값은 서로 다르다.

출력:   
    첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다. 
    i번째 줄에는 정점 i의 방문 순서를 출력한다. 
    시작 정점의 방문 순서는 1이다. 
    시작 정점에서 방문할 수 없는 경우 0을 출력한다.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>* g;
bool* dfs_visit;
int* answer;
int index;

void dfs(int start){
    if(dfs_visit[start]){
        return;
    }

    dfs_visit[start]=true;

    answer[start]=index++;

    for(int i=0;i<g[start].size();i++){
        dfs(g[start][i]);
    }

}

int main(){
    int v, e, start;
    //cin>>v>>e>>start;

    scanf("%d %d %d",&v,&e,&start);

    index=1;

    g=new vector<int>[v];
    dfs_visit=new bool[v];
    answer=new int[v];
    
    for(int i=0;i<v;i++){
        vector<int> temp;
        g[i]=temp;
        dfs_visit[i]=false;
        answer[i]=0;
    }

    for(int i=0;i<e;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d %d",&a,&b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for(int i=0;i<v;i++){
        sort(g[i].begin(),g[i].end());
    }

    dfs(start-1);

    for(int i=0;i<v;i++){
        //cout<<answer[i]<<endl;
        printf("%d\n",answer[i]);
    }

    return 0;
}