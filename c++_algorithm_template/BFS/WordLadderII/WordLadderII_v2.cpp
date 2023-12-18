// BFS + DFS (backtracking)
class Solution {
public:
    unordered_map<string,vector<string>> reverseMap;
    vector<vector<string>> res;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int wordSize = beginWord.size();
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        queue<string> queue;
        queue.push(beginWord);
        unordered_set<string> visited = {beginWord};

        while (!queue.empty()) {
            int size = queue.size();

            unordered_set<string> levelVisited;
            for (int i = 0; i < size; i++) {
                string curWord = queue.front(); queue.pop();
                for (int j = 0; j < wordSize; j++) {
                    char curChar = curWord[j];
                    for (int c = 'a'; c <= 'z'; c++) {
                        if (c == curChar) continue;
                        string newWord = curWord;
                        newWord[j] = c;
                        if (wordDict.count(newWord)) {
                            if (!visited.count(newWord)) {
                                reverseMap[newWord].push_back(curWord);

                                if (!levelVisited.count(newWord)) {
                                    levelVisited.insert(newWord);
                                    queue.push(newWord);
                                }
                            }
                        }
                    }
                }
            }
            for (string w : levelVisited) {
                visited.insert(w);
            }

            if (visited.count(endWord)) {
                break;
            }
        }

        vector<string> curRes;
        dfs(endWord, beginWord, curRes);

        for (vector<string>& curRes : res) {
            reverse(curRes.begin(), curRes.end()); // reverse each path
        }
        return res; 
    }

    // directed graph traversal
    void dfs(string& startWord, string& endWord, vector<string>& cur) {
        cur.push_back(startWord);
        if (startWord == endWord) {
            res.push_back(cur);
        } else {
            for (auto nextWord: reverseMap[startWord]) {
                dfs(nextWord, endWord, cur);
            }
        }
        cur.pop_back();
    }
};