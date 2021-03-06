#
# <Makefile template>
# Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
#
# This file is part of 42-toolkit.
#
# 42-toolkit is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

CFLAGS	+=	-Wextra -Wall -Werror
LDFLAGS	+=
DEBUG	=	-g3 -fno-inline -DD_ERRORS_ON

OBJDIR	=	.objs
LISTDIR	=	src

DIRSRC	=	src

NAME	=	a.out

SRC		=	$(DIRSRC)/main.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.SILENT:

$(addprefix $(OBJDIR)/, %.o)	:	%.c
								$(CC) $(CFLAGS) -o $@ -c $<
								printf '\033[0;32mBuilding C Object $@\n\033[0m' "Building C Object $@"

$(NAME)	:	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
		printf '\033[1;31m%s \033[1;35m%s \033[1;33m%s\n\033[0m' "Linking C executable" "$(NAME)" "$(CC)"

clean	:
		/bin/rm	-fr $(OBJDIR)
		printf '\033[1;34m%s\n\033[0m' "Clean project $(NAME)"

fclean	:	clean
		/bin/rm -fr $(NAME)
		printf '\033[1;34m%s\n\033[0m' "Fclean project $(NAME)"

re		:	fclean all

debug	:	CFLAGS += $(DEBUG)
debug	:	re
		printf '\033[1;31m%s \033[1;35m%s\n\033[0m' "Debug version" "$(DEBUG)"

analyze	:	CFLAGS += --analyze
analyze	:	re

every	:	CFLAGS += -Weverything
every	:	re
		printf '\033[1;33m%s\n\033[0m' "Good job !"

all		:	$(NAME)

$(OBJDIR)	:
		/bin/mkdir $(OBJDIR);			\
		for DIR in $(LISTDIR);			\
		do								\
			/bin/mkdir $(OBJDIR)/$$DIR;	\
		done							\

help	:
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "clean"	"Cleaning all object"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "fclean"	"Cleaning all object and executable"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "debug"	"Add debug flags"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "re"		"Deleting all object and build"
		printf '\n'
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "analyze"	"Analyze code but compile nothing"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "every"	"God code"

.PHONY:	clean fclean re debug analyze every
