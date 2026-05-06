class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        vector<Node*> oldNodes;
        vector<Node*> newNodes;

        Node* temp = head;

        // 1. Store old nodes
        while (temp) {
            oldNodes.push_back(temp);
            temp = temp->next;
        }

        int n = oldNodes.size();

        // 2. Create new nodes (same values)
        newNodes.push_back(new Node(oldNodes[0]->val));
        for (int i = 1; i < n; i++) {
            newNodes.push_back(new Node(oldNodes[i]->val));
        }

        // 3. Fix next pointers
        for (int i = 0; i < n - 1; i++) {
            newNodes[i]->next = newNodes[i + 1];
        }

        // 4. Map old node -> index
        unordered_map<Node*, int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[oldNodes[i]] = i;
        }

        // 5. Fix random pointers
        for (int i = 0; i < n; i++) {
            if (oldNodes[i]->random) {
                int idx = indexMap[oldNodes[i]->random];
                newNodes[i]->random = newNodes[idx];
            }
        }

        return newNodes[0];
    }
};