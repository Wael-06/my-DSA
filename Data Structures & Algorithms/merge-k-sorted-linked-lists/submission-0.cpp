class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode head(0);
        ListNode* res = &head;

        while (list1 && list2) {

            if (list1->val <= list2->val) {
                res->next = list1;
                list1 = list1->next;
            }
            else {
                res->next = list2;
                list2 = list2->next;
            }

            res = res->next;
        }

        res->next = (list1 ? list1 : list2);

        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {

            vector<ListNode*> mergedLists;

            for (int i = 0; i < lists.size(); i += 2) {

                ListNode* l1 = lists[i];

                ListNode* l2 = (i + 1 < lists.size())
                                ? lists[i + 1]
                                : nullptr;

                mergedLists.push_back(
                    mergeTwoLists(l1, l2)
                );
            }

            lists = mergedLists;
        }

        return lists[0];
    }
};