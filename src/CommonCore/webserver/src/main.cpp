/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:58:50 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:04:49 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "WebServer.hpp"

int	main(int argc, char **argv)
{
	WebServer ws;
	
	(void)argc;
	(void)argv;

	ws.start();
//	ws.run();
	ws.stop();
	return (EXIT_SUCCESS);
}