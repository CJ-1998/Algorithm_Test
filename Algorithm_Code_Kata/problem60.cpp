/*
제목
    바탕화면 정리

문제 설명
    코딩테스트를 준비하는 머쓱이는 프로그래머스에서 문제를 풀고 나중에 다시 
    코드를 보면서 공부하려고 작성한 코드를 컴퓨터 바탕화면에 아무 위치에나 저장해 둡니다. 
    저장한 코드가 많아지면서 머쓱이는 본인의 컴퓨터 바탕화면이 너무 지저분하다고 생각했습니다. 
    프로그래머스에서 작성했던 코드는 그 문제에 가서 다시 볼 수 있기 때문에 저장해 둔 파일들을 전부 삭제하기로 했습니다.

    컴퓨터 바탕화면은 각 칸이 정사각형인 격자판입니다. 
    이때 컴퓨터 바탕화면의 상태를 나타낸 문자열 배열 wallpaper가 주어집니다. 
    파일들은 바탕화면의 격자칸에 위치하고 바탕화면의 격자점들은 바탕화면의 
    가장 왼쪽 위를 (0, 0)으로 시작해 (세로 좌표, 가로 좌표)로 표현합니다. 
    빈칸은 ".", 파일이 있는 칸은 "#"의 값을 가집니다. 
    드래그를 하면 파일들을 선택할 수 있고, 선택된 파일들을 삭제할 수 있습니다. 
    머쓱이는 최소한의 이동거리를 갖는 한 번의 드래그로 모든 파일을 선택해서 
    한 번에 지우려고 하며 드래그로 파일들을 선택하는 방법은 다음과 같습니다.

    드래그는 바탕화면의 격자점 S(lux, luy)를 마우스 왼쪽 버튼으로 클릭한 상태로 
    격자점 E(rdx, rdy)로 이동한 뒤 마우스 왼쪽 버튼을 떼는 행동입니다. 
    이때, "점 S에서 점 E로 드래그한다"고 표현하고 점 S와 점 E를 각각 드래그의 시작점, 끝점이라고 표현합니다.

    점 S(lux, luy)에서 점 E(rdx, rdy)로 드래그를 할 때, "드래그 한 거리"는 |rdx - lux| + |rdy - luy|로 정의합니다.

    점 S에서 점 E로 드래그를 하면 바탕화면에서 두 격자점을 각각 왼쪽 위, 오른쪽 아래로 하는 직사각형 내부에 있는 모든 파일이 선택됩니다.

    예를 들어 wallpaper = [".#...", "..#..", "...#."]인 바탕화면을 그림으로 나타내면 다음과 같습니다.

    이러한 바탕화면에서 다음 그림과 같이 S(0, 1)에서 E(3, 4)로 드래그하면 세 개의 파일이 
    모두 선택되므로 드래그 한 거리 (3 - 0) + (4 - 1) = 6을 최솟값으로 모든 파일을 선택 가능합니다.

    (0, 0)에서 (3, 5)로 드래그해도 모든 파일을 선택할 수 있지만 
    이때 드래그 한 거리는 (3 - 0) + (5 - 0) = 8이고 이전의 방법보다 거리가 늘어납니다.

    머쓱이의 컴퓨터 바탕화면의 상태를 나타내는 문자열 배열 wallpaper가 매개변수로 주어질 때 
    바탕화면의 파일들을 한 번에 삭제하기 위해 최소한의 이동거리를 갖는 드래그의 시작점과 끝점을 담은 
    정수 배열을 return하는 solution 함수를 작성해 주세요. 
    드래그의 시작점이 (lux, luy), 끝점이 (rdx, rdy)라면 정수 배열 [lux, luy, rdx, rdy]를 return하면 됩니다.

제한사항
    1 ≤ wallpaper의 길이 ≤ 50
    1 ≤ wallpaper[i]의 길이 ≤ 50
        wallpaper의 모든 원소의 길이는 동일합니다.
    wallpaper[i][j]는 바탕화면에서 i + 1행 j + 1열에 해당하는 칸의 상태를 나타냅니다.
    wallpaper[i][j]는 "#" 또는 "."의 값만 가집니다.
    바탕화면에는 적어도 하나의 파일이 있습니다.
    드래그 시작점 (lux, luy)와 끝점 (rdx, rdy)는 lux < rdx, luy < rdy를 만족해야 합니다.

입출력 예
    wallpaper	result
    [".#...", "..#..", "...#."]	[0, 1, 3, 4]
    ["..........", ".....#....", "......##..", "...##.....", "....#....."]	[1, 3, 5, 8]
    [".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."]	[0, 0, 7, 9]
    ["..", "#."]	[1, 0, 2, 1]
*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int top=0;      // row 위에서부터 보면서 제일 처음 만나는 row
    int left=0;     // col 왼쪽부터 보면서 제일 처음 만나는 col
    int bottom=0;   // row 위에서부터 보면서 제일 마지막에 만나는 row
    int right=0;    // col 왼쪽부터 보면서 제일 마지막에 만나는 col
    
    vector<vector<char>> v;
    
    for(int i=0;i<wallpaper.size();i++){
        vector<char> temp;
        for(int j=0;j<wallpaper[i].size();j++){
            temp.push_back(wallpaper[i][j]);
        }
        v.push_back(temp);
    }
    
    for(int i=0;i<v.size();i++){
        bool check = false;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='#'){
                top=i;
                check=true;
                break;
            }
        }
        if(check)
            break;
    }
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='#'){
                bottom=i;
            }
        }
    }
    
    for(int i=0;i<v[0].size();i++){
        bool check = false;
        for(int j=0;j<v.size();j++){
            if(v[j][i]=='#'){
                left=i;
                check=true;
                break;
            }
        }
        if(check)
            break;
    }
    
    for(int i=0;i<v[0].size();i++){
        for(int j=0;j<v.size();j++){
            if(v[j][i]=='#'){
                right=i;
            }
        }
    }
    
    // cout<<top<<" "<<left<<" "<<bottom+1<<" "<<right+1;
    
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bottom+1);
    answer.push_back(right+1);
    
    return answer;
}

/*
생각: 
    2차원 배열로 그려보고 정답의 규칙을 파악하면 됨.
    다른 사람 풀이 보면 # 만났을 때 각각 row, col의 min과 max를 기록하면 됨

    아래와 같은 형식
        // answer[0] = min(answer[0],i);
        // answer[1] = min(answer[1],j);
        // answer[2] = max(answer[2],i+1);
        // answer[3] = max(answer[3],j+1);
*/