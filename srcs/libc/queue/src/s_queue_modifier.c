/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_queue_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/30 13:28:54 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:44:02 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_queue function>
** < push, pop >
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

#include <queue/s_queue.h>
#include <f_secure/f_secure.h>
#include <f_error/m_error.h>

static t_queue_cell	*f_queue_create_cell(void *data)
{
	t_queue_cell	*cell;

	if ((cell = uf_malloc_s(1, sizeof(*cell))) != NULL)
	{
		cell->v_data = data;
		cell->v_next = NULL;
	}
	return (cell);
}

bool				f_queue_push(t_queue *v_this, void *data)
{
	t_queue_cell	*push;

	push = D_QUEUE(create_cell)(data);
	if (push == NULL)
		return (M_ERROR(false, "Bad alloc"));
	if (v_this->v_head == NULL)
		v_this->v_head = push;
	if (v_this->v_tail != NULL)
		v_this->v_tail->v_next = push;
	v_this->v_tail = push;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

void				*f_queue_pop(t_queue *v_this)
{
	t_queue_cell	*del;
	void			*data;

	if (v_this->v_head != NULL)
	{
		del = v_this->v_head;
		data = del->v_data;
		v_this->v_head = del->v_next;
		v_this->v_size = v_this->v_size - 1;
		if (v_this->v_size == 0)
			v_this->v_tail = NULL;
		uf_free_s((void **)&del);
		return (data);
	}
	return (NULL);
}
