/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:04:45 by uercan            #+#    #+#             */
/*   Updated: 2023/03/25 14:34:16 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	input;
	Harl		harl;

	if (argc != 2)
		std::cout << "Invalid level!" << std::endl;
	else
		harl.to_compare(argv[1]);
	return (0);
}