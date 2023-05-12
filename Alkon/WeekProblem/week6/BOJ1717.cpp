#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int* arr;
int* parentnode;

int findnode(int node){
    if(parentnode[node]==node){
        return node;
    }
    else{
        parentnode[node]=findnode(parentnode[node]);
        return parentnode[node];
    }
}

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    // cin>>n>>m;

    arr=new int[n+1];
    parentnode=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=1;
        parentnode[i]=i;
    }

    for(int i=0;i<m;i++){
        int op, a, b;
        scanf("%d %d %d",&op, &a, &b);
        // cin>>op>>a>>b;

        int tempa,tempb;
        tempa=findnode(a-1);
        tempb=findnode(b-1);

        if(op==0){
            if(tempa==tempb){
                continue;
            }
            else{
                if(arr[tempa]>arr[tempb]){
                    arr[tempa]+=arr[tempb];
                    parentnode[tempb]=tempa;
                }
                else{
                    arr[tempb]+=arr[tempa];
                    parentnode[tempa]=tempb;
                }
            }
        }
        else{
            if(tempa==tempb){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}