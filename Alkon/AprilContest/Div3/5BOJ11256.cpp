#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int cnt=0;
    scanf("%d",&cnt);

    for(int i=0;i<cnt;i++){
        int candy=0;
        int box=0;
        scanf("%d %d",&candy, &box);

        vector<int> v;
        for(int j=0;j<box;j++){
            int a, b;
            scanf("%d %d",&a, &b);

            v.push_back(a*b);
        }

        sort(v.begin(),v.end(),greater<>());

        int answer=0;
        int sum=0;

        for(int k=0;k<box;k++){
            sum+=v[k];
            answer++;
            if(sum>=candy){
                break;
            }
        }
        printf("%d\n",answer);
    }

    return 0;
}