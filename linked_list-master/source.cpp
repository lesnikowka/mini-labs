#include "linked_list.h"

int main() {
	List<int> list;
	List<int> list2;

	for (int i = 0; i < 10; i++) {
		list.push_back(i);
	}

	for (int i = 0; i < 10; i++) {
		list2.push_front(i);
	}
	
	for (int i = 0; i < list.get_size(); i++)
		std::cout << list[i] << ",";

	return 0;
}