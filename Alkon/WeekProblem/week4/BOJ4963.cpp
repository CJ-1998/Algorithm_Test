/*
문제:
    정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 
    섬의 개수를 세는 프로그램을 작성하시오.
    한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. 
    두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 
    지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

입력:
    입력은 여러 개의 테스트 케이스로 이루어져 있다. 
    각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. 
    w와 h는 50보다 작거나 같은 양의 정수이다.
    둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
    입력의 마지막 줄에는 0이 두 개 주어진다.

출력:
    각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check;

int a;
int b;

int checkLand(int x, int y){
    if(graph[x][y]==0){
        return 0;
    }
    if(check[x][y]==1){
        return 0;
    }

    check[x][y]=1;
    int answer=1;

    if(x-1>=0&&y-1>=0){
        answer+=checkLand(x-1,y-1);
    }
    if(x-1>=0){
        answer+=checkLand(x-1,y);
    }
    if(x-1>=0&&y+1<a){
        answer+=checkLand(x-1,y+1);
    }
    if(y-1>=0){
        answer+=checkLand(x,y-1);
    }
    if(y+1<a){
        answer+=checkLand(x,y+1);
    }
    if(x+1<b&&y-1>=0){
        answer+=checkLand(x+1,y-1);
    }
    if(x+1<b){
        answer+=checkLand(x+1,y);
    }
    if(x+1<b&&y+1<a){
        answer+=checkLand(x+1,y+1);
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr;

    while(true){
        a=-1;
        b=-1;
        cin>>a>>b;

        if(a==0&&b==0){
            break;
        }

        graph.clear();
        check.clear();

        for(int i=0;i<b;i++){
            vector<int>temp1;
            vector<int>temp2;
            for(int j=0;j<a;j++){
                int t=0;
                cin>>t;
                temp1.push_back(t);
                temp2.push_back(0);
            }
            graph.push_back(temp1);
            check.push_back(temp2);
        }

        int answer=0;
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                if(checkLand(i,j)!=0){
                    answer++;
                }
            }
        }
        cout<<answer<<endl;
    }

    return 0;
}