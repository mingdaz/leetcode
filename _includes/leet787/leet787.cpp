const int INF = 10 * 1000 * 1000;
struct DijkstraNode{
    int distance;
    int path_length;
    int vertex;
    DijkstraNode(int distance, int path_length, int vertex): distance(distance), path_length(path_length), vertex(vertex) {}
    bool operator < (const DijkstraNode& b) const {
        return distance > b.distance;
    }
};

struct Flight{
    int destination;
    int distance;
    Flight(int destination, int distance): destination(destination), distance(distance) {}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<Flight> > edge_list(n);
        for (auto& flight: flights) {
            edge_list[flight[0]].push_back(Flight(flight[1], flight[2]));
        }
        
        vector<vector<bool> > visited_nodes(n, vector<bool>(K + 2, false));
        vector<vector<int> > distance(n, vector<int>(K + 2, INF));
        priority_queue<DijkstraNode> dijkstra_queue;
        distance[src][0] = 0;
        dijkstra_queue.push(DijkstraNode(0, 0, src));

        while (!dijkstra_queue.empty()) {
            auto node = dijkstra_queue.top();
            dijkstra_queue.pop();

            if (visited_nodes[node.vertex][node.path_length]) {
                continue;
            }

            visited_nodes[node.vertex][node.path_length] = true;

            if (node.vertex == dst) {
                return node.distance;
            }

            if (node.path_length <= K) {
                for (auto& flight: edge_list[node.vertex]) {
                    int new_distance = node.distance + flight.distance;
                    if (new_distance < distance[flight.destination][node.path_length + 1]) {
                        distance[flight.destination][node.path_length + 1] = new_distance;
                        dijkstra_queue.push(DijkstraNode(new_distance, node.path_length + 1, flight.destination));
                    }
                }
            }
        }
        return -1;
    }
};