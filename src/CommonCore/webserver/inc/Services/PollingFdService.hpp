/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PollingFdService.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:43:50 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/18 20:23:15 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLLINGFDSERVICE_HPP
# define POLLINGFDSERVICE_HPP

# include <poll.h>

# define FD_NONE -1


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
		void				removeFd(unsigned int i);
	private:
		PollingFdService(void);

};

#endif