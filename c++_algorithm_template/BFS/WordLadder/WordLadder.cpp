// https://leetcode.com/problems/word-ladder/
// 127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> Map;
        unordered_set<string> Set(wordList.begin(), wordList.end());

        // create transition matrix for word ladder
        wordList.push_back(beginWord);
        for (int i=0; i<wordList.size(); i++) {
            string s=wordList[i];
            for (int j=0; j<s.size(); j++) {
                string t=s;
                for (char ch='a'; ch<='z'; ch++) {
                    if (ch==s[j]) continue;
                    t[j]=ch;
                    if (Set.find(t)!=Set.end())
                        Map[s].push_back(t);
                }
            }
        }

        queue<string>q;
        q.push(beginWord);
        int step = 1;
        set<string> visited;

        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string s = q.front();
                q.pop();
                for (auto t:Map[s]) {
                    if (visited.count(t)) continue;
                    if (t==endWord) return step+1;
                    visited.insert(t);
                    q.push(t);
                }
            }
            step++;
        }
        return 0;
    }
};