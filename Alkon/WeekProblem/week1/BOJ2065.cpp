/*
문제:
    강을 사이에 두고 위치한 두 정박장 사이를 한 대의 나룻배가 오가고 있다. 
    두 정박장은 강을 기준으로 왼쪽(left), 오른쪽(right)으로 구분한다. 
    제일 처음에는 나룻배가 왼쪽 정박장에 위치해 있다. 
    이 나룻배는 한번에 최대 M명의 사람을 태울 수 있으며, 한 쪽 정박장에서 다른 쪽 정박장으로 이동하는데 양쪽 방향 모두 t만큼의 시간이 걸린다. 
    나룻배는 손님을 한 쪽 정박장에서 다른 쪽 정박장으로 실어 나르며 두 정박장 사이를 움직인다.
    
    나룻배가 어떤 정박장에 도착하게 되면, 그 정박장으로 가고자 하는 사람들을 우선 모두 내려준다. 
    그 다음에는, 그 정박장에서 기다리고 있던 손님들을 배에 태울 수 있는 데까지 태운다. 
    손님이 배에 타는데 드는 시간은 없다고 가정하며, 가장 오래 기다린 사람이 먼저 배를 타게 된다. 
    손님을 다 태운 후에는 반대쪽 정박장으로 이동하게 된다. 
    만약 기다리던 손님이 없다면, 나룻배가 그 정박장에서 다음 손님을 기다리게 된다. 
    만약 기다리던 중 반대 쪽 정박장에 손님이 도착하면, 그 쪽 정박장으로 이동하게 된다.

    각각의 손님들이 어느 정박장에 언제 도착하는지에 대한 정보가 주어질 때, 각 손님들이 원하는 곳에 도착하게 되는 시간을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 세 정수 M, t, N이 주어진다. 
    다음 N개의 줄에는 각각의 손님이 정박장에 도착하는 시간과 도착하는 정박장의 위치가 주어진다. 
    손님이 정박장에 도착하는 시간은 10만 이하의 음이 아닌 정수이다.

출력:
    N개의 줄에, 입력받은 순서대로 각 손님이 목적지에 도착하게 되는 시간을 출력한다.
*/

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