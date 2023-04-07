#include <iostream>
#include <string>
#include <stack>

bool bracketsIsCorrect(const std::string& str) {
	std::stack<char> st;
	std::string brackets_left = "([{";
	std::string brackets_right = ")]}";

	for (char element : str) {
		if (brackets_left.find(element) != -1 || brackets_right.find(element) != -1){
			if (brackets_left.find(element) != -1) 
				st.push(brackets_right[brackets_left.find(element)]);
			else if (!st.empty() && st.top() == element) 
				st.pop();
			else 
				return false;
		}
	}
	return st.empty();
}


int main(int argv, char** argc) {
	if (argv < 2) 
		std::cout << "Too less arguments" << std::endl;
	else 
		for (int i = 1; i < argv; i++) {
			std::cout << std::string(argc[i]) << std::endl;
			if (bracketsIsCorrect(std::string(argc[i]))) std::cout << "Correct" << std::endl;
			else std::cout << "Incorrect" << std::endl;
		}
}