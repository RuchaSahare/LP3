#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

int partition(int arr[],int low,int high,bool random)
{
    if(random)
    {
        int randomIndex=low+rand()%(high-low+1);
        swap(arr[low],arr[randomIndex]);
    }
    
    
    int pivot=arr[low];
    int start=low+1;//give index
    int end=high;//give index
    
    while(start<=end)
    {
        while(start<=end && arr[start]<=pivot)
        {
            start++;
        }
        while(start<=end && arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[low],arr[end]);
    return end;
}

void quicksort(int arr[],int low,int high,bool random)
{
    if(low<high)
    {
        int loc=partition(arr,low,high,random);
        quicksort(arr,low,loc-1,random);
        quicksort(arr,loc+1,high,random);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    
    int data[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    
    cout<<"Unsorted Array: ";
    printArray(data,n);
    
    int deter[n];
    for(int i=0;i<n;i++)
    {
        deter[i]=data[i];
    }
    
    quicksort(deter,0,n-1,false);
    cout<<"Sorted array after deterministic sort"<<endl;
    printArray(deter,n);
    
    quicksort(data,0,n-1,true);
    cout<<"Sorted array after random sort"<<endl;
    printArray(data,n);
    return 0;
    
    
}