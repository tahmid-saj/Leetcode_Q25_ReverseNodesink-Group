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
    ListNode* reverseOneGroup(ListNode* head, ListNode* nextHead){
        //return the new head after reversing
        //1->2->3
        //3->2->1
        ListNode* prev =nullptr;
        ListNode* cur = head;
        while(cur!=nextHead){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;        
    }
    
    ListNode* getKthNode(ListNode* head, int k){
        while(k>1 && head){
            head= head->next;
            k--;
        }
        if (k==1) return head;
        return nullptr;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        //(1->2->3)->4->5->6->7
        ListNode* groupHead = head;
        ListNode* kthNode = getKthNode(groupHead,k);
                
        if(kthNode != nullptr){
            ListNode* nextHead = kthNode->next;
            ListNode* reversedHead = reverseOneGroup(groupHead, nextHead);
            //the head is first node before reversing 1->2
            //now is the last node in the group after reversing 2->1
            // 1-> next = next goup's head
            head->next = reverseKGroup(nextHead,k);
            return reversedHead;
        }
        
        return head;
            
        
    }
};
