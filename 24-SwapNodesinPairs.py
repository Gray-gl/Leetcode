#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

//定义轻型线性表
struct ListNode {
    int val;
    ListNode *next;

    //初始化头节点
    ListNode() : val(0), next(nullptr) {}

    //带值的初始化头节点
    ListNode(int x) : val(x), next(nullptr) {}

    //带下一个结点和值的初始化
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    /*
     * 描述：交换对应序列的两个结点，并将交换之后的链表返回
     * 参数：head是指头结点
     *      k是需要交换的结点的序列
     * 返回：交换之后的链表的头节点
     * 原理：找到两个目标节点，然后进行交换值
     */
    ListNode* swapNodes(ListNode* head, int k) {

        //找到目标结点，初始化两个指针，用于搜寻目标节点
        ListNode* left = head;
        ListNode* right;

        //左边的结点，是当前的结点
        for (int i = 1; i < k; ++i) {
            left = left->next;
        }

        //右边的结点的前一个结点
        right =  findLastNode(head,k);

        //交换对应的值
        int temp = left->val;
        left->val = right->next->val;
        right->next->val = temp;

        //返回最终结果
        return head;
    }

    /*
     * 描述：两两交换链表的连续的两个结点
     * 参数：head是对应的链表的头节点
     * 返回：交换过顺序之后链表的头指针
     */
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next){
            return head;
        }

        //保存两个新链表的头指针
        ListNode* left = head;
        ListNode* right = head->next;

        //保存两个新链表的尾指针
        ListNode* leftEnd = left;
        ListNode* rightEnd = right;

        //遍历原先长链表的指针
        ListNode* temp = head->next->next;

        //开始遍历长链表将之分为两个的短链表
        int i = 1;
        while (temp){
            if(i % 2 != 0){
               leftEnd->next = temp;
               leftEnd = leftEnd->next;
            }else{
                rightEnd->next = temp;
                rightEnd = rightEnd->next;
            }
            temp = temp->next;
            i ++;
        }

        //make the end of two short linklist as nullPointer
        leftEnd->next = nullptr;
        rightEnd->next = nullptr;

        //将两个链表进行合并
        rightEnd = right;
        while (left){

            //store the left part of the right linkedlist
            leftEnd = rightEnd->next;

            //split the left part to the right
            rightEnd->next = left;

            //move the end of the right to the end
            rightEnd = rightEnd->next;

            //move the left part to the left
            left = leftEnd;

        }


        //return the result
        return right;

    }
};

int main(int argc, char const *argv[])
{
    //声明vector用来保存数组
    vector<int> number;

    //处理输入，形成对应的链表
    string a = "";
    getline(cin,a);

    //去除开头和结尾
    a = a.erase(0,1);
    a = a.erase(a.size()-1,1);

    //将分割之后的结果进行输出
    stringstream sstr(a);
    string token;
    while(getline(sstr,token,',')){
        number.push_back(atoi(token.c_str()));
    }

    //生成对应的链表
    auto *head = new ListNode(number.at(0));
    ListNode* temp = head;
    for (int i = 1; i < number.size(); ++i)
    {
        temp->next = new ListNode(number.at(i));
        temp = temp->next;
    }

    //目标节点
    Solution solution;
    ListNode* result = solution.swapPairs(head);

    while(result){
        cout<<result->val<<endl;
        temp = result->next;
        delete(result);
        result = temp;
    }

    return 0;
}
