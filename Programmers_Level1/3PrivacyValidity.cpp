/*
문제:
    고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다. 약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다. 당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다. 수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

    예를 들어, A라는 약관의 유효기간이 12 달이고, 2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.
    당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

    모든 달은 28일까지 있다고 가정합니다.

    오늘 날짜를 의미하는 문자열 today, 약관의 유효기간을 담은 1차원 문자열 배열 terms와 수집된 개인정보의 정보를 담은 1차원 문자열 배열 privacies가 매개변수로 주어집니다. 이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

제한 사항:
    today는 "YYYY.MM.DD" 형태로 오늘 날짜를 나타냅니다.
    1 ≤ terms의 길이 ≤ 20
        terms의 원소는 "약관 종류 유효기간" 형태의 약관 종류와 유효기간을 공백 하나로 구분한 문자열입니다.
        약관 종류는 A~Z중 알파벳 대문자 하나이며, terms 배열에서 약관 종류는 중복되지 않습니다.
        유효기간은 개인정보를 보관할 수 있는 달 수를 나타내는 정수이며, 1 이상 100 이하입니다.
    1 ≤ privacies의 길이 ≤ 100
        privacies[i]는 i+1번 개인정보의 수집 일자와 약관 종류를 나타냅니다.
        privacies의 원소는 "날짜 약관 종류" 형태의 날짜와 약관 종류를 공백 하나로 구분한 문자열입니다.
        날짜는 "YYYY.MM.DD" 형태의 개인정보가 수집된 날짜를 나타내며, today 이전의 날짜만 주어집니다.
        privacies의 약관 종류는 항상 terms에 나타난 약관 종류만 주어집니다.
    today와 privacies에 등장하는 날짜의 YYYY는 연도, MM은 월, DD는 일을 나타내며 점(.) 하나로 구분되어 있습니다.
        2000 ≤ YYYY ≤ 2022
        1 ≤ MM ≤ 12
        MM이 한 자릿수인 경우 앞에 0이 붙습니다.
        1 ≤ DD ≤ 28
        DD가 한 자릿수인 경우 앞에 0이 붙습니다.
    파기해야 할 개인정보가 하나 이상 존재하는 입력만 주어집니다.
*/


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> getDate(string today){
    //날짜형식 string을 받아서 .을 제거하고 년월일을 int로 바꾸고 vector에 넣어 반환하는 함수. 
    while(today.find(".")!=string::npos){
        int temp=today.find(".");
        today[temp]=' ';
    }
    
    vector<int> day;
    
    stringstream stream;
    stream.str(today);
    int d;
    
    while(stream>>d){
        day.push_back(d);
    }
    
    return day;
}

vector<string> getString (string str){
    //공백으로 구분된 stirng을 vector에 넣어 반환하는 함수.
    vector<string> strList;
    
    stringstream s;
    s.str(str);
    string temp;
    
    while(s>>temp){
        strList.push_back(temp);
    }
    
    return strList;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> day=getDate(today);
    
    map<string,int> m;
    
    for(int i=0;i<terms.size();i++){
        //알파벳과 month를 map에 넣는 for문.
        
        vector<string> str=getString(terms[i]);
        
        string grade;
        int month;
        
        grade=str[0];
        month=stoi(str[1]);
        
        m[grade]=month;
    }
    
    vector<vector<int>> dateList;
    vector<string> gradeList;
    
    for(int i=0;i<privacies.size();i++){
        //날짜와 약관 종류를 vector에 구분해서 넣는 for문.
        vector<string> s=getString(privacies[i]);
        
        gradeList.push_back(s[1]);
        
        dateList.push_back(getDate(s[0]));
        
    }
    
    for(int i=0;i<privacies.size();i++){
        int mon=m[gradeList[i]];
        
        int y=mon/12;
        int mn=mon%12;
        
        dateList[i][0]+=y;
        dateList[i][1]+=mn;
        //유효기간을 날짜에 더하는 것.
        
        if(dateList[i][1]!=12){
            dateList[i][0]+=dateList[i][1]/12;
            dateList[i][1]=dateList[i][1]%12;
        }
        //month가 13이상이면 year에 추가하는 것.
        
        dateList[i][2]-=1;
        if(dateList[i][2]==0){
            dateList[i][2]=28;
            dateList[i][1]-=1;
            if(dateList[i][1]==0){
                dateList[i][1]=12;
                dateList[i][0]-=1;
            }
        }
        //날짜에 하루를 빼는 것.
        
        if(dateList[i][0]<day[0]){
            answer.push_back(i+1);
        }
        else if(dateList[i][0]==day[0]){
            if(dateList[i][1]<day[1]){
                answer.push_back(i+1);
            }
            else if(dateList[i][1]==day[1]){
                if(dateList[i][2]<day[2]){
                    answer.push_back(i+1);
                }
            }
        }
        //년월일을 비교해서 현재 날짜 전이면 추가하는 것.
    }
    
    return answer;
}

/*
개선 사항:
    1. 날짜를 그냥 전체 일수로 바꿔서 비교하는 것이다. 

배운 점:
    1. map 사용법
    2. stringstream 사용법 
    3. string to int는 stoi 함수
*/