/*
문제:
    돌고래는 사람 다음으로 지능이 높은 동물이다. 한 과학자가 돌고래들의 반응을 실험해 보고자 돌고래 앞에 거울을 놓아두었다. 그러자, 돌고래들이 거울을 보고 거울에 비친 모습이 자신이라는 것을 확인하는 데까지 그리 오랜 시간이 걸리지 않았다. 과학자는 결론적으로, "돌고래는 높은 수준의 사고와 추상적 개념을 모두 이해하고 도구를 사용하는 능력이 있다"라는 사실을 알게 되었다.
    이를 알게 된 임스는 거울에 비쳐 반사되어 뒤집혀서 보이는 것처럼, 여러 가지 숫자로 이루어진 배열을 상하좌우 방향으로 뒤집어, 새로운 배열을 만들고 싶어졌다.

    2를 뒤집으면 5로, 5를 뒤집으면 2로, 1과 8을 뒤집으면 각각 1과 8로 보인다. 
    나머지 숫자들은 뒤집었을 때의 상태를 숫자로 나타낼 수 없다. 
    임스가 뒤집고자 하는 방향(상하좌우 중 하나)과 배열의 크기 N이 주어지고, 
    0이 아닌 숫자(1~9)로 이루어진 N x N 배열이 주어졌을 때, 주어진 방향으로 뒤집어진 배열의 모습을 출력하시오.

입력:
    첫 번째 줄에는 임스가 뒤집고자 하는 방향 W와, 배열의 크기 N이 주어진다. 
    W는 L, R, U, D 중 하나이다. 
    2<=N<=20 
    입력의 두 번째 줄부터 N개의 줄에 0이 아닌 숫자가 구성된 배열이 공백으로 구분되어 주어진다.

출력:
    주어진 방향으로 뒤집혀 보이는 배열을 출력한다. 만약 구분할 수 없는 숫자인 경우 "?"로 출력한다.
*/

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    char c;
    scanf("%c",&c);

    int n=0;
    scanf("%d",&n);

    vector<vector<int>>v;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int t=0;
            scanf("%d",&t);
            temp.push_back(t);
        }
        v.push_back(temp);
    }

    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    v[i][j]=1;
                }
                else if(v[i][j]==2){
                    v[i][j]=5;
                }
                else if(v[i][j]==5){
                    v[i][j]=2;
                }
                else if(v[i][j]==8){
                    v[i][j]=8;
                }
                else{
                    v[i][j]=0;
                }
            }
        }

    if(c=='U'||c=='D'){
        
        reverse(v.begin(),v.end());
    }
    else{
        
        for(int i=0;i<n;i++){
            reverse(v[i].begin(),v[i].end());
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==0){
                printf("%c ",'?');
            }
            else{
                printf("%d ",v[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}