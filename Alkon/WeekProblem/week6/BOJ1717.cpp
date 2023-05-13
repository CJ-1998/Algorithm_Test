/*
문제:
    초기에 n+1개의 집합 {0}, {1}, {2}, ... , {n}이 있다. 
    여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
    집합을 표현하는 프로그램을 작성하시오.

입력:
    첫째 줄에 n, m이 주어진다. 
    m은 입력으로 주어지는 연산의 개수이다. 
    다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 
    이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 
    두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 
    이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.

출력:
    1로 시작하는 입력에 대해서 a와 b가 같은 집합에 포함되어 있으면 "YES" 또는 "yes"를, 그렇지 않다면 "NO" 또는 "no"를 한 줄에 하나씩 출력한다.
*/

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
    for(int i=0;i<n+2;i++){
        arr[i]=1;
        parentnode[i]=i;
    }

    for(int i=0;i<m;i++){
        int op, a, b;
        scanf("%d %d %d",&op, &a, &b);
        // cin>>op>>a>>b;

        int tempa,tempb;

        tempa=findnode(a);
        tempb=findnode(b);

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

/*
배운 점:
    1. union find에서 size 최적화 할 때 부모를 가지고 있는 배열과 크기를 가지고 있는 배열 2개 있어야 한다. 
    2. union 연산할 때 작은 집합의 root의 부모를 큰 집합의 root로 해야 한다.
*/