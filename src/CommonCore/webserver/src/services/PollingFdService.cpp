/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PollingFdService.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:51:02 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/18 20:36:08 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>

#include "Services/PollingFdService.hpp"
#include "fds.h"

/*
class PollingFdService
{
	protected:
		unsigned int	_size;
		unsigned int	_max_size;
		short			_events_template;
		struct pollfd*	_fds;

		void				closeAllFds(void);
		void				defragFds(void);

	public:
		PollingFdService(unsigned int	max_size, short events_template);
		PollingFdService(const PollingFdService& ps);
		~PollingFdService(void);
		PollingFdService&	operator=(const PollingFdService& ps);
		void				addFd(int fd);
		int					getSize(void) const;
		struct pollfd		getFd(unsigned int i) const;
		void				removeFd(unsigned int i) const;
	private:
		PollingFdService(void);

};

*/


PollingFdService::PollingFdService(void) : 	
		_max_size(0), _size(0), _fds(NULL), _events_template(0)
{
	
}

PollingFdService::PollingFdService(unsigned int max_size, short events_template) :  
		_max_size(max_size), _size(0), _events_template(events_template)
{
	int i;
	
	if (this->_max_size <= 0)
	{
		//throw Exception...
	}
	this->_fds = new struct pollfd [this->_max_size];
	if (this->_fds == NULL)
	{
		//throw Exception...
	}
	for (i = 0;i < this->_max_size; i++)
	{
		this->addFd(FD_NONE);
	}
}

PollingFdService::PollingFdService(const PollingFdService& ps)
{
	int i;
	
	closeAllFds();
	this->_max_size = ps._max_size;
	this->_events_template = ps._events_template;
	this->_fds = new struct pollfd [this->_max_size];
	if (this->_fds == NULL)
	{
		//throw Exception...
	}
	for (i = 0;i < this->_max_size; i++)
	{
		this->_fds[i].fd = ps._fds[i].fd;
		this->_fds[i].events = this->_events_template;
		this->_fds[i].revents = 0;
	}
}

PollingFdService::~PollingFdService(void)
{
	if (this->_fds != NULL)
	{
		closeAllFds();
		delete [] this->_fds;
	}
}

void	PollingFdService::closeAllFds(void)
{
	int	i;

	if (this->_fds != NULL)
	{
		for (i = 0; i < this->_max_size; i++)
		{
			if (this->_fds[i].fd > 0)
				close(this->_fds[i].fd);
		}
	}
}

void	PollingFdService::addFd(int fd)
{
	if (this->_fds == NULL)
	{
		//throw exception
	}
	else
	{
		if(this->_size + 1 < this->_max_size)
		{
			this->_fds[this->_size].fd = fd;
			this->_fds[this->_size].events = this->_events_template;
			this->_fds[this->_size].revents = 0;
			this->_size++;
		}
		else
		{
				//throw exception
		}
	}
}

int				PollingFdService::getSize(void) const
{
	return (this->_size);
}

struct pollfd	PollingFdService::getFd(unsigned int i) const
{
	if (i >= this->_size)
	{
		//throw exception
	}
	return (this->_fds[i]);
}

PollingFdService&	PollingFdService::operator=(const PollingFdService& ps)
{
	int i;
	
	if (this != &ps)
	{
		closeAllFds();
		this->_max_size = ps._max_size;
		this->_events_template = ps._events_template;
		this->_fds = new struct pollfd [this->_max_size];
		if (this->_fds == NULL)
		{
			//throw Exception...
		}
		for (i = 0;i < this->_max_size; i++)
		{
			this->_fds[i].fd = ps._fds[i].fd;
			this->_fds[i].events = this->_events_template;
			this->_fds[i].revents = 0;
		}
	}	
}

void				PollingFdService::removeFd(unsigned int i)
{

	if ( this->_size == 0)
		return ;
	if (i >= this->_size)
	{
		//throw exception.
	}
	this->_fds[i].fd = FD_NONE;
	this->_fds[i].revents = 0;
	this->_fds[i].events = 0;
	this->defragFds();
}

void				PollingFdService::defragFds(void)
{
	int	i;
	int	j;

	for (i = 0; i < this->_size; i++)
	{
		if (this->_fds[i].fd == FD_NONE)
		{
			for(j = i; j < this->_size - 1; j++)
			{
				this->_fds[j].fd = this->_fds[j + 1].fd;
				this->_fds[j].events = this->_fds[j + 1].events;
				this->_fds[j].revents = this->_fds[j + 1].revents;
			}
			i--;
			this->_size--;
		}
	 }

}
