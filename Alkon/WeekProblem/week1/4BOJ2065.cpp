// 실패한 버전.
// 54%에서 계속 틀림.
// 왜 틀린지 모르겠음....

/*
요구사항:
    1. 나룻배는 처음에 왼쪽에 정박해 있다. 
    2. 나룻배는 한번에 최대 M명 사람 태울 수 있다. 
    3. 이동할 때 t 시간 걸린다. 
    4. 정박장에 기다리고 있던 손님 배에 태울 수 있는데까지 태운다. 
    5. 기다리고 있는 손님 없으면 그 정박장에서 기다린다. 
    6. 기다리다가 반대편 정박장에 손님 오면 그 정박장으로 이동한다. 
    7. 손님들이 원하는 곳에 도착하게 되는 시간 구하자. 
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const string LEFT="left";
    const string RIGHT="right";

    int maxPerson=0;
    int movingTime=0;
    int num=0;

    cin>>maxPerson>>movingTime>>num;

    vector<int> arrivalTime;
    vector<string> arrivalPlace;
    queue<int> arrivalLeft;
    queue<int> arrivalRight;
    vector<int> answerTime;

    for(int i=0;i<num;i++){
        int time=0;
        string place="";

        cin>>time>>place;

        if(place.compare(LEFT)==0){
            arrivalLeft.push(time);
        }
        else{
            arrivalRight.push(time);
        }

        arrivalTime.push_back(time);
        arrivalPlace.push_back(place);
        answerTime.push_back(-1);
    }

    int nowTime=0;
    string nowPlace=LEFT;

    int cnt=0;

    while(true){

        if(cnt==num){
            break;
        }

        // 현재 위치가 왼쪽인 경우
        if(nowPlace.compare(LEFT)==0){
            // 왼쪽에 이제 사람이 없는 경우
            if(arrivalLeft.empty()){
                // 오른쪽에 아직 기다리는 사람이 없는 경우
                if(arrivalRight.front()>nowTime){
                    nowTime=arrivalRight.front();
                }
                nowTime+=movingTime;
                nowPlace=RIGHT;
                continue;
            }
            
            // 왼쪽에 기다리는 사람이 있는 경우 
            if(arrivalLeft.front()<=nowTime){
                int tempCnt=0;
                
                while(true){
                    // 왼쪽에 기다리는 사람 다 태워서 이제 왼쪽에 사람이 없는 경우 
                    if(arrivalLeft.empty()){
                        nowTime+=movingTime;
                        nowPlace=RIGHT;
                        break;
                    }
                    
                    // 나룻배에 사람 최대로 태운 경우 
                    if(tempCnt==maxPerson){
                        nowTime+=movingTime;
                        nowPlace=RIGHT;
                        break;
                    }

                    // 왼쪽에 기다리는 사람이 있는 경우 
                    if(arrivalLeft.front()<=nowTime){
                        int t=arrivalLeft.front();
                        arrivalLeft.pop();
                        // int index=find(arrivalTime.begin(),arrivalTime.end(),t)-arrivalTime.begin();
                        auto it=find(arrivalTime.begin(),arrivalTime.end(),t);
                        int index=distance(arrivalTime.begin(),it);
                        while(it!=arrivalTime.end()){
                            if(arrivalPlace[index].compare(LEFT)==0){
                                break;
                            }
                            else{
                                it=find(it+1,arrivalTime.end(),t);
                                index=distance(arrivalTime.begin(),it);
                                // index=find(it+1,arrivalTime.end(),t)-arrivalTime.begin();
                            }
                        }
                        arrivalTime[index]=-1;
                        arrivalPlace[index]="";
                        answerTime[index]=nowTime+movingTime;
                        cnt++;
                        tempCnt++;
                    }
                    // 왼쪽에 기다리는 사람 다 태워서 없는 경우
                    else{
                        nowTime+=movingTime;
                        nowPlace=RIGHT;
                        break;
                    }
                }
            }
            // 왼쪽에 기다리는 사람이 없는 경우 
            else{
                // 오른쪽에 기다리는 사람이 있는 경우 
                if(arrivalRight.front()<=nowTime){
                    nowTime+=movingTime;
                    nowPlace=RIGHT;
                    continue;
                }
                //오른쪽에 기다리는 사람이 없는 경우 
                else{
                    //왼쪽에 오는 사람이 오른쪽에 오는 사람보다 늦게 오는 경우 
                    if(arrivalLeft.front()>arrivalRight.front()){
                        nowTime=arrivalRight.front();
                        nowTime+=movingTime;
                        nowPlace=RIGHT;
                    }
                    //왼쪽에 오는 사람이 오른쪽에 오는 사람보다 빨리 오는 경우 
                    else{
                        nowTime=arrivalLeft.front();
                    }
                }
            }
        }
        //현재 위치가 오른쪽인 경우
        else{
            //오른쪽에 이제 사람이 없는 경우 
            if(arrivalRight.empty()){
                //왼쪽에 아직 기다리는 사람이 없는 경우 
                if(arrivalLeft.front()>nowTime){
                    nowTime=arrivalLeft.front();
                }
                nowTime+=movingTime;
                nowPlace=LEFT;
                continue;
            }

            //오른쪽에 기다리는 사람이 있는 경우 
            if(arrivalRight.front()<=nowTime){
                int tempCnt=0;

                while(true){
                    //오른쪽에 기다리는 사람 다 태워서 이제 더이상 없는 경우 
                    if(arrivalRight.empty()){
                        nowTime+=movingTime;
                        nowPlace=LEFT;
                        break;
                    }

                    //나룻배에 최대로 태운 경우 
                    if(tempCnt==maxPerson){
                        nowTime+=movingTime;
                        nowPlace=LEFT;
                        break;
                    }

                    //오른쪽에 기다리는 사람이 있는 경우 
                    if(arrivalRight.front()<=nowTime){
                        int t=arrivalRight.front();
                        arrivalRight.pop();
                        auto it=find(arrivalTime.begin(),arrivalTime.end(),t);
                        int index=distance(arrivalTime.begin(),it);
                        while(it!=arrivalTime.end()){
                            if(arrivalPlace[index].compare(RIGHT)==0){
                                break;
                            }
                            else{
                                it=find(it+1,arrivalTime.end(),t);
                                index=distance(arrivalTime.begin(),it);
                                // index=find(it+1,arrivalTime.end(),t)-arrivalTime.begin();
                            }
                        }
                        arrivalTime[index]=-1;
                        arrivalPlace[index]="";
                        answerTime[index]=nowTime+movingTime;
                        cnt++;
                        tempCnt++;
                    }
                    //오른쪽에 기다리는 사람 다 태워서 이제 기다리는 사람 없는 경우 
                    else{
                        nowTime+=movingTime;
                        nowPlace=LEFT;
                        break;
                    }
                }
            }
            //오른쪽에 기다리는 사람이 없는 경우 
            else{
                //왼쪽에 기다리는 사람이 있는 경우 
                if(arrivalLeft.front()<=nowTime){
                    nowTime+=movingTime;
                    nowPlace=LEFT;
                    continue;
                }

                //왼쪽에 기다리는 사람이 없는 경우 
                else{
                    //왼쪽에 기다리는 사람이 더 빨리 오는 경우 
                    if(arrivalRight.front()>arrivalLeft.front()){
                        nowTime=arrivalLeft.front();
                        nowTime+=movingTime;
                        nowPlace=LEFT;
                    }
                    //오른쪽에 기다리는 사람이 더 빨리 오는 경우 
                    else{
                        nowTime=arrivalRight.front();
                    }
                }
            }
        }
    }

    for(int i=0;i<answerTime.size();i++){
        cout<<answerTime[i]<<endl;
    }

    return 0;
}