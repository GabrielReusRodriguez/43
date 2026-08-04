/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:36:42 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:39:51 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUESTHANDLER_HPP
# define REQUESTHANDLER_HPP

class RequestHandler
{
	protected:
	
	public:
		RequestHandler(void);
		RequestHandler(const RequestHandler& rqh);
		~RequestHandler(void);
		RequestHandler&	operator=(const RequestHandler& rqh);
};

#endif