#include <iostream>
#include "Zoo.h"


int main() {
	Zoo zoo = Zoo();

	Sparrow bird1 = Sparrow("Bird1");
	Bird* bird2 = new Chiken("Bird2");

	Cow* cow1 = new Cow("Cow1");
	Cow cow2 = Cow("Cow2");

	zoo.pushBack(&bird1);
	zoo.pushBack(bird2);

	zoo.popBack();

	zoo.pushBack(&cow2);

	std::cout << "Number of birds: " << zoo.numberOfBirds() << std::endl;

	delete bird2;
	delete cow1;

	return 0;
}