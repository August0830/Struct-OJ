#include<iostream>
using namespace std;
int *HeapData;
int *reverseHelper;
template<class T>
class MinHeap{
public:
    MinHeap(int size);
    MinHeap(const MinHeap<T>& mp){
        currentSize=mp.currentSize;
        maxHeapSize=mp.maxHeapSize;
        heap=(T*)HeapData;
        for(int i=0;i<currentSize;++i){
            heap[i]=mp.heap[i];
        }
    }
    MinHeap(T arr[],int n);
    bool insert(T ele);
    T pop();
    bool isFull();
    bool isEmpty();
    void print();
    int Size();
    T top();
    friend void orderPrint(MinHeap<int> mp){
    	int i=0;
    	while(!mp.isEmpty())
        	reverseHelper[i++]=mp.pop();
    	while(i-->0)
			cout<<reverseHelper[i]<<' ';
        cout<<endl;
    }
    
private:
    T *heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start,int end);
    void siftUp(int start);
};

template<class T>
MinHeap<T>::MinHeap(int size){
    maxHeapSize=size;
    heap=new T[size];
    currentSize=0;
    maxHeapSize=size;
}

template<class T>
MinHeap<T>::MinHeap(T arr[],int n){
    maxHeapSize=n;
    heap=new T[maxHeapSize];
    currentSize=n;
    for(int i=0;i<n;i++){
        heap[i]=arr[i];
    }
    int currentPos=(n-2)/2;
    while(currentPos>=0){
        siftDown(currentPos,currentSize-1);
        currentPos--;
    }
}

template<class T>
bool MinHeap<T>::isFull(){
    return currentSize==maxHeapSize;
}

template<class T>
bool MinHeap<T>::isEmpty(){
    return currentSize==0;
}

template<class T>
void MinHeap<T>::siftDown(int start,int end){
    T tmp=heap[start];
    int i=start;
    int j=i*2+1;
    while(j<=end){
        if(j<end&&heap[j]>heap[j+1])j++;
        if(tmp>heap[j]){
           heap[i]=heap[j];
           i=j;
           j=i*2+1; 
        }
        else{
            break;
        }
    }
    heap[i]=tmp;
}

template<class T>
void MinHeap<T>::siftUp(int start){
    T tmp=heap[start];
    int j=start,i=(j-1)/2;
    while(j>0){
        if(heap[i]>tmp){
            heap[j]=heap[i];
            j=i;
            i=(j-1)/2;
        }
        else{
            break;
        }
    }
    heap[j]=tmp;
}

template<class T>
T MinHeap<T>::pop(){    
    T tmp=heap[0];
    heap[0]=heap[currentSize-1];
    siftDown(0,--currentSize-1);
    return tmp;
}

template<class T>
bool MinHeap<T>::insert(T ele){
    if(this->isFull()){
    	if(heap[0]<ele){
	    	heap[0]=ele;
	    	siftDown(0,currentSize-1);
	    	return true;
	    }
    	else return false;	    		
    }
    heap[currentSize]=ele;
    siftUp(currentSize++);
    return true;
}

template<class T>
void MinHeap<T>::print(){
    for(int i=0;i<currentSize;i++){
        cout<<heap[i]<<' ';
    }
    cout<<endl;
}

template<class T>
int MinHeap<T>::Size(){
    return currentSize;
}

template<class T>
T MinHeap<T>::top(){
    return heap[0];
}



int main()
{
    int n,k;
    cin>>n>>k;
    HeapData=new int[k];
    reverseHelper=new int[k];
    MinHeap<int> mp(k);
    char s[20];
    int x;
    while(scanf("%s",s)==1){
        if(s[0]=='C'){  //s=="Check"
            orderPrint(mp);
        }
        else{
            sscanf(s,"%d",&x);
            mp.insert(x);
        }
    }



    return 0;
}
/*
10 3
10000
7000
Check
40000
2800
1500
Check
500
8000
3000
Check
2000
60000
Check

*/