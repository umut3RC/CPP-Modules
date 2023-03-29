/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:04:45 by uercan            #+#    #+#             */
/*   Updated: 2023/03/23 17:28:49 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	std::string	input;
	Harl		harl;
	while (1)
	{
		std::cin >> input;
		if (!harl.to_compare(input))
			std::cout << "Invalid level!" << std::endl;
	}
	return (0);
}