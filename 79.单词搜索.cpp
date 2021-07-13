/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    int raw;
    int col;
    vector<pair<int,int> > des{{0,1},{0,-1},{-1,0},{1,0}};

public:
    bool ifEqual(vector<vector<char>>& board,vector<vector<bool> >& visited,int x,int y,string &word,int k){
        if(!inArea(x,y)||visited[x][y]||board[x][y]!=word[k]) return false;
        if(board[x][y]==word[k]&&k==word.length()-1) return true;
        visited[x][y]=true;
        for(int i=0;i<4;++i){
            if(ifEqual(board,visited,x+des[i].first,y+des[i].second,word,k+1)) return true;
        }
        visited[x][y]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0||board[0].size()==0) return false;
        raw=board.size();
        col=board[0].size();
        vector<vector<bool> > visited(raw,vector<bool>(col,false));
        for(int i=0;i<raw;++i){
            for(int j=0;j<col;++j){
                if(ifEqual(board,visited,i,j,word,0)) return true;
            }
        }
        return false;
    }

    bool inArea(int x,int y){
        return x>-1&&x<raw&&y>-1&&y<col;
    }
};
// @lc code=end

