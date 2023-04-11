#pragma once
#include <vector>
#include <stack>
#include <ctime>
#include <stdlib.h>

const size_t STANDART_LVL = 4;

template<class T, class Y>
class SkipList {
public:
	struct Node {
		T key;
		Y val;
		std::vector<Node*> next;

		Node(size_t size_, T key_ = T(), Y val_ = Y()) : key(key_), val(val_), next(std::move(std::vector<Node*>(size_ + 1, nullptr))) {}
		size_t lvl() { return next.size() - 1; }
	};
private:
	Node head;

	size_t max_lvl;

	Node* find_(const T& key, Node* n) {
		if (n != &head && (!n || n->key == key)) return n;

		for (int i = n->next.size() - 1; i >= 0; i--) {
			if ((n->next[i]) != nullptr && key >= (n->next[i]->key)) {
				return find_(key, n->next[i]);
			}
		}

		return nullptr;
	}

	void fill_history(std::stack<Node*>& history, const T& key) {
		Node* n = &head;
		history.push(n);

		bool end_while = false;

		while (!end_while && n && (key > n->key)) {
			end_while = true;
			int i = n->next.size() - 1; 
			for (; i >= 0; i--) {
				if (n->next[i] && key > n->next[i]->key) {
					end_while = false;
					n = n->next[i];
					break;
					
				}
			} 
			


			if (n && end_while) history.push(n);
		}

	}

	size_t random_lvl() {
		double val = (double)std::rand() / RAND_MAX;

		size_t lvl = 0;
		double deg = 1;

		for (size_t i = 0; i < max_lvl; i++, deg *= 0.5) {
			if (val <= deg) lvl = i;
			else break;
		}
		

		return lvl;
	}

public:
	SkipList() : head(STANDART_LVL), max_lvl(STANDART_LVL) {
		std::srand(std::time(0));
	};
	~SkipList() {
		if (head.next[0]) {
			Node* tmp = head.next[0];
			Node *next = nullptr;

			while (tmp) {
				next = tmp->next[0];
				delete tmp;
				tmp = next;
			}
		}
	}

	Node* find(const T& key) {
		return find_(key, &head);
	}

	bool is_null(Node* node) {
		for (auto i : node->next)
			if (i) return false;

		return true;
	}

	void emplace(const T& key, const T& val) {
		if (!find(key)) {
			Node* new_node = new Node(random_lvl(), key, val);


			if (is_null(&head)) {
				for (int i = 0; i <= new_node->lvl(); i++) {
					head.next[i] = new_node;
				}
			}
			else {
				std::stack<Node*> history;
				fill_history(history, key);


				for (size_t i = 0; i <= new_node->lvl(); i++) {
					if (history.empty()) break;
					
					if (i > history.top()->lvl()) {
						history.pop();
					}
					new_node->next[i] = history.top()->next[i];
					history.top()->next[i] = new_node;

				}
			}
		}
	}
};
