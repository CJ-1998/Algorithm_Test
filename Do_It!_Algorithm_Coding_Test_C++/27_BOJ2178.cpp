/*
문제:
    N×M크기의 배열로 표현되는 미로가 있다.
    미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
    이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
    한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
    
    1	0	1	1	1	1
    1	0	1	0	1	0
    1	0	1	0	1	1
    1	1	1	0	1	1
    
    위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 
    칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력:
    첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 
    다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
    각각의 수들은 붙어서 입력으로 주어진다.

출력:
    첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
    항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check;

int n, m;
bool arrive;

vector<int> answerTemp;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int tempx=q.front().first;
        int tempy=q.front().second;

        // cout<<"tempx: "<<tempx<<" tempy: "<<tempy<<endl;

        q.pop();

        check[tempx][tempy]=1;

            if(tempx-1>=0){
                if(graph[tempx-1][tempy]!=0 && check[tempx-1][tempy]!=1){
                    check[tempx-1][tempy]=1;
                    graph[tempx-1][tempy]=graph[tempx][tempy]+1;
                    q.push(make_pair(tempx-1,tempy));
                }
            }
            if(tempx+1<n){
                if(graph[tempx+1][tempy]!=0 && check[tempx+1][tempy]!=1){
                    check[tempx+1][tempy]=1;
                    graph[tempx+1][tempy]=graph[tempx][tempy]+1;
                    q.push(make_pair(tempx+1,tempy));
                }
            }
            if(tempy-1>=0){
                if(graph[tempx][tempy-1]!=0 && check[tempx][tempy-1]!=1){
                    check[tempx][tempy-1]=1;
                    graph[tempx][tempy-1]=graph[tempx][tempy]+1;
                    q.push(make_pair(tempx,tempy-1));
                }
            }
            if(tempy+1<m){
                if(graph[tempx][tempy+1]!=0 && check[tempx][tempy+1]!=1){
                    check[tempx][tempy+1]=1;
                    graph[tempx][tempy+1]=graph[tempx][tempy]+1;
                    q.push(make_pair(tempx,tempy+1));
                }
            }

    }

}

// int dfs(int x, int y, int depth){

//     // if(arrive){
//     //     return 0;
//     // }

//     if(graph[x][y]==0){
//         return 0;
//     }

//     if(check[x][y]==1){
//         return 0;
//     }

//     // cout<<"x: "<<x+1<<" y: "<<y+1<<" depth: "<<depth<<endl;

//     // cout<<"x: "<<x<<" y: "<<y<<endl;

//     check[x][y]=1;

//     int myDepth=depth;

//     int answer=1;

//     if(x==n-1&&y==m-1){
//         // arrive=true;
//         // cout<<"depth: "<<myDepth+1<<endl;
//         answerTemp.push_back(myDepth+1);
//         return answer;
//     }

//     vector<int> temp;

//     if(x-1>=0){
//         int c=dfs(x-1,y, myDepth+1);
//         if(c!=0){
//             temp.push_back(c);
//         }
//     }
//     if(x+1<n){
//         int c=dfs(x+1,y, myDepth+1);
//         if(c!=0){
//             temp.push_back(c);
//         }
//     }
//     if(y-1>=0){
//         int c=dfs(x,y-1, myDepth+1);
//         if(c!=0){
//             temp.push_back(c);
//         }
//     }
//     if(y+1<m){
//         int c=dfs(x,y+1, myDepth+1);
//         if(c!=0){
//             temp.push_back(c);
//         }
//     }

//     sort(temp.begin(),temp.end());

//     // for(int i=0;i<temp.size();i++){
//     //     cout<<temp[i]<<" ";
//     // }
//     // cout<<endl;

//     if(temp.size()!=0){
//         answer+=temp[0];
//     }

//     // if(x!=n-1&&y!=m-1){
//     //     return 0;
//     // }

//     return answer;
// }

int main(){

    cin >> n >> m;
    arrive=false;

    for(int i=0;i<n;i++){
        string temp="";
        cin >> temp;

        vector<int> t1;
        vector<int> t2;
        for(int j=0;j<m;j++){
            t1.push_back(temp[j]-'0');
            t2.push_back(0);
        }
        graph.push_back(t1);
        check.push_back(t2);
    }

    // dfs(0,0,0);

    // sort(answerTemp.begin(),answerTemp.end());

    // cout<<answerTemp[0]<<endl;

    bfs(0,0);
    cout<<graph[n-1][m-1]<<endl;

    return 0;
}

/*
배운 점:
    1. 모든 것이 DFS로 풀리진 않는다 .
    2. BFS 사용 방법
    3. 깊이, 계층 이런 것 있는 그래프는 BFS가 낫다. 
*/