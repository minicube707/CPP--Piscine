/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:12:36 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/22 14:41:04 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <ctime>
# include <iostream>

# define RAND_MAX 2147483647    //Max Int

//Give a random number between 0 and 1
float my_random(void);