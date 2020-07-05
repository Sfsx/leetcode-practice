#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (words.size() == 0) return result;
    int singleSize = words[0].size();
    int wordsSize = words.size();
    map<string, int> wordsMap;
    map<string, int>::iterator itor;
    for (int i = 0; i < words.size(); i++) {
        itor = wordsMap.find(words[i]);
        if (itor != wordsMap.end()) {
            wordsMap[words[i]]++;
        }
        wordsMap.insert(pair<string, int>(words[i], 1));
    }
    string key;

    for (int j = 0; j + wordsSize * singleSize <= s.size(); j++) {
        map<string, int> current;
        int flag = 0;
        for (int i = 0; i < wordsSize && j + i * singleSize < s.size(); i++) {
            int cur = 0; // wordmap 的当前 string 的记录值
            key = s.substr(j + i * singleSize, singleSize);
            itor = wordsMap.find(key);
            if (itor != wordsMap.end()) {
                cur = itor->second;
                itor = current.find(key);
                if (itor != current.end()) {
                    current[key]++;
                }
                current.insert(pair<string, int>(key, 1));
                if (current[key] > cur) {
                    flag = 1;
                    break;
                }
            } else {
                // j = j + i * singleSize;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            result.push_back(j);
        }
    }
    return result;
}

int main() {
    // string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    // vector<string> words = {"fooo","barr","wing","ding","wing"};
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    findSubstring(s, words);
    return 0;
}
