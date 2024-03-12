/*
문제:
    방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
    둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 
    같은 간선은 한 번만 주어진다.

출력:
    첫째 줄에 연결 요소의 개수를 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> check;

int dfs(int index){
    if(check[index]==1){
        return 0;
    }

    int answer=1;
    check[index]=1;

    for(int i=0;i<graph[index].size();i++){
        answer+=dfs(graph[index][i]);
    }

    return answer;
}

int main(){

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        vector<int> temp;
        graph.push_back(temp);
        check.push_back(0);
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    int answer=0;
    for(int i=0;i<n;i++){
        if(dfs(i)!=0){
            answer++;
        }
    }

    cout<<answer<<endl;
    

    return 0;
}

/*
배운 점:
    1. 그래프의 연결된 노드의 개수를 찾을 때에는 linkedlist로 구현한 그래프가 나은 것 같다. 
    2. 2차원 배열 형태로 구현한 그래프로는 어떻게 풀지 잘 모르겠다. 
*/