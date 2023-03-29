/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:31:09 by uercan            #+#    #+#             */
/*   Updated: 2023/03/21 16:34:21 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie [N];
	for(int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		zombies[i].announce();
	}
	return (zombies);
}

int	main ()
{

	Zombie *zombies;

	zombies = Zombie::zombieHorde(5, "VaaDAAAAA");

	delete [] zombies;
	return (0);
}
