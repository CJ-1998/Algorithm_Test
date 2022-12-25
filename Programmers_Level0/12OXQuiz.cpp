/*
문제:
    덧셈, 뺄셈 수식들이 'X [연산자] Y = Z' 형태로 들어있는 
    문자열 배열 quiz가 매개변수로 주어집니다. 
    수식이 옳다면 "O"를 틀리다면 "X"를 순서대로 담은 배열을 
    return하도록 solution 함수를 완성해주세요.

제한 사항:
    연산 기호와 숫자 사이는 항상 하나의 공백이 존재합니다. 단 음수를 표시하는 마이너스 기호와 숫자 사이에는 공백이 존재하지 않습니다.
    1 ≤ quiz의 길이 ≤ 10
    X, Y, Z는 각각 0부터 9까지 숫자로 이루어진 정수를 의미하며, 각 숫자의 맨 앞에 마이너스 기호가 하나 있을 수 있고 이는 음수를 의미합니다.
    X, Y, Z는 0을 제외하고는 0으로 시작하지 않습니다.
    -10,000 ≤ X, Y ≤ 10,000
    -20,000 ≤ Z ≤ 20,000
    [연산자]는 + 와 - 중 하나입니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//string과 index를 받아서 하나의 숫자를 vector<char>로 반환하는 함수
vector<char> getOneNum(string oneExp, int index){
    vector<char> oneNum;
    while(oneExp[index]!=' '){
        oneNum.push_back(oneExp[index]);
        index++;
        if(index==oneExp.size()){
            break;
        }
    }
    return oneNum;
}

//vector<char>를 받아서 숫자로 변환해주는 함수
int getCharToNum(vector<char> num){
    int number=0;
    if(num[0]!='-'){
        for(int i=0;i<num.size();i++){
            number+=(num[i]-48)*pow(10,num.size()-i-1);
        }
    }
    else{
        for(int i=1;i<num.size();i++){
            number+=(num[i]-48)*pow(10,num.size()-i-1);
        }
        number*=-1;
    }
    return number;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(int i=0;i<quiz.size();i++){
        int index=0;
        bool isPlus=false;  //+이면 true
        
        vector<char> first=getOneNum(quiz[i],index);

        index=first.size()+1;   //연산자 있는 곳까지 index 이동
        if(quiz[i][index]=='+'){
            isPlus=true;
        }
        index+=2;   //다음 숫자 있는 곳까지 index 이동
        
        vector<char> second=getOneNum(quiz[i],index);
        
        index+=second.size()+3; //다음 숫자 있는 곳까지 index 이동
        
        vector<char> third=getOneNum(quiz[i],index);
        
        int one=getCharToNum(first);
        int two=getCharToNum(second);
        int three=getCharToNum(third);
        
        if(isPlus){
            if(one+two==three){
                answer.push_back("O");
            }
            else{
                answer.push_back("X");
            }
        }
        else{
            if(one-two==three){
                answer.push_back("O");
            }
            else{
                answer.push_back("X");
            }
        }
    }
    return answer;
}

/*
개선 사항:
    1. stringstream을 사용하면 훨씬 쉽게 할 수 있다. 

배운 점: 
    1. stringstream의 사용법
    2. stringstream은 sstream 라이브러리에 있다. 
    3. stringstream은 주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용하게 사용된다. 
    4. stringstream은 공백과 \n을 제외하고 문자열에서 맞는 자료형 정보 빼낸다. 
    5. stringstream.str(string)은 현재 stream의 값을 문자열로 바꾸는 것이다. 
    6. 그리고 string str변수를 선언한다. 
    7. 그리고 stream>>str 하면 str이 string 변수에 string을 받아오는 것이다.
*/