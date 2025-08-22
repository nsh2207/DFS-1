#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc]==color) return image;
    int old_color = image[sr][sc], m = image.size(), n = image[0].size();
    queue<pair<int,int>>bfs;
    bfs.push({sr,sc});
    image[sr][sc]=color;
    while(!bfs.empty()){
        pair<int,int>top = bfs.front();
        bfs.pop();
        int row = top.first, col = top.second;
        vector<vector<int>>nei = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto adj:nei){
            int nei_row = row+adj[0], nei_col = col+adj[1];
            if(nei_row>=0&&nei_row<=m-1&&nei_col>=0&&nei_col<=n-1&&image[nei_row][nei_col]==old_color){
                image[nei_row][nei_col]=color;
                bfs.push({nei_row,nei_col});
            }
        }
    }
    return image;
} 
int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n) in the worst case, where m is the number of rows and n is the number of columns in the image
// Did this code successfully run on Leetcode: Yes
// Any problem you faced while coding this: No
// Your code here along with comments explaining your approach in three sentences only
// Performed BFS to travewrse the image and change the color of the incoming adjacent pixels having the old color