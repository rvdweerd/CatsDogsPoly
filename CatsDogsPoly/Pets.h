#pragma once
#include <iostream>
#include <string>

class Pet
{
public:
	enum class Species
	{
		cats = 0 ,
		dogs,
		rabbits,
		nTypes
	};
	static std::string SpeciesName(Species spec)
	{
		switch (spec)
		{
		case Species::cats :
			return "cat";
			break;
		case Species::dogs:
			return "dog";
			break;
		case Species::rabbits:
			return "rabbit";
			break;
		}
		return "";
	}
	

public:
	virtual ~Pet()
	{}
	virtual void Poke() const = 0;
	virtual Species GetType() const = 0;
protected:
	Pet(Species type)
		:
		type(type)
	{}
//private:
	Species type;
};

class Dog : public Pet
{
public:
	Dog()
		:
		Pet(Pet::Species::dogs)
	{}
	~Dog() override = default;
	virtual void Poke() const override
	{
		std::cout << "Woof\n";
	}
	virtual Species GetType() const override
	{
		return type;
	}
};

class Cat : public Pet
{
public:
	Cat()
		:
		Pet(Pet::Species::cats)
	{}
	~Cat() override = default;
	virtual void Poke() const override
	{
		std::cout << "Miauw\n";
	}
	virtual Species GetType() const override
	{
		return type;
	}
};

class Rabbit : public Pet
{
public:
	Rabbit()
		:
		Pet(Pet::Species::rabbits)
	{}
	~Rabbit() override = default;
	virtual void Poke() const override
	{
		std::cout << "Jump\n";
	}
	virtual Species GetType() const override
	{
		return type;
	}
};