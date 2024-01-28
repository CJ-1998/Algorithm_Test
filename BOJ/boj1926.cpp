/*
문제:
    어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 
    단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
    가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 
    그림의 넓이란 그림에 포함된 1의 개수이다.

입력:
    첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 
    두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
    (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력:
    첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 
    단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check;

int a,b;

int dfs(int x, int y){
    if(x<0||y<0||x>=a||y>=b){
        return 0;
    }

    if(check[x][y]==1){
        return 0;
    }
    if(graph[x][y]==0){
        return 0;
    }

    check[x][y]=1;

    int sum=1;
    sum+=dfs(x-1,y);
    sum+=dfs(x,y-1);
    sum+=dfs(x,y+1);
    sum+=dfs(x+1,y);

    return sum;
}

int main(){
    cin>>a>>b;

    for(int i=0;i<a;i++){
        vector<int>temp1;
        vector<int>temp2;
        for(int j=0;j<b;j++){
            int temp=0;
            cin>>temp;
            temp1.push_back(temp);
            temp2.push_back(0);
        }
        graph.push_back(temp1);
        check.push_back(temp2);
    }

    int count=0;
    int big=0;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int temp=dfs(i,j);
            if(temp!=0){
                count++;
                if(temp>big){
                    big=temp;
                }
            }
        }
    }

    cout<<count<<endl;
    cout<<big<<endl;

}