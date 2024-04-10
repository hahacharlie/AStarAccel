#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;
const double BLOCKED_CELL_PERCENTAGE = 0.3; // 30% of the cells will be blocked

struct Position {
  int x, y;
};

// Overload the equality operator for Position
bool operator==(const Position &lhs, const Position &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

// Overload the hash function for Position
namespace std {
template <> struct hash<Position> {
  size_t operator()(const Position &pos) const {
    return hash<int>()(pos.x) ^ hash<int>()(pos.y);
  }
};
} 

struct Node {
  Position pos;
  int gCost; // Distance from starting node
  int hCost; // Heuristic - distance from end node
  Node *parent;

  Node(Position position, Node *p = nullptr)
      : pos(position), gCost(0), hCost(0), parent(p) {}

  int fCost() const { return gCost + hCost; }
};

// Comparator for priority queue
struct CompareNode {
  bool operator()(Node *a, Node *b) { return a->fCost() > b->fCost(); }
};

// Calculate Manhattan distance
int heuristic(Position a, Position b) {
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// Function to check if a cell is valid
bool isValid(const std::vector<std::vector<bool>> &grid, Position pos) {
  return pos.x >= 0 && pos.y >= 0 && pos.x < grid.size() &&
         pos.y < grid[0].size() && grid[pos.x][pos.y];
}

// Function to check if a cell is walkable
bool isWalkable(const std::vector<std::vector<bool>> &grid, Position pos) {
  return grid[pos.y][pos.x];
}

// A* pathfinding algorithm
std::vector<Position> findPath(const std::vector<std::vector<bool>> &grid,
                               Position start, Position end) {
  std::priority_queue<Node *, std::vector<Node *>, CompareNode> openSet;
  std::unordered_map<Position, Node *> allNodes;

  Node *startNode = new Node(start);
  startNode->hCost = heuristic(start, end);
  openSet.push(startNode);
  allNodes[start] = startNode;

  std::vector<Position> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  while (!openSet.empty()) {
    Node *currentNode = openSet.top();
    openSet.pop();

    if (currentNode->pos == end) {
      std::vector<Position> path;

      while (currentNode != nullptr) {
        path.push_back(currentNode->pos);
        currentNode = currentNode->parent;
      }

      std::reverse(path.begin(), path.end());

      // Cleanup the memory
      for (auto &entry : allNodes) {
        delete entry.second;
      }
      allNodes.clear(); // clear the map after cleanup

      return path;
    }

    for (auto &dir : directions) {
      Position newPos = {currentNode->pos.x + dir.x,
                         currentNode->pos.y + dir.y};

      if (!isValid(grid, newPos))
        continue;

      int tentativeGCost = currentNode->gCost + 1;
      if (!allNodes.count(newPos) || tentativeGCost < allNodes[newPos]->gCost) {
        Node *newNode = new Node(newPos, currentNode);
        newNode->gCost = tentativeGCost;
        newNode->hCost = heuristic(newPos, end);
        openSet.push(newNode);
        allNodes[newPos] = newNode;
      }
    }
  }

  // Cleanup in case of failure to find a path
  for (auto &entry : allNodes) {
    delete entry.second;
  }
  allNodes.clear();
  
  return {};
}

int main() {
  std::srand(std::time(nullptr)); // Seed for random number generation
  std::vector<std::vector<bool>> grid(
      GRID_HEIGHT,
      std::vector<bool>(GRID_WIDTH, true)); // Initialize all cells as walkable

  // Randomly block cells
  for (int i = 0; i < GRID_HEIGHT; ++i) {
    for (int j = 0; j < GRID_WIDTH; ++j) {
      if (std::rand() / (double)RAND_MAX < BLOCKED_CELL_PERCENTAGE) {
        grid[i][j] = false; // Mark cell as blocked
      }
    }
  }

  Position start, end;

  // Generate start position
  do {
    start.x = std::rand() % GRID_WIDTH;
    start.y = std::rand() % GRID_HEIGHT;
  } while (!isWalkable(grid, start));

  // Generate end position
  do {
    end.x = std::rand() % GRID_WIDTH;
    end.y = std::rand() % GRID_HEIGHT;
  } while (!isWalkable(grid, end) ||
           (end.x == start.x &&
            end.y == start.y)); // Ensure end is different from start

  // Print the grid for visualization, marking start and end positions
  for (int i = 0; i < GRID_HEIGHT; ++i) {
    for (int j = 0; j < GRID_WIDTH; ++j) {
      if (i == start.y && j == start.x) {
        std::cout << "S "; // Start position
      } else if (i == end.y && j == end.x) {
        std::cout << "E "; // End position
      } else {
        std::cout << (grid[i][j] ? "." : "#") << " ";
      }
    }
    std::cout << std::endl;
  }

  std::cout << "Start: (" << start.x << ", " << start.y << ")\n";
  std::cout << "End: (" << end.x << ", " << end.y << ")\n";

  auto path = findPath(grid, start, end);

  for (auto &pos : path) {
    std::cout << "(" << pos.x << ", " << pos.y << ") ";
  }
  std::cout << std::endl;

  return 0;
}
