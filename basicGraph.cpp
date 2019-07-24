//Created by Brandon Barnes

//displayMatrix design modified from: https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix
//Graph sizing based on design from: https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix


#include <iostream>
#include <vector>

using namespace std;

class Edge{
	int rowPosition;
	int columnPosition;
	int weight;
	
	public:
	Edge(int r, int c, int w){
		this->rowPosition = r;
		this->columnPosition = c;
		this->weight = w;
	}
	int getRow(){
		return this->rowPosition;
	}
	int getColumn(){
		return this->columnPosition;
	}
	int getWeight(){
		return this->weight;
	}
};

class Node{
	int value;
	vector<Edge> edges;
	
	public:
	Node(){
		this->value = 0;
	}
	
	Node(int startingValue){
		this->value = startingValue;
	}
	
	void addEdge(int rowPosition, int columnPosition, int weight){
		edges.push_back(Edge(rowPosition, columnPosition, weight));
	}
	int getValue(){
		return this->value;
	}
	Edge getEdge(int position){
		return edges[position];
	}
};

void displayMatrix(vector<vector <Node> > adjMatrix,int rows, int columns){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<columns; j++){
			cout << adjMatrix[i][j].getValue() << ' ';
		}
		cout << endl;
	}
}

vector<vector <Node> > genBasicGraph(int rowSize, int columnSize){
	Node* temp = new Node(1);
	vector<vector <Node> > graph(rowSize, vector<Node>(columnSize));
	
	
	graph[0][0] = *temp;
	
	for(int i = 1; i<rowSize && i<columnSize; i++){
		temp = new Node(i);
		graph[i][i] = *temp;
		temp->addEdge(i-1,i-1,i);
		graph[i-1][i-1].addEdge(i,i,i);
	}
	
	
	return graph;
	
}


int main(){
	vector<vector <Node> > graph(10, vector<Node>(10));
	int rowSize = 10;
	int columnSize = 10;
	
	
	
	
	Node* temp = new Node(0);
	graph[0][0] = *temp;
	
	temp = new Node(1);
	graph[1][1] = *temp;
	temp->addEdge(0,0,1);
	graph[0][0].addEdge(1,1,1);
	
	temp = new Node(4);
	graph[2][2] = *temp;
	temp->addEdge(1,1,2);
	graph[1][1].addEdge(2,2,2);
	
	temp = new Node(9);
	graph[3][3] = *temp;
	temp->addEdge(2,2,3);
	graph[2][2].addEdge(3,3,3);
	
	
	temp = new Node(16);
	graph[4][4] = *temp;
	temp->addEdge(3,3,4);
	graph[3][3].addEdge(4,4,4);
	
	
	temp = new Node(25);
	graph[5][5] = *temp;
	temp->addEdge(4,4,5);
	graph[4][4].addEdge(5,5,5);
	
	temp = new Node(36);
	graph[6][6] = *temp;
	temp->addEdge(5,5,6);
	graph[5][5].addEdge(6,6,6);
	
	temp = new Node(49);
	graph[7][7] = *temp;
	temp->addEdge(6,6,7);
	graph[6][6].addEdge(7,7,7);
	
	temp = new Node(64);
	graph[8][8] = *temp;
	temp->addEdge(7,7,8);
	graph[7][7].addEdge(8,8,8);
	
	temp = new Node(81);
	graph[9][9] = *temp;
	temp->addEdge(8,8,9);
	graph[8][8].addEdge(9,9,9);
	
	temp = new Node(1000);
	graph[0][9] = *temp;
	temp->addEdge(1,1,12);
	graph[1][1].addEdge(0,9,12);
	
	
	temp = new Node(1000);
	graph[9][0] = *temp;
	temp->addEdge(4,4,15);
	graph[4][4].addEdge(8,8,15);
	
	return 0;
}