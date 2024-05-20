#include<iostream>
using namespace std;
int findClosest( int n, int k,int arr[]) 
    { 
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if((arr[j]==arr[j+1]))
                    continue;
                if(abs(arr[j]-k)==abs(arr[j+1]-k))
                    return max(arr[j],arr[j+1]);
                if((abs(arr[i]-k)==abs(arr[j]-k))&&(abs(arr[j]-k)==abs(arr[j+1]-k))){
                    return max(arr[i],arr[j]);}
                if(abs(arr[i]-k)==abs(arr[j]-k))
                {
                  return abs(arr[i]-k);
                }
            }
        }
    }
int main()
{
    int arr[]={1,2,3,5,6,8,9};
    cout<<endl<<findClosest(7,4,arr);
}