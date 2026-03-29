#include<iostream>
using namespace std;
class MaxHeap{
    int *arr;
    int size;//total_elem in heap
    int tot_size; //total size of heap

    public:
    MaxHeap(int n){
        arr=new int[n];
        size=0;
        tot_size=n;
    }
    //insert into heap;  
    void insert(int value){

        //if heap size is available or not
        if(size==tot_size){
            cout<<"Heap overflow_error\n";
            return;
        }
        arr[size]=value;
        int index=size;
        size++;

        //Compare it with its parent
        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        cout<<arr[index]<<" is inserted into the heap\n";
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
     void Heapify(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        //Largest will store the index of the element which is greater between parent, left child and right child

        if(left<size && arr[left]>arr[index]){
            largest=index;
        }
        if(right<size && arr[right]>arr[index]){
            largest=index;
        }

        if(index!=largest){
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
     } 
    void Delete(){
        if(size==0){
            cout<<"Heap UnderFlow";
            return;
        }
        cout<<arr[0]<<" deleted from the heap";
        arr[0]=arr[size-1];
        size--;

        if(size==0) return;

        Heapify(0);
    }
};
int main(){
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
}//tc for this one is nlogn 