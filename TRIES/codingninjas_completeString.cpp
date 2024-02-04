/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
/*Problem Link
 https://www.codingninjas.com/studio/problems/complete-string_2687860
*/
#include <bits/stdc++.h> 
struct Node {
    struct Node *links[26];
    bool isEnd = 0;

    bool containThatSht(char c) {
        return (links[c - 'a'] != NULL && links[c - 'a']->cnt != 0);
    }

};
class Trie {
    Node *root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for (int i =0; i < word.length(); i++) {
            if (!node->containThatSht(word[i]))
                node->links[word[i] - 'a'] = new Node();
            node = node->links[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for (int i =0; i < word.length(); i++) {
            if (!node->containThatSht(word[i])) return false;
            node = node->links[word[i] - 'a'];
        }
        return node->isEnd;

    }


    bool isComplete(string &s) {
        Node *node = root;
        for (int i =0;i < s.length(); i++) {
            node = node->links[s[i] - 'a'];
            if (!node->isEnd) return false;
        }
        return node->isEnd;
    }
};


string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie tr;
    string res = "";
    for (auto &i:a) tr.insert(i);
    map<string, int> mp;
    for (auto &i:a)
        if (tr.isComplete(i)) mp.insert({i, i.size()});
    for (auto &i:mp) {
        if (i.second >= res.size()) {
            if (i.second == res.size()) res = (res > i.first ? i.first : res);
            else res = i.first;
        }
    }
    if (res == "") return ("None");
    return res;

}
