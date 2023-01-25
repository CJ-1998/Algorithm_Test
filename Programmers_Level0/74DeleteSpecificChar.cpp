/*
문제:
    문자열 my_string과 문자 letter이 매개변수로 주어집니다. my_string에서 letter를 제거한 문자열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string의 길이 ≤ 100
    letter은 길이가 1인 영문자입니다.
    my_string과 letter은 알파벳 대소문자로 이루어져 있습니다.
    대문자와 소문자를 구분합니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(int i=0;i<my_string.length();i++){
        if(my_string[i]!=letter[0]){
            answer+=my_string[i];
        }
    }
    return answer;
}

/*
개선 사항:
    1. string에서 특정 문자 제거하려면 str.erase(remove(str.begin(), str.end(),char), str.end());

배운 점:
    1. tring에서 특정 문자 제거하려면 str.erase(remove(str.begin(), str.end(),char), str.end());
    2. 한 문자 string을 char로 하려면 str[0];
    3. remove 함수는 algorithm 라이브러리에 있다. 
    4. remove(시작 반복자, 종료 반복자, 살제할 원소 값); 하면 해당 원소를 찾으면 삭제한다. 
    5. 하지만 벡터나 string 크기 변화가 없어서 줄어든만큼 뒤에 값이 남아있다. 
    6. 그래서 v.resize(it - v.begin()); 해야 한다. 
    7. 여기서 it은 remove의 반환 값인 반복자이다.
*/