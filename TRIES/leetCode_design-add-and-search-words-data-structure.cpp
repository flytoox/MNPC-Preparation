/*Problem Link
 https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/
#include <bits/stdc++.h> 
struct Node {
    struct Node *links[26];
    bool isEnd=false;
};
class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *node = root;
        for (int i=0; i < word.size(); i++) {
            if (!node->links[word[i] - 'a']) node->links[word[i] - 'a'] = new Node();
            node = node->links[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    bool dfs(string &s, Node *node, int i) {
        for (;i < s.size(); i++) {
            if (s[i]!= '.' && !node->links[s[i] - 'a']) return false;
            if (s[i] == '.') {
                for (auto &j : node->links)
                    if (j && dfs(s, j, i+1)) return true;
                return false;
            }
            node = node->links[s[i] - 'a'];
        }
        return node->isEnd;
    }

    bool search(string word) {
        stack<Node *>st;
        Node *node = root;
        for (int i = 0; i< word.size(); i++) {
            if (word[i]!= '.' && !node->links[word[i] - 'a']) return false;
            if (word[i] == '.')
                return dfs(word, node, i);
            node = node->links[word[i] - 'a'];
        }
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
