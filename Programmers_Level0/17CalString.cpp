/*
문제:
    my_string은 "3 + 5"처럼 문자열로 된 수식입니다. 
    문자열 my_string이 매개변수로 주어질 때, 
    수식을 계산한 값을 return 하는 solution 함수를 완성해주세요.
제한 사항:
    연산자는 +, -만 존재합니다.
    문자열의 시작과 끝에는 공백이 없습니다.
    0으로 시작하는 숫자는 주어지지 않습니다.
    잘못된 수식은 주어지지 않습니다.
    5 ≤ my_string의 길이 ≤ 100
    my_string을 계산한 결과값은 1 이상 100,000 이하입니다.
        my_string의 중간 계산 값은 -100,000 이상 100,000 이하입니다.
        계산에 사용하는 숫자는 1 이상 20,000 이하인 자연수입니다.
        my_string에는 연산자가 적어도 하나 포함되어 있습니다.
    return type 은 정수형입니다.
    my_string의 숫자와 연산자는 공백 하나로 구분되어 있습니다.
*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    stringstream toString;
    toString.str(my_string);
    
    string buf, op;
    int one, two, time=0;
    
    while(toString>>buf){
        if(time==0){
            one=stoi(buf);
        }
        else{
            if(time%2==0){
                two=stoi(buf);
                if(op=="+"){
                    one+=two;
                }
                else{
                    one-=two;
                }
            }
            else{
                op=buf;
            }
        }
        time++;
    }
    
    return one;
}

/*
개선 사항:
    1. one을 while문 말고 밖에서 그냥 처음에 하나 받아오고 시작하면 좀 코드 이쁠 것 같다. 

배운 점:
    1. stringstream의 사용법
        1.1. stringstream ss; ss.str(string); 이렇게 사용
        1.2. ss>string변수; 하면 하나의 string 얻어오는 것이다. 
    2. stoi(string)하면 string을 int로 바꿀 수 있다. 
        2.1. string에 숫자말고 문자가 있으면 숫자만 나온다. 
        2.2. 33ABS이면 33이 나온다는 것이다.
*/