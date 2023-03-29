/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:15:10 by uercan            #+#    #+#             */
/*   Updated: 2023/03/28 20:58:48 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap ended" << std::endl;
}

ClapTrap::ClapTrap()
{
	this->_health = 0;
	std::cout << "ClapTrap start" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " named " << std::endl;
}

void	ClapTrap::hit_point(int hp)
{
	this->_health = hp;

	std::cout << "ClapTrap "
	<< this->_name 
	<< " takeDamage "
	<< hp
	<< std::endl;
}

void	ClapTrap::attack(const std::string& target)//ClapTrap <name> attacks <target>, causing <damage> points of damage!
{
	std::cout << "ClapTrap " 
	<< this->_name 
	<< " attacks "
	<< target 
	<< ", causing "
	<< this->_attack_damage
	<< " points of damage!" 
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_health -= amount;
	std::cout << "ClapTrap " 
	<< this->_name 
	<< " takeDamage "
	<< amount
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_health += amount;
	this->_health -= amount;
	std::cout << "ClapTrap " 
	<< this->_name 
	<< " beRepaired "
	<< amount
	<< std::endl;
}
