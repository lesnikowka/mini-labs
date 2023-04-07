#pragma once

#include <string>
#include <vector>

class Animal {
public:
	Animal(std::string name) : name_(name), id_(numberOfAnimals++) {}

	std::string getName() { return name_; }

	int getId() { return id_; }

	virtual void voice() = 0;

private:
	std::string name_;
	int id_;
	static int numberOfAnimals;
};
int Animal::numberOfAnimals = 0;



class Mammal : public Animal {
public:
	Mammal(std::string name) : Animal(name) {}
};



class Feathered : public Animal {
public:
	Feathered(std::string name) : Animal(name) {}
};



class Cow : public Mammal {
public:
	Cow(std::string name) : Mammal(name) {}

	void voice() override { std::cout << "Moo" << std::endl; }
};



class Bird : public Feathered {
public:
	Bird(std::string name) : Feathered(name) {}

};



class Sparrow : public Bird {
public:
	Sparrow(std::string name) : Bird(name) {}

	void voice() override { std::cout << "Chi-rik"; }
};



class Chiken : public Bird {
public:
	Chiken(std::string name) : Bird(name) {}

	void voice() override { std::cout << "Ko-ko"; }
};


class Zoo {
public:
	void pushBack(Animal* animal) {
		animals_.push_back(animal);
	}
	void popBack() {
		animals_.pop_back();
	}

	void voice() {
		for (Animal* el : animals_)
			el->voice();
	}

	int numberOfBirds() {
		int count = 0;

		for (Animal* el : animals_)
			if (dynamic_cast<Bird*>(el)) count++;

		return count;
	}

private:
	std::vector<Animal*> animals_;
};
