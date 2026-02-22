/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:40:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/22 14:41:26 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "random.hpp"

//Give a random number between 0 and 1
float my_random(void) {return static_cast<double>(std::rand()) / RAND_MAX;}