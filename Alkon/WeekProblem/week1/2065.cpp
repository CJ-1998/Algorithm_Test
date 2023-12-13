#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxPeople=0;
    int movingTime=0;
    int personNum=0;

    cin>>maxPeople>>movingTime>>personNum;

    const string LEFT = "left";
    const string RIGHT = "right";

    vector<pair<int,string>> arrivalInfo;
    vector<int> answerTime;
    queue<int> arrivalLeft;
    queue<int> arrivalRight;

    for(int i=0;i<personNum;i++){
        int time=0;
        string place="";

        cin>>time>>place;

        arrivalInfo.push_back(make_pair(time,place));
        answerTime.push_back(-1);

        if(place.compare(LEFT)==0){
            arrivalLeft.push(i);
        }
        else{
            arrivalRight.push(i);
        }
    }

    int cnt=0;
    int nowTime=0;
    string nowPlace=LEFT;

    while(true){
        if(cnt==personNum){
            break;
        }

        //위치가 왼쪽인 경우
        if(nowPlace.compare(LEFT)==0){
            //왼쪽에 기다리는 사람이 이제 없는 경우 
            if(arrivalLeft.empty()){
                int index=arrivalRight.front();
                int rightTime=arrivalInfo[index].first;

                //오른쪽에 기다리는 사람이 아직 안 온 경우 
                if(nowTime<rightTime){
                    nowTime=rightTime;
                }
                nowTime+=movingTime;
                nowPlace=RIGHT;
            }
            //왼쪽에 기다리는 사람이 있는 경우 
            else{
                //오른쪽에 기다리는 사람이 이제 없는 경우 
                if(arrivalRight.empty()){
                    int leftIndex=arrivalLeft.front();
                    int leftTime=arrivalInfo[leftIndex].first;
                    
                    //왼쪽에 기다리는 사람이 아직 안 온 경우 
                    if(nowTime<leftTime){
                        nowTime=leftTime;
                    }
                    //왼쪽에 기다리는 사람이 이미 와있는 경우
                    else{
                        int tempCnt=0;
                        while(true){
                            if(arrivalLeft.empty()){
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }

                            if(tempCnt==maxPeople){
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }

                            int realLeftIndex=arrivalLeft.front();
                            int realLeftTime=arrivalInfo[realLeftIndex].first;
                            if(realLeftTime<=nowTime){
                                arrivalLeft.pop();
                                answerTime[realLeftIndex]=nowTime+movingTime;
                                cnt++;
                                tempCnt++;
                            }
                            else{
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }
                        }
                    }
                }
                else{
                    int leftIndex=arrivalLeft.front();
                    int leftTime=arrivalInfo[leftIndex].first;
                    int rightIndex=arrivalRight.front();
                    int rightTime=arrivalInfo[rightIndex].first;

                    if(leftTime<=nowTime){
                        int tempCnt=0;
                        while(true){
                            if(arrivalLeft.empty()){
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }

                            if(tempCnt==maxPeople){
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }

                            int realLeftIndex=arrivalLeft.front();
                            int realLeftTime=arrivalInfo[realLeftIndex].first;
                            if(realLeftTime<=nowTime){
                                arrivalLeft.pop();
                                answerTime[realLeftIndex]=nowTime+movingTime;
                                cnt++;
                                tempCnt++;
                            }
                            else{
                                nowTime+=movingTime;
                                nowPlace=RIGHT;
                                break;
                            }
                        }
                    }
                    else{
                        if(leftTime>rightTime){
                            if(nowTime<rightTime){
                                nowTime=rightTime;
                            }
                            nowTime+=movingTime;
                            nowPlace=RIGHT;
                        }
                        else{
                            nowTime=leftTime;
                        }
                    }
                }
            }
        }
        //위치가 오른쪽인 경우
        else{
            //왼쪽에 기다리는 사람이 이제 없는 경우 
            if(arrivalRight.empty()){
                int index=arrivalLeft.front();
                int leftTime=arrivalInfo[index].first;

                //오른쪽에 기다리는 사람이 아직 안 온 경우 
                if(nowTime<leftTime){
                    nowTime=leftTime;
                }
                nowTime+=movingTime;
                nowPlace=LEFT;
            }
            //왼쪽에 기다리는 사람이 있는 경우 
            else{
                //오른쪽에 기다리는 사람이 이제 없는 경우 
                if(arrivalLeft.empty()){
                    int rightIndex=arrivalRight.front();
                    int rightTime=arrivalInfo[rightIndex].first;
                    
                    //왼쪽에 기다리는 사람이 아직 안 온 경우 
                    if(nowTime<rightTime){
                        nowTime=rightTime;
                    }
                    //왼쪽에 기다리는 사람이 이미 와있는 경우
                    else{
                        int tempCnt=0;
                        while(true){
                            if(arrivalRight.empty()){
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }

                            if(tempCnt==maxPeople){
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }

                            int realRightIndex=arrivalRight.front();
                            int realRightTime=arrivalInfo[realRightIndex].first;
                            if(realRightTime<=nowTime){
                                arrivalRight.pop();
                                answerTime[realRightIndex]=nowTime+movingTime;
                                cnt++;
                                tempCnt++;
                            }
                            else{
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }
                        }
                    }
                }
                else{
                    int rightIndex=arrivalRight.front();
                    int rightTime=arrivalInfo[rightIndex].first;
                    int leftIndex=arrivalLeft.front();
                    int leftTime=arrivalInfo[leftIndex].first;

                    if(rightTime<=nowTime){
                        int tempCnt=0;
                        while(true){
                            if(arrivalRight.empty()){
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }

                            if(tempCnt==maxPeople){
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }

                            int realRightIndex=arrivalRight.front();
                            int realRightTime=arrivalInfo[realRightIndex].first;
                            if(realRightTime<=nowTime){
                                arrivalRight.pop();
                                answerTime[realRightIndex]=nowTime+movingTime;
                                cnt++;
                                tempCnt++;
                            }
                            else{
                                nowTime+=movingTime;
                                nowPlace=LEFT;
                                break;
                            }
                        }
                    }
                    else{
                        if(rightTime>leftTime){
                            if(nowTime<leftTime){
                                nowTime=leftTime;
                            }
                            nowTime+=movingTime;
                            nowPlace=LEFT;
                        }
                        else{
                            nowTime=rightTime;
                        }
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