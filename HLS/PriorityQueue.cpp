#include <iostream>
#include <limits>
#include <vector>

class HybridPriorityQueue {
public:
  // constructor for the priority queue, to populate the queue with negative infinity. 
  HybridPriorityQueue(size_t size)
      : pq(size, std::numeric_limits<int>::min()) {} 

  // Performs a replace operation: removes the top element and inserts a new element
  void replace(int newValue) {
    pq[0] = newValue;
    heapify(0);
  }

  // Returns the top element without removing it
  int top() const {
    return pq.empty() ? std::numeric_limits<int>::min() : pq[0];
  }

private:
  std::vector<int> pq;

  void buildHeap() {
    for (int i = pq.size() / 2 - 1; i >= 0; --i) {
      heapify(i);
    }
  }

  void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq.size() && pq[left] < pq[largest])
      largest = left;

    if (right < pq.size() && pq[right] < pq[largest])
      largest = right;

    if (largest != i) {
      std::swap(pq[i], pq[largest]);
      heapify(largest);
    }
  }
};

int main() {
  HybridPriorityQueue pq(5);

  pq.replace(10);
  pq.replace(20);
  pq.replace(30);
  pq.replace(40);
  pq.replace(50);

  std::cout << "Top before replace: " << pq.top() << std::endl;
  pq.replace(25);
  std::cout << "Top after replace: " << pq.top() << std::endl;

  return 0;
}
