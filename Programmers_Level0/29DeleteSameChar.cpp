/*
문제:
    문자열 my_string이 매개변수로 주어집니다. 
    my_string에서 중복된 문자를 제거하고 
    하나의 문자만 남긴 문자열을 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string ≤ 110
    my_string은 대문자, 소문자, 공백으로 구성되어 있습니다.
    대문자와 소문자를 구분합니다.
    공백(" ")도 하나의 문자로 구분합니다.
    중복된 문자 중 가장 앞에 있는 문자를 남깁니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i=0;i<my_string.length()-1;i++){
        for(int j=i+1;j<my_string.length();j++){
            if(my_string[i]==my_string[j]){
                my_string.erase(my_string.begin()+j);
                j--;
            }
        }
    }
    answer=my_string;
    return answer;
}

/*
개선 사항:
    1. map 사용해서 value가 0일 때만 answer에 추가하면 된다. 

배운 점:
    1. string에서 문자 개수는 map을 사용하면 좋다. 
    2. 문자를 key로 개수를 value로 하면 좋다.
*/