/*
제목
    카펫

문제 설명
    Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

    Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

    Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
    갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
    노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
    카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

입출력 예
    brown	yellow	return
    10	2	[4, 3]
    8	1	[3, 3]
    24	24	[8, 6]
*/

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

// 2a+2b-4=brown;
// brown+yellow=a*b;
// a+b=brown/2+2;
// a*b=brown+yellow;
// b^2 - (brown/2+2)b + (brown+yellow) = 0

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sqa = (brown+4)/2;
    int tri = brown+yellow;
    
    int b=1;
    
    vector<int> bVec;
    
    int cnt=0;
    
    while(true){
        long long temp = ((b*b)-(sqa*b)+tri);
        if(temp==0){
            cnt++;
            bVec.push_back(b);
            if(2*b==sqa){
                cnt++;
                bVec.push_back(b);
            }
        }
        
        if(cnt==2){
            break;
        }
        
        b++;
    }
    
    sort(bVec.begin(), bVec.end(), greater<>());
    
    
    return bVec;
}