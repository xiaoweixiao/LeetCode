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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,carray=0,x=0,y=0;
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(l1!=nullptr||l2!=nullptr){
            x=(l1!=nullptr)?l1->val:0;
            y=(l2!=nullptr)?l2->val:0;
            sum=carray+x+y;
            carray=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            if(l1!=nullptr)
                l1=l1->next;
            if(l2!=nullptr)
                l2=l2->next;
        }
        if(carray>0)
            cur->next=new ListNode(carray);
        return head->next;
    }
};
