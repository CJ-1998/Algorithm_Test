#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;

    for (int i = 0; i < info.size(); i++) {
        string str = info[i];
        stringstream stream;
        stream.str(str);

        string key = "";

        string temp;

        for (int j = 0; j < 4; j++) {
            stream >> temp;
            if (j == 0) {
                if (temp == "java") {
                    key += "0";
                } else if (temp == "python") {
                    key += "1";
                } else {
                    key += "2";
                }
            } else if (j == 1) {
                if (temp == "backend") {
                    key += "0";
                } else {
                    key += "1";
                }
            } else if (j == 2) {
                if (temp == "junior") {
                    key += "0";
                } else {
                    key += "1";
                }
            } else if (j == 3) {
                if (temp == "pizza") {
                    key += "0";
                } else {
                    key += "1";
                }
            }
        }
        stream >> temp;
        if (m.find(key) == m.end()) {
            vector<int> t;
            t.push_back(stoi(temp));
            m[key] = t;
        } else {
            m[key].push_back(stoi(temp));
        }
    }

    // for(const auto& [key, value] : m){
    //     cout<<"key: "<<key<<" value: ";
    //     for(int i=0;i<value.size();i++){
    //         cout<<value[i]<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int i = 0; i < query.size(); i++) {
        string str = query[i];
        stringstream stream;
        stream.str(str);

        string key = "";

        string temp;
        int answerCount = 0;

        for (int j = 0; j < 7; j++) {
            if (j % 2 != 0) {
                stream >> temp;
                continue;
            } else {
                stream >> temp;
                if (j == 0) {
                    if (temp == "java") {
                        key += "0";
                    } else if (temp == "python") {
                        key += "1";
                    } else if (temp == "cpp") {
                        key += "2";
                    } else {
                        key += "9";
                    }
                } else if (j == 2) {
                    if (temp == "backend") {
                        key += "0";
                    } else if (temp == "frontend") {
                        key += "1";
                    } else {
                        key += "9";
                    }
                } else if (j == 4) {
                    if (temp == "junior") {
                        key += "0";
                    } else if (temp == "senior") {
                        key += "1";
                    } else {
                        key += "9";
                    }
                } else if (j == 6) {
                    if (temp == "pizza") {
                        key += "0";
                    } else if (temp == "chicken") {
                        key += "1";
                    } else {
                        key += "9";
                    }
                }
            }
        }
        stream >> temp;
        int value = stoi(temp);

        string changedKey = key;
        string savedkey = "";

        for (int a = 0; a < 3; a++) {
            if (key[0] == '9') {
                changedKey[0] = '0' + a;
            }
            for (int b = 0; b < 2; b++) {
                if (key[1] == '9') {
                    changedKey[1] = '0' + b;
                }
                for (int c = 0; c < 2; c++) {
                    if (key[2] == '9') {
                        changedKey[2] = '0' + c;
                    }
                    for (int d = 0; d < 2; d++) {
                        if (key[3] == '9') {
                            changedKey[3] = '0' + d;
                        }
                        if (changedKey != savedkey) {
                            cout << "key: " << key << " changedKey: " << changedKey << " savedKey: " << savedkey
                                 << endl;
                            savedkey = changedKey;
                            for (int e = 0; e < m[savedkey].size(); e++) {
                                if (m[savedkey][e] >= value) {
                                    answerCount++;
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(answerCount);
    }

    return answer;
}