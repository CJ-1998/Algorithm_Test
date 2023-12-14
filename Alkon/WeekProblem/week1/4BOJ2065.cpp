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