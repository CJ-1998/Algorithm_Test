/*
문제:
    수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
    
    1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
    2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
    3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

    1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 사항:
    시험은 최대 10,000 문제로 구성되어있습니다.
    문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
    가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> three={3,3,1,1,2,2,4,4,5,5};
    
    vector<int> num={0,0,0};
    
    int temp1=0;
    int temp2=0;
    int temp3=0;
    
    for(int i=0;i<answers.size();i++){
        if(one[temp1]==answers[i]){
            num[0]++;
        }
        if(two[temp2]==answers[i]){
            num[1]++;
        }
        if(three[temp3]==answers[i]){
            num[2]++;
        }
        temp1++;
        temp2++;
        temp3++;
        
        if(temp1==one.size()){
            temp1=0;
        }
        if(temp2==two.size()){
            temp2=0;
        }
        if(temp3==three.size()){
            temp3=0;
        }
    }
    
    vector<int> tnum=num;
    sort(num.begin(),num.end(),greater<int>());
    
    for(int i=0;i<num.size();i++)
    {
        if(tnum[i]==num[0]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. 찍는 방식 index와 answer index 맞추려면 나머지 연산 쓰면 된다. answer index%찍는 방식 개수 하면 된다. 

배운 점:
    1. vector에서 가장 큰 값 찾기 : *max_element(vec.begin(),vec.end());
*/