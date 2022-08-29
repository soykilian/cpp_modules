/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:54:18 by mclerico          #+#    #+#             */
/*   Updated: 2022/08/29 12:07:35 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Current top  of the stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of the stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iteration of the stack:"<< std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	MutantStack<int>::reverse_iterator rev = mstack.rbegin();
	MutantStack<int>::reverse_iterator revend = mstack.rend();
	++rev;
	--rev;
	std::cout << "Reverse iteration of the stack:"<< std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	while (rev !=revend)
	{
		std::cout << *rev << " ";
		++rev;
	}
	std::cout << std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	std::stack<int> s(mstack);
	return 0;
}
