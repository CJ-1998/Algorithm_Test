/*
제목
    자연수 뒤집어 배열로 만들기

문제 설명
    자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.

제한 조건
    n은 10,000,000,000이하인 자연수입니다.

입출력 예
    n	return
    12345	[5,4,3,2,1]
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string temp=to_string(n);
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        answer.push_back(temp[i]-'0');
    }
    return answer;
}