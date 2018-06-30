#include<iostream>
using namespace std;
#include<vector>
void merge(vector<int>&a,int low,int middle,int high)
{
    vector<int>b;//辅助数组
    for(int i=0;i<a.size();i++)
     b.push_back(a[i]);
     int index1,index2,k;
     for( index1=low,index2=middle+1,k=low; index1<=middle && index2<=high; k++)//i j是B的指针
     {
         if(b[index1]<b[index2])
         a[k]=b[index1++];
         else
         a[k]=b[index2++];
    }
    //只能执行一句
    while(index1<=middle) a[k++]=b[index1++];
    while(index2<=middle) a[k++]=b[index2++];
}
void MergeSort(vector<int>&a,int low,int high)
{
    if(low<high)
    {
        int middle=(low+high)/2;
        MergeSort(a,low,middle-1);
        MergeSort(a,middle+1,high);
        merge(a,low,middle,high);
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

    MergeSort(a,0,length-1);

    cout<<"output a: "<<endl;
    for(int i=0;i<length;i++)
     std::cout<<a[i]<<"  "<<endl;
}
/*归并排序法：
T(n)=nlogn
空间复杂度：O(n)
*/
