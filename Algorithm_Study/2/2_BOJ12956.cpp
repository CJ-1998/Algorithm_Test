/*
문제
    N개의 교차로와 M개의 거리로 이루어진 도시가 있다. 
    교차로는 0번부터 N-1번까지 번호가 매겨져 있고, 도로는 0번부터 M-1번까지 번호가 매겨져 있다. 
    모든 도로는 양방향이며, 도로는 서로 다른 교차로를 연결한다. 
    임의의 두 교차로는 최대 1개의 도로로 연결되어 있다. 
    모든 교차로는 연결되어 있기 때문에, 한 교차로에서 다른 교차로로 도로를 이용해서 항상 갈 수 있다.

    도시의 시장은 퍼레이드를 개최하려고 한다. 퍼레이드는 도로 하나에서 열린다. 

    도시에는 모든 교차로의 쌍(X, Y) 마다 X와 Y를 오가는 버스가 존재한다. 
    퍼레이드는 버스의 운행에 영향을 줄 수 있다. 
    버스가 퍼레이드에 영향을 받는 경우는 퍼레이드에 사용하는 도로를 제외하고 구한 최단 거리의 길이가 
    제외하지 않고 구한 X에서 Y로 가는 최단 경로의 길이보다 큰 경우이다. 
    퍼레이드 때문에 X에서 Y로 갈 수 없게 되는 경우도 영향을 받는 경우이다.

    각 도로에서 퍼레이드를 개최한다고 했을 때, 영향을 받는 버스 노선의 수가 몇 개인지 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 도시의 개수 N (1 ≤ N ≤ 100)과 도로의 개수 M (1 ≤ M ≤ 2,000)이 주어진다.
    둘째 줄부터 M개의 줄에는 도로의 정보가 0번 도로부터 순서대로 주어진다.
    도로의 정보는 from, to, time으로 이루어져 있으며, 
    from과 to를 오가는데 걸리는 시간이 time이라는 뜻이다. 
    (0 ≤ from, to ≤ N-1, 1 ≤ time ≤ 1,000, from ≠ to)

출력
    각 도로에서 퍼레이드가 열린다고 했을 때, 영향을 받는 버스 노선의 개수를 0번 도로부터 순서대로 공백으로 구분해 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  #define INF 300000000

const int INF = 99999999;

vector<vector<vector<int>>> parade (int node, vector<vector<int>>roads){

    vector<vector<vector<int>>> graphs;

    for(int index=0;index<roads.size();index++){
        vector<vector<int>> graph;
        
        for(int i=0;i<node;i++){
            vector<int> temp;
            for(int j=0;j<node;j++){
                temp.push_back(INF);
            }
            graph.push_back(temp);
        }

        for(int i=0;i<roads.size();i++){
            if(i!=index){
                graph[roads[i][0]][roads[i][1]]=roads[i][2];
                graph[roads[i][1]][roads[i][0]]=roads[i][2];
            }
        }

        for(int i=0;i<node;i++){
            graph[i][i]=0;
        }

        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
                for(int k=0;k<node;k++){
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }

        graphs.push_back(graph);
    }

    return graphs;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<vector<int>> graph;

    int node = 0; 
    int road = 0;

    cin >> node >> road; 

    for(int i=0;i<node;i++){
        vector<int> temp;
        for(int j=0;j<node;j++){
            temp.push_back(INF);
        }
        graph.push_back(temp);
    }

    for(int i=0;i<node;i++){
        graph[i][i]=0;
    }

    vector<vector<int>> roads;

    for(int i=0;i<road;i++){
        int start = 0;
        int end = 0;
        int time = 0;
        cin>>start>>end>>time;

        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        temp.push_back(time);

        graph[start][end]=time;
        graph[end][start]=time;
        roads.push_back(temp);
    }

    for(int k=0;k<node;k++){
        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                // if(graph[i][j]>graph[i][k]+graph[k][j]){
                //     graph[i][j]=graph[i][k]+graph[k][j];
                // }
            }
        }
    }

    // for(int j=0;j<node;j++){
    //     for(int k=0;k<node;k++){
    //         cout<<graph[j][k]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(int index=0;index<road;index++){
        vector<vector<int>> graph2;

        for(int i=0;i<node;i++){
            vector<int> temp;
            for(int j=0;j<node;j++){
                temp.push_back(INF);
            }
            graph2.push_back(temp);
        }

        for(int i=0;i<node;i++){
            graph2[i][i]=0;
        }

        for(int i=0;i<road;i++){
            if(i!=index){
                graph2[roads[i][0]][roads[i][1]]=roads[i][2];
                graph2[roads[i][1]][roads[i][0]]=roads[i][2];
            }
        }

        for(int k=0;k<node;k++){
            for(int i=0;i<node;i++){
                for(int j=0;j<node;j++){
                    graph2[i][j] = min(graph2[i][j],graph2[i][k]+graph2[k][j]);
                    // if(graph2[i][j]>graph2[i][k]+graph2[k][j]){
                    //     graph2[i][j]=graph2[i][k]+graph2[k][j];
                    // }
                }
            }
        }

        int count = 0;
        for(int j=0;j<node;j++){
            for(int k=j+1;k<node;k++){
                if(graph[j][k]<graph2[j][k]){
                    count++;
                }
            }
        }

        if(index!=road-1)
            cout<<count<<" ";
        else
            cout<<count<<'\n';
    }

    /*
    vector<vector<vector<int>>> graphs = parade(node, roads);

    for(int i=0;i<graphs.size();i++){

        // for(int l=0;l<node;l++){
        //     for(int m=0;m<node;m++){
        //         cout<<graphs[i][l][m]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        int count = 0;
        for(int j=0;j<node;j++){
            for(int k=j+1;k<node;k++){
                if(graph[j][k]!=INF){
                    if(graph[j][k]<graphs[i][j][k]){
                        count++;
                    }
                }
            }
        }
        if(i!=graphs.size()-1)
            cout<<count<<" ";
        else
            cout<<count<<'\n';
    }
    */

    return 0;
}

/*
틀린 이유 : 
    1. 3중 for문에서 습관적으로 i, j, k로 함;;

배운 점:
    1. floyd warshall 알고리즘
*/