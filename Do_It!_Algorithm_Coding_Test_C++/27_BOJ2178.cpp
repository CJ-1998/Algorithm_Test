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