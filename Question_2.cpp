#include <vector>
#include <queue>
#include <iostream>
#include <utility> // for std::pair
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(),lev=0;
    vector<vector<int>>levels(m,vector<int>(n,0));
    queue<pair<int,int>>bfs;
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            if(mat[i][j]==0){
                bfs.push({i,j});
            }
        }
    }
    bfs.push({-1,-1});
    while(!bfs.empty()){
        pair<int,int>top = bfs.front();
        bfs.pop();
        int row = top.first, col = top.second;
        if(row==-1){
            if(!bfs.empty()) bfs.push(top);
            lev++;
            continue;
        }
        levels[row][col] = lev;
        vector<vector<int>>nei = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto adj:nei){
            int nei_row = row+adj[0], nei_col = col+adj[1];
            if(nei_row>=0&&nei_row<=m-1&&nei_col>=0&&nei_col<=n-1&&mat[nei_row][nei_col]){
                mat[nei_row][nei_col]=0;
                bfs.push({nei_row,nei_col});
            }
        }
    }
    return levels;
}
int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> result = updateMatrix(mat);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n) in the worst case, where m is the number of rows and n is the number of columns in the matrix
// Did this code successfully run on Leetcode: Yes
// Any problem you faced while coding this: No
// Your code here along with comments explaining your approach in three sentences only
// Performed multisource BFS and kept on marking 1 pixels to 0 as we compute the level or nearest 0 for the 1 pixel so that we won't need the visited boolean array
