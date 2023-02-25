/*
문제:
    주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
    nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.
*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool prime(int num){
    bool check=true;
    for(int i=2;i<num;i++){
        if(num%i==0){
            check=false;
            break;
        }
    }
    return check;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<int> sum;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                sum.push_back(nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    // sort(sum.begin(),sum.end());
    // sum.erase(unique(sum.begin(),sum.end()),sum.end());
    
    for(int i=0;i<sum.size();i++){
        cout<<sum[i]<<endl;
        if(prime(sum[i])){
            answer++;
        }
    }

    return answer;
}

/*
배운 점:
    1. 배열에서 3개 뽑아야 하는 경우 for문의 초기 변수는 i=0. j=i+1, k=j+1로 해야 된다. 
       마지막을 k=i+2로 하면 틀린 값 나온다. 
*/