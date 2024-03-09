/*
문제:
    적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 
    따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
    크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
    그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
    또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
    (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

    예를 들어, 그림이 아래와 같은 경우에
        RRRBB
        GGBBB
        BBBRR
        BBRRR
        RRRRR
    적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 
    하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
    
    그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
    둘째 줄부터 N개 줄에는 그림이 주어진다.

출력:
    적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check1;
vector<vector<int>> check2;

int n;

int r;
int g;
int b;

int check1Dfs(int x, int y, int color){

    if(check1[x][y]==1){
        return 0;
    }

    if(graph[x][y]!=color){
        return 0;
    }

    // cout<<"x: "<<x<<" y: "<<y<<" now: "<<graph[x][y]<<" color: "<<color<<endl;

    check1[x][y]=1;

    int count=1;

    if(x-1>=0){
        count+=check1Dfs(x-1,y,graph[x][y]);
    }
    if(x+1<n){
        count+=check1Dfs(x+1,y,graph[x][y]);
    }
    if(y-1>=0){
        count+=check1Dfs(x,y-1,graph[x][y]);
    }
    if(y+1<n){
        count+=check1Dfs(x,y+1,graph[x][y]);
    }

    // cout<<"x: "<<x<<" y: "<<y<<" count "<<count<<endl;

    return count;
}

int check2Dfs(int x, int y, int color){
    if(check2[x][y]==1){
        return 0;
    }

    if(graph[x][y]!=color){
        return 0;
    }

    check2[x][y]=1;

    int count=1;

    if(x-1>=0){
        count+=check2Dfs(x-1,y,graph[x][y]);
    }
    if(x+1<n){
        count+=check2Dfs(x+1,y,graph[x][y]);
    }
    if(y-1>=0){
        count+=check2Dfs(x,y-1,graph[x][y]);
    }
    if(y+1<n){
        count+=check2Dfs(x,y+1,graph[x][y]);
    }

    return count;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        string temp="";
        cin >> temp;

        vector<int>temp1;
        vector<int>temp2;

        vector<int> temp3;

        for(int j=0;j<n;j++){
            temp1.push_back(0);
            temp2.push_back(0);

            if(temp[j]=='R'){
                temp3.push_back(1);
            }
            else if(temp[j]=='G'){
                temp3.push_back(2);
            }
            else{
                temp3.push_back(3);
            }
        }

        graph.push_back(temp3);
        check1.push_back(temp1);
        check2.push_back(temp2);
    }    

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;   
    // }

    r=0;
    g=0;
    b=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t=check1Dfs(i,j,graph[i][j]);
            if(t!=0){    
                if(graph[i][j]==1){
                    r++;
                }
                else if(graph[i][j]==2){
                    g++;
                }
                else{
                    b++;
                }
            }
            // cout<<r<<" "<<g<<" "<<b<<endl;
        }
    }

    int answer1=r+b+g;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==2){
                graph[i][j]=1;
            }
        }
    }

    r=0;
    g=0;
    b=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t=check2Dfs(i,j,graph[i][j]);
            if(t!=0){    
                if(graph[i][j]==1){
                    r++;
                }
                else if(graph[i][j]==2){
                    g++;
                }
                else{
                    b++;
                }
            }
            // cout<<r<<" "<<g<<" "<<b<<endl;
        }
    }

    int answer2=r+b+g;


    cout<<answer1<<" "<<answer2<<endl;

    return 0;
}