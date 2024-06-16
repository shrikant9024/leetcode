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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode*next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode * fast = head;
        ListNode * start = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast  = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* end = newHead;
        while(end!=NULL){
           if(start->val!=end->val) return false;
            else{
                end =end->next;
                start= start->next;
            }
        }
        return true;
    }
};