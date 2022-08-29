/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:54:11 by mclerico          #+#    #+#             */
/*   Updated: 2022/08/29 12:01:48 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>{
	public:
		virtual ~MutantStack(){};
		MutantStack() : std::stack<T>(){};
		MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj){std::cout << "Copy constructor called" << std::endl;};
		MutantStack &operator=(const MutantStack<T> &obj){
	if (this == obj)
		return *this;
	std::stack<T>::operator=(obj);
	return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin(){ return this->c.begin();}

		iterator	end(){ return this->c.end();}

		const_iterator	begin() const{ return this->c.begin();}

		const_iterator	end() const{ return this->c.end();}

		reverse_iterator	rbegin(){ return this->c.rbegin();}

		reverse_iterator	rend(){ return this->c.rend();}

		const_reverse_iterator	rbegin() const{ return this->c.rbegin();}

		const_reverse_iterator	rend() const{ return this->c.rend();}
};
#endif

