#pragma once

#pragma once

#pragma once
#include <vector>
#include <stack>
#include <ctime>
#include <stdlib.h>

const size_t STANDART_LVL = 10;

template<class T, class Y>
class SkipList {
public:
	struct Node {
		T key;
		Y val;
		std::vector<Node*> next;
		std::vector<Node*> prev;

		Node(size_t size_, T key_ = T(), Y val_ = Y()) : key(key_), val(val_),
			next(std::move(std::vector<Node*>(size_ + 1, nullptr))), prev(std::move(std::vector<Node*>(size_ + 1, nullptr))) {}
		size_t lvl() { return next.size() - 1; }
	};

	SkipList() :
		head(STANDART_LVL),
		max_lvl(STANDART_LVL) {
		std::srand(std::time(0));
	};
	SkipList(const SkipList& sl) :
		max_lvl(sl.max_lvl),
		head(STANDART_LVL)
	{
		Node* extern_node = sl.head.next[0];
		while (extern_node) {
			emplace(extern_node->key, extern_node->val);
			extern_node = extern_node->next[0];
		}
	}
	SkipList(SkipList&& sl) noexcept :
		head(STANDART_LVL),
		max_lvl(STANDART_LVL)
	{
		std::swap(head, sl.head);
		std::swap(max_lvl, sl.max_lvl);
	}
	~SkipList() {
		if (head.next[0]) {
			Node* tmp = head.next[0];
			Node* next = nullptr;

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

	void emplace(const T& key, const T& val) {
		if (!find(key)) {
			Node* new_node = new Node(random_lvl(), key, val);

			std::stack<Node*> history;
			fill_history(history, key);


			for (size_t i = 0; i <= new_node->lvl(); i++) {
				if (history.empty()) break;

				while (i > history.top()->lvl())
					history.pop();

				new_node->next[i] = history.top()->next[i];
				if (history.top()->next[i]) {
					history.top()->next[i]->prev[i] = new_node;
				}
				history.top()->next[i] = new_node;
				new_node->prev[i] = history.top();

			}

		}
	}

	void erase(const T& key) {
		Node* cur_node = find(key);

		if (!cur_node) {
			throw std::exception("Element was not found");
		}

		for (size_t i = 0; i <= cur_node->lvl(); i++) {
			cur_node->prev[i]->next[i] = cur_node->next[i];
			if (cur_node->next[i]) {
				cur_node->next[i]->prev[i] = cur_node->prev[i];
			}
		}

		delete cur_node;
	}

private:
	Node head;

	size_t max_lvl;

	Node* find_(const T& key, Node* n) {
		if (n != &head && (!n || n->key == key)) { 
			return n; 
		}

		for (int i = n->next.size() - 1; i >= 0; i--) {
			if ((n->next[i]) && key >= (n->next[i]->key)) {
				return find_(key, n->next[i]);
			}
		}

		return nullptr;
	}

	void fill_history(std::stack<Node*>& history, const T& key) {
		Node* n = &head;
		history.push(n);

		bool end_while = false;

		while (!end_while && n && (key >= n->key)) {
			end_while = true;

			for (int i = n->next.size() - 1; i >= 0; i--) {
				if (n->next[i] && key >= n->next[i]->key) {
					end_while = false;
					n = n->next[i];
					break;

				}
			}

			if (n && !end_while) {
				history.push(n);
			}
		}

	}

	size_t random_lvl() const {
		//std::vector<int> v = { 2,2,0,0,2,0,0,1,0,0,2,2 };
		//static int n = -1;

		double val = (double)std::rand() / RAND_MAX;

		size_t lvl = 0;
		double deg = 1;

		for (size_t i = 0; i < max_lvl; i++, deg *= 0.5) {
			if (val <= deg) lvl = i;
			else break;
		}

		//std::cout << "LVL: " << lvl << std::endl;
		//n++;
		//return v[n];

		return lvl;
	}

	bool is_null(Node* node) const {
		for (auto i : node->next)
			if (i) return false;

		return true;
	}
};
