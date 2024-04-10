#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

struct Node {
    int x, y; // Node coordinates
    int g, h; // g: cost from start node to this node, h: heuristic cost from this node to goal
    Node *parent; // Pointer to parent Node

    Node(int x, int y, Node *parent = nullptr) : x(x), y(y), parent(parent), g(0), h(0) {}

    // Total cost f = g + h
    int f() const { return g + h; }

    // Less than operator for priority queue comparison, reversed to make priority_queue work as min-heap
    bool operator>(const Node& rhs) const {
        return f() > rhs.f();
    }
};

// Custom hash function for using Node* as a key in unordered_map
struct NodeHash {
    size_t operator()(const Node* node) const {
        return std::hash<int>()(node->x) ^ std::hash<int>()(node->y);
    }
};

// Custom equality function for using Node* as a key in unordered_map
struct NodeEqual {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->x == rhs->x && lhs->y == rhs->y;
    }
};

// Heuristic function (Manhattan distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

// Function to reconstruct path from start to goal
std::vector<Node*> reconstructPath(Node* current) {
    std::vector<Node*> path;
    while (current) {
        path.push_back(current);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

// A* search algorithm
std::vector<Node*> aStarSearch(const std::vector<std::vector<int>>& grid, Node start, Node goal) {
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> openSet;
    std::unordered_map<Node*, int, NodeHash, NodeEqual> costSoFar;
    std::vector<Node*> allNodes; // To keep track of all dynamically allocated nodes for memory cleanup

    start.g = 0;
    start.h = heuristic(start.x, start.y, goal.x, goal.y);
    openSet.push(new Node(start));
    allNodes.push_back(openSet.top());
    costSoFar[openSet.top()] = 0;

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->x == goal.x && current->y == goal.y) {
            auto path = reconstructPath(current);
            // Clean up dynamically allocated nodes
            for (Node* node : allNodes) delete node;
            return path;
        }

        static const int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (const auto& dir : directions) {
            int nextX = current->x + dir[0], nextY = current->y + dir[1];

            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size() || grid[nextX][nextY] == 1)
                continue;

            int newCost = current->g + 1;
            Node* next = new Node(nextX, nextY, current);
            allNodes.push_back(next);

            if (!costSoFar.count(next) || newCost < costSoFar[next]) {
                next->g = newCost;
                next->h = heuristic(nextX, nextY, goal.x, goal.y);
                openSet.push(next);
                costSoFar[next] = newCost;
            }
        }
    }

    // Clean up dynamically allocated nodes if path not found
    for (Node* node : allNodes) delete node;
    return {}; // Return empty path if goal is not reachable
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Node start(0, 0);
    Node goal(2, 3);

    auto path = aStarSearch(grid, start, goal);

    for (Node* step : path) {
        std::cout << "(" << step->x << ", " << step->y << ") ";
    }

    return 0;
}
