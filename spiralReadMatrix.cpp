//Created by Brandon Barnes

#include <iostream>
#include <vector>

using namespace std;

void spiralReadMatrix(vector<vector <int> > matrix, int columns, int rows){
	if(rows<1 || columns<1){ //invalid cases
		return;
	}
	
	int numberCount = rows*columns;
	int sentinel = 0;
	int rowPosition = 0;
	int columnPosition = 0;
	int spiralCount = 0;
	int timeSaverTemp = 0; //used to store calculations to save time in loops
	
	while(numberCount>sentinel){
		
		
		//top left to top right
		timeSaverTemp = (rows-spiralCount); 
		while(rowPosition<timeSaverTemp){
			cout <<matrix[columnPosition][rowPosition] << " ";
			rowPosition++;
			sentinel++;
		}
		
		//top right to bottom right
		rowPosition--;
		columnPosition++;
		timeSaverTemp = (columns-spiralCount);
		while(columnPosition<timeSaverTemp){
			cout << matrix[columnPosition][rowPosition] << " ";
			columnPosition++;
			sentinel++;
		}
		
		
		//bottom right to bottom left
		columnPosition--;
		rowPosition--;
		timeSaverTemp = (0+spiralCount)-1;
		while(rowPosition>timeSaverTemp){
			cout <<matrix[columnPosition][rowPosition] << " ";
			rowPosition--;
			sentinel++;
		}
		
		//bottom left to new top left
		rowPosition++;
		columnPosition--;
		timeSaverTemp = (0+spiralCount);
		while(columnPosition>timeSaverTemp){
			cout <<matrix[columnPosition][rowPosition] << " ";
			columnPosition--;
			sentinel++;
		}
		columnPosition++;
		rowPosition++;
		spiralCount++;
		
	}
	
	
	
	return;
}

int main(){
	vector<vector<int> > matrixA = { {1, 2, 3, 4}, 
									 {5, 6, 7, 8},
									 {9, 10, 11, 12},
									 {13, 14, 15, 16} }; //square test matrix 3x3
	
	vector<vector<int> > matrixB = { {1, 2, 3}, 
									 {4, 5, 6} }; //rectangular test matrix, 2x3
	
	spiralReadMatrix(matrixB, 2, 3);
	
	return 0;
}