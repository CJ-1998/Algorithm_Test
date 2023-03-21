#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
    int ship=0;
    int t=0;
    int n=0;

    scanf("%d %d %d",&ship, &t, &n);

    queue<int> left;
    queue<int> right;

    for(int i=0;i<n;i++){
        int time=0;
        string lr;

        //scanf("%d %s", &time, &lr);

        cin>>time>>lr;

        if(!lr.compare("left")){
            left.push(time);
        }

        if(!lr.compare("right")){
            right.push(time);
        }
    }

    int nowtime=0;
    string nowship="left";

    vector<int> arrivetime;

    while(true){
        if(left.empty()&&right.empty()){
            break;
        }
        int nowshipcnt=0;
        if(!nowship.compare("left")){
            if(!left.empty()&&!right.empty()){
                while(nowtime>=left.front()){
                    if(nowshipcnt==ship){
                        break;
                    }
                    left.pop();
                    nowshipcnt++;
                    if(left.empty())
                        break;
                }
                if(nowshipcnt==0){
                    if(left.front()>right.front()){
                        nowtime=right.front();
                        nowtime+=t;
                        nowship="right";
                    }
                    else{
                        nowtime=left.front();
                    }
                }
                else{
                    nowtime+=t;
                    nowship="right";
                    for(int i=0;i<nowshipcnt;i++){
                        arrivetime.push_back(nowtime);
                    }
                }
            }
            else if(!left.empty()&&right.empty()){
                while(nowtime>=left.front()){
                    if(nowshipcnt==ship){
                        break;
                    }
                    left.pop();
                    nowshipcnt++;
                    if(left.empty())
                        break;
                }
                if(nowshipcnt==0){
                    nowtime=left.front();
                }
                else{
                    nowtime+=t;
                    nowship="right";
                    for(int i=0;i<nowshipcnt;i++){
                        arrivetime.push_back(nowtime);
                    }
                }
            }
            else if(left.empty()&&!right.empty()){
                nowtime=right.front();
                nowtime+=t;
                nowship="right";
            } 
        }
        else if(!nowship.compare("right")){
            if(!left.empty()&&!right.empty()){
                while(nowtime>=right.front()){
                    if(nowshipcnt==ship){
                        break;
                    }
                    right.pop();
                    nowshipcnt++;
                    if(right.empty())
                        break;
                }
                if(nowshipcnt==0){
                    if(right.front()>left.front()){
                        nowtime=left.front();
                        nowtime+=t;
                        nowship="left";
                    }
                    else{
                        nowtime=right.front();
                    }
                }
                else{
                    nowtime+=t;
                    nowship="left";
                    for(int i=0;i<nowshipcnt;i++){
                        arrivetime.push_back(nowtime);
                    }
                }
            }
            else if(left.empty()&&!right.empty()){
                while(nowtime>=right.front()){
                    if(nowshipcnt==ship){
                        break;
                    }
                    right.pop();
                    nowshipcnt++;
                    if(right.empty())
                        break;
                }
                if(nowshipcnt==0){
                    nowtime=right.front();
                }
                else{
                    nowtime+=t;
                    nowship="left";
                    for(int i=0;i<nowshipcnt;i++){
                        arrivetime.push_back(nowtime);
                    }
                }
            }
            else if(!left.empty()&&right.empty()){
                nowtime=left.front();
                nowtime+=t;
                nowship="left";
            } 
        }
    }

    for(int i=0;i<arrivetime.size();i++){
        printf("%d \n",arrivetime[i]);
    }

    return 0;
}