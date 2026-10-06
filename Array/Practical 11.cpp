#include<iostream>
using namespace std;

int b_search(int p[],int l, int r, int k)
{
    int mid;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(k==p[mid])
        return mid;
        else if(k<p[mid])
        r = mid-1;
        else
        l = mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int p[n];
    cout<<"Enter the elements of the array in sorted order: ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int k;
    cout<<"Enter the element to be searched: ";
    cin>>k;
    int result = b_search(p,0,n-1,k);
    if(result==-1)
    cout<<"Element not found in the array."<<endl;
    else
    cout<<"Element found at index: "<<result<<endl;
    
    return 0; 
}