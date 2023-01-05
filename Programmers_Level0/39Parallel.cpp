/*
문제:
    점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.
        [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
    주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<double> dist;
    for(int i=0;i<dots.size()-1;i++){
        for(int j=i+1;j<dots.size();j++){
            double temp=((double)(dots[j][1]-dots[i][1])/(double)(dots[j][0]-dots[i][0]));
            dist.push_back(temp);
        }
    }
    
    for(int i=0;i<dist.size()-1;i++){
        for(int j=i+1;j<dist.size();j++){
            if(dist[i]==dist[j]){
                return 1;
            }
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. 하나씩 비교할 때 이중 for문이 아니라 dist[i]==dist[i+1] 이렇게 하면 좋다. 
*/