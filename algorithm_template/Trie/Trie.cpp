// Trie template

// https://leetcode.com/problems/implement-trie-ii-prefix-tree/
// 1804. Implement Trie II (Prefix Tree)
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store 
// and retrieve keys in a dataset of strings. There are various applications of this data structure, 
// such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
// int countWordsStartingWith(String prefix) Returns the number of strings in the trie that 
// have the string prefix as a prefix.
// void erase(String word) Erases the string word from the trie.

struct TrieNode {
    bool leaf = false;
    map<char, TrieNode*> children;
    int count = 0;
    int wordCount = 0;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            cur->count++;
        }
        cur->leaf = true;
        cur->wordCount++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children.count(c)) {
                return 0;
            }
            cur = cur->children[c];
        }
        return cur->leaf ? cur->wordCount : 0;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (!cur->children.count(c)) {
                return 0;
            }
            cur = cur->children[c];
        }
        return cur->count;
    }
    
    void erase(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            cur = cur->children[c];
            cur->count--;
        }
        cur->wordCount--;
    }
};



// ---------------------------------------------------------------------
// Trie problems
// https://leetcode.com/problems/word-search-ii/
// 212. Word Search II
// Search words from matrix given words dictionary (2 simga interview)


// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// 421. Maximum XOR of Two Numbers in an Array
// Search max xor in an array + trie


// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// 1707. Maximum XOR With an Element From Array
// Search max xor given max upper bound + trie


// https://github.com/zjkang/ds_algorithm/blob/main/python/trie/leetcode_1803_count_pairs_with_xor_in_a_range.py
// 1803. Count Pairs With XOR in a Range
// low <= nums[i] ^ nums[j] <= high for xor + trie + upper_bound




