import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        int x=0;
        int y=0;
        int xy = brown+yellow;
        
        for(int i=1;i<=xy;i++){
            if(xy%i==0){
                if((i+xy/i) == (brown/2+2)){
                    if(i<xy/i){
                        x=xy/i;
                        y=i;
                    }else{
                        x=i;
                        y=xy/i;
                    }
                }
            }
        }
        
        answer = new int[2];
        answer[0]=x;
        answer[1]=y;
        
        return answer;
    }
}

// 문제
// 중앙에 노란색, 테두리 1줄 갈색
// 노란색, 갈색 격자 개수는 기억
// 전체 카펫의 크기 기억 못함
// 갈색 격자 수 brown, 노란 격자 수 yellow 주어짐
// 카펫의 가로, 세로 반환

// 제한
// brown = 8~5000
// yellow = 1~2백만
// 가로 >= 세로

// 풀이
// 테두리 = 가로*2 + (세로-2)*2 = 2x + 2y - 4
// 중앙 = (가로-2)*(세로-2) = xy -2x -2y +4
// 가로*세로 = 테두리 + 중앙

// x+y = 테두리/2 + 2
// xy = 테두리 + 중앙
