#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

string convert(string input)
{
    stack<char>stackop;
    queue<char>queueoutput;
    string op="+-*/^";
    string result;

    int len=input.size();
    for(int i=0;i<len;i++)
    {
        if(isalpha(input[i]))
        {
            queueoutput.push(input[i]);
        }
        else if(op.find(input[i])!=string::npos)
        {
            while(stackop.size()>0&&op.find(stackop.top())!=string::npos&&op.find(input[i])<=op.find(stackop.top()))
            {
                queueoutput.push(stackop.top());
                stackop.pop();
            }
            stackop.push(input[i]);
        }
        else if(input[i]=='(')
        {
            stackop.push(input[i]);
        }
        else if (input[i]==')')
        {
            while(!stackop.empty())
            {
                if(stackop.top()=='(')
                {
                    stackop.pop();
                    break;
                }
                queueoutput.push(stackop.top());
                stackop.pop();
            }
        }
        

    }
    while(!stackop.empty())
    {
        queueoutput.push(stackop.top());
        stackop.pop();
    }
    while(!queueoutput.empty())
    {
        result=result+queueoutput.front();
        queueoutput.pop();
    }
    return result;
}

int main()
{
    string x="(a+(b*c))";
    cout<<convert(x)<<endl;
    return 0;
}