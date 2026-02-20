/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:18:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 18:57:29 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

class Data
{
    private:
        std::string _string;
        int _i;
        float _f;
        double _d;
        
    public:
        Data();
        Data(std::string string, int i, float f, double d);
        ~Data();
        Data(const Data &other);
        Data operator=(const Data &other);

        /*--GETTER--*/
        std::string get_string(void) const;
        int get_int(void) const;
        float get_float(void) const;
        double get_double(void) const;
};

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Data& obj);
