#pragma once
#include <iostream>
#include <string>

class Pet
{
public:
	virtual ~Pet()
	{}
	virtual void Poke() const = 0;
	virtual std::string GetType() const = 0;
protected:
	Pet(std::string name)
		:
		name(name)
	{}
private:
	std::string name;
};

class Dog : public Pet
{
public:
	Dog()
		:
		Pet("doggie")
	{}
	~Dog() override = default;
	virtual void Poke() const override
	{
		std::cout << "Woof\n";
	}
	virtual std::string GetType() const override
	{
		return type;
	}
private:
	std::string type = "dogs";
};

class Cat : public Pet
{
public:
	Cat()
		:
		Pet("kitty")
	{}
	~Cat() override = default;
	virtual void Poke() const override
	{
		std::cout << "Miauw\n";
	}
	virtual std::string GetType() const override
	{
		return type;
	}
private:
	std::string type = "cats";
};