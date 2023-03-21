#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    stack <int> num;

    vector<int> input;
    vector<int> answer;
    
    int cnt=0;
    scanf("%d",&cnt);

    for(int i=0;i<cnt;i++){
        int temp=0;
        scanf("%d",&temp);
        input.push_back(temp);
    }

    reverse(input.begin(),input.end());

    for(int i=0;i<cnt;i++){
        if(num.empty()){
            num.push(input[i]);
        }
        else{
            if(num.top()>=input[i]){
                num.push(input[i]);  
            }
            else{
                num.pop();
                num.push(input[i]);
            }
        }
    }

    reverse(input.begin(),input.end());
    
    for(int i=0;i<cnt;i++){
        while(true){
            if(num.empty()){
                answer.push_back(-1);
                break;
            }
            else if(input[i]==num.top()){
                num.pop();
            }
            else if(input[i]>num.top()){
                answer.push_back(-1);
                break;
            }
            else{
                answer.push_back(num.top());
                break;
            }
        }
    }

    for(int i=0;i<answer.size();i++){
        printf("%d ",answer[i]);
    }

    return 0;
}
