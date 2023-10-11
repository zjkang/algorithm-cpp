// https://leetcode.com/problems/word-ladder-ii/
// 126. Word Ladder II

// BFS + DFS with reverse map
class Solution {
public:
    unordered_set<string>wordSet;
    unordered_map<string,vector<string>>next;
    unordered_map<string,unordered_set<string>>prev;
    vector<vector<string>>results;
    string beginWord;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        wordList.push_back(beginWord);
        for (auto str:wordList)
            wordSet.insert(str);
        this->beginWord = beginWord;

        if (wordSet.find(endWord)==wordSet.end()) return {};
        // transition matrix
        for (int i=0; i<wordList.size(); i++) {
            string str = wordList[i];
            for (int k=0; k<str.size(); k++) {
                for (char ch='a'; ch<='z'; ch++) {
                    if (ch == str[k]) continue;
                    string temp = str;
                    temp[k] = ch;
                    if (wordSet.find(temp)!=wordSet.end())
                        next[str].push_back(temp);
                }
            }
        }

        unordered_set<string>visited;
        queue<string>q;
        int flag = 0;

        q.push(beginWord);
        visited.insert(beginWord);

        // setup reverse map
        while (!q.empty()) {
            int len = q.size();
            unordered_set<string>newVisited;

            for (int k=0; k<len; k++) {
                string str = q.front();
                q.pop();
                for (auto nextStr: next[str]) {
                    if (visited.find(nextStr)!=visited.end())
                        continue;
                    prev[nextStr].insert(str);
                    newVisited.insert(nextStr);
                    if (nextStr==endWord) flag = 1;
                }
            }

            if (flag==1) break;

            for (auto x: newVisited) {
                visited.insert(x);
                q.push(x);
            }
        }

        if (flag==0) return {};

        vector<string> cur = {endWord};
        DFS(endWord, cur);

        return results;
    }

    void DFS(string word, vector<string>& path) {
        if (word==beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(),temp.end());
            results.push_back(temp);
            return;
        }

        for (auto preStr:prev[word]) {
            path.push_back(preStr);
            DFS(preStr, path);
            path.pop_back();
        }
        return;
    }
};