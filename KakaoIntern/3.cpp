#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> indexNum;

int getSum(vector<vector<int>> dice, vector<int> index, vector<int> diceNum){
    int answer=0;
    for(int i=0;i<diceNum.size();i++){
        answer+=dice[diceNum[i]][index[i]];
    }
    return answer;
}

void repeatPermutation(vector<int> vec, vector<int> perm, int depth)
{
    if (depth == perm.size())
    {
        vector<int> temp;
        for(int i = 0; i < perm.size(); i++)
        {
            temp.push_back(perm[i]);
        }
        indexNum.push_back(temp);
        
        return;
    }
    
    for(int i = 0; i < vec.size(); i++)
    {
        perm[depth] = vec[i];
        repeatPermutation(vec, perm, depth + 1);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len=dice.size();

    //주사위 조합 구하기
    vector<vector<int>> choose;

	vector<int> n;
	for(int i=0; i<len; i++){
		n.push_back(i);
	}

	vector<int> ind;
	int k = len/2;

	for(int i=0; i<k; i++){
		ind.push_back(1);
	}

	for(int i=0; i<n.size()-k; i++){
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());

	do{
        vector<int>temp;
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				temp.push_back(n[i]);
			}
		}
        choose.push_back(temp);

	}while(next_permutation(ind.begin(), ind.end()));

    reverse(choose.begin(),choose.end());

    int cLen=choose.size();

    //승패 결과 저장하는 것 초기화 
    vector<vector<int>>record;
    for(int i=0;i<cLen;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            temp.push_back(0);
        }
        record.push_back(temp);
    }

    //값 계산할 각 index 중복 순열 구하기
    vector<int> v={0,1,2,3,4,5};
    int r=len/2;
    vector<int> comb(r);

    repeatPermutation(v,comb,0);

    //승패 결과 계산
    for(int i=0;i<cLen/2;i++){
        vector<int> a=choose[i];
        vector<int> b=choose[cLen-1-i];

        for(int j=0;j<indexNum.size();j++){
            vector<int> x=indexNum[j];
            int mySum=getSum(dice,x,a);
            for(int k=0;k<indexNum.size();k++){
                vector<int>y=indexNum[k];
                int yourSum=getSum(dice,y,b);
                if(mySum>yourSum){
                    record[i][0]++;
                }else if(mySum<yourSum){
                    record[i][2]++;
                }else{
                    record[i][1]++;
                }
            }
        }
    }

    for(int i=0;i<cLen/2;i++){
        record[cLen-1-i][0]=record[i][2];
        record[cLen-1-i][1]=record[i][1];
        record[cLen-1-i][2]=record[i][0];
    }

    int answerIndex=0;
    int big=0;
    for(int i=0;i<record.size();i++){
        if(big<record[i][0]){
            answerIndex=i;
            big=record[i][0];
        }
    }

    vector<int> answer;
    for(int i=0;i<choose[answerIndex].size();i++){
        answer.push_back(choose[answerIndex][i]+1);
    }
    return answer;
}

//출처: https://ansohxxn.github.io/algorithm/repeated-permutation/
//출처: https://twpower.github.io/90-combination-by-using-next_permutation