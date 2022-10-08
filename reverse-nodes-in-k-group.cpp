/**
 * Definition for singly-linked list.
 * struct ListNode {
*     int val;
*     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {} *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
    
        ListNode *s1, *s2, *t, *t1, *t2;
        
        // For counting number of node in a link list
        int count=0;
        s1 = head;
        while(s1 != NULL) {
            count++;
            s1 = s1->next;
        }
        
        // if k is more then number of node in link list then return head
        if(k>count) return head;
        
        // find the multiple of k from total number of node count because no need to rever the remaining node.
        int target = (count/k) * k;

        //start reverting two consecutive node till kth node.
        s2=NULL;
        t=head;
        while(target) {
            int next = k-1;
            
            s1 = s2;
            s2 = t;
            t1 = s2;
            t2 = t1->next;
            
            while(next) {
                t = t2->next;
                t2->next = t1;
                t1 = t2;
                t2=t;
                next--;
            }
            
            // if starting from head then assign head else point to next node after kth node.
            if(s1 == NULL)
                head = t1;
            else
                s1->next = t1;
            
            s2->next = t2;

            target -= k;
        }
        
        return head;
    }
};
