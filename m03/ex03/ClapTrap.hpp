/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:10:01 by uercan            #+#    #+#             */
/*   Updated: 2023/05/27 16:53:06 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_attack_damage;
	public:
		ClapTrap( void );
		ClapTrap ( const ClapTrap &src );
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap	&operator=( const ClapTrap &src );
		void	hit_point(int hp);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	energy_points(unsigned int amount);
		
		void	set_name( std::string name );
		void	set_health( int hp );
		void	set_energy( int energy );
		void	set_attack_damage( int AD );
		
		std::string	get_name( void ) const;
		int			get_health( void ) const;
		int			get_energy( void ) const;
		int			get_attack_damage( void ) const;
	
};
#endif