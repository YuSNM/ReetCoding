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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = l1;
        bool carry = 0;
        while (1) {
            
            carry = (l1->val += l2->val + carry) / 10;
            l1->val %= 10;
            
            if(l1->next == nullptr && l2->next == nullptr) {
                if(carry) l1->next = new ListNode(1);
                return Head;
            }
            else if(l1->next == nullptr) {
                l1->next = l2->next;
                l1 = l1->next;
                break;
            }else if (l2->next == nullptr) {
                l1 = l1->next;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        while (1) {
            carry = (l1->val += carry) / 10;
            l1->val %= 10;
            
            if(l1->next == nullptr) break;
            l1 = l1->next;
        }
        if(carry) l1->next = new ListNode(1);
        
        
        return Head;
    }
};