/*
문제:
    군 전략가 머쓱이는 전쟁 중 적군이 다음과 같은 
    암호 체계를 사용한다는 것을 알아냈습니다.
        암호화된 문자열 cipher를 주고받습니다.
        그 문자열에서 code의 배수 번째 글자만 진짜 암호입니다.
    문자열 cipher와 정수 code가 매개변수로 주어질 때 
    해독된 암호 문자열을 return하도록
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ cipher의 길이 ≤ 1,000
    1 ≤ code ≤ cipher의 길이
    cipher는 소문자와 공백으로만 구성되어 있습니다.
    공백도 하나의 문자로 취급합니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int index=code;
    int i=1;
    while(index<=cipher.length()){
        answer+=cipher[index-1];
        i++;
        index=code*i;
    }
    return answer;
}

/*
배운 점:
    1. index는 0부터 시작한다.
*/