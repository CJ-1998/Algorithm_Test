/*
문제:
    게임개발자인 "죠르디"는 크레인 인형뽑기 기계를 모바일 게임으로 만들려고 합니다.
    "죠르디"는 게임의 재미를 높이기 위해 화면 구성과 규칙을 다음과 같이 게임 로직에 반영하려고 합니다.

    게임 화면은 "1 x 1" 크기의 칸들로 이루어진 "N x N" 크기의 정사각 격자이며 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있습니다. (위 그림은 "5 x 5" 크기의 예시입니다). 각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다. 모든 인형은 "1 x 1" 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다. 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다. 집어 올린 인형은 바구니에 쌓이게 되는 데, 이때 바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다. 다음 그림은 [1번, 5번, 3번] 위치에서 순서대로 인형을 집어 올려 바구니에 담은 모습입니다.

    만약 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은 터뜨려지면서 바구니에서 사라지게 됩니다. 위 상태에서 이어서 [5번] 위치에서 인형을 집어 바구니에 쌓으면 같은 모양 인형 두 개가 없어집니다.

    크레인 작동 시 인형이 집어지지 않는 경우는 없으나 만약 인형이 없는 곳에서 크레인을 작동시키는 경우에는 아무런 일도 일어나지 않습니다. 또한 바구니는 모든 인형이 들어갈 수 있을 만큼 충분히 크다고 가정합니다. (그림에서는 화면표시 제약으로 5칸만으로 표현하였음)

    게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때, 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    board 배열은 2차원 배열로 크기는 "5 x 5" 이상 "30 x 30" 이하입니다.
    board의 각 칸에는 0 이상 100 이하인 정수가 담겨있습니다.
        0은 빈 칸을 나타냅니다.
        1 ~ 100의 각 숫자는 각기 다른 인형의 모양을 의미하며 같은 숫자는 같은 모양의 인형을 나타냅니다.
    moves 배열의 크기는 1 이상 1,000 이하입니다.
    moves 배열 각 원소들의 값은 1 이상이며 board 배열의 가로 크기 이하인 자연수입니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        moves[i]--;
    }
    
    vector<int> bucket;
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]]!=0){
                bucket.push_back(board[j][moves[i]]);
                cout<<board[j][moves[i]]<<endl;
                board[j][moves[i]]=0;
                
                int len=bucket.size()-1;
                if(bucket[len]==bucket[len-1]){
                    answer++;
                    bucket.pop_back();
                    bucket.pop_back();
                }
                break;
            }
        }
    }
    
    // vector<vector<int>> newboard;
    // for(int i=0;i<board.size();i++){
    //     vector<int> t;
    //     for(int j=board.size()-1;j>=0;j--){
    //         t.push_back(board[j][i]);
    //     }
    //     cout<<endl;
    //     newboard.push_back(t);
    // }
    
    // vector<int> bucket;
    // for(int i=0;i<moves.size();i++){
    //     int len=newboard[moves[i]].size()-1;
    //     int temp=newboard[moves[i]][len];
    //     newboard[moves[i]].pop_back();
        
    //     if(temp!=0){
    //         bucket.push_back(temp);
    //         int blen=bucket.size()-1;
    //         if(bucket[blen]==bucket[blen-1]){
    //             answer++;
    //             bucket.pop_back();
    //             bucket.pop_back();
    //         }
    //     }
    // }
    return answer*2;
}

/*
개선 사항:
    1. stack 사용하면 top(). push() 이런 함수 사용해서 더 쉽게 할 수 있다. 

배운 점:
    1. stack 자료 구조는 stack 라이브러리에 있다. 
    2. stack<자료형>이름; 이렇게 선언한다. 
    3. stack.empty(); 해서 true 나오면 stack이 빈 것이다. 
    4. stack.top(); 하면 stack의 top을 반환해준다.
    5. stack.push(값); 하면 stack에 값을 넣는다. 
    6. vector.push_back(값); 하면 vector에 값을 넣는다. 
    7. vector.pop_back(); 하면 제일 뒤의 값 반환해준다.
*/