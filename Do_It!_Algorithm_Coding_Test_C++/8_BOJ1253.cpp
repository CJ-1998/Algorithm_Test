#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> sum;

bool binarySearch(int num, int a, int b){
    int start=a;
    int end=b;
    
    if(start>end){
        return false;
    }
    
    int mid=(start+end)/2;
    
    if(sum[mid]==num){
        return true;
    }

    if(sum[mid]>num){
        return binarySearch(num,start,mid-1);
    }

    if(sum[mid]<num){   
        return binarySearch(num,mid+1,end);
    }
}

int main(){

    int cnt=0;
    cin>>cnt;

    vector<int> v;

    for(int i=0;i<cnt;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    for(int i=0;i<cnt-1;i++){
        for(int j=i+1;j<cnt;j++){
            sum.push_back(v[i]+v[j]);
        }
    }

    sort(sum.begin(),sum.end());
    sum.erase(unique(sum.begin(),sum.end()),sum.end());

    // for(int i=0;i<sum.size();i++){
    //     cout << sum[i] <<" ";
    // }
    // cout<<endl;


    int answer=0;

    for(int i=0;i<cnt;i++){
        if(binarySearch(v[i], 0, sum.size()-1)){
            answer++;
        }
    }

    cout<<answer<<endl;

    return 0;
}