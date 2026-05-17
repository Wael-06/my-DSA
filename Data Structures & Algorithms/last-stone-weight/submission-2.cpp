class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> h(stones.begin(), stones.end());

        while(h.size() > 1) {

            int x = h.top();
            h.pop();

            int y = h.top();
            h.pop();

            if(x != y) {
                h.push(abs(x - y));
            }
        }

        return h.empty() ? 0 : h.top();
    }
};