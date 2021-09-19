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

public:

    /*
     * 描述：nums是要修改的vector数组
     * 返回：k是不同的元素
     * 注意：传入的是引用，会对原来的数组进行修改
     */
    int removeDuplicatesI(vector<int>& nums) {

        //仅有一个元素，直接返回
        if(nums.size() <= 1)
            return nums.size();

        //两个指针用来遍历
        int start = 0;
        int result =1;

        for (int i = 1; i < nums.size(); ++i) {
            if(nums.at(i) == nums.at(start)){
                nums.at(i) = -99999;
            }else{
                nums.at(++start) = nums.at(i);
                result ++;
            }
        }

        return result;

    }

    /*
   * 描述：nums是要修改的vector数组
   * 返回：k是不同的元素
   * 注意：传入的是引用，会对原来的数组进行修改
   */
    int removeDuplicates(vector<int>& nums) {

        //仅有一个元素，直接返回
        if(nums.size() <= 1)
            return nums.size();

        //两个指针用来遍历
        int start = 0;
        int result =1;
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if(nums.at(i) == nums.at(start)){
                count ++;
                if(count == 2){
                    nums.at(++start) = nums.at(i);
                    result ++;
                }else{
                    nums.at(i) = 999999;
//                    count = 0;
                }

            }else{
                nums.at(++start) = nums.at(i);
                result ++;
                count = 1;
            }
        }

        return result;

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

    Solution solution;
    int result = solution.removeDuplicates(number);

    //traverse all the elements of the linkedlist
    for (int j = 0; j < result; ++j) {
        cout<<number.at(j);
    }
    return 0;
}
