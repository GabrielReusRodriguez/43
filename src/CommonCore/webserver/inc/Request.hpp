/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:51:54 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/06 14:49:02 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <string>

class Request
{
	protected:
		int				_fd_out;
		unsigned int	http_code;
		std::string		raw_req;

	public:
		Request();
		Request(const Request &request);
		~Request();
		
		void			operator=(const Request &request);
		int				&getFdOut(void) const;
		void			setFdOut(const int &fd_out);
};

#endif