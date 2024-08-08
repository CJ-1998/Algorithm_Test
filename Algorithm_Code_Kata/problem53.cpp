/*
제목
    숫자 짝꿍

문제 설명
    두 정수 X, Y의 임의의 자리에서 공통으로 나타나는 정수 k(0 ≤ k ≤ 9)들을 
    이용하여 만들 수 있는 가장 큰 정수를 두 수의 짝꿍이라 합니다
    (단, 공통으로 나타나는 정수 중 서로 짝지을 수 있는 숫자만 사용합니다). 
    X, Y의 짝꿍이 존재하지 않으면, 짝꿍은 -1입니다. X, Y의 짝꿍이 0으로만 구성되어 있다면, 짝꿍은 0입니다.

    예를 들어, X = 3403이고 Y = 13203이라면, X와 Y의 짝꿍은 X와 Y에서 
    공통으로 나타나는 3, 0, 3으로 만들 수 있는 가장 큰 정수인 330입니다. 
    다른 예시로 X = 5525이고 Y = 1255이면 X와 Y의 짝꿍은 X와 Y에서 
    공통으로 나타나는 2, 5, 5로 만들 수 있는 가장 큰 정수인 552입니다
    (X에는 5가 3개, Y에는 5가 2개 나타나므로 남는 5 한 개는 짝 지을 수 없습니다.)

    두 정수 X, Y가 주어졌을 때, X, Y의 짝꿍을 return하는 solution 함수를 완성해주세요.

제한사항
    3 ≤ X, Y의 길이(자릿수) ≤ 3,000,000입니다.
    X, Y는 0으로 시작하지 않습니다.
    X, Y의 짝꿍은 상당히 큰 정수일 수 있으므로, 문자열로 반환합니다.

입출력 예
    X	Y	result
    "100"	"2345"	"-1"
    "100"	"203045"	"0"
    "100"	"123450"	"10"
    "12321"	"42531"	"321"
    "5525"	"1255"	"552"
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string x, string y) {
    
    string answer = "";
    
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    
    vector<int> vx;
    vector<int> vy;
    vector<int> cnt;
    
    for(int i=0;i<10;i++){
        vx.push_back(0);
        vy.push_back(0);
        cnt.push_back(0);
    }
    
    for(int i=0;i<x.length();i++){
        int temp=x[i]-'0';
        vx[temp]++;
    }
    
    for(int i=0;i<y.length();i++){
        int temp=y[i]-'0';
        vy[temp]++;
    }
    
    bool same=false;
    
    for(int i=0;i<10;i++){
        if(vx[i]!=0&&vy[i]!=0){
            if(vx[i]<vy[i]){
                cnt[i]=vx[i];
            }
            else{
                cnt[i]=vy[i];
            }
            same=true;
        }
    }
    if(same){
        for(int i=9;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                answer+=i+'0';
            }
        }
    }
    else{
        answer="-1";
    }
    
    if(answer[0]=='0'){
        answer="0";
    }
    
    /*
    // 자릿수 크면 여기서 오류남
    int t = stoi(answer);
    answer = to_string(t);
    */
    
    return answer;
}

/*
틀린 이유
    - 처음에는 string.find로 한 String 순회하면서 각 자리수의 숫자가 있는지 찾아서 시간초과남
    - stoi나 to_string 함수 사용하면 자릿수 크면 오류 발생함
*/