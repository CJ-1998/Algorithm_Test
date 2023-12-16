#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    int cnt=0;

    cin>>num>>cnt;

    vector<int> arr;

    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        arr.push_back(temp);
    }

    priority_queue<int> pq;
    deque<int> d;
    int min=INT_MAX;
    for(int i=0;i<num;i++){
        d.push_back(arr[i]);
        pq.push(arr[i]);
        if(i<cnt){
            if(d.back()<min){
                min=d.back();
            }
        }
        else{
            if(d.front()==min){
                d.pop_front();
                min=INT_MAX;
                for(int j=0;j<d.size();j++){
                    if(d.at(j)<min){
                        min=d.at(j);
                    }
                }
            }
            else{
                d.pop_front();
                if(d.back()<min){
                    min=d.back();
                }
            }
        }

        cout<<min<<" ";
    }

    return 0;
}