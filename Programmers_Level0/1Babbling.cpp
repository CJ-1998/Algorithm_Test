/*
문제:
    머쓱이는 태어난 지 6개월 된 조카를 돌보고 있습니다. 
    조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음을 
    최대 한 번씩 사용해 조합한(이어 붙인) 발음밖에 하지 못합니다. 
    문자열 배열 babbling이 매개변수로 주어질 때, 
    머쓱이의 조카가 발음할 수 있는 단어의 개수를 
    return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ babbling의 길이 ≤ 100
    1 ≤ babbling[i]의 길이 ≤ 15
    babbling의 각 문자열에서 "aya", "ye", "woo", "ma"는 각각 최대 한 번씩만 등장합니다.
    즉, 각 문자열의 가능한 모든 부분 문자열 중에서 "aya", "ye", "woo", "ma"가 한 번씩만 등장합니다.
    문자열은 알파벳 소문자로만 이루어져 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int rotateTime=0;
    
    for(int i=0;i<babbling.size();i++){
        if(!babbling[i].compare("aya")||!babbling[i].compare("ye")||
           !babbling[i].compare("woo")||!babbling[i].compare("ma")){
            answer++;
            continue;
        }
        string temp=babbling[i];
        for(int j=0;j<5;j++){
            if(!temp.compare("")){
                answer++;
                break;
            }
            if(temp.find("aya")==0||temp.find("woo")==0){
                temp=temp.substr(3);
            }
            else if(temp.find("ye")==0||temp.find("ma")==0){
                temp=temp.substr(2);
            }
            else{
                break;
            }
        }
    }
    return answer;
}

/*
개선 사항:
    위에서 단어와 compare 하지 말고 그냥 다 아래에서
    find하고 substr해서 ""이면 answer++하게 해도 될 것 같다. 

배운 점:
    1. compare는 같으면 0을 반환하니 if나 while에서 주의해야 한다. 
    2. find(string)해서 있으면 string이 시작하는 index를 반환.
    3. substr(num)은 index num부터 끝까지 string 자름.
*/