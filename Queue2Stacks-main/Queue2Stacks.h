#pragma once
#include <stack>

template <class T> 
class Queue2Stacks {
	std::stack<T> stack1, stack2;

public:
	Queue2Stacks() = default;
	Queue2Stacks(const Queue2Stacks& queue) {
		stack1 = queue.stack1;
		stack2 = queue.stack2;
	}
	int size() noexcept {
		return stack1.size() + stack2.size();
	}
	bool empty() noexcept {
		return (stack1.size() + stack2.size()) == 0;
	}
	void push(const T& elem) {
		stack1.push(elem);
	}
	void pop() {
		if (stack1.size() + stack2.size() == 0) {
			throw std::logic_error("queue is empty");
		}
		else {
			if (stack2.size() == 0) {
				while (!stack1.empty()) {
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			stack2.pop();
		}
	}
	T front() {
		if (stack1.size() + stack2.size() == 0) {
			throw std::logic_error("queue is empty");
			return T();
		}
		else {
			if (stack2.size() == 0) {
				while (!stack1.empty()) {
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			return stack2.top();
		}

	}
	T back() {
		if (stack1.size() + stack2.size() == 0) {
			throw std::logic_error("queue is empty");
			return T();
		}
		else {
			if (stack1.size() == 0) {
				while (!stack2.empty()) {
					stack1.push(stack2.top());
					stack2.pop();
				}
			}
			return stack1.top();
		}
	}

};