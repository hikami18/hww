#pragma once
#include <iostream>

using namespace std;

class Animal 
{
protected:
	char* name;
	int kg;
public:
	Animal() = default;
	Animal(const char* n, int k)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		kg = k;
	}
	void Print()
	{
		cout << "Name: " << name << "; Weight: kg: " << kg << endl;
	}
	virtual ~Animal()
	{
		delete[]name;
	}

	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;
};

struct IFly
{
	virtual void Fly() = 0;
};

struct ISwim
{
	virtual void Swim() = 0;
};

class Pingwin : public Animal, public ISwim
{
	char* continent;
public:
	Pingwin() = default;
	Pingwin(const char* n, int kg, const char* cont) : Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(continent) + 1, cont);
	}
	virtual void Eat()
	{
		cout << "Penguins eat fish\n";
	}
	virtual void Sound()
	{
		cout << "Penguins make penguin sounds\n";
	}
	virtual void Continent()
	{
		cout << "Penguins live in " << continent << "\n";
	}
	virtual void Swim()
	{
		cout << "Penguins swim great\n";
	}
	~Pingwin()
	{
		delete[]continent;
	}
};

class Parrot : public Animal, public IFly
{
	char* continent;
public:
	Parrot() = default;
	Parrot(const char* n, int kg, const char* cont) : Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(continent) + 1, cont);
	}
	virtual void Eat()
	{
		cout << "Parrots eat grain\n";
	}
	virtual void Sound()
	{
		cout << "Parrots make sounds\n";
	}
	virtual void Continent()
	{
		cout << "Parrots live in " << continent << "\n";
	}
	virtual void Fly()
	{
		cout << "Parrots fly great\n";
	}
	~Parrot()
	{
		delete[] continent;
	}
};

class Airplane : public IFly
{
public:
	void Fly() override
	{
		cout << "Airplanes fly great\n";
	}
};
