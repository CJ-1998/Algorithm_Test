import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int one = 0;
        int two = 0;
        int three = 0;
        
        int oneIdx = 0;
        int twoIdx = 0;
        int threeIdx = 0;
        
        int[] oneAns = {1,2,3,4,5};
        int[] twoAns = {2,1,2,3,2,4,2,5};
        int[] threeAns = {3,3,1,1,2,2,4,4,5,5};
        
        for(int i=0;i<answers.length;i++){
            oneIdx=i%5;
            twoIdx=i%8;
            threeIdx=i%10;
            
            if(answers[i]==oneAns[oneIdx]){
                one++;
            }
            if(answers[i]==twoAns[twoIdx]){
                two++;
            }
            if(answers[i]==threeAns[threeIdx]){
                three++;
            }  
        }
        
        List<Integer> ans = new ArrayList<>();
        ans.add(one);
        ans.add(two);
        ans.add(three);
        
        Collections.sort(ans);
        int max = ans.get(2);
        
        List<Integer> realAns = new ArrayList<>();
        
        if(one==max){
            realAns.add(1);
        }
        
        if(two==max){
            realAns.add(2);
        }
        
        if(three==max){
            realAns.add(3);
        }
        
        answer = new int[realAns.size()];
        
        for(int i=0;i<realAns.size();i++){
            answer[i]=realAns.get(i);
        }
        
        return answer;
    }
}

// 문제
// 문제 찍드려고 함
// 1번 찍는 방식 : 12345 반복
// 2번 찍는 방식 : 21232425 반복
// 3번 찍는 방식 : 3311224455 반복
// 정답 answer 배열 주어졌을 때 가장 많은 문제 맞힌 사람 배열에 담아 반환

// 제한
// 문제수 : 1~1만
// 높은 점수 사람 여럿인 경우 오름차순 정렬