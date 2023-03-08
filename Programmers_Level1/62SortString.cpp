/*
문제:
    문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

제한 사항:
    strings는 길이 1 이상, 50이하인 배열입니다.
    strings의 원소는 소문자 알파벳으로 이루어져 있습니다.
    strings의 원소는 길이 1 이상, 100이하인 문자열입니다.
    모든 strings의 원소의 길이는 n보다 큽니다.
    인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    for(int i=0;i<strings.size()-1;i++){
        for(int j=i+1;j<strings.size();j++){
            if(strings[i][n]>strings[j][n]){
                string temp=strings[j];
                strings[j]=strings[i];
                strings[i]=temp;
            }
            else if(strings[i][n]==strings[j][n]){
                if(strings[i]>strings[j]){
                    string t=strings[j];
                    strings[j]=strings[i];
                    strings[i]=t;
                }
            }
        }
    }
    return strings;
}

/*
개선 사항:
    1. sort의 비교 함수를 index의 값이 같으면 string을 비교하고 다르면 index 값 비교하게 해서 sort 함수 돌리면 된다. 
    2. pair로 index의 값과 string을 넣고 sort한다. pair를 sort할 때 앞의 값을 1차로 비교하고 같으면 뒤의 값을 2차로 비교한다. 

배운 점:
    1. pair<자료형, 자료형> 변수명; 하면 pair형 변수 만들 수 있다. 
    2. make_pair(자료형 값, 자료형 값); 하면 pair형 변수 초기화할 수 있다. 
    3. pair를 sort할 때 앞의 값을 1차로 비교하고 같으면 뒤의 값을 2차로 비교한다.
*/