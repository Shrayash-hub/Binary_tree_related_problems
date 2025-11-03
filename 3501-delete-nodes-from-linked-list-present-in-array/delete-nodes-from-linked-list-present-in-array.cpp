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
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       unordered_set<int> unique(nums.begin(), nums.end());
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (unique.count(curr->val)) {
                
                if (curr == head) {
                    head = curr->next;   // move head ahead
                    curr = head;         // now update curr
                } else {
                    prev->next = curr->next; // bypass deleted node
                    curr = prev->next;   // move forward safely
                }
                
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};