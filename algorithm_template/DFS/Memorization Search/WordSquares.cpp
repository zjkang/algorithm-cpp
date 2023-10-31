// https://www.lintcode.com/problem/word-squares/description

// Word Squares (prefix-hash + DFS)

// Given a set of words without duplicates, find all word squares you can build from them.
// A sequence of words forms a valid word square if the kth row and column read the exact same string,
// where 0 ≤ k < max(numRows, numColumns).
// For example, the word sequence ["ball","area","lead","lady"] forms a word square because
// each word reads the same both horizontally and vertically.
// b a l l
// a r e a
// l e a d
// l a d y

// Example 1:
// Input:
// ["area","lead","wall","lady","ball"]
// Output:
// [["wall","area","lead","lady"],["ball","area","lead","lady"]]

// note: similar to n-queens
// wall
// area
// lead
// lady

// wall
// area       -> a: [‘area’]: ‘ar’: [‘area’]
// le         -> ‘le’: [‘lead’]

// Explanation:
// The output consists of two word squares. The order of output does not matter
// (just the order of words in each word square matters).

// Example 2:
// Input:
// ["abat","baba","atan","atal"]
// Output:
//  [["baba","abat","baba","atan"],["baba","abat","baba","atal"]]


// memo for pre-fix words
class Solution {
    vector<vector<string>> res;
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.size() == 0) return {};
        auto prefixHash = buildPrefixHash(words);
        vector<string> oneres;
        dfs(words, prefixHash, oneres);
        return res;
    }

    void dfs(vector<string>& words,
            map<string,vector<string>>& prefixHash,
            vector<string>& oneres) {
        if (oneres.size() == words[0].size()) {
            res.push_back(oneres);
            return;
        }
        auto validWords = getValidWords(words, prefixHash, oneres);
        for (auto w : validWords) {
            oneres.push_back(w);
            dfs(words, prefixHash, oneres);
            oneres.pop_back();
        }

    }

    map<string,vector<string>> buildPrefixHash(vector<string>& words) {
        map<string,vector<string>> map;
        for (auto w : words) {
            int length = 1;
            while (length <= w.size()) {
                string prefixWord = w.substr(0,length);
                map[prefixWord].push_back(w);
                length++;
            }
        }
        return map;
    }

    vector<string> getValidWords(
        vector<string>& words,
        map<string,vector<string>>& prefixHash,
        vector<string>& oneres) {
        if (oneres.size() == 0) return words;
        int rows = oneres.size();
        string prefixWord = "";
        for (auto w : oneres) {
            prefixWord.push_back(w[rows]);
        }
        return prefixHash[prefixWord];
    }
}


