#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
private:
    char parentheses[2] = {'(',')'};
    bool judge(string temp,int n){

        //判定最终的条件
        int remain = 2*n-temp.size();

        //judge whether the result is legal
        stack<char> mid;
        for (int i = 0; i < temp.size(); ++i) {
            if(temp.at(i) == '('){
                mid.push(temp.at(i));
            }else{

                //if all the left parentheses are removed
                if(mid.empty()){
                    return false;
                }

                //judge whether the parentheses is matching
                if(mid.top() == '('){
                    mid.pop();
                }
            }
        }

        if(mid.size() <= remain )   return true;
        else return false;
    }

    void dfs(int n,string temp,int layer,vector<string> &result){

        //judge whether it is time to terminate
        if(layer > 2*n){
            result.push_back(temp);
            return;
        }

            //if not satisfied with the result
            //continue to handle the result
        else{
            for (int i = 0; i < 2; ++i) {
                temp.append(1,parentheses[i]);
                if(judge(temp,n)){
                    dfs(n,temp,layer+1,result);
                }
                temp.pop_back();
            }
        }
        return;
    }

public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string temp = "";
        //使用回溯进行判定
        dfs(n,temp,1,res);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Solution result;

    result.generateParenthesis(n);
    for (int i = 0; i < result.res.size(); ++i) {
        cout<<result.res.at(i)<<endl;
    }

    return 0;
}



//the follow content is the code I refer from others
class Solution {
public:
    vector<string>result;
    
    void helper(int open,int close,int n,string current)
    {
        if(current.length()==n*2)
        {
            result.push_back(current);
            return;
        }
        if(open<n)  helper(open+1,close,n,current+"(");
        if(close<open)  helper(open,close+1,n,current+")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return result;
    }
};
