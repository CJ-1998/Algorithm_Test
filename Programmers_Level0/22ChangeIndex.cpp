/*
문제:
    문자열 my_string과 정수 num1, num2가 매개변수로 
    주어질 때, my_string에서 인덱스 num1과 인덱스 num2에 
    해당하는 문자를 바꾼 문자열을 return 하도록 
    solution 함수를 완성해보세요.

제한 사항:
    1 < my_string의 길이 < 100
    0 ≤ num1, num2 < my_string의 길이
    my_string은 소문자로 이루어져 있습니다.
    num1 ≠ num2
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    char temp;
    temp=my_string[num1];
    my_string[num1]=my_string[num2];
    my_string[num2]=temp;
    return my_string;
}

/*
개선 사항:
    1. swap 함수를 사용하면 좋을 것 같다. 

배운 점:
    1. swap 함수는 algorithm 라이브러이에 있다. 
    2. swap(a, b)를 하면 a와 b의 값이 바뀐다. 
*/