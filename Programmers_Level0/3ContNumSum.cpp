/*
문제:
    연속된 세 개의 정수를 더해 12가 되는 경우는 3, 4, 5입니다. 
    두 정수 num과 total이 주어집니다. 
    연속된 수 num개를 더한 값이 total이 될 때, 
    정수 배열을 오름차순으로 담아 return하도록 solution함수를 완성해보세요.

제한사항:
    1 ≤ num ≤ 100
    0 ≤ total ≤ 1000
    num개의 연속된 수를 더하여 total이 될 수 없는 
    테스트 케이스는 없습니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int plusNum=0;
    for(int i=1;i<num;i++){
        plusNum+=i;
    }
    int firstNum=(total-plusNum)/num;
    for(int i=0;i<num;i++){
        answer.push_back(firstNum+i);
    }
    return answer;
}

/*
개선할 것:
    1. 등차 관련 구하는 식이 있어서 사용하면 좋을 듯
    2. 초기 값을 구하는 식: 전체 합=n{2*a+(n-1)d}/2
    3. n=전체 항 개수, a=초기 값, d=등차
    4. 여기서 n은 num이고 d는 연속된 수이니 1

배운 점: 
    1. 벡터에 값을 넣는 함수는 vector.push_back(값); 이다.
    2. 연속된 수는 공차가 1인 등차수열이다.
*/