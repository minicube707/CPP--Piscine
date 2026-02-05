/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 17:13:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << i->getType() << "\n";
    i->makeSound();
    
    std::cout << j->getType() << "\n";
    j->makeSound();
    
    delete j;//should not create a leak
    delete i;
    
    ///MY TEST
    std::cout << "\n";
    const Animal* c = new Cat();
    c->haveAnIdea("I am dead and alive in the same time", 0);
    std::cout << c->tellAnIdea(0) << "\n";
    
    c->haveAnIdea("Garfield like eat lasagne and pizza", 42);
    c->haveAnIdea("I think I gonna help Tom to hunt Jerry", 37);
    c->haveAnIdea("One day I dream being in space leaving a rainbow trail", 3);
    c->haveAnIdea("I have no Idea want I look like if a wear a hat, boot and foil", 51);
    c->haveAnIdea("Last Idea", 99);
    c->haveAnIdea("Idea Overflow", 100);

    c->printIdea();
    
    //Create a new instance Cat.
    //*static_cast<const Cat*>(c): Transform the c pointer (Animal*) in Cat*
    const Animal* deepcopy = new Cat(*static_cast<const Cat*>(c));
    delete c;
    
    std::cout << "\nDeepCopy\n\n";
    
    deepcopy->printIdea();
    delete deepcopy;
    
    //const Animal animal;
    //const Cat cat;
    //const Dog dog;
    return 0;
}