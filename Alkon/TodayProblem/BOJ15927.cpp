#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int answer=-1;
    string pal;
    cin>>pal;
    
    int len=pal.length();
    vector<char> str;

    bool check=false;
    int big=0;

    for(int i=1;i<len;i++){
        if(str.size()==0){
            str.push_back(pal[0]);
        }
        else if(str.size()>1){
            if(str[str.size()-1]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
            if(str[str.size()-2]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
        }
        else{
            if(str[str.size()-1]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
        }
    }
    
    cout<<big<<endl;
    return 0;
}