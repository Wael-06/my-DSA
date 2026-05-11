class KthLargest {
private:
    // Min-heap to store the k largest elements
    // std::greater<int> makes the priority_queue a min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k_size;

public:
    KthLargest(int k, std::vector<int>& nums) {
        k_size = k;
        
        // Add initial numbers to the heap
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Push the new value into the heap
        minHeap.push(val);
        
        // If the heap grows larger than k, remove the smallest element
        if (minHeap.size() > k_size) {
            minHeap.pop();
        }
        
        // The top of the min-heap is the smallest of the k largest elements,
        // which is the k-th largest element overall.
        return minHeap.top();
    }
};