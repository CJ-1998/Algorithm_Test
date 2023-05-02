#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int answer=0;

    while(str.compare("\n")){
        cin>>str;
        answer++;
    }


    // for(int i=0;i<str.size();i++){
    //     if('a'<=str[i]<='z'||'A'<=str[i]<='Z'){
    //     //if(str[i]==' '){
    //         answer++;
    //     }
    // }

    // answer=str.size()-answer;
    // if('a'<=str[0]<='z'||'A'<=str[0]<='Z')
    //     answer++;
    
    cout<<answer<<endl;

    return 0;
}