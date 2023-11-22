#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    cin>>num;

    vector<int>maxNum;
    vector<int>startNum;

    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        maxNum.push_back(temp);
    }

    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        startNum.push_back(temp);
    }

    for(int i=0;i<num;i++){
        if(startNum[i]>maxNum[i]){
            cout<<-1<<endl;
            return 0;
        }
    }

    int pushCnt=0;
    cin>>pushCnt;

    reverse(startNum.begin(),startNum.end());
    reverse(maxNum.begin(),maxNum.end());

    int nowIndex=0;
    for(int i=0;i<pushCnt;i++){
        startNum[nowIndex]++;
        for(int j=0;j<num;j++){
            if(startNum[j]>maxNum[j]){
                startNum[j]=0;

                if(j!=num-1){
                    startNum[j+1]++;
                }
            }
        }
        
    }

    reverse(startNum.begin(),startNum.end());

    for(int i=0;i<num;i++){
        cout<<startNum[i];
    }


    return 0;
}