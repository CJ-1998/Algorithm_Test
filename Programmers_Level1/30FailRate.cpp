/*
문제:
    슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다. 그녀가 만든 프랜즈 오천성이 대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다. 원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다.

    이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다. 역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서 위기에 빠지고 말았다. 오렐리를 위해 실패율을 구하는 코드를 완성하라.
        실패율은 다음과 같이 정의한다.
            스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

    전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때, 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

제한 사항:
    스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
    stages의 길이는 1 이상 200,000 이하이다.
    stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
        각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
        단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
    만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
    스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.
*/  

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> rate;
    for(int i=1;i<=N;i++){
        int pass=0;
        int fail=0;
        for(int j=0;j<stages.size();j++){
            if(stages[j]>=i){
                pass++;
                if(stages[j]==i){
                    fail++;
                }
            }
        }
        double temp=(double)fail/(double)(pass);
        if(pass==0)
            temp=0;
        rate.push_back(temp);
    }
    
    vector<double> cmp=rate;
    sort(cmp.begin(),cmp.end(),greater<double>());
    for(int i=0;i<cmp.size();i++){
        for(int j=0;j<rate.size();j++){
            if(cmp[i]==rate[j]){
                answer.push_back(j+1);
                rate[j]=-1;
            }
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. pair를 써서 실패율과 stage를 넣고 sort한 다음에 stage를 answer에 넣는 것이다. 

배운 점:
    1. double을 내림차순 sort할 때는 3번째 인자로 greater<double>() 줘야 한다. 
*/