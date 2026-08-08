/**
 * Leetcode Hard 913. Cat and Mouse

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0).

Then, the game can end in three ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return

1 if the mouse wins the game,
2 if the cat wins the game, or
0 if the game is a draw.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>
using namespace std;


class BacktrackSolution {
public:
    // This is Backtrack solution I tried but it didn't work because of cycles and cycle return. 
    // The issue is that the game can have cycles, and we need to detect and handle them properly.
    vector<int> dist;
    vector<vector<vector<int>>> dp;
    vector<vector<vector<int>>> visited; // 0 for unvisited, 1 for visiting, 2 for visited
    
    int backtrack(vector<vector<int>>& graph, int mouse = 1, int cat = 2, int turn = 0){
        if (cat == mouse) return 2;
        if (mouse == 0) return 1;

        if (visited[mouse][cat][turn] == 2) return dp[mouse][cat][turn];
        if (visited[mouse][cat][turn] == 1) return dp[mouse][cat][turn] == -1? 0:dp[mouse][cat][turn];
        visited[mouse][cat][turn] = 1;
        if (dp[mouse][cat][turn] != -1) {
            visited[mouse][cat][turn] = 2; 
            return dp[mouse][cat][turn];
        }

        int temp = 0;
        bool alwaysdraw = true;
        if (turn == 0){
            alwaysdraw = false;
            for (auto edge:graph[mouse]){
                temp = backtrack(graph, edge, cat, !turn);
                if (temp == 1) {
                    visited[mouse][cat][turn] = 2;
                    return dp[mouse][cat][turn] = 1;
                }
                if (temp == 0) alwaysdraw = true;
            }
            visited[mouse][cat][turn] = 2;
            return dp[mouse][cat][turn] = alwaysdraw? 0:2;
        }
        alwaysdraw = false;
        for (auto edge:graph[cat]){
            if (edge == 0) continue;
            temp = backtrack(graph, mouse, edge, !turn);
            if (temp == 2) {
                visited[mouse][cat][turn] = 2;
                return dp[mouse][cat][turn] = 2;
            }
            if (temp == 0) alwaysdraw = true;
        }
        visited[mouse][cat][turn] = 2;
        return dp[mouse][cat][turn] = alwaysdraw? 0:1;
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int ans = 0;
        dp.assign(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, -1)));
        visited.assign(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, 0))); 
        ans = backtrack(graph);
        return ans;
    }
};

class Solution {
public:
    // We will try real retrograde approach here
    int catMouseGame(vector<vector<int>>& graph) {
        vector<vector<vector<int>>> dp(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, -1)));
        queue<tuple<int,int,int>> que;
        for (int j=0;j<graph.size();j++){
            dp[0][j][0] = 1;
            dp[0][j][1] = 1;
            que.push({0,j,0});
            que.push({0,j,1});
        }
        for (int i=0;i<graph.size();i++){
            dp[i][i][0] = 2; 
            dp[i][i][1] = 2; 
            que.push({i,i,0});
            que.push({i,i,1});
        }

        vector<vector<vector<int>>> outdegree(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, 0)));
        for (int m=0;m<graph.size();m++){
            for (int j=0;j<graph.size();j++){
                outdegree[m][j][0] = graph[m].size();
                int cnt = 0;
                for (int nxt: graph[j]){
                    if (nxt != 0) cnt++;
                }
                outdegree[m][j][1] = cnt;
            }
        }
        while (!que.empty()){
            tuple it = que.front();
            que.pop();

            int mouse = get<0>(it);
            int cat = get<1>(it);
            int turn = get<2>(it);

            if (turn == 0) {
                int prevturn = 1;
                for (int prevcat: graph[cat]){
                    if (prevcat == 0) continue;
                    if (dp[mouse][prevcat][prevturn] != -1) continue;
                    if (dp[mouse][cat][turn] == 2) {
                        dp[mouse][prevcat][prevturn] = 2;
                        que.push({mouse, prevcat, prevturn});
                    } else if (dp[mouse][cat][turn] == 0) continue; 
                    else {
                        outdegree[mouse][prevcat][prevturn]--;
                        if (outdegree[mouse][prevcat][prevturn] == 0){
                            dp[mouse][prevcat][prevturn] = 1;
                            que.push({mouse, prevcat, prevturn});
                        }
                    }
                }
            } else {
                int prevturn = 0;
                for (int prevmouse: graph[mouse]){
                    if (dp[prevmouse][cat][prevturn] != -1) continue;
                    if (dp[mouse][cat][turn] == 1) {
                        dp[prevmouse][cat][prevturn] = 1;
                        que.push({prevmouse, cat, prevturn});
                    } else if (dp[mouse][cat][turn] == 0) continue; 
                    else {
                        outdegree[prevmouse][cat][prevturn]--;
                        if (outdegree[prevmouse][cat][prevturn] == 0){
                            dp[prevmouse][cat][prevturn] = 2;
                            que.push({prevmouse, cat, prevturn});
                        }
                    }
                }
            }
        }
        int ans = dp[1][2][0];
        return ans == -1 ? 0 : ans;
    }
};

int main() {
    // BacktrackSolution s;
    Solution s;
    vector<vector<int>> graph;

    graph = {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
    cout << s.catMouseGame(graph) << endl;

    graph = {{1,3},{0},{3},{0,2}};
    cout << s.catMouseGame(graph) << endl;

    graph = {{2,3},{3,4},{0,4},{0,1},{1,2}};
    cout << s.catMouseGame(graph) << endl;

    graph = {{5,6},{3,4},{6},{1,4,5},{1,3,5},{0,3,4,6},{0,2,5}};
    cout << s.catMouseGame(graph) << endl;

    return 0;
}

