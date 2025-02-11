#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class CampusMap {
private:
    unordered_map<string, vector<string>> adjacencyList;

public:


    void addEdge(string node1, string node2) {
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }

    vector<string> shortestPath(string start, string end) {
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;
        queue<string> queue;

        for (auto& i : adjacencyList) {
            visited[i.first] = false;
        }

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            string current = queue.front();
            queue.pop();

            for (auto neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {   //false
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    queue.push(neighbor);

                    if (neighbor == end) {
                        vector<string> path;
                        string step = end;
                        while (step != start) {
                            path.push_back(step);
                            step = parent[step];
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }

        return vector<string>();
    }

    void printMap() {
        cout << "Campus Map:" << endl;
        for (auto& pair : adjacencyList) {
            cout << pair.first << " -> ";
            for (auto neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CampusMap campus;

    campus.addEdge("Block 25", "Block 26");
    campus.addEdge("Block 26", "Block 27");
    campus.addEdge("Block 27", "Block 28");
    campus.addEdge("Block 28", "Block 29");
    campus.addEdge("Block 29", "Block 30");
    campus.addEdge("Block 30", "Block 31");
    campus.addEdge("Block 31", "Block 32");
    campus.addEdge("Block 32", "Block 33");
    campus.addEdge("Block 33", "Block 34");
    campus.addEdge("Block 35", "Block 36");
    campus.addEdge("Block 36", "Block 37");
    campus.addEdge("Block 37", "Block 38");
    campus.addEdge("Block 38", "Block 26");
    campus.addEdge("Block 35", "Block 33");



    string start;
    string end;
    cout << "Enter starting position: ";
    getline(cin, start);
    cout << "Enter ending position: ";
    getline(cin, end);
    vector<string> path = campus.shortestPath(start, end);

    if (!path.empty()) {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << end << endl;
    }

    return 0;
}
