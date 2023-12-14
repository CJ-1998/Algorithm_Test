/*
문제:
    루트 없는 트리가 주어진다. 
    이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 
    둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력:
    첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> check;
vector<int> parent;

void dfs(int index, int parentIndex){
    if(check[index]==0){
        return;
    }

    check[index]=0;
    parent[index]=parentIndex+1;
    for(int i=0;i<graph[index].size();i++){
        dfs(graph[index][i], index);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    cin>>num;

    for(int i=0;i<num;i++){
        vector<int> temp;
        graph.push_back(temp);
        parent.push_back(-1);
        check.push_back(-1);
    }

    for(int i=0;i<num-1;i++){
        int a=0;
        int b=0;

        cin>>a>>b;

        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    dfs(0,0);

    for(int i=1;i<num;i++){
        cout<<parent[i]<<"\n";
    }

    return 0;
}