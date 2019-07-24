//Created by Brandon Barnes

#include <iostream>

using namespace std;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

class MinHeap{
	int* root;
	int currentSize;
	int MAX_SIZE;
	public:
	
	void MinHeapify(int i){
		int l = left(i); 
		int r = right(i); 
		int smallest = i; 
		if (l<currentSize && (root[l] < root[i])) 
			smallest=l; 
		if (r < currentSize && root[r] < root[smallest]) 
			smallest=r; 
		if (smallest!=i){
			swap(&root[i], &root[smallest]); 
			MinHeapify(smallest); 
		} 
	}
	
	
	
	
    int parent(int i){
		return ((i-1)/2);
	}
	
    int left(int i){
		return ((2*i)+1);
	}
	
    int right(int i){
		return ((2*i)+2);
	}
	
	int getMin(){
		return root[0];
	}
	
	
  
    int extractMin(){
		if(currentSize == 0){
			return 2^32-1;
		}
		
		int min = root[0];
		
		if(currentSize>1){
			root[0] = root[currentSize-1];
			MinHeapify(0);
		}
		currentSize--;
		return min;
	}
    
	MinHeap(int array[], int size){
		this->root = array;
		this->currentSize = size;
		this->MAX_SIZE = size;
	}
	
};

int kthSmallest(int array[], int sizeArr,int desiredPick){
	MinHeap tempHeap = MinHeap(array, sizeArr);
	for(int i = 0; i<desiredPick-1; i++){
		tempHeap.extractMin();
	}
	return tempHeap.getMin();
}

int main(){
	int temp;
	int desiredPick = 4;
	int size = 10;
	int array[size] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};
	temp = kthSmallest(array, size, desiredPick);
	cout << temp << endl;
	
	
	return 0;
}