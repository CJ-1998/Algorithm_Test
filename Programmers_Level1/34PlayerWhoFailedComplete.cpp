/*
문제:
    수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
    마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한 사항:
    마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
    completion의 길이는 participant의 길이보다 1 작습니다.
    참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
    참가자 중에는 동명이인이 있을 수 있습니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    for(int i=0;i<completion.size();i++){
        if(participant[i].compare(completion[i])){
            answer=participant[i];
            break;
        }
    }
    if(!answer.compare("")){
        answer=participant[participant.size()-1];
    }
    return answer;
}

/*
개선 사항:
    1. unordered_map 사용한 풀이다. 완주자에서 값이 있으면 1씩 증가시키는 것이다. 참여자에서 값이 있으면 1씩 감소시키는 것이다. 
    2. unordered_multset을 사용한 풀이다. 참여자를 넣고 완주자를 찾아서 지운다. 그리고 남은 것의 값을 반환하면 된다. 
    3. xor swap 이라는데 뭔지 모르겠다. 

배운 점:
    1. unordered_map은 hash table로 구현한 자료구조로 탐색 시간 복잡도는 O(1)이다.
        1-1. unordered_map 라이브러리에 있다. 
        1-2. 중복 데이터를 허용하지 않고 map에 비해 데이터 많을 때 성능 좋다. 
        1-3. key가 유사한 데이터 많으면 hash 충돌로 성능 떨어질 수 있다. 
        1-4. unordered_map<key, value> 이름; 이렇게 선언한다. 
        1-5. um.find(key); 해서 찾으면 iter, 못 찾으면 end()를 반환한다. 
        1-6. um.insert({key, value}); 이렇게 값을 넣는다. 
    2. unordered_multiset은 hash table로 구성되어 있고 중복이 허용되는 것이다. 
        2-1. unordered_multiset은 set, multiset과 달리 삽입한 순서 유지하는 것이다. 
        2-2. unordered_set 라이브러리에 있다.
*/