#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std; 

const int INF = numeric_limits<int>::max(); 

vector<int> dijkstra(const vector<vector<int>>& graph, int start) {
    int cities = graph.size();
    vector<int> distances(cities, INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current_city = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distances[current_city])
            continue;

        for (int neighbor = 0; neighbor < cities; ++neighbor) { 
            if (graph[current_city][neighbor] != INF) {
                int weight = graph[current_city][neighbor];
                int distance_via_current = distances[current_city] + weight;

                if (distance_via_current < distances[neighbor]) {
                    distances[neighbor] = distance_via_current;
                    pq.push(make_pair(distances[neighbor], neighbor));
                }
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {0 , 10 , INF , INF , 15 , 5 },
        {10 , 0 , 10 , 30 , INF , INF },
        {INF , 10 , 0 , 12 , 5 , INF },
        {INF , 30 , 12 , 0 , INF , 20 },
        {15 , INF , 5 , INF , 0 , INF },
        {5 , INF , INF , 20 ,INF , 0 }
    };

    int starting_city = 5;
    vector<int> shortest_distances = dijkstra(graph, starting_city);

    for (int city = 0; city < shortest_distances.size(); ++city) {
        cout << "Shortest distance from city " << starting_city << " to city " << city << ": ";
        if (shortest_distances[city] == INF)
            cout << "Not reachable";
        else
            cout << shortest_distances[city];
        cout << endl;
    }

    return 0;
}
