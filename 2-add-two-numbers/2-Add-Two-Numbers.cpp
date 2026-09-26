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
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        
        int x = 0;
        int carry = 0;
        while(!(l1==nullptr && l2==nullptr)){
            x = 0;

            if(l1!=nullptr && l2!=nullptr){
                x = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1!=nullptr){
                x = l1->val;   
                l1 = l1->next;
            } else {
                x = l2->val;
                l2 = l2->next;
            }

            x+=carry;

            if(x>9){
                x = x%10;
                carry = 1;
            } else {
                carry = 0;
            }

            ptr->next = new ListNode(x);
            ptr = ptr->next;
        }



        if(carry){
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }

        return dummy.next;
    }
};
