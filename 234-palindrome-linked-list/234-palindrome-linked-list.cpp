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
    vector<int> v;
    ListNode* temp;
public:
    
    bool recur(ListNode* node) {
        if (!node) return 1;
        if (!recur(node->next) || temp->val != node->val) 
           return 0; 
        temp = temp->next;
        return 1;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return recur(head);
    }
};