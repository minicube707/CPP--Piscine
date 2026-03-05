/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:02:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/05 15:47:49 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Wrong number of arguments\n";
        return 0;
    }
    
    BitcoinExchange btc;
    std::string file_content;
    
    //Parsing data.csv
    if (btc.extract_file("data.csv", file_content))
        return 0;
    if (btc.parse_file_content(file_content, ',', btc.get_map_DB()))
        return 0;
    
    //Parsing input.txt
    file_content.clear();
    if (btc.extract_file(argv[1], file_content))
        return 0;
    if (btc.parse_file_content(file_content, '|', btc.get_map_transaction()))
        return 0;
    
    /*
    std::map<std::string, std::string>::iterator it;
    std::map<std::string, std::string> map = btc.get_map_DB();
    
    for (it = map.begin(); it != map.end(); ++it)
        std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    
    std::cout << "\n";
    map = btc.get_map_transaction();
    for (it = map.begin(); it != map.end(); ++it)
        std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    */

    btc.display_exchange_rate();
    return 0;
}