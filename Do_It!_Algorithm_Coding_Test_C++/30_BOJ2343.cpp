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