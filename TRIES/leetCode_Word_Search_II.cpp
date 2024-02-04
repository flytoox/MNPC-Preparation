/*Problem Link:
https://leetcode.com/problems/word-search-ii/description/
*/


#include <bits/stdc++.h> 

struct Node {
    struct Node *links[26];
    bool isEnd = 0;
    string S;
    char c;
    bool isIn =false;
    bool containThatSht(char c) {
        return (links[c - 'a'] != NULL);
    }

};
class Trie {

public:

    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string &s) {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->containThatSht(s[i]))
                node->links[s[i] - 'a'] = new Node();
            node = node->links[s[i] - 'a'];
            node->c = s[i];
        }
        node->S = s;
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string &s) {
        Node *node = root;
        for (int i =0; i < s.size(); i++) {
            if (!node->containThatSht(s[i])) return false;
            node = node->links[s[i] - 'a'];
        }
        return node->isEnd;
    }

};

class Solution {
public:
    bool isGoodIandJ(int i, int j, vector<vector<char>> &v) {
        return (i >= 0 && i < v.size() && j >= 0 && j < v[i].size());
    }
    void dfs(Node *node, vector<vector<char>>& b, int i, int j, vector<vector<int>> &vis, vector<string> &ans) {
        if (!isGoodIandJ(i, j, b)) return ;
        if (vis[i][j]) return ;
        if (!node->links[b[i][j] - 'a']) return;
        node = node->links[b[i][j] - 'a'];
        if (node->isEnd && !node->isIn)
            ans.push_back(node->S), node->isIn = true;
        vis[i][j] = 1;
        dfs(node, b, i+1, j, vis, ans);
        dfs(node, b, i-1, j, vis, ans);
        dfs(node, b, i, j+1, vis, ans);
        dfs(node, b, i, j-1, vis, ans);
        vis[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tr;
        for(auto &i:words) tr.insert(i);
        vector<vector<int>> vis(board.size(), vector<int> (board[0].size(), 0));
        vector<string> res;
        Node *node = tr.root;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                dfs(tr.root, board, i, j, vis, res);
        return res;
    }
};