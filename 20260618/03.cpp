#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> *dataset,int left,int right)
{
    if(left==right) return;
    
    int i=left-1,j=right+1,mid=(*dataset)[(left+right)/2];

    while(i<j)
    {
        do
        {
            i++;

        } while ((*dataset)[i]<mid);
        do
        {
            j--;
        } while ((*dataset)[j]>mid);
        
        if(i<j)
        {
            swap((*dataset)[i],(*dataset)[j]);
        }
    }
    
    quicksort(dataset,left,j);
    quicksort(dataset,j+1,right);
}

#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> *dataset,int left,int right)
{
    if(left >= right) return;

    int i=left-1,j=right+1,mid=(*dataset)[(left+right)/2];

    while(i<j)
    {
        do{i++;} while((*dataset)[i]<mid);
        do{j--;} while((*dataset)[j]>mid);

        if(i<j)
            swap((*dataset)[i],(*dataset)[j]);
    }

    quicksort(dataset,left,j);
    quicksort(dataset,j+1,right);
}

void siftup(vector<int> *heap,int i)
{
    if(i == 0) return;

    int parent = (i - 1) / 2;

    if((*heap)[parent] > (*heap)[i])
    {
        swap((*heap)[parent], (*heap)[i]);
        siftup(heap, parent);
    }
}

void siftdown(vector<int> *heap, int i, int n)
{
    while(true)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if(l < n && (*heap)[l] < (*heap)[smallest]) smallest = l;
        if(r < n && (*heap)[r] < (*heap)[smallest]) smallest = r;

        if(smallest == i) break;

        swap((*heap)[i], (*heap)[smallest]);
        i = smallest;
    }
}

void heapsort(vector<int> *heap)
{
    int n = heap->size();

    // 1. 建堆（你用 siftup 也可以，这里补标准版）
    for(int i=1;i<n;i++)
    {
        siftup(heap, i);
    }

    // 2. 排序过程
    for(int i=n-1;i>0;i--)
    {
        swap((*heap)[0], (*heap)[i]);
        siftdown(heap, 0, i);
    }
}


int main(void)
{
    int num_data; cin >> num_data;
    vector<int> dataset1,dataset2;
    for(int i=0;i<num_data;i++)
    {
        int value; cin >> value; dataset1.push_back(value); cin >> value; dataset2.push_back(value);
    }

    quicksort(&dataset1,0,size(dataset1)-1);
    
    heapsort(&dataset2);

    for(int x:dataset2)
        cout << x << " ";

    return 0;
}