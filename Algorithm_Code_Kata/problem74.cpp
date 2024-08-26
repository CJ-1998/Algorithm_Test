/*
제목
    괄호 회전하기

문제 설명
    다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.
        (), [], {} 는 모두 올바른 괄호 문자열입니다.
        만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 
        예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
        만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 
        예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.
    
    대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 
    이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 
    문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
    s의 길이는 1 이상 1,000 이하입니다.

입출력 예
    s	        result
    "[](){}"	3
    "}]()[{"	2
    "[)(]"	    0
    "}}}"	    0
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int a1=0;
    int a2=0;
    int b1=0;
    int b2=0;
    int c1=0;
    int c2=0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            a1++;
        }else if(s[i]=='}'){
            a2++;
        }else if(s[i]=='['){
            b1++;
        }else if(s[i]==']'){
            b2++;
        }else if(s[i]=='('){
            c1++;
        }else if(s[i]==')'){
            c2++;
        }
    }
    
    if(a1!=a2||b1!=b2||c1!=c2){
        return 0;
    }
    
    for(int i=0;i<s.length();i++){
        stack<char> stk;
        for(int j=0;j<s.length();j++){
            if(stk.empty()){
                stk.push(s[j]);
            }
            else{
                if(s[j]=='}'&&stk.top()=='{'){
                    stk.pop();
                }else if(s[j]==']'&&stk.top()=='['){
                    stk.pop();
                }else if(s[j]==')'&&stk.top()=='('){
                    stk.pop();
                }else{
                    stk.push(s[j]);
                }
            }
        }
        if(stk.empty()){
            answer++;
        }
        rotate(s.begin(),s.begin()+1,s.end());
    }
    
    
    return answer;
}