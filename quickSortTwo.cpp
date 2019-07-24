//Created by Brandon Barnes

#include <iostream>

using namespace std;
void swap(int* first, int* second) 
{ 
    int temp = *first; 
    *first = *second; 
    *second = temp; 
} 


int partition(int* array, int low, int high){
	int pivot = array[high];
	int temp = (low-1);
	
	for(int i = low; i<= high-1; i++){
		if(array[i]<=pivot){
			temp++;
			swap(&array[temp], &array[i]);
		}
	}
	swap(&array[temp+1], &array[high]);
	return(temp+1);
	
}

void quickSort(int* array, int low, int high){
	if(low<high){
		int part = partition(array, low, high);
		
		quickSort(array, low, part-1);
		quickSort(array, part+1, high);
	}
}

  
// Driver program to test above functions 
int main() 
{ 
    int array[] = {15, 16, 8, 42, 4, 23}; 
    quickSort(array, 0, 5); 
	for(int i = 0; i<6; i++){
		cout << array[i]<< ' ';
	}
    return 0; 
} 