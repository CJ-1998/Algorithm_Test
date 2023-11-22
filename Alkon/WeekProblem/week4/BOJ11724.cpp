/*
문제:
    방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
    둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력:
    첫째 줄에 연결 요소의 개수를 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;

vector<int> check;

int dfs(int node){
    if(check[node]==1){
        return 0;
    }

    check[node]=1;

    for(int i=0;i<graph[node].size();i++){
        dfs(graph[node][i]);
    }
    return 1;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node=0;
    int edge=0;

    cin>>node>>edge;

    for(int i=0;i<node;i++){
        vector<int> temp;
        graph.push_back(temp);
        check.push_back(0);
    }

    for(int i=0;i<edge;i++){
        int start=0;
        int end=0;
        cin>>start>>end;
        start--;
        end--;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int answer=0;
    for(int i=0;i<node;i++){
        // if(check[i]==0){
        //     dfs(i);
        //     answer++;
        // }
        answer+=dfs(i);
        
        // for(int j=0;j<node;j++){
        //     cout<<check[j]<<" ";
        // }
        // cout<<endl;
        // cout<<answer<<endl;
    }
    cout<<answer<<endl;

    return 0;
}

/*
배운 점:
    1.  이전 코드에서는 start->end edge 하나만 저장해서 방향 그래프처럼 되었다.
        그래서 입력이 3 2 1 2 3 2 경우 dfs 하면 1과 3이 연결되어 있지 않다고 판단이 된다. 
        그래서 다른 연결요소로 체크 될 수 있어 틀렸다. 
        문제에서 방향 그래프인지 아닌지 체크하고 구현해야 할 것 같다. 
*/