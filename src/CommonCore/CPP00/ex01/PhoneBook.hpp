/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:01:40 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/24 00:03:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_SIZE_CONTACTS 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		add(void);
		void		search(void);
	private:
		Contact 	contacts[8];
		size_t  	total;
		std::string	format_string(std::string unformated);
		void		print_contact_resume(void);
		void		print_contact(size_t index);
};


#endif