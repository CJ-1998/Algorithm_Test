/*
문제:
    문자열 my_str과 n이 매개변수로 주어질 때, 
    my_str을 길이 n씩 잘라서 저장한 배열을 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_str의 길이 ≤ 100
    1 ≤ n ≤ my_str의 길이
    my_str은 알파벳 소문자, 대문자, 숫자로 이루어져 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int start=0;
    int end=my_str.length();
    while(start<end){
        if(start+n<=end)
            answer.push_back(my_str.substr(start,n));
        else
            answer.push_back(my_str.substr(start));
        start+=n;
    }
    return answer;
}

/*
개선 사항:
    조건, 증감이 있는 것은 for문으로 간단히 할 수 있다. 
    그냥 substr 인자 2개 있는 것 해도 문자열 최대 길이 넘어도 
    그냥 끝까지만 자르는 것 같다. 그래서 if-else로 안 나눠도 되는 것 같다. 
    처음 오류는 start!=end가 조건이라 오류 난 것 같다. 

배운 점: 
    substr()의 사용법
*/