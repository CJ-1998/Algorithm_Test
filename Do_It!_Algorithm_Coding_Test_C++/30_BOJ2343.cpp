/*
문제:
    강토는 자신의 기타 강의 동영상을 블루레이로 만들어 판매하려고 한다. 
    블루레이에는 총 N개의 강의가 들어가는데, 블루레이를 녹화할 때, 강의의 순서가 바뀌면 안 된다. 
    순서가 뒤바뀌는 경우에는 강의의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 
    즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.
    강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 
    오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 강의 동영상을 녹화하기로 했다. 
    이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 
    단, M개의 블루레이는 모두 같은 크기이어야 한다.
    강토의 각 강의의 길이가 분 단위(자연수)로 주어진다. 
    이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 강의의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 
    다음 줄에는 강토의 기타 강의의 길이가 강의 순서대로 분 단위로(자연수)로 주어진다. 
    각 강의의 길이는 10,000분을 넘지 않는다.

출력:
    첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n=0;
    int m=0;
    cin>>n>>m;

    vector<int> lecture;

    long long sum=0;
    for(int i=0;i<n;i++){
        int x=0;
        cin>>x;
        sum+=x;
        lecture.push_back(x);
    }

    long long oneBlueRay=sum/m;

    long long left=0;
    // long long right=oneBlueRay;
    long long right=sum;

    vector<long long> timeMid;

    while(left<=right){
        long long mid=(left+right)/2;
        // cout<<"-------------"<<endl;
        // cout<<"mid: "<<mid<<endl;
        
        vector<long long> temp;
        long long sumTemp=0;
        for(int i=0;i<n;i++){
            if(temp.size()>m){
                break;
            }

            sumTemp+=lecture[i];
            if(sumTemp<=mid){
                if(i==n-1){
                    temp.push_back(sumTemp);
                }
                continue;
            }
            else{
                // cout<<"next: "<<lecture[i]<<endl;
                if(i<n-1)
                    temp.push_back(sumTemp-lecture[i]);
                else{
                    // cout<<"~~~"<<endl;
                    if(sumTemp<=mid)
                        temp.push_back(sumTemp);
                    else{
                        temp.push_back(sumTemp-lecture[i]);
                        temp.push_back(lecture[i]);
                    }
                }
                sumTemp=lecture[i];
            }
        }

        if(temp.size()>m){
            left=mid+1;
        }
        else{
            sort(temp.begin(),temp.end());
            timeMid.push_back(temp[temp.size()-1]);
            // for(int k=0;k<temp.size();k++){
            //     cout<<temp[k]<<" ";
            // }
            // cout<<endl;
            // cout<<"max time: "<<temp[temp.size()-1]<<endl;
            right=mid-1;
        }

    }

    sort(timeMid.begin(),timeMid.end());

    // cout<<timeMid[timeMid.size()-1];
    cout<<timeMid[0];

    return 0;
}