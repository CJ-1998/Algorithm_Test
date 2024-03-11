/*
문제:
    김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 
    이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 
    이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. 
    N, M은 500,000 이하의 자연수이다.
    듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

출력:
    듣보잡의 수와 그 명단을 사전순으로 출력한다.
*/


#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<string> s;
    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        s.insert(name);
    }

    vector<string> v;
    for(int i = 0; i < m; i++){
        string name;
        cin>>name;
        
        if(s.find(name) != s.end()){
            v.push_back(name);
        }
    }

    cout<<v.size()<<"\n";
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }

    return 0;
}

/*
배운 점:
    1. set은 값 넣을 때 insert와 찾을 때 find를 사용한다. 
    2. set에 없는 값을 find 하면 set.end()를 반환한다. 
*/