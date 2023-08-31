/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if( (l1==nullptr) && (l2==nullptr)) {
            return nullptr;
        }
        
        if( (l1==nullptr) && (l2!=nullptr)) {
            return l2;
        }
        if( (l1!=nullptr) && (l2==nullptr)) {
            return l1;
        }
        
        if(l1->val>l2->val) {
            ListNode *tmp = l1;    
            l1=l2;
            l2=tmp;
        }
        
        ListNode *res = (l1->val<=l2->val) ? l1:l2;
        
        while(l2!=nullptr && l1!=nullptr) {

            int nextVal = 0;
            if(l1->next==nullptr) {
                nextVal = INT_MAX;
            } else {
                nextVal = l1->next->val;
            }
            
            if( (l1->val <= l2->val) && ( l2->val < nextVal) )   {
                
                ListNode *oldl1next = l1->next;
                l1->next=l2;

                ListNode *oldl2next = l2->next;
                l2->next = oldl1next;
                l2=oldl2next;
                
                l1=l1->next;
                
            } else {
                l1=l1->next;
            }
            
            // if(res)
            //     printList(res);
        }
        return res;
    }
    
private: 
    
    void printList(ListNode *head) {
        while(head) {
            cout << "[" << head->val << "] ";
            head = head->next;
        }
        cout << endl;
    }
    
};