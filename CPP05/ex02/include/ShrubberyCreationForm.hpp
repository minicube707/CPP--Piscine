/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:31 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/19 15:45:27 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

#define ASCII_TREE \
"                                              .\n"\
"                                              .         ;\n"\
"                 .              .              ;%     ;;\n"\
"                   ,           ,                :;%  %;\n"\
"                    :         ;                   :;%;'     .,\n"\
"           ,.        %;     %;            ;        %;'    ,;\n"\
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"\
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"\
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"\
"                `%;.     ;%;     %;'         `;%%;.%;'\n"\
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"\
"                    `:%;.  :;bd%;          %;@%;'\n"\
"                      `@%:.  :;%.         ;@@%;'\n"\
"                        `@%.  `;@%.      ;@@%;\n"\
"                          `@%%. `@%%    ;@@%;\n"\
"                            ;@%. :@%%  %@@%;\n"\
"                              %@bd%%%bd%%:;\n"\
"                                #@%%%%%:;;\n"\
"                                %@@%%%::;\n"\
"                                %@@@%(o);  . '\n"\
"                                %@@@o%;:(.,'\n"\
"                            `.. %@@@o%::;\n"\
"                               `)@@@o%::;\n"\
"                                %@@(o)::;\n"\
"                               .%@@@@%::;\n"\
"                               ;%@@@@%::;.\n"\
"                              ;%@@@@%%:;;;\n"\
"                          ...;%@@@@@%%:;;;;,..    Gilo97\n"

class ShrubberyCreationForm: public AForm
{
    private:
        //Const to initialize the value of the grades
        static const int _const_grade_sign = 145;
        static const int _const_grade_exec = 137;
        
        //Variable
        std::string _target;
                
    public:
        //Constructor
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other); 
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        /*------METHODE------*/
        void execute(Bureaucrat const & executor) const;
};


