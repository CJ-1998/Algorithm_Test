/*
문제:
    괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 
    예를 들어
        "()()" 또는 "(())()" 는 올바른 괄호입니다.  
        ")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.
    '(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

제한 사항:
    문자열 s의 길이 : 100,000 이하의 자연수
    문자열 s는 '(' 또는 ')' 로만 이루어져 있습니다.
*/

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            stk.push(s[i]);
        }
        else{
            if(stk.empty()){
                answer=false;
                break;
            }
            stk.pop();
        }
    }
    
    if(!stk.empty()){
        answer=false;
    }

    return answer;
}

/*
개선 사항:
    1. stack 사용하지 않고 (와 )의 개수로 할 수 있다. 

배운 점:
    1. stack 사용법.
    2. stack은 stack.push(element), stack.pop()으로 사용하면 된다. 
*/