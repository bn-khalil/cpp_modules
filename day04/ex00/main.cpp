#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    cat->makeSound();
    cat->makeSound();
    meta->makeSound();
    dog->makeSound();
    dog->makeSound();

    const Animal* s = cat;
    s->makeSound();
    s = dog;
    s->makeSound();

    std::cout << std::endl;

    const WrongAnimal* beta = new WrongCat();
    beta->makeSound();

    delete beta;
    return 0;
}