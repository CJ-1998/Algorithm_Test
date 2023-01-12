/*
문제:
    2차원 좌표 평면에 변이 축과 평행한 직사각형이 있습니다. 직사각형 네 꼭짓점의 좌표 [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]가 담겨있는 배열 dots가 매개변수로 주어질 때, 직사각형의 넓이를 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    dots의 길이 = 4
    dots의 원소의 길이 = 2
    -256 < dots[i]의 원소 < 256
    잘못된 입력은 주어지지 않습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int hori=0;
    int vert=0;
    
    for(int i=1;i<4;i++){
        if(dots[0][0]==dots[i][0]){
            if(dots[i][1]>dots[0][1]){
                vert=dots[i][1]-dots[0][1];
            }
            else{
                vert=dots[0][1]-dots[i][1];
            }
        }
        if(dots[0][1]==dots[i][1]){
            if(dots[i][0]>dots[0][0]){
                hori=dots[i][0]-dots[0][0];
            }
            else{
                hori=dots[0][0]-dots[i][0];
            }
        }
    }
    answer=hori*vert;
    return answer;
}

/*
개선 사항:
    1. x, y 모두 다른 것끼리 보면 가로, 세로 다 구할 수 있다. 
    2. x 최대값과 최소값, y 최대값과 최소값으로도 가로, 세로 구할 수 있다. 

배운 점:
    1. abs 함수 사용법. 
    2. max 함수 사용법.
*/