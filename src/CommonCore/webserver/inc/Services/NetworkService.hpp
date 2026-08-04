/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkService.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:17:36 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/18 19:40:54 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKSERVICE_HPP
# define NETWORKSERVICE_HPP

# include <sys/socket.h>
# include <arpa/inet.h>

# define SOCKET_NONE		-1

# define SERVER_PORT		2202
# define SERVER_MAX_CONN	10

# define SERVER_POLL_TIMEOUT	-1
# define SERVER_MAX_NUM_FD		200
class NetworkService
{
	protected:
		int					fd_server_socket;
		struct sockaddr_in 	addr;
		bool				running;

		void	configure_socket(void);
		void	bind_socket_to_port(void);	
		void	listen_call(void);
		void	run(void);

	public:
		NetworkService(void);
		NetworkService(const NetworkService &net);
		~NetworkService(void);

		NetworkService &	operator=(const NetworkService &net);

		bool	isRunning(void) const;
		void	start(void);
		void	stop(void);

	private:
		void	poll_push_fd(int *poll_fds, int new_fd, int *nfds);	
};

#endif