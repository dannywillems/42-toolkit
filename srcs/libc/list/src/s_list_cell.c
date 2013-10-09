/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_cell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:58:01 by qperez            #+#    #+#             */
/*   Updated: 2013/10/09 23:36:41 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_cell method>
** < create >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
**
** This file is part of 42-toolkit.
**
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <s_list_cell.h>
#include <stdlib.h>

t_list_cell			*f_list_cell_create(t_list_cell *prev,
										t_list_cell *next, void *data)
{
	t_list_cell	*cell;

	cell = malloc(sizeof(*cell));
	if (cell != NULL)
	{
		cell->v_next = next;
		cell->v_prev = prev;
		cell->v_data = data;
	}
	return (cell);
}

inline t_list_cell	*f_list_cell_next(const t_list_cell *cur)
{
	return (cur->v_next);
}

inline t_list_cell	*f_list_cell_prev(const t_list_cell *cur)
{
	return (cur->v_prev);
}
