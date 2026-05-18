class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //O(n)
        //O(klog(n))
        priority_queue<int, vector<int>, greater<int>> heap;

        for(int n:nums){
            heap.push(n);

            if(heap.size()>k)heap.pop();
        }

        return heap.top();

    }
};
