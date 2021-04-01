// Floyd's Algorithm
// O(n)
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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast and fast->next) slow = slow->next, fast = fast->next->next;
        ListNode *prev = slow, *temp;
        slow = slow->next, prev->next = nullptr;
        while (slow) temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        slow = prev, fast = head;
        while (slow) if (slow->val != fast->val) return false; else slow = slow->next, fast = fast->next;
        return true;
    }
};



