/*
제목
    공원 산책

문제 설명
    지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 
    격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다. 
    산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며,
     명령은 다음과 같은 형식으로 주어집니다.
        ["방향 거리", "방향 거리" … ]

    예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다. 
    로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.
        주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.
        주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.

    위 두 가지중 어느 하나라도 해당된다면, 
    로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.
    공원의 가로 길이가 W, 세로 길이가 H라고 할 때, 
    공원의 좌측 상단의 좌표는 (0, 0), 우측 하단의 좌표는 (H - 1, W - 1) 입니다.

    공원을 나타내는 문자열 배열 park, 로봇 강아지가 
    수행할 명령이 담긴 문자열 배열 routes가 매개변수로 주어질 때, 
    로봇 강아지가 모든 명령을 수행 후 놓인 위치를 
    [세로 방향 좌표, 가로 방향 좌표] 순으로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항
    3 ≤ park의 길이 ≤ 50
    3 ≤ park[i]의 길이 ≤ 50
        park[i]는 다음 문자들로 이루어져 있으며 시작지점은 하나만 주어집니다.
            S : 시작 지점
            O : 이동 가능한 통로
            X : 장애물
        park는 직사각형 모양입니다.
    
    1 ≤ routes의 길이 ≤ 50
        routes의 각 원소는 로봇 강아지가 수행할 명령어를 나타냅니다.
        로봇 강아지는 routes의 첫 번째 원소부터 순서대로 명령을 수행합니다.
        routes의 원소는 "op n"과 같은 구조로 이루어져 있으며, op는 이동할 방향, n은 이동할 칸의 수를 의미합니다.
    
        op는 다음 네 가지중 하나로 이루어져 있습니다.
            N : 북쪽으로 주어진 칸만큼 이동합니다.
            S : 남쪽으로 주어진 칸만큼 이동합니다.
            W : 서쪽으로 주어진 칸만큼 이동합니다.
            E : 동쪽으로 주어진 칸만큼 이동합니다.
        1 ≤ n ≤ 9

입출력 예
    park	routes	result
    ["SOO","OOO","OOO"]	["E 2","S 2","W 1"]	[2,1]
    ["SOO","OXX","OOO"]	["E 2","S 2","W 1"]	[0,1]
    ["OSO","OOO","OXO","OOO"]	["E 2","S 3","W 1"]	[0,0]
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<char>> graph;
    
    int startx=0;
    int starty=0;
    
    int xmax=park.size();
    int ymax=park[0].size();
    
    for(int i=0;i<xmax;i++){
        vector<char> temp;
        for(int j=0;j<ymax;j++){
            if(park[i][j]=='S'){
                startx=i;
                starty=j;
                temp.push_back('o');
            }
            else if(park[i][j]=='O'){
                temp.push_back('o');
            }
            else{
                temp.push_back('x');
            }
        }
        graph.push_back(temp);
    }
    
    // for(int i=0;i<graph.size();i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int nowx=startx;
    int nowy=starty;
    
    for(int i=0;i<routes.size();i++){
        int distance = routes[i][2]-'0';
        
        if(routes[i][0]=='E'){
            if(nowy+distance>=ymax){
                continue;
            }
            else{
                bool check=false;
                for(int i=nowy+1;i<=nowy+distance;i++){
                    if(graph[nowx][i]=='x'){
                        check=true;
                        break;
                    }
                }
                if(check){
                    continue;
                }
                else{
                    nowy+=distance;
                }
            }
        }
        else if(routes[i][0]=='W'){
            if(nowy-distance<0){
                continue;
            }
            else{
                bool check=false;
                for(int i=nowy-1;i>=nowy-distance;i--){
                    if(graph[nowx][i]=='x'){
                        check=true;
                        break;
                    }
                }
                if(check){
                    continue;
                }
                else{
                    nowy-=distance;
                }
            }
        }
        else if(routes[i][0]=='S'){
            if(nowx+distance>=xmax){
                continue;
            }
            else{
                bool check=false;
                for(int i=nowx+1;i<=nowx+distance;i++){
                    if(graph[i][nowy]=='x'){
                        check=true;
                        break;
                    }
                }
                if(check){
                    continue;
                }
                else{
                    nowx+=distance;
                }
            }
        }
        else{
            if(nowx-distance<0){
                continue;
            }
            else{
                bool check=false;
                for(int i=nowx-1;i>=nowx-distance;i--){
                    if(graph[i][nowy]=='x'){
                        check=true;
                        break;
                    }
                }
                if(check){
                    continue;
                }
                else{
                    nowx-=distance;
                }
            }
            
        }
    }
    
    answer.push_back(nowx);
    answer.push_back(nowy);
    
    return answer;
}

/*
걸린 시간 : 18m36s
*/