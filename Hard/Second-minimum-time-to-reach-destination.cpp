/*
- 2045) Second minimum time to reach destination
    
    A city is represented as a **bi-directional connected** graph with `n` vertices where each vertex is labeled from `1` to `n` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by **at most one** edge, and no vertex has an edge to itself. The time taken to traverse any edge is `time` minutes.
    
    Each vertex has a traffic signal which changes its color from **green** to **red** and vice versa every `change` minutes. All signals change **at the same time**. You can enter a vertex at **any time**, but can leave a vertex **only when the signal is green**. You **cannot wait** at a vertex if the signal is **green**.
    
    The **second minimum value** is defined as the smallest value **strictly larger** than the minimum value.
    
    - For example the second minimum value of `[2, 3, 4]` is `3`, and the second minimum value of `[2, 2, 4]` is `4`.
    
    Given `n`, `edges`, `time`, and `change`, return *the **second minimum time** it will take to go from vertex* `1` *to vertex* `n`.
    
    **Notes:**
    
    - You can go through any vertex **any** number of times, **including** `1` and `n`.
    - You can assume that when the journey **starts**, all signals have just turned **green**.

*/


#include<vector>
#include<queue>
#include<climits>


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> graph(n+1);

        auto buildGraph = [&graph](const vector<int>&edge) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        };

        for_each(edges.begin(), edges.end(), buildGraph);

        queue<pair<int,int>> bfsQ;
        bfsQ.push({1,0});

        vector<vector<int>> distances(n+1, vector<int>(2, INT_MAX));
        distances[1][0] = 0;


        while (!bfsQ.empty()) {
            pair<int, int> nodeData = bfsQ.front();
            bfsQ.pop();
            int currNode = nodeData.first;
            int currDist = nodeData.second;

          
            auto toNeighbors = [&](int neighbor) {
            
                if (currDist + 1 < distances[neighbor][0]) {
                    distances[neighbor][1] = distances[neighbor][0]; 
                    distances[neighbor][0] = currDist + 1;    
                    bfsQ.push({neighbor, currDist + 1});
                }
                
                else if (distances[neighbor][0] < currDist + 1 &&
                         currDist + 1 < distances[neighbor][1]) {
                    distances[neighbor][1] = currDist + 1;
                    bfsQ.push({neighbor, currDist + 1});
                }
            };

            for_each(graph[currNode].begin(), graph[currNode].end(), toNeighbors);
        }
          
        int totalT = 0;
        for (int i = 0; i < distances[n][1]; ++i) {
            totalT += time;
            if (i < distances[n][1] - 1 && (totalT / change) % 2 == 1) {
                totalT += change - (totalT % change); 
            }
        }
        return totalT;
    }
    
};
