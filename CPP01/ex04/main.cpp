/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:08:56 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/13 18:05:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of argument!" << std::endl;
        return (1);
    }
    
    char *filename = argv[1];
    std::string target = argv[2];
    std::string replace = argv[3];
    size_t len_target = target.length();
    
    //Reading
    std::ifstream f(filename);
    if (!f.is_open())
    {
        std::cout << "Error: can't open " << filename << std::endl;
        return (1);
    }
    
    if (target == "")
    {
        std::cout << "Error: can't manage EOF for target" << std::endl;
        return (1); 
    }
    
    /*Copy into tmp*/
    std::string line;
    std::string tmp;
    while (std::getline(f, line))
    {
        if (!f.eof())
            line.append("\n");
        tmp.append(line);
    }
    f.close();

    /*Replace*/
    size_t index;
    while (true)
    {   
        index = tmp.find(target);
        if (index == std::string::npos)
            break;
        
        tmp.erase(index, len_target);
        tmp.insert(index, replace);
    }  

    /*Edit filename output*/
    std::string filename_repalce = filename;
    filename_repalce.append(".replace");
    
    //Writting
    std::ofstream w(filename_repalce.c_str());
    if (w.is_open())
        w << tmp;
    w.close();
    return (0);
}