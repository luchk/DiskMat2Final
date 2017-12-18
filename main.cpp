#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int i, int j)
{
    int s=a[i];
    a[i]=a[j];
    a[j]=s;
}

void show (int *a,int n)
{
    static int num=0;
    //cout.width (3);
    cout << num++ <<":";
    for (int i=0;i<n;i++)
        cout << a[i]<<" ";
    cout<<endl;
}

bool GenP(int *a,int n)
{
    int j=n-2;
    while (j!=-1 && a[j]>=a[j+1])j--;
    if (j==-1)
        return false;
    int k=n-1;
    while (a[j]>=a[k])k--;
        swap(a,j,k);
    int l=j+1, r=n-1;
    while (l<r)
        swap(a,l++,r--);
    return true;
}

bool GenC(int *a, int f, int r)
{
    for (int i=r-1;i>=0;i--)
    {
        if(a[i]!=f-r+i+1)
        {
            a[i]=a[i]+1;
            for(int j=i+1;j<=r-1;j++)
            {
                a[j]=a[j-1]+1;
            }
            return true;
        }
    }
}




int main()
{
    int b;
    cout<<"if choose genp press 0";
    cout<<endl;
    cout<<"if choose genc press 2";
    cout<<endl;
    cin>>b;
    if (b<1)
    {
        int n;
        cout << "enter number of numbers ";
        cin >> n;
        int a[n];
        for (int j = 0; j < n; ++j)
        {
            cout << "enter " << j+1 << " element ";
            cin >> a[j];
        }
        show(a,n);
//        sort(a+0,a+n);
//        for (int i=0;i<n;i++)
//        {
//            a[i]=i+1;
//        }
        show(a,n);
        while (GenP(a, n))
        {
            show(a, n);}
        }

    else if (b>1)
    {
        const int n=4;
        int f=6;
        int r=4;
        int a[n]={1,3,2,4};
        show(a,n);
        sort(a+0,a+n);
        show(a,n);
        for(int i=1;i<=14;i++)
        {
            GenC(a,f,r);
            show(a,r);
        }
        return 0;
    }
    return 0;
}
