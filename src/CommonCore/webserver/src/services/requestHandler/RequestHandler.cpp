/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:42:04 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:45:40 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Services/RequestHandler.hpp"

RequestHandler::RequestHandler(void)
{

}

RequestHandler::RequestHandler(const RequestHandler& rqh)
{
	
}

RequestHandler::~RequestHandler(void)
{
	
}

RequestHandler&	RequestHandler::operator=(const RequestHandler& rqh)
{
	if (this != &rqh)
	{
		
	}
	return (*this);
}

/*
class RequestHandler
{
	protected:
	
	public:
		RequestHandler(void);
		RequestHandler(const RequestHandler& rqh);
		~RequestHandler(void);
		RequestHandler&	operator=(const RequestHandler& rqh);
};
*/
