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

// Trie template
// 基础的trie template的实现

struct TrieNode {
    bool leaf = false;
    map<char, TrieNode*> children;
    int count = 0; // # of nodes under current node
    int wordCount = 0; // # of words at leaf
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
