/*
문제:
    영어가 싫은 머쓱이는 영어로 표기되어있는 숫자를 
    수로 바꾸려고 합니다. 문자열 numbers가 매개변수로 
    주어질 때, numbers를 정수로 바꿔 return 하도록 
    solution 함수를 완성해 주세요.

제한 사항:
    numbers는 소문자로만 구성되어 있습니다.
    numbers는 "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 들이 공백 없이 조합되어 있습니다.
    1 ≤ numbers의 길이 ≤ 50
    "zero"는 numbers의 맨 앞에 올 수 없습니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(string numbers) {
    string stringToInt[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    long long answer = 0;
    for(int i=0;i<10;i++){
        while(true){
            int index=numbers.find(stringToInt[i]);
            if(index!=string::npos){
                numbers[index]=i+48;
                numbers.erase(index+1,stringToInt[i].length()-1);
            }
            else{
                break;
            }
        }
    }
    
    //answer=stoll(numbers);
    
    int exp=numbers.length()-1;
    for(int i=0;i<numbers.length();i++){
        answer+=(numbers[i]-48)*pow(10,exp);
        exp--;
    }
    cout<<numbers<<endl;
    cout<<answer<<endl;
    return answer;
}

/*
개선 사항:
    1. 값을 바꿀 때에는 replace 함수, 
    2. string을 숫자로 바꿀 때에는 stoll을 쓰면 좋을 것 같다.

배운 점:
    1. replace함수는 string 라이브러리에 있다. 
        1.1. 인자로 바꿀 문자열 시작 위치, 치환할 길이, 치환할 문자열 주면 된다. 
    2. stoll함수는 string 라이브러리에 있다. 
        2.1. string을 long long으로 바꿔주는 것이다.
*/