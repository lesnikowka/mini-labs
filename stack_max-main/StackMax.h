#pragma once
#include <stack>

template <class T>
class StackMax {
	std::stack<T> stack, stack_max;
public:
	StackMax() = default;

	StackMax(const StackMax<T>& st) : stack(st.stack), stack_max(st.stack_max) {}

	StackMax<T>& operator=(const StackMax<T>& st) {
		stack = st.stack;
		stack_max = st.stack_max;
		return *this;
	}

	int size() {
		return stack.size();
	}

	void push(const T& elem) {
		if (stack.size() == 0 || stack_max.top() <= elem) stack_max.push(elem);
		stack.push(elem);
	}

	void pop() {
		if (stack.size() == 0) throw std::logic_error("stack is empty");

		else {
			if (stack.top() == stack_max.top()) stack_max.pop();
			stack.pop();
		}
	}

	T top() {
		if (stack.size() == 0) {
			throw std::logic_error("stack if empty");
			return T();
		}
		return stack.top();
	}

	T max() {
		if (stack.size() == 0) { 
			throw std::logic_error("stack is empty");
			return T();
		}
		return stack_max.top();
	}
};