/*
문제 설명:
    자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.
        조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.  
        조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
        조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
    예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.
    
    자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.

제한 사항:
    n은 1,000,000 이하의 자연수 입니다.
*/

#include <string>
#include <vector>
#include <bitset>

using namespace std;

int rtnone(int num){
    int one=0;
    
    bitset<30> bs(num);
    string str=bs.to_string();
    str=str.substr(str.find('1'));
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='1'){
            one++;
        }
    }
    
    return one;
}

int solution(int n) {
    int answer = 0;
    
    int none=rtnone(n);
    
    int cmp=n+1;
    
    while(true){
        if(none==rtnone(cmp)){
            answer=cmp;
            break;
        }
        else
            cmp++;
    }

    return answer;
}

/*
배운 점:
    1. integer to binary string 하는 방법에 bitset 사용하는 방법이 있다. 
    2. #include<bitset>에 들어있다. 
    3. bitset<자리수> bs(int); string s=bs.to_string(); s=s.substr(s.find(’1’)); 하면 된다. 
    4. 또는 to_binary(int); 함수 사용하면 된다.
*/