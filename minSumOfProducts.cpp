//Created by Brandon Barnes


//Does not preserve ordering of array

#include <iostream> //for example display

using namespace std;

//quickSort util
void swap(int* first, int* second) 
{ 
    int temp = *first; 
    *first = *second; 
    *second = temp; 
} 

//quickSort util
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

//dependency for minSumOfProducts
void quickSort(int* array, int low, int high){
	if(low<high){
		int part = partition(array, low, high);
		
		quickSort(array, low, part-1);
		quickSort(array, part+1, high);
	}
}

int minSumOfProducts(int arr1[], int arr2[], int sizeOne, int sizeTwo){
	int accumulator = 0;
	int j = 0;
	
	if(sizeOne == 0 || sizeTwo == 0){
		return 0;
	}
	
	
	
	quickSort(arr1, 0, sizeOne-1);
	quickSort(arr2, 0, sizeTwo-1);
	
	if(sizeOne == 1 || sizeTwo == 1){
		return arr1[0]*arr2[0];
	}
	
	if(sizeOne > sizeTwo){
		for(int i = sizeOne-1; i>-1; i--){ 
		//not checking j since sizeTwo loops occur and sizeTwo < sizeOne, so no bounds errors could occur
			accumulator = accumulator + (arr1[j] * arr2[i]);
			j++;
		}
		
	}
	else{
		//sizeTwo >= sizeOne
		for(int i = sizeOne-1; i>-1; i--){ 
		//not checking j since sizeOne loops occur and sizeOne <= sizeTwo, so no bounds errors could occur
			accumulator = accumulator + (arr1[i] * arr2[j]);
			j++;
		}
	}
	
	
	return accumulator;
}



int main(){
	
	int arr1[] = {1,1,1};
	int arr2[] = {3,4,8,2,4,9};
	int sizeOne = sizeof(arr1)/sizeof(arr1[0]);
	int sizeTwo = sizeof(arr2)/sizeof(arr2[0]);
	
	cout << minSumOfProducts(arr1, arr2, sizeOne, sizeTwo) << endl;
	
	
	return 0;
}