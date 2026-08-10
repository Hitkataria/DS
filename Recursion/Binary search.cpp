#include<iostream>
using namespace std;

int bsearch(int p[], int l, int h, int k)
{
    if(l > h)
    {
        return -1;
    }

    int mid = (l + h) / 2;

    if(k == p[mid])
    {
        return mid;
    }

    if(k < p[mid])
    {
        return bsearch(p, l, mid - 1, k);
    }
    else
    {
        return bsearch(p, mid + 1, h, k);
    }
}

int main()
{
    int p[10] = {11, 22, 31, 44, 55, 66, 71, 73, 81, 91};
    int k;

    cout << "Enter element to search: ";
    cin >> k;

    int x = bsearch(p, 0, 9, k);

    if(x == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << x;
    }

    return 0;
}