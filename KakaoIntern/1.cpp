#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int getIndex(vector<string>friends, string name){
    for(int i=0;i<friends.size();i++){
        if(friends[i].compare(name)==0){
            return i;
        }
    }
}

int getGiveGift(vector<vector<int>>send, int len, int index){
    int answer=0;
    for(int i=0;i<len;i++){
        if(send[index][i]!=-1)
            answer+=send[index][i];
    }
    return answer;
}

int getTakeGift(vector<vector<int>>send, int len, int index){
    int answer=0;
    for(int i=0;i<len;i++){
        if(send[i][index]!=-1)
            answer+=send[i][index];
    }
    return answer;
}

int solution(vector<string> friends, vector<string> gifts) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> send;

    for(int i=0;i<friends.size();i++){
        vector<int> temp;
        for(int j=0;j<friends.size();j++){
            if(i==j){
                temp.push_back(-1);
            }else{
                temp.push_back(0);
            }
        }
        send.push_back(temp);
    }

    for(int i=0;i<gifts.size();i++){
        string str=gifts[i];
        stringstream stream;
        string temp; 
        stream.str(str);
        vector<int> index;
        while(stream>>temp){
            index.push_back(getIndex(friends,temp));
        }
        send[index[0]][index[1]]++;
    }

    vector<vector<int>> giftScore;
    for(int i=0;i<friends.size();i++){
        vector<int> temp;
        for(int j=0;j<3;j++){
            temp.push_back(0);
        }
        giftScore.push_back(temp);
    }

    for(int i=0;i<friends.size();i++){
        giftScore[i][0]=getGiveGift(send,friends.size(),i);
        giftScore[i][1]=getTakeGift(send,friends.size(),i);
        giftScore[i][2]=giftScore[i][0]-giftScore[i][1];
    }

    vector<int> giftCnt;
    for(int i=0;i<friends.size();i++){
        giftCnt.push_back(0);
    }

    for(int i=0;i<friends.size()-1;i++){
        for(int j=i+1;j<friends.size();j++){
            int a=send[i][j];
            int b=send[j][i];

            if(a>b){
                giftCnt[i]++;
            }else if(b>a){
                giftCnt[j]++;
            }else{
                int aScore=giftScore[i][2];
                int bScore=giftScore[j][2];
                if(aScore>bScore){
                    giftCnt[i]++;
                }else if(bScore>aScore){
                    giftCnt[j]++;
                }
            }
        }
    }

    sort(giftCnt.begin(),giftCnt.end(),greater<>());

    int answer = giftCnt[0];
    return answer;
}