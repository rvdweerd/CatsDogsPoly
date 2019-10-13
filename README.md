# CatsDogsPoly
Experimenting with inheritance/polymorphism

Class architecture:

Household class   
   |
   vec of pointers -->  Pet (Abstract class)
                         ^
                         |
                     ----------
                     |        |
                    Dog      Cat (Concrete classes)
                    

Notes
Uses <algorithm> to manipulate std::vector<Pet*>
  std::remove_if()
  std::random_shuffle()
