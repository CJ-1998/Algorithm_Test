/*
문제:
    문자열 my_string이 매개변수로 주어집니다. my_string은 소문자, 대문자, 자연수로만 구성되어있습니다. my_string안의 자연수들의 합을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string의 길이 ≤ 1,000
    1 ≤ my_string 안의 자연수 ≤ 1000
    연속된 수는 하나의 숫자로 간주합니다.
    000123과 같이 0이 선행하는 경우는 없습니다.
    문자열에 자연수가 없는 경우 0을 return 해주세요.
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<int> num;
    for(int i=0;i<my_string.length();i++){
        if(48<=my_string[i]&&my_string[i]<=57){
            num.push_back(my_string[i]-'0');
        }
        else{
            num.push_back(-1);
        }
    }
    for(int i=0;i<my_string.length();i++){
        int index=0;
        int temp=i;
        bool check=false;
        while(true){
            if(temp==my_string.length()){
                break;   
            }
            if(num[temp]==-1){
                break;
            }
            else{
                check=true;
                index++;
                temp++;
            }
        }
        if(check){
            for(int j=0;j<index;j++){
                answer+=num[i+j]*pow(10,index-j-1);
            }
            i=i+index-1;
        }
    }
    return answer;
}

/*
개선 사항:
    1. 숫자 아닌 것은 지우고 stringstream으로 숫자 뽑아내면 된다. 

배운 점:
    1. stringstream의 사용법
    2. 문자열 안에서 숫자 뽑을 때에는 stringstream 사용하자.
    3. isdigit(string) 하면 char가 숫자인지 아닌지 반환한다. 숫자면 true
    4. 숫자 아스키 코드는 48~57이다.
*/