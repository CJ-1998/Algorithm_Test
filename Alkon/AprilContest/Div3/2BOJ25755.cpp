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

    if(c=='U'||c=='D'){
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
                else{
                    v[i][j]=0;
                }
            }
        }
        reverse(v.begin(),v.end());
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    v[i][j]=1;
                }
                else{
                    v[i][j]=0;
                }
            }
        }

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