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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=nullptr)
        {
            curr->next=l1;
        }
        if(l2!=nullptr)
        {
            curr->next=l2;
        }
        return dummy->next;
    }
};