#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
    int maxSize ;
    vector<vector<int>> adj;

    public:
    Graph(int size) : maxSize(size) , adj(size,vector<int>(size,0)) {} ;

    void addEdge(int src ,int dest) {
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }

    void print() {
        for (int row = 0 ; row < maxSize ; row ++ ) {
            for (int col = 0 ; col < maxSize ; col ++ ) {
                cout << adj[row][col] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startNode) {
        vector<bool> visited(maxSize,false);
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true ;

        while (!q.empty()) {
            int current = q.front() ;
            q.pop() ;

            cout << current << " "; 

            for (int nigga = 0 ; nigga < maxSize ; nigga ++ ) {
                if (adj[startNode][nigga] == 1 && !visited[nigga]) {
                    q.push(nigga);
                    visited[nigga] = true ;
                }
            }
        }
    }

    void dfs(int start, vector<int> &visited) {
        visited[start] = true;

        for (int nigga = 0; nigga < maxSize; nigga++){
            if(adj[start][nigga] == 1 && !visited[nigga]){
                dfs(nigga, visited);
            }
        }
    }

    void dfsHelper(int root , vector<bool> &visited) {
        if (root == 0) {
            
        }
    }
    
};

int main() {
    Graph gp(3) ;

    gp.addEdge(0,1);
    gp.addEdge(0,2);

    gp.bfs(0);
    return 0;
}