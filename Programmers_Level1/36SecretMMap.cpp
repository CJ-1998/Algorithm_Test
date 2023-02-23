/*
문제:
    네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다. 그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다. 다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.

    1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
    2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
    3. "지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
    4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.

    네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.

입력 형식:
    입력으로 지도의 한 변 크기 n 과 2개의 정수 배열 arr1, arr2가 들어온다.

        1 ≦ n ≦ 16
        arr1, arr2는 길이 n인 정수 배열로 주어진다.
        정수 배열의 각 원소 x를 이진수로 변환했을 때의 길이는 n 이하이다. 즉, 0 ≦ x ≦ 2n - 1을 만족한다.

출력 형식:
    원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string getStr(int n, int num){
    string str;
    while(num!=0){
        if(num%2==1){
            str+='#';
        }
        else{
            str+=' ';
        }
        num/=2;
    }
    int len=n-str.length();
    for(int i=0;i<len;i++){
        str+=' ';
    }
    reverse(str.begin(),str.end());
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> one;
    vector<string> two;
    
    for(int i=0;i<n;i++){
        one.push_back(getStr(n,arr1[i]));
        two.push_back(getStr(n,arr2[i]));
    }
    
    for(int i=0;i<n;i++){
        string temp;
        for(int j=0;j<n;j++){
            if(one[i][j]=='#'||two[i][j]=='#'){
                temp+='#';
            }
            else{
                temp+=' ';
            }
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}

/*
개선 사항:
    1.  | 비트 연산자로 겹친 곳의 수를 알아낸 것이다. 
        그리고 이것을 이진수로 바꾸고 string으로 바꾼다. 
        string으로 바꿀 때에도 숫자에서 5번 >>1 해서 2씩 나눈 것이다.

배운 점:
    1. reverse 함수 사용법
        1-1. algorithm 라이브러리에 있다. 
        1-2. reverse(str.begin(), str.end()); 하면 str을 뒤집어준다.
*/