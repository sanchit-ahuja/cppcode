#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
    private:
        int maxSize;
        vector <char> stackVect;
        int top;
    public:
    Stack(int s) : maxSize(s), top(-1) //constructor
        { stackVect.resize(maxSize); }

    void push(char j)
    {stackVect[++top]=j;}

    char pop()
    {return stackVect[top--];}

    char peek()
    {return stackVect[top];}

}

class Bracket
{
    private:
        string input;
    public:
    Bracket(string in):input(in)
    {}
    void check()
    {
        int stackSize=input.length();}
        Stack thestack(stackSize);
        for(int j=0;j<input.length();j++)
        {
            char ch=input[j];
            
        }    
}