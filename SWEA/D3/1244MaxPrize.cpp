//----------------풀이 중------------------
// 같은 것 있을 때 문제 아직 해결 못함. 
//32888 2 의 경우 88832 나와야 하는데 아래는 88823 나옴

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//정답과 같으면 제일 뒤의 2개 바꾸는 함수

//정답과 다르면 2개 index 바꾸는 함수

//찾으려는 값 받으면 index 주는 함수
int getAnswerIndex(vector<char> input, char num){
    int index=0;
 	for(int i=0;i<input.size();i++){
     	if(input[i]==num){
            index=i;
        }
    }
    return index;
}

//입력과 정답 줬을 때 앞에서 처음 다른 index 주는 함수
int getDifferentIndex(vector<char> input, vector<char> answer){
    for(int i=0;i<input.size();i++){
     	if(input[i]!=answer[i]){
         	return i;   
        }
    }
    return -1;
}

//입력과 정답 줬을 때 다른 개수 주는 함수
int getDifferentCount(vector<char> input, vector<char> answer){
    int count=0;
    for(int i=0;i<input.size();i++){
     	if(input[i]!=answer[i]){
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string money="";
        int cnt=0;
        cin>>money>>cnt;
        
        vector<char> moneyVector;
        vector<char> moneyAnswer;
        for(int i=0;i<money.length();i++){
         	moneyVector.push_back(money[i]);
            moneyAnswer.push_back(money[i]);
        }
        
        sort(moneyAnswer.begin(),moneyAnswer.end(),greater<>());
        
        for(int i=0;i<cnt;i++){
            int index=getDifferentIndex(moneyVector,moneyAnswer);
            if(index==-1){
                char temp;
                int len=moneyVector.size()-1;
                temp= moneyVector[len];
                moneyVector[len]=moneyVector[len-1];
                moneyVector[len-1]=temp;
            }
            else{
                int changeIndex=getAnswerIndex(moneyVector,moneyAnswer[index]);
                char temp;
                temp= moneyVector[index];
                moneyVector[index]=moneyVector[changeIndex];
                moneyVector[changeIndex]=temp;
            }
        }
        
        /*
        if(cnt!=1&&getDifferentCount(moneyVector,moneyAnswer)==2){
            cout<<"#"<<test_case<<" ";
            for(int i=0;i<moneyVector.size();i++){
                cout<<moneyAnswer[i];   
            }
            cout<<endl;
        }
        */
        
        cout<<"#"<<test_case<<" ";
        for(int i=0;i<moneyVector.size();i++){
         	cout<<moneyVector[i];   
        }
        cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}