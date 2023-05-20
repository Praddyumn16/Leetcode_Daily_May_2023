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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;

        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        ListNode* ans = head;

        bool flag = 1;

        while(curr && next) {
            curr->next = next->next;
            next->next = curr;
            if(prev)
                prev->next = next;
            prev = curr;
            if(flag) {
                ans = next;
                flag = 0;
            }
            curr = curr->next;
            if(curr)
                next = curr->next;
        }

        return ans;
    }
};