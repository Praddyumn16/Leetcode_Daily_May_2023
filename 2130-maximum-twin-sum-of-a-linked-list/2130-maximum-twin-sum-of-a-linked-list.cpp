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
    int pairSum(ListNode* head) {
        vector<int> val;
        ListNode* temp = head;
        while(temp) {
            val.push_back(temp->val);
            temp = temp->next;
        }

        int ans = 0 , l = 0 , r = val.size() - 1;

        while(l < r) 
            ans = max(ans , val[l++] + val[r--]);

        return ans;
    }
};