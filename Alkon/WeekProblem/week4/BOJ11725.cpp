#include<iostream>
#include<vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    cin>>num;

    vector<int> parent(num);
    vector<int> check(num);

    for(int i=0;i<num;i++){
        parent[i]=0;
        check[i]=-1;
    }

    check[0]=0;

    for(int i=0;i<num-1;i++){
        int a=0;
        int b=0;

        cin>>a>>b;

        if(a==1){
            parent[b-1]=1;
            check[b-1]=0;
            continue;
        }
        if(b==1){
            parent[a-1]=1;
            check[a-1]=0;
            continue;
        }

        if(check[a-1]==0){
            parent[b-1]=a;
            check[b-1]=0;
            continue;
        }

        if(check[b-1]==0){
            parent[a-1]=b;
            check[a-1]=0;
            continue;
        }
    }

    for(int i=1;i<num;i++){
        cout<<parent[i]<<"\n";
    }

    return 0;
}