#include<iostream>
using namespace std;

void insertsort(int arr[],int n)
{
    for(int j=1;j<n;j++)
    {
        int key=arr[j];
        int i=j-1;
        while(i>=0&&arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}


int main()
{
    int arr[]={5,2,4,6,1,3};
    insertsort(arr,6);
    for(int i=0;i<6;i++)
    {
        cout << arr[i]<< " ";
    }
    return 0;
}