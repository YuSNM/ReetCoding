//Time: 596 ms (89.29%), Space: 199.7 MB (5.02%) - LeetHub

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swapval(int *v1, int *v2) {
        int temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }

    ListNode *swapNodes(ListNode *head, int k) {
        vector<int *> v;

        for (ListNode *node = head; node; node = node->next)  
            v.push_back(&node->val);

        swapval(v[k - 1], v[v.size() - k]);

        return head;
    }
};
