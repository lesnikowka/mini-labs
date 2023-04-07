#include <iostream>

template<class T>
class List {
	class Point {
	public:
		T value;
		Point* last_ptr;
		Point* next_ptr;
		Point(Point* last_ptr, Point* next_ptr, T value) : last_ptr(last_ptr), next_ptr(next_ptr), value(value) {}
	};
	Point* head;
	Point* tail;
	int size;

public:
	List() : head(nullptr), tail(nullptr), size(0){}

	~List() {
		Point* ptr = head;
		Point* temp_ptr = ptr;
		while (ptr != nullptr) {
			ptr = ptr->next_ptr;
			delete temp_ptr;
			temp_ptr = ptr;
		}
	}

	int get_size() { return size; }

	void push_back(T value_) {
		if (head == nullptr) {
			head = tail = new Point(nullptr, nullptr, value_);
		}
		else {
			Point* old_tail = tail;
			tail = new Point(old_tail, nullptr, value_);
			old_tail->next_ptr = tail;
		}
		size++;
	}

	void push_front(T value_) {
		if (head == nullptr) {
			head = tail = new Point(nullptr, nullptr, value_);
		}
		else {
			Point* old_head = head;
			head = new Point(nullptr, old_head, value_);
			old_head->last_ptr = head;
		}
		size++;
	}
	
	T& operator[](unsigned int index) {
		try {
			if (index >= size) throw new std::exception("Out of the range");
			else {
				Point* ptr;
				int i = 0;
				if (index < size / 2) {
					ptr = head;
					while (ptr != nullptr) {
						if (i == index) return ptr->value;
						i++;
						ptr = ptr->next_ptr;
					}
				}
				else{
					ptr = tail;
					while (ptr != nullptr) {
						if (size - 1 - i == index) return ptr->value;
						i++;
						ptr = ptr->last_ptr;
					}
				}
			}
		}
		catch(std::exception ex){
			std::cout << ex.what();
		}
	}
};

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