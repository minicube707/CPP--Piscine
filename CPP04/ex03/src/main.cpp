/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/09 15:46:24 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    return 0;
}

/*
int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure()); // doit etre rejete car + de 4
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("water"); // inexistant
	me->equip(tmp); // doit ne rien equiper

	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp); // + de 4 slots
	
	me->unequip(3); // enleve cure
	me->unequip(3); // slot vide -> ok
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure
	me->use(3, *bob); // slot vide -> rien
	
	ICharacter* patrick = new Character( *(Character*)me );
	
	tmp = src->createMateria("cure");
	patrick->unequip(0); // enlever ice
	patrick->equip(tmp); // ajouter cure
	patrick->use(0, *bob); // doit afficher cure au lieu de ice

	Character assignTest("assign");
	assignTest = *(Character*)patrick;
	assignTest.use(0, *bob);
	
	delete bob;
	delete me;
	delete src;
	delete patrick;

	return 0;
}*/