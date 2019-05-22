//先确定链表表头，然后再逐个比较去较小节点添加到目标链表之后
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
        ListNode* head,*list;
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        if(l1->val<l2->val){
            list=l1;
            l1=l1->next;
        }
        else{
            list=l2;
            l2=l2->next;
        }
        
        head=list;
        while(l1&&l2){
            if(l1->val<l2->val){
                list->next=l1;
                l1=l1->next;
            }
            else{
                list->next=l2;
                l2=l2->next;
            }
            list=list->next;
        }
        if(l1)
            list->next=l1;
        else
            list->next=l2;
        return head;
    }
};
