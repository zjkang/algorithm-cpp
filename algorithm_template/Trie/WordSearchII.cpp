// https://leetcode.com/problems/word-search-ii/
// 212. Word Search II
// Search words from matrix given words dictionary (2 simga interview)

// 此题是用将常规的DFS算法与Trie的数据结构相结合。设计DFS函数

// void DFS(int i, int j, TrieNode* node, string word, vector<vector<int>>&visited, vector<vector<char>>& board)
// 表示(i,j)为起点、node为Trie树的当前节点、visited为已经经过的路径，
// 求是否能在board里继续遍历出可以拼成字典树里面任意的完整单词。能拼出完整单词的依据是走到某个节点时node->isEnd==true，
// 无法继续的判据是node->next[board[i][j]-'a']==NULL

// 在新的数据集中，上面的方法会TLE。改进之处是每探索到一个单词之后，就将该单词从字典树里移出，避免重复搜索同一个单词。
// 怎么修改字典树呢？我们不需要真地去删除节点，只需要给每个节点添加一个count标记。在最初建立字典树的时候，每添加一个单词，我们就给沿途的节点的count加一。
// 删除单词的时候，就给每个节点的count减一。当我们遍历字典树的时候，如果发现某个节点的count等于0时，就可以认为这个节点已经不存在了。

class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        bool isEnd;
        int count = 0;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;
            isEnd=false;
            count=0;
        }
    };
    TrieNode* root;
    vector<string>rets;
    int M, N;
    bool visited[12][12];
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        M=board.size();
        N=board[0].size();
        root=new TrieNode();
        for (int i=0; i<words.size(); i++)
        {
            TrieNode* node=root;
            for (auto ch: words[i])
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a']=new TrieNode();
                node=node->next[ch-'a'];
                node->count++;
            }
            node->isEnd=true;
        }

        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             TrieNode* node = root;
             string word;
             visited[i][j]=1;
             DFS(i,j,node,word,board);
             visited[i][j]=0;
         }

        return rets;
    }

    void DFS(int i, int j, TrieNode* node, string& word, vector<vector<char>>& board)
    {
        if (node->next[board[i][j]-'a']==NULL) return;
        if (node->next[board[i][j]-'a']->count==0) return;

        node = node->next[board[i][j]-'a'];
        word.push_back(board[i][j]);

        if (node->isEnd==true)
        {
            node->isEnd = false;
            rets.push_back(word);
            remove(root, word);
        }

        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        for (int k=0; k<4; k++)
        {
            int x=i+dir[k].first;
            int y=j+dir[k].second;
            if (x<0||x>=M||y<0||y>=N) continue;
            if (visited[x][y]==1) continue;

            visited[x][y]=1;
            DFS(x,y,node,word,board);
            visited[x][y]=0;
        }

        word.pop_back();
    }

    void remove(TrieNode* root, string word)
    {
        TrieNode* node = root;
        for (auto ch: word)
        {
            node = node->next[ch-'a'];
            node->count --;
        }
    }
};