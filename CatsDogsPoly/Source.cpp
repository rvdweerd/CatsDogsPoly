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
	void BuyCats(int n)
	{
		for (int i = 0; i < n; i++)
		{
			pets.emplace_back(new Cat());
		}
	}
	void BuyDogs(int n)
	{
		for (int i = 0; i < n; i++)
		{
			pets.emplace_back(new Dog);
		}
	}
	void MinglePets()
	{
		std::cout << "Let them mingle\n";
		std::random_shuffle(pets.begin(), pets.end());
	}
	void ReleaseAllCats()
	{
		std::cout << "Let the cats loose\n";
		auto endIt = std::remove_if(pets.begin(), pets.end(), [](Pet* p)->bool 
			{
				std::string type = p->GetType();
				if ( type == "cats")
				{
					std::cout << "one cat ran off\n";
					delete p;
					p = nullptr;
				}
				
				return (type == "cats"); 
			});
		pets.erase( endIt , pets.end());
		std::cout << "all cats ran\n";
		std::cout << "-----------\n";
	}
	void ReleaseAllDogs()
	{
		std::cout << "Let the dogs loose\n";
		auto endIt = std::remove_if(pets.begin(), pets.end(), [](Pet* p)->bool
			{
				std::string type = p->GetType();
				if (type == "dogs")
				{
					std::cout << "one dog ran off\n";
					delete p;
					p = nullptr;
				}

				return (type == "dogs");
			});
		pets.erase(endIt, pets.end());
		std::cout << "all dogs ran\n";
		std::cout << "-----------\n";
	} 
	void Release(const std::string animal)
	{
		std::cout << "Let the "<<animal<<"s loose\n";
		auto endIt = std::remove_if(pets.begin(), pets.end(), [&animal](Pet* p)->bool
			{
				std::string animalType = p->GetType();
				if (animalType == animal)
				{
					std::cout << "one dog ran off\n";
					delete p;
					p = nullptr;
				}

				return (animalType == animal);
			});
		pets.erase(endIt, pets.end());
		std::cout << "all " << animal << "s ran\n";
		std::cout << "-----------\n";
	}
private:
	std::vector<Pet*> pets = {};
};

int main()
{
	Household TheSimpsons;
	TheSimpsons.BuyCats(3);
	TheSimpsons.BuyDogs(4);
	
	TheSimpsons.PokePets();
	TheSimpsons.MinglePets();
	TheSimpsons.PokePets();
	
	//TheSimpsons.Release("dogs");
	TheSimpsons.ReleaseAllCats();
	//TheSimpsons.ReleaseAllDogs();
	TheSimpsons.PokePets();
	
	while (!_kbhit());
	return 0;
}