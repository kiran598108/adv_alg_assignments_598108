#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

using Graph = unordered_map<char, vector<pair<char, int>>>;


pair<int, vector<char>> dijkstra_Alg(const Graph& graph, char start, char end) {
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
   
    unordered_map<char, int> short_dist;
    
    unordered_map<char, char> prev_nodes;

    
    for (const auto& node : graph) {
        short_dist[node.first] = INT_MAX;
        prev_nodes[node.first] = '\0';
    }

    
    short_dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        char curr_node = pq.top().second;
        pq.pop();

        
        if (curr_node == end) {
            break;
        }

        
        if (curr_dist > short_dist[curr_node]) {
            continue;
        }

        
        for (const auto& neighbor : graph.at(curr_node)) {
            char next_node = neighbor.first;
            int weight = neighbor.second;
            int distance = curr_dist + weight;

            
            if (distance < short_dist[next_node]) {
                short_dist[next_node] = distance;
                prev_nodes[next_node] = curr_node;
                pq.push({distance, next_node});
            }
        }
    }

   
    vector<char> path;
    char current = end;
    while (current != '\0') {
        path.push_back(current);
        current = prev_nodes[current];
    }
    reverse(path.begin(), path.end());

    return {short_dist[end], path};
}

int main() {
    
    Graph graph = {
        {'A', {{'B', 10}, {'E', 3}}},
        {'B', {{'E', 4}, {'C', 2}}},
        {'E', {{'B', 1}, {'D', 2}, {'C', 8}}},
        {'C', {{'D', 9}}},
        {'D', {{'C', 7}}}
    };

    char start_node, end_node;
    char choice;

    do {
       
        cout << "Enter the starting node: ";
        cin >> start_node;
        cout << "Enter the ending node: ";
        cin >> end_node;

        
        if (graph.find(start_node) != graph.end() && graph.find(end_node) != graph.end()) {
            auto result = dijkstra_Alg(graph, start_node, end_node);
            int cost = result.first;
            vector<char> path = result.second;

            cout << "The shortest path cost from " << start_node << " to " << end_node << " is " << cost << "." << endl;
            cout << "The path is: ";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i < path.size() - 1) {
                    cout << " -> ";
                }
            }
            
            cout << endl;
        } else {
            cout << "Invalid nodes. Please check your input." << endl;
        }

        cout<<"============================"<<endl;
        cout << "Do you want to find another path? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program. Goodbye!" << endl;

    return 0;
}