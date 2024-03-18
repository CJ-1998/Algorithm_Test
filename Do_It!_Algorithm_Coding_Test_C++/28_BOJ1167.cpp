/*
문제:
    트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력:
    트리가 입력으로 주어진다. 
    먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)
    둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 
    정점 번호는 1부터 V까지 매겨져 있다.
    먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
    하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 
    예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 
    정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 
    각 줄의 마지막에는 -1이 입력으로 주어진다. 
    주어지는 거리는 모두 10,000 이하의 자연수이다.

출력:
    첫째 줄에 트리의 지름을 출력한다.
*/

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> check;
vector<int> sum;

void bfs(int x){
    queue<int>q;
    q.push(x);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        check[u]=1;

        for(int i=0;i<graph[u].size();i++){
            
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            
            if(check[v]==1)
                continue;
                
            sum[v]=sum[u]+w;
            q.push(v);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n=0;
    cin >> n;

    for(int i=0;i<n;i++){
        check.push_back(0);
        sum.push_back(0);
    }
    
    for(int i=0;i<n;i++){
        int origin=0;
        cin>>origin;

        vector<pair<int,int>>graphTemp;

        int temp=0;
        while(true){
            cin>>temp;
            if(temp==-1){
                break;
            }
            else{
                int weight=0;
                cin>>weight;
                graphTemp.push_back(make_pair(temp-1,weight));
            }
        }
        graph.push_back(graphTemp);
    }
    
    bfs(0);
    int maxSum=0;
    for(int i=1;i<n;i++){
        if(sum[maxSum]<sum[i]){
            maxSum=i;
        }
    }

    fill(check.begin(),check.end(),0);
    fill(sum.begin(),sum.end(),0);
    bfs(maxSum);
    sort(sum.begin(),sum.end());
    cout<<sum[sum.size()-1];

    return 0;
}

/*
배운 점:
    1. 트리의 지름은 아래와 같이 찾는다. 
        1-1. 트리에서 임의의 정점xx를 잡는다.
        1-2. 정점xx에서 가장 먼 정점yy를 찾는다.
        1-3. 정점yy에서 가장 먼 정점zz를 찾는다.
*/