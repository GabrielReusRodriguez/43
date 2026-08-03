/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:20:27 by gabriel           #+#    #+#             */
/*   Updated: 2024/06/28 13:22:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public: 
		Contact(void);
		Contact(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret);
		~Contact(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_darkest_secret(void);
		std::string	get_phone_number(void);
		void		set_first_name(std::string _first_name);
		void		set_last_name(std::string _last_name);
		void		set_nickname(std::string _nickname);
		void		set_darkest_secret(std::string _darkest_secret);
		void		set_phone_number(std::string _phone_number);
	private: 
		std::string	first_name;
        std::string last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif