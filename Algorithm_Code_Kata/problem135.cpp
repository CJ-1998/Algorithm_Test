/*
제목
    단어 변환

문제 설명
    두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 
    아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.
        1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
        2. words에 있는 단어로만 변환할 수 있습니다.

    예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

    두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 
    최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
    각 단어는 알파벳 소문자로만 이루어져 있습니다.
    각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
    words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
    begin과 target은 같지 않습니다.
    변환할 수 없는 경우에는 0를 return 합니다.

입출력 예
    begin	target	words	return
    "hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
    "hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int count (string begin, string target, vector<string> words, int num){
    if(begin.compare(target)==0){
        return num;
    }
    
    vector<string> minusone;
    for(int i=0;i<words.size();i++){
        int cnt=0;
        for(int j=0;j<begin.size();j++){
            if(words[i][j]==begin[j])
                cnt++;
        }
        
        if(cnt==begin.size()-1){
            minusone.push_back(words[i]);
        }
    }
    
    if(minusone.size()==0){
        return 9999999;
    }
    else{
        vector<int> best;
        for(int i=0;i<minusone.size();i++){
            vector<string> temp = words;
            temp.erase(remove(temp.begin(),temp.end(),minusone[i]),temp.end());
            int ret = count(minusone[i],target,temp,num+1);
            best.push_back(ret);
        }
        sort(best.begin(),best.end());
        return best[0];
    }
    
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(),words.end(),target)==words.end()){
        return 0;
    }
    
    answer=count(begin, target, words, 0);
    
    
    return answer;
}

/*
오래 걸린 이유:
    글자 같은 것 개수 구할 때 find 함수 써서 자리수 다른 것까지 체크함
*/