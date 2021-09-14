#include<iostream>


using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* BHead = l2;
        ListNode* AHead = l1;
        ListNode* result;

        if(AHead && !BHead) return AHead;
        if(!AHead && BHead) return BHead;

        if(AHead && BHead){
            if(AHead->val >= BHead->val) {
                result = BHead;
                BHead = BHead->next;
            }else{
                result = AHead;
                AHead = AHead->next;
            }
        }

      
     //the fellow is the code I refer from the others
         ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val>=l2->val) l2->next = mergeTwoLists(l1, l2-> next);
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            l2 = l1;
        }return l2;
    }
      


        //get the final result
        ListNode* temp = result;

        //both lists are all true
        while(BHead && AHead){
            if(AHead->val > BHead->val){
                temp->next = BHead;
                BHead = BHead->next;
            }else{
                temp->next = AHead;
                AHead = AHead->next;
            }
            temp = temp->next;
        }

        //concat the rest part of the list
        if(BHead){
            temp->next = BHead;
        }

        if(AHead){
            temp->next = AHead;
        }

        return result;
        
    }
};

