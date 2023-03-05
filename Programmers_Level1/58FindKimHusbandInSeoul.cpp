/*
문제:
    String형 배열 seoul의 element중 "Kim"의 위치 x를 찾아, "김서방은 x에 있다"는 String을 반환하는 함수, solution을 완성하세요. seoul에 "Kim"은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.

제한 사항:
    seoul은 길이 1 이상, 1000 이하인 배열입니다.
    seoul의 원소는 길이 1 이상, 20 이하인 문자열입니다.
    "Kim"은 반드시 seoul 안에 포함되어 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for(int i=0;i<seoul.size();i++){
        if(!seoul[i].compare("Kim")&&seoul[i].length()==3){
            answer+=to_string(i);
            answer+="에 있다";
            break;
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. find 함수를 사용해서 index를 찾으면 된다. 

배운 점:
    1. find(vec.begin(), vec.end(), “str”)-vec.begin(); 하면 vector에서 str가 있는 index를 찾을 수 있다. 
    2. 숫자를 string으로 바꿀 때 to_string(num) 사용하면 된다.
*/