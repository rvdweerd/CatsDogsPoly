#include "Pets.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

class Household
{
public:
	Household()
	{}
	std::vector<Pet*> GetPets() const
	{
		return pets;
	}
	void PokePets() const
	{
		for (Pet* p : pets)
		{
			p->Poke();
		}
		std::cout << "-----------\n";
	}
	void BuyPets(Pet::Species animal, int n)
	{
		for (int i = 0; i < n; i++)
		{
			Pet* pNewPet = nullptr;
			switch (animal)
			{
			case Pet::Species::cats:
				pNewPet = new Cat;
				break;
			case Pet::Species::dogs:
				pNewPet = new Dog;
				break;
			case Pet::Species::rabbits:
				pNewPet = new Rabbit;
				break;
			}
			pets.emplace_back( pNewPet );
		}
		std::cout << "The Simpsons bought " << n << " " << Pet::SpeciesName(animal) << "s.\n";

	}
	void MinglePets()
	{
		if (pets.size() > 0)
		{
			std::cout << "Let them mingle\n";
		}
		else
		{
			std::cout << "No pets left to mingle\n";
		}
		std::random_shuffle(pets.begin(), pets.end());
	}
	void ReleasePets(const Pet::Species animal)
	{
		std::cout << "Let the "<<Pet::SpeciesName(animal)<<"s loose\n";
		auto endIt = std::remove_if(pets.begin(), pets.end(), [&animal](Pet* p)->bool
			{
				Pet::Species animalType = p->GetType();
				if (animalType == animal)
				{
					std::cout << "one " << Pet::SpeciesName(animal) << " ran off\n";
					delete p;
					p = nullptr;
				}

				return (animalType == animal);
			});
		pets.erase(endIt, pets.end());
		std::cout << "all " << Pet::SpeciesName(animal) << "s ran\n";
		std::cout << "-----------\n";
	}
private:
	std::vector<Pet*> pets = {};
};

int main()
{
	Household TheSimpsons;
	TheSimpsons.BuyPets(Pet::Species::cats, 5);
	TheSimpsons.BuyPets(Pet::Species::dogs, 3);
	TheSimpsons.BuyPets(Pet::Species::rabbits, 2);

	TheSimpsons.MinglePets();
	TheSimpsons.PokePets();
	
	TheSimpsons.ReleasePets(Pet::Species::cats);
	TheSimpsons.MinglePets();
	TheSimpsons.PokePets();

	TheSimpsons.ReleasePets(Pet::Species::rabbits);
	TheSimpsons.MinglePets();
	TheSimpsons.PokePets();

	TheSimpsons.ReleasePets(Pet::Species::dogs);
	TheSimpsons.MinglePets();
	TheSimpsons.PokePets();


	while (!_kbhit());
	return 0;
}