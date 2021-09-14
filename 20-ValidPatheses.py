#include<iostream>
#include<stack>

using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char> oprend;
        char temp;
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) == '(' || s.at(i) == '{' ||s.at(i) == '[' ){
                oprend.push(s.at(i));
            }else {
                //判定并且获取栈顶的元素
                temp = oprend.top();
                oprend.pop();

                //
                bool judge = (s.at(i) == '}' && temp == '{') ||
                             (s.at(i) == ']' && temp == '[') ||
                             (s.at(i) == ')' && temp == '(');
                if (!judge) {
                    return false;
                }
            }
        }
    }
};
