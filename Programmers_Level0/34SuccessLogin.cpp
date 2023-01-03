/*
문제:
    머쓱이는 프로그래머스에 로그인하려고 합니다. 
    머쓱이가 입력한 아이디와 패스워드가 담긴 배열 id_pw와 
    회원들의 정보가 담긴 2차원 배열 db가 주어질 때, 
    다음과 같이 로그인 성공, 실패에 따른 메시지를 
    return하도록 solution 함수를 완성해주세요.
        아이디와 비밀번호가 모두 일치하는 
        회원정보가 있으면 "login"을 return합니다.
        로그인이 실패했을 때 아이디가 일치하는 
        회원이 없다면 “fail”를, 아이디는 일치하지만 
        비밀번호가 일치하는 회원이 없다면 “wrong pw”를 return 합니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    for(int i=0;i<db.size();i++){
        if(!id_pw[0].compare(db[i][0])){
            if(!id_pw[1].compare(db[i][1])){
                return "login";
            }
            else{
                answer="wrong pw";
            }
        }
    }
    return answer;
}

/*
개선 사항:
    1. map에서 key를 id로 하고 value를 password로 한 후 찾는 것이다. 

배운 점:
    1. map에 key가 없는 것을 확인하려면 map.find(key)==map.end()이면 key가 없는 것이다. 
*/