/*
문제:
    문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. 
    str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
    예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

제한 조건:
    s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream stream;
    stream.str(s);
    int num;
    vector<int> v;
    while(stream>>num){
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    
    answer+=to_string(v[0]);
    answer+=" ";
    answer+=to_string(v[v.size()-1]);
    
    return answer;
}

/*


배운 점:
    1. stringstream 사용법
    2. int to string은 to_string 함수 사용
    3. -도 같이 묶어서 stoi하면 음수로 인식한다. 
*/