#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>


std::vector<int> wide_search(std::vector<std::vector<int>> adj_matrix, int point) {

	std::queue<int> queue;
	std::vector<int> way;

	if (point >= adj_matrix.size())
		return way;

	std::vector<bool> labelled(adj_matrix.size());
	
	std::vector<int> last_point(adj_matrix.size());
	
	for (int i = 0; i < last_point.size(); i++)
		last_point[i] = -1;

	int current = 0;

	queue.push(current);


	while (!labelled[point] && !queue.empty()){
		current = queue.front();

		queue.pop();

		labelled[current] = 1;

		for (int i = 0; i < adj_matrix.size(); i++)
			if (adj_matrix[current][i] && !labelled[i] ){
				//std::cout << "CURRENT: " << current << " NEIGHBOR: " << i << std::endl;
				if(last_point[i] == -1)
					last_point[i] = current;
				queue.push(i);
			}
	}

	if (!labelled[point])
		return way;


	int i = point;

	while(i != 0){
		way.push_back(i);
		i = last_point[i];
	} 
	way.push_back(0);


	return way;
}


void random_fill(std::vector<std::vector<int>>& adj_matrix, int size) {
	std::srand(std::time(0));

	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
			if (std::rand() > (RAND_MAX / 2)) {
				adj_matrix[i][j] = 1;
				adj_matrix[j][i] = 1;
			}
			

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) 
			std::cout << adj_matrix[i][j] << "  ";
		
		std::cout << std::endl;
	}
}


int main() {
	int size;
	int point;

	std::cin >> size >> point;
	std::vector<std::vector<int>> adj_matrix(size);

	for (int i = 0; i < size; i++)
		adj_matrix[i].resize(size);

	//for (int i = 0; i < adj_matrix.size(); i++)
	//	for (int j = 0; j < adj_matrix.size(); j++)
	//		std::cin >> adj_matrix[i][j];

	random_fill(adj_matrix, size);

	std::vector<int> way = wide_search(adj_matrix, point);


	for (int i = way.size()-1; i >= 0; i--)
		std::cout << way[i] << " ";


	/*
		0  0  1  1  0  0  0  0  0  1
		0  0  0  0  1  0  1  1  1  0
		1  0  0  1  0  0  0  0  0  1
		1  0  1  0  0  0  1  0  0  1
		0  1  0  0  0  1  1  0  1  0
		0  0  0  0  1  0  1  0  0  1
		0  1  0  1  1  1  0  0  1  1
		0  1  0  0  0  0  0  0  1  0
		0  1  0  0  1  0  1  1  0  0
		1  0  1  1  0  1  1  0  0  0

	*/

	return 0;
}
