/*Problem Link:
https://leetcode.com/problems/n-queens/
*/

#include <bits/stdc++.h> 
class Solution {
public:
    int NumberOfQueen;
    vector<vector<string>> res;
    bool goodPos(int i, int j, vector<string> &v) {
        for (int h = 0; h < v.size(); h++) {
            int ind = j - (i - h);
            if (ind < 0 || ind > v[i].size())
                continue;
            if (v[h][ind] == 'Q') return false;
        }
        for (int h = 0; h < v.size(); h++) {
            int ind = j + (i - h);
            if (ind < 0 || ind > v[i].size())
                continue;
            if (v[h][ind] == 'Q') return false;
        }
        for (int h = 0; h < v[i].size(); h++)
            if (v[i][h] == 'Q') return false;
        for (int h = 0; h < v.size(); h++)
            if (v[h][j] == 'Q') return false;
        return true;
    }
    void dfs(int j, vector<string> &v) {
        for (auto &gg:v) cout << gg << endl;
        cout << endl;
        if (j == NumberOfQueen) {res.push_back(v); return ;}
        for (int i = 0; i < v.size();i++) {
            if (goodPos(i, j, v)) v[i][j] = 'Q', dfs(j+1, v), v[i][j] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        NumberOfQueen = n;
        vector<string> v(n, string(n, '.'));
        for (int i = 0; i < v.size(); i++) {
            v[i][0] = 'Q', dfs(1, v), v[i][0] = '.';
        }
        return res;
    }
};