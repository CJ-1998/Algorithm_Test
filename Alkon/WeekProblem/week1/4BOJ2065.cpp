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

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

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
    }

    int nowTime=0;
    string nowPlace=LEFT;

    int cnt=0;

    while(true){

        if(cnt==num){
            break;
        }

        if(nowPlace.compare(LEFT)==0){
            if(arrivalLeft.front()<=nowTime){
                
            }
            else{
                if(arrivalLeft.front()<arrivalRight.front()){
                    
                }
            }
        }
        else{

        }
    }

    

    return 0;
}