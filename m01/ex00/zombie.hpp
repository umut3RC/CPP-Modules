/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:21:52 by uercan            #+#    #+#             */
/*   Updated: 2023/03/21 15:01:23 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif