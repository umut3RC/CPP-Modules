/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:10:01 by uercan            #+#    #+#             */
/*   Updated: 2023/03/28 20:52:38 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ClapTrap
{
	private:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_attack_damage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		void	hit_point(int hp);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
};
