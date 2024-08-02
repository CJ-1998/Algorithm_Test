/*
제목
    3진법 뒤집기

문제 설명
    자연수 n이 매개변수로 주어집니다. 
    n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 
    return 하도록 solution 함수를 완성해주세요.

제한사항
    n은 1 이상 100,000,000 이하인 자연수입니다.

입출력 예
    n	result
    45	7
    125	229
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    
    while(n!=0){
        three.push_back(n%3);
        n/=3;
    }
    
    int temp=0;
    for(int i=three.size()-1;i>=0;i--){
        answer+=three[temp++]*pow(3,i);
    }
    
    return answer;
}