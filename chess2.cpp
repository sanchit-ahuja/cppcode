#include<bits/stdc++.h>
using namespace std;

int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[8] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool valid(int x,int y,int N,int M)
{
     if(x <= 0 || y <= 0 || x > N || y > M)
                return false;
        return true;
}

int bfs(int N, int M, int x1,int y1,int x2,int y2)
{
    queue<pair<pair<int,int>,int>>q;
    map<pair<int,int>,bool> um;
    q.push(make_pair(make_pair(x1,y1),0));
    while(!q.empty())
    {
        pair<pair<int,int>,int> k = q.front();
        q.pop();
        if(k.first.first == x2 && k.first.second == y2)
        {
            return k.second;
        }
        int x = k.first.first;
        int y = k.first.second;
        int dist = k.second +1;
        if(um[make_pair(x,y)] == true)
        {
            continue;
        }
        um[make_pair(x,y)] =true;
        for(int i =0; i<8;i++)
        {
            int a = x+row[i];
            int b = y +col[i];
            if(valid(a,b,N,M))
            {
                q.push(make_pair(make_pair(a,b),dist));
            }
        }
    }
    return -1;
}

int main()
{
    cout<<bfs(8,8,1,1,8,8)<<endl;
}