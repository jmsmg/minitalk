/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:27:13 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/12 17:34:06 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	int		pid;
	char	message;

	if (argc != 3)
		return (1);

	message = argv[2];

}
