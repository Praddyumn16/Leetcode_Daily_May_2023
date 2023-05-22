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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n = 0;
        ListNode* temp = head;
        
        while(temp) {
            n++;
            temp = temp->next;
        }

        ListNode* a;
        ListNode* b;
        
        int i = 0;
        temp = head;

        while(temp) {
            i++;
            if(i == k)
                a = temp;
            if(i == n - k + 1)
                b = temp;
            temp = temp->next;
        }

        int x = a->val;
        a->val = b->val;
        b->val = x;

        return head;
    }
};