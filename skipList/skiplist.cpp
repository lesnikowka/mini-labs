#include <iostream>
#include "skipList.h"
#include <vector>

template<class T, class Y>
SkipList<T, Y> create_list(const std::vector<std::pair<T, Y>>& v) {
	SkipList<int, int> sl;

	for (const auto& e : v) {
		sl.emplace(e.first, e.second);
	}

	return sl;
}

template<class T, class Y>
bool Contain(const std::vector<std::pair<int, int>> v, SkipList<T, Y> sl) {
	for (const auto& e : v) {
		if (sl.find(e.first) == nullptr) {
			return false;
		}
	}
	return true;
}

std::vector<std::pair<int, int>> create_vector(size_t size) {
	std::srand(0);
	std::vector<std::pair<int, int>> v;
	for (int i = 0; i < size; i++) {
		int tmp = std::rand() / 1000;
		if (std::find(v.begin(), v.end(), std::make_pair(tmp,tmp)) == v.end()) {
			v.push_back(std::make_pair(tmp, tmp));
		}
	}
	return v;
}

void printVector(std::vector<std::pair<int, int>> v) {
	std::cout << "{";
	for (auto i : v) {
		std::cout << "{" << i.first << ", " << i.second << "}, ";
	}
	std::cout << "}" << std::endl << std::endl;
}

int main() {
	//std::vector<std::pair<int, int>> v = { {1,1},{6,45},{-1,-12},{100,1030},{234,234},{884663,5452},{8977,0},{5,40}, {100, 3}, {888,3}, {2,2} };
	//
	//SkipList<int, int> sl = create_list<int, int>(v);
	//
	//bool b = Contain<int, int>(v, sl);
	//
	//std::vector<std::pair<int, int>> v = { {1,1},{6,45},{-1,-12},{100,1030},{234,234},{884663,5452},{8977,0},{5,40}, {100, 3}, {888,3}, {2,2} };


	std::vector<std::pair<int, int>> v = create_vector(7);
	printVector(v);

	v = { {0,0}, {7,7}, {21,21}, {2,2}, {8,8}, {11,11} };

	SkipList<int, int> sl;

	for (const auto& e : v) {
		sl.emplace(e.first, e.second);
	}

	

	bool b = Contain<int, int>(v, sl);

	sl.erase(v[0].first);
	sl.erase(v[1].first);
	sl.erase(v[2].first);
	sl.erase(v[3].first);
	sl.erase(v[4].first);
	sl.erase(v[5].first);

	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());

	printVector(v);

	bool b2 = Contain<int, int>(v, sl);

}
