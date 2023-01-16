/*
문제:
    영어에선 a, e, i, o, u 다섯 가지 알파벳을 모음으로 분류합니다. 문자열 my_string이 매개변수로 주어질 때 모음을 제거한 문자열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    my_string은 소문자와 공백으로 이루어져 있습니다.
    1 ≤ my_string의 길이 ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<char> collection={'a','e','i','o','u'};
    for(int i=0;i<my_string.length();i++){
        bool isCollection=false;
        for(int j=0;j<collection.size();j++){
            if(my_string[i]==collection[j]){
                isCollection=true;
                break;
            }
        }
        if(!isCollection){
            answer+=my_string[i];
        }
    }
    return answer;
}

/*
개선 사항:
    1. 비교할 것이 적으면 2중 for문 말고 그냥 if문으로 해도 된다. 

배운 점:
    1. 비교할 것이 적으면 2중 for문 말고 그냥 if문으로 해도 된다. 
    2. string에 값 추가는 그냥 +로 하면 된다.
*/