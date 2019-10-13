# CatsDogsPoly
Experimenting with inheritance/polymorphism

Class architecture:
Household class holds a vector of pointers to Pet (abstract base class)
Dog and Cat are derived classes of Pet

Notes:
Uses <algorithm> to manipulate std::vector<Pet*>
std::remove_if()
std::random_shuffle()
