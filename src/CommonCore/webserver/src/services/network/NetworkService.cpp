/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkService.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:26:12 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/18 19:39:38 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <poll.h>


#include "Services/NetworkService.hpp"
#include "Exceptions/NetWorkException.hpp"
#include "Debugger/Debugger.hpp"

NetworkService::NetworkService(void)
{
	this->fd_server_socket = SOCKET_NONE;
	this->running = false;
}

NetworkService::NetworkService(const NetworkService &net)
{
	this->fd_server_socket = net.fd_server_socket;
	this->addr = net.addr;
	this->running = net.running;
}

NetworkService::~NetworkService(void)
{
	this->stop();
}

NetworkService &	NetworkService::operator=(const NetworkService &net)
{
	if (this != &net)
	{
		this->stop();
		this->fd_server_socket = net.fd_server_socket;
		this->addr = net.addr;
		this->running = net.running;
	}
	return (*this);
}

void	NetworkService::start(void) 
{
	this->fd_server_socket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (this->fd_server_socket < 0)
	//	throw NetworkException("Error creando el socket del servidor.");
		throw NetworkException(errno);
	this->configure_socket();
	this->bind_socket_to_port();
	this->listen_call();
	Debugger::debug("POST listen call");
	this->running = true;
	this->run();
/*
	try
	{
		this->bind_socket_to_port();
	}
	catch(NetworkException& e)
	{
		std::cerr << e.what() << '\n';
		throw e;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw e;
	}
*/	
	
}

void NetworkService::stop(void)
{
	if (this->fd_server_socket >= 0)
	{
		close (this->fd_server_socket);
	}
}

void	NetworkService::configure_socket(void)
{
	int true_var;

	//Ponemos el addr todo a 0 para evitar "basura".
	memset(&this->addr, 0 , sizeof(this->addr));
	this->addr.sin_family = AF_INET;
	this->addr.sin_addr.s_addr = INADDR_ANY;
	this->addr.sin_port = htons(SERVER_PORT);

	//Lo configuramos con sockopt
	true_var = 1;
	if ( setsockopt(this->fd_server_socket, SOL_SOCKET, SO_REUSEADDR, &true_var, sizeof(true_var)) < 0 )
	{
		throw NetworkException(errno);
	}
	/*
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
	*/

	//Establecemos el non blocking...
/*	
	if ( fcntl(this->fd_server_socket, FIONBIO, &true_var) < 0)
	{
		throw NetworkException(errno);
	}
	*/
	/*
	rc = ioctl(listen_sd, FIONBIO, (char *)&on);
  	if (rc < 0)
  	{
    	perror("ioctl() failed");
    	close(listen_sd);
    	exit(-1);
  	}
	*/
}

void	NetworkService::bind_socket_to_port(void)
{
	if (bind(
			this->fd_server_socket, 
			(struct sockaddr *)&this->addr, 
			sizeof(this->addr)
			) < 0)
	{
		throw NetworkException(errno);
	}
}

void	NetworkService::listen_call(void)
{
	if (listen(this->fd_server_socket, SERVER_MAX_CONN) < 0)
	{
		throw NetworkException(errno);
	}
}

bool	NetworkService::isRunning(void) const
{
	return (this->running);
}

#include <stdio.h>

void	NetworkService::run(void)
{
	struct pollfd	fds[SERVER_MAX_NUM_FD];
	nfds_t			nfds;
	int				poll_return;
	int				i;

	fds[0].fd = this->fd_server_socket;
	fds[0].events = POLLIN;
	nfds = 1;
	while (this->running)
	{
		//Poll retorna el numero de elemenos que el revent se ha seteado a NO zero. ( indica un evento o error)
		//Debugger::debug("PRE Poll");
		poll_return = poll(fds, nfds, SERVER_POLL_TIMEOUT);
		//Debugger::debug("POST Poll");
		if (poll_return < 0)
		{
			close (this->fd_server_socket);
			this->running = false;
			throw NetworkException(errno);
		}
		if (poll_return == 0)
		{
			//timeout
			this->running = false;
			std::cerr << "TIMEOUT wainting for socket to read..." << std::endl;
			continue;
		}
//		Debugger::debug("Pre for poll");
		//Tenemos que buscar todos los fds que han hecho saltar el poll...
		for (i = 0; i < poll_return; i++)
		{
			//Si revent está a 0 es que no ha hecho saltar un evento o error, seguimos el loop.
			if (fds[i].revents == 0)
				continue;
			//Si hay un evento (revenst != 0 ) pero no es pollin es que se ha registrado un evento NO esperado asi que error.
			if (fds[i].revents != POLLIN)
			{
				this->running = false;
				close (this->fd_server_socket);
				throw NetworkException("Error at Polling, we received an un expected event.");				
			}
			/*
				Hemos descartado errores y fds que no saltaban el evento POLLIN, 
				en caso que sea el socket del servidor que escucha conexiones es que tenemos nuevas conexiones para aceptar
				Si no, es que una conexion YA ESTABLECIDA nos ha enviado datos y queremos leerlos */
			if (fds[i].fd == this->fd_server_socket)
			{
				//Aceptamos todas las conexiones que tiene en cola...
				int	new_fd;
				new_fd = 5;
				while (new_fd != -1)
				{
//					Debugger::debug("Pre accept");
					new_fd = accept(this->fd_server_socket, NULL, NULL);
//					Debugger::debug("Post accept");
					//Check de errores...
					if (new_fd < 0)
					{
						/*
						Hemos configurado el servidor como no bloqueante, por lo que si nos aparece un error diferente de tipo
						EWOULDBLOCK (cuando entra y no tiene que leer),  entonces es que ha habido un error.
						*/
						if (errno != EWOULDBLOCK)
						{
							Debugger::debug("ERROR");
							printf("ERRNO: %d\n", errno);
							close (this->fd_server_socket);
							this->running = false;
							throw NetworkException(errno);
						}
					}
					else
					{
						printf("Scoket: %d\n", new_fd);
					}
					//Añadimos el nuevo fd a la poll...
//					fds[nfds].fd = new_fd;
//					fds[nfds].events = POLLIN;
//					nfds++;
					/*
					Debugger::debug("Pre accept");
					new_fd = accept(this->fd_server_socket, NULL, NULL);
					Debugger::debug("Post accept");
					//Check de errores...
					if (new_fd < 0)
					{
						Debugger::debug("ERROR");
						printf("ERRNO: %d\n", errno);
						close (this->fd_server_socket);
						this->running = false;
						throw NetworkException(errno);
					}
					//Añadimos el nuevo fd a la poll...
					fds[nfds].fd = new_fd;
					fds[nfds].events = POLLIN;
					nfds++;
					*/
				}
				//Añadimos el nuevo fd a la poll...
				fds[nfds].fd = new_fd;
				fds[nfds].events = POLLIN;
				nfds++;
			}
			else
			{
				/*
					Tenemos una conexion previamente abierta que nos ha enviado datos y tenemos que leerlos 
					Para luego procesar la peticion.
				*/
			}
		}
	}
	Debugger::debug("Post run");	
}


/*
	protected:
		int					fd_server_socket;
		struct sockaddr_in 	addr;
//		bool				run;

	public:
		NetworkService(void);
		NetworkService(const NetworkService &net);
		~NetworkService(void);

		NetworkService &	operator=(const NetworkService &net);

//		bool	isRun(void) const;
		void	start(void);
		void	stop(void);

		*/