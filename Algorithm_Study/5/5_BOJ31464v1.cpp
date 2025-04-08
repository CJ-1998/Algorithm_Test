#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int chocolateCount=0;
int answerCount=0;
vector<vector<int>> graph;
vector<pair<int,int>> answer;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=0;
    cin>>n;

    for(int i=0;i<n;i++){
        string temp="";
        cin>>temp;
        vector<int>tempVec;
        for(int j=0;j<n;j++){
            if(temp[i]=='#'){
                chocolateCount++;
                tempVec.push_back(1);
            }
            else{
                tempVec.push_back(0);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==0){
                continue;
            }
            else{
                graph[i][j]=0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(graph[k][l]==0){
                            continue;
                        }
                        else{
                            graph[k][l]=0;
                            /* 
                                다 연결되어 있는지 확인 (chocolateCount-2 개수만큼 연결 되어 있다면)
                                다 연결 되어 있으면 i, j pair answer에 넣기
                                다 연결 안 된 것 하나라도 발견 시 현재 2중 for문 나가기
                            */
                        }
                    }
                }
            }
        }
    }


    return 0;
}