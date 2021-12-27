#include<iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

https://leetcode.com/problems/word-search-ii/

class Solution {
private:
    struct Trie{
        Trie* next[26];
        bool end = 0;
    };
    
    void insert(string word){
        Trie *r=root;
        for(auto ch : word){
            if(r->next[ch-'a']==NULL)
                r->next[ch-'a'] = new Trie();
            r = r->next[ch-'a'];
        }
        r->end = 1;
    }
    
    Trie *root;
    unordered_set<string> ans;
    vector<vector<char>> board;
    int row, col, dir=4;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void search(int x, int y, string word, Trie *r){
        if(r->next[board[x][y]-'a'] == NULL)
            return;
        r = r->next[board[x][y]-'a'];
        word += board[x][y];
        if(r->end == 1)
            ans.insert(word);
        char temp = board[x][y];
        board[x][y]='*';
        for(int i=0; i<dir; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 or ny<0 or nx>=row or ny>=col or board[nx][ny]=='*') continue;
            search(nx, ny, word, r);
        }
        board[x][y]=temp;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& Board, vector<string>& words) {
        board = Board;
        root = new Trie();
        row = board.size(), col = board[0].size();
        for(auto word : words)
            insert(word);
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                search(i, j, "", root);
        return vector<string>(ans.begin(), ans.end());
    }
};
