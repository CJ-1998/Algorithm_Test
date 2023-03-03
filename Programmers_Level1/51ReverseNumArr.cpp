/*
문제:   
    자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.

제한 사항:
    n은 10,000,000,000이하인 자연수입니다.
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

/*
개선 사항:
    1. 10으로 나눈 나머지하면 뒤의 자리부터 나온다. 그리고 원래 값을 10으로 나누면서 반복하면 된다. 

배운 점:
    1. reverse(str.begin(), str.end()); 하면 string 뒤집어 준다. 
*/