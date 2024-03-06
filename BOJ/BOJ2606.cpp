/*
문제:
    신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
    컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
    예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 
    1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 
    2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 
    하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
    어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 
    컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 
    1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력:
    첫째 줄에는 컴퓨터의 수가 주어진다. 
    컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
    둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
    이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력:
    1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/

#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

vector<vector<int>> graph;
vector<int> check;

int findVirus(int t){
    if(graph[t].size() == 0){
        return 0;
    }
    if(check[t]==1){
        return 0;
    }

    int sum=1;
    check[t] = 1;

    for(int i=0;i<graph[t].size();i++){
        if(check[graph[t][i]] == 1){
            continue;
        }
        else{
            // cout<<t+1<<" call "<<graph[t][i]+1<<endl;
            sum+=findVirus(graph[t][i]);
            check[graph[t][i]]=1;
        }
    }

    return sum;
}

int main(){

    int computer=0;
    int line=0;
    cin>>computer>>line;

    for(int i=0;i<computer;i++){
        vector<int>temp1;
        vector<int>temp2;

        graph.push_back(temp1);
        check.push_back(0);
    }

    for(int i=0;i<line;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    // for(int i=0;i<graph.size();i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]+1<<" ";
    //     }
    //     cout<<endl;
    // }

    int answer=0;
    check[0]=1;

    for(int i=0;i<graph[0].size();i++){
        answer+=findVirus(graph[0][i]);
    }

    cout<<answer<<endl;

    return 0;
}

/*
배운 점:
    1. linkedlist 형태의 graph
    2. 탐색을 진행하고 탐색했다고 표시해야 한다. 

어려웠던 점:
    1. 양쪽 노드 전부 그래프에 표현하지 않아 생각되로 동작하지 않았다. 
    2. 한번 지나간 노드를 건너뛰지 않아 더 추가되는 경우가 발생하였다. 
    3. 탐색했다고 먼저 표시하고 탐색을 진행하니 연결된 노드를 다 탐색하지 않는 경우가 발생했다. 
*/