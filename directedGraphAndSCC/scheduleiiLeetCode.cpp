// https://leetcode.com/problems/course-schedule-ii/description/
// leetcode solution not work on offline editor
// to run it use only leet code editor online
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> adj[3000];

    bool dfsCycle(int u , vector <int> &visited){
        visited[u] = 1;

        for(auto v : adj[u]){
            if(visited[v] == 0){
                if(dfsCycle(v , visited)){
                    return true;
                }
            }

            if(visited[v] == 1){
                return true;
            }
        }

        visited[u] = 2;
        return false;
    }

    void topoDfs(int u , vector <int> &order , vector <int> &visited){
        visited[u] = 1;
        for(auto v : adj[u]){
            if(visited[v] == 0){
                topoDfs(v , order , visited);
            }
        }
        order.push_back(u);
    }

    vector<int> findOrder(int n, vector<vector<int>>& e) {

        // make adj list
        for(auto v : e){
            adj[v[1]].push_back(v[0]);
        }

        // check for cycle first
        vector <int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                bool cycle = dfsCycle(i,visited);
                if(cycle){
                    return {};
                }
            }
        }

        // if cycle not present then topo sort
        vector <int> order;
        for(int i=0;i<n;i++) visited[i]=0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                topoDfs(i,order,visited);
            }
        }
        reverse(order.begin(),order.end());
        
        return order;
    }
};

int main(){
    return 0;
}