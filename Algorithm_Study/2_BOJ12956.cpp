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
