/*
문제:
    <그림 1>과 같이 정사각형 모양의 지도가 있다. 
    1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
    철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
    여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
    대각선상에 집이 있는 경우는 연결된 것이 아니다. 
    <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
    지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력:
    첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력:   
    첫 번째 줄에는 총 단지수를 출력하시오. 
    그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check;
int num;

vector<int> answer;

int dfs(int i, int j){
    if(graph[i][j]==0){
        return 0;
    }
    if(check[i][j]==1){
        return 0;
    }

    int sum=1;
    check[i][j]=1;
    if(i-1>=0){
        sum+=dfs(i-1,j);
    }
    if(i+1<num){
        sum+=dfs(i+1,j);
    }
    if(j-1>=0){
        sum+=dfs(i,j-1);
    }
    if(j+1<num){
        sum+=dfs(i,j+1);
    }

    return sum;
}

int main(){

    num=0;
    cin>>num;

    for(int i=0;i<num;i++){
        vector<int> a;
        vector<int> b;
        string temp="";
        cin>>temp;
        for(int j=0;j<num;j++){
            a.push_back(temp[j]-'0');
            b.push_back(0);
        }
        graph.push_back(a);
        check.push_back(b);
    }

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            int t=dfs(i,j);
            if(t!=0){
                answer.push_back(t);
            }
        }
    }

    sort(answer.begin(),answer.end());

    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}

/*
배운 점:
    1. 모여있는 것 개수 구하려면 dfs 돌면서 주위 dfs 같이 돌고 개수 반환하고 더하면 된다.
*/