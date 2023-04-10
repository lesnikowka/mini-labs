#pragma once
#include <vector>
#include <stack>
#include <ctime>

const size_t STANDART_LVL = 5;

template<class T, class Y>
class SkipList {
public:
	struct Node {
		T key;
		Y val;
		std::vector<Node*> next;

		Node(size_t size_, T key_ = T(), Y val_ = Y()) key(key_), val(val_), next(size_) {}
		size_t lvl() { return next.size(); }
	};
private:
	Node head;

	size_t max_lvl;

	Node* find_(const T& key, Node* n) {
		if (n != &head && (!n || n->key == key)) return n;

		for (int i = n->next.size() - 1; i >= 0; i--) 
			if (n->next[i] && key >= n->next[i]->key)
				return find_(key, n->next[i]);

		return nullptr;
	}

	void fill_history(std::stack<T>& history, const T& key) {
		Node* n = &head;
		while (n && key > n->key) {
			for (int i = next.size() - 1; i >= 0; i--) {
				if (n != &head && key > n->next[i]->key) {
					history.push(n);
					n = n->next[i];
					break;
				}
			}
		}
	}

	size_t random_lvl() {
		std::srand(std::time(0));


	}

public:
	SkipList() : head(new Node(STANDART_LVL)), max_lvl(STANDART_LVL) {};
	~SkipList() {
		if (head->next[0]) {
			Node* tmp = head->next[0], next = nullptr;

			while (tmp) {
				next = tmp->next[0];
				delete tmp;
				tmp = next;
			}
		}
	}

	Node* find(const T& key) {
		return find_(key, head->next[0]);
	}

	void emplace(const T& key, const T& val) {
		if (!find(key)) {
			Node* prev = find()
		}
	}
};
