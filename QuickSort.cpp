#include<iostream>
#include<vector>
using namespace std;
//交换函数
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//分割函数  找到key的位置
int Partition(vector<int>&a,int left, int right)
{
    int key=a[left];
    //设置2个指针
    int low=left;
    int high=right;
    while(low<high)
    {
        while(low<high && a[high]>=key) high--;//从大的开始
        while(low<high && a[low]<=key)  low++;
        if(a[low]<a[high])//重点是这里
          swap(a[low],a[high]);
    }
    a[left]=a[low];
    a[low]=key;
    return(low);
}
void QuickSort(vector<int>&a,int low,int high)
{
    if(low<high)
    {
    int middle=Partition(a,low,high);
    cout<<endl<<"middle:"<<middle<<endl;
    QuickSort(a,low,middle-1);
    QuickSort(a,middle+1,high);
    }
}
int main()
{
    vector<int>a;
    int length;
    std::cout<<"input the length :"<<endl;
    std::cin>>length;
    for(int i=0;i<length;i++)
    {
        int temp;
        std::cin>>temp;
        a.push_back(temp);
    }
    cout<<"output a:";
    for(int i=0;i<length;i++)
        cout<<a[i];
    QuickSort(a,0,length-1);
     cout<<"output a: "<<endl;
    for(int i=0;i<length;i++)
     std::cout<<a[i]<<"  "<<endl;
}
