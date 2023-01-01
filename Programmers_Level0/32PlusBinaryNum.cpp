/*
문제:
    이진수를 의미하는 두 개의 문자열 bin1과 bin2가 
    매개변수로 주어질 때, 두 이진수의 합을 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    return 값은 이진수를 의미하는 문자열입니다.
    1 ≤ bin1, bin2의 길이 ≤ 10
    bin1과 bin2는 0과 1로만 이루어져 있습니다.
    bin1과 bin2는 "0"을 제외하고 0으로 시작하지 않습니다.
*/

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int one=0;
    int two=0;
    int j=0;
    
    for(int i=0;i<bin1.length();i++){
        if(bin1[i]=='1'){
            one+=pow(2,bin1.length()-1-i);
        }
    }
    for(int i=0;i<bin2.length();i++){
        if(bin2[i]=='1'){
            two+=pow(2,bin2.length()-1-i);
        }
    }
    
    int three=one+two;
    string threeString;
    j=0;
    if(three==0){
        answer="0";
    }
    else if(three==1){
        answer="1";
    }
    else{
        while(three>0){
            threeString+=(three%2)+48;
            three/=2;
        }
        for(int i=threeString.length()-1;i>=0;i--){
            answer+=threeString[i];
        }
    }
   
    return answer;
}

/*
개선 사항:
    1. reverse 함수를 사용하면 더 간단해진다. 

배운 점:
    1. reverse 함수는 문자열이나 벡터 뒤집을 때 사용하고 
        algorithm 라이브러리에 있으며 인자로 .start(), .end() 주면 된다. 
    2. string 변수에 더할 때 char로 더해도 되고 string으로 더해도 된다. 
    3. 숫자를 char로 만드려면 48을 더하면 된다. 
    4. 10진수 숫자를 이진수로 만드려면 값이 0보다 클 때까지 
        %2 값을 더하고 값을 2로 나눈 것으로 바꾸면 된다. 그리고 reverse 하면 된다.
*/