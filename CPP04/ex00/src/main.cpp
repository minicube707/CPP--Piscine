/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 13:41:45 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
    std::cout << "\nRight Animal\n\n";
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
	delete j;
	delete meta;
    
    
    ////////////////////////////////////////////////////
    std::cout << "\nWrong Animal\n\n";
    
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    
    std::cout << wi->getType() << " " << std::endl;
    
    wi->makeSound(); //will output the cat sound!
    wmeta->makeSound();

    delete wi;
	delete wmeta;
    
    return 0;
}