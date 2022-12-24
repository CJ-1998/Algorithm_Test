/*
문제:
    영어 대소문자로 이루어진 문자열 my_string이 
    매개변수로 주어질 때, my_string을 모두 소문자로 바꾸고
    알파벳 순서대로 정렬한 문자열을 return 하도록 
    solution 함수를 완성해보세요.

제한 사항:
    0 < my_string 길이 < 100
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    int len=my_string.length();
    char* upperString = new char[len];
    
    for(int i=0;i<len;i++){
        char tempChar=my_string.at(i);
        if(64<tempChar&&tempChar<91){
            tempChar+=32;
        }
        upperString[i]=tempChar;
    }
    
    sort(upperString,upperString+len);
    for(int i=0;i<len;i++){
        answer+=upperString[i];
    }
    
    return answer;
}

/*
개선 사항:
    1. tolower 함수를 사용하면 더 간단하게 할 수 있다. 
    2. 더 나아가 transform 함수 사용하면 더 간단히 할 수 있다. 

배운 점:
    1. 아스키코드표에서 A-Z는 65~90이고 a-z는 97~122이다. 
    2. 아스키코드에서 소문자-대문자는 32이다. 
    3. sort함수는 algorithm 라이브러리에 있고 sort(배열, 배열+배열 길이)하면 오름차순 정렬 된다. 
    4. sort(배열, 배열+배열 길이, greater<자료형>()) 하면 내림차순 정렬 된다. 
    5. 벡터에 쓸 때는 앞에 2개 인자를 v.begin(), v.end()로 하면 된다. 
    6. transform 함수
    7. tolower, toupper 함수
    8. string[i], string.begin(), string.end()
*/