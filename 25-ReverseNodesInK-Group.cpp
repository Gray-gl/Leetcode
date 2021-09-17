#include<iostream>
#include <vector>
#include <string>
#include <vector>
#include <sstream>

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
private:
    /*
     * description:swap first two nodes in the ListNode
     * notes:not reverse all the node
     * parameters:l1 is the head of the linkedlist
     *            times to control the times of the reverse
     */
    ListNode* swapNode(ListNode* l1,int &times,int turns){

        if(turns < times){

            if(!l1 || !l1->next)    return l1;

            ListNode* temp;
            temp = l1->next;
            l1->next = temp->next;
            temp->next = swapNode(l1,times,turns+1);
            l1 = temp;
        }

        return l1;
    }

public:


    /*
     * description:l1 is the head node of the linkedlist
     *             k is the number of the nodes you want to change
     */
    ListNode* swapkNode(ListNode* l1,int k){
        for (int i = k-1; i > 0 && l1; --i) {
            l1 = swapNode(l1,i,0);
        }
        return l1;
    }

    /*
     * description:swap k nodes
     */
    ListNode* reverseKGroup(ListNode* head, int k) {

        //compute the length of the linkedlist
        int len =0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len ++;
        }

        //judge the link between k and result
        ListNode* result = NULL;
        int times = len /k;

        //reverse once
        if(len < k)  return head;

        //reverse many times
        result = swapkNode(head,k);
        temp = result;
        ListNode* prior = result;
        for (int i = 1; i < times; ++i) {
            for (int j = 0; j < k; ++j) {
                if(j == k-1)    prior = temp;
                temp = temp->next;
            }
            prior->next = swapkNode(temp,k);
            temp = prior->next;
        }

        return result;
    }

    /*
     * description:refer to others
     *      recursive solution
     */
    ListNode* reverseKGroup2(ListNode* head, int k) {

        //进行遍历，判定整个链表的结点的数量，如果不满足k个，直接返回head
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }

        //进行递归处理反转对应结点
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        //下述过程完成k个结点的反转交换
        //这个反转结点就做的很棒，这里反转了，然后剩下的在进行递归地反转
        //单纯的对链表结点的指针进行反向，逆转方向，需要保留三个指针，当前结点，前一个结点，和后一个结点
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }

    /*
     * description：iterative solution
     */
    ListNode* reverseKGroup3(ListNode* head, int k) {

        //dummy 头节点，后面是首结点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //curr、prev和nxt负责对结点进行逆置
        //before和after是对应的首尾结点
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;


        while(true){
            //这里是验证对应的链表结点长度是否满足k个结点
            //after是不满足对应条件k个结点开始结点
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }

            //after是head头节点
            //prev是head结点之前的结点
            curr = after;
            prev = before;

            //这里是对k个结点进行指针的逆置
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            //这里是转移结点，将头节点移动到对应
            //将头节点转移到下一个需要移动的结点之前，充当头节点
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }

};

int main(){

    //use vector to save the result
    vector<int > number;

    //处理输入和输出
    string input;
    getline(cin,input);
    input.erase(0,1);
    input.erase(input.size()-1,1);

    //split the string into different elements
    stringstream sstr(input);
    string token;
    while(getline(sstr,token,',')){
        number.push_back(atoi(token.c_str()));
    }

    //gennerate the linkedlist
    ListNode head(number.at(0));
    ListNode *temp = &head;
    for(int i = 1;i < number.size();i ++){
        temp->next = new ListNode(number.at(i));
        temp = temp->next;
    }

    //k nodes to swap
    int n;
    cin>>n;
    Solution solution;
    ListNode* result = solution.reverseKGroup2(&head,n);

    //traverse the whole linkedlist
    while(result){
        cout<<result->val<<endl;
        temp = result->next;
//        delete(result);
        result = temp;
    }

    return 0;
}
