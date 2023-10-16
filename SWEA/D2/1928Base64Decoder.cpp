
#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

map <char, int> table;

string intToBinary(int num){
 	string binary="";   
    for(int i=0;i<6;i++){
        binary+=to_string(num%2);
        num/=2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}

int binaryToInt (string binary){
    int num=0;
    for(int i=0;i<8;i++){
        num+=(binary[i]-'0')*((int)pow(2,7-i));
    }
    return num;
}

void initTable(){
	char one='A';
    char two='a';
    char three='0';
    int oneStart=0;
    int twoStart=26;
    int threeStart=52;
    int fourStart=62;
    
    for(oneStart; oneStart<26; oneStart++){
        table.insert(make_pair(one++,oneStart));
    }
    
    for(twoStart; twoStart<26; twoStart++){
        table.insert(make_pair(two++,twoStart));
    }
    
    for(threeStart; threeStart<10; threeStart++){
        table.insert(make_pair(three++,threeStart));
    }
    
    table.insert(make_pair('+',fourStart++));
    table.insert(make_pair('/', fourStart));
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
    initTable();
    
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string binaryString="";
        string inputString;
        cin>>inputString;
        
		int iter=inputString.length()/4;
        int startIndex=0;
        
        for(int i=0;i<10;i++){
        	for(int j=0;j<4;j++){
             	   
            }
        }


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}