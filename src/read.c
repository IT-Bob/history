/**
**	\file	read.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Lecture du fichier d'historique
*/

#include "history.h"

/**
**	\brief	Lecture du fichier d'historique
**
**	La fonction lit le fichier d'historique du fichier donné en paramètre
**	et retourne une liste créée à partir de celui-ci.
**	Chaque maillon de la liste contient une ligne de commande.
**
**	\param	path	- chemin d'accès au fichier
**	\param	history	- historique déjà existant (ou `NULL`)
**
**	\return	**liste** contenant l'historique des commandes ou **NULL** en cas
**			d'erreur.
*/

t_lstag	*read_history(char *path, t_lstag *history)
{
	int		fd;
	char	*line;
	t_lstag	*h;

	fd = open_history(path);
	h = history;
	line = NULL;
	if (fd >= 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			h = add_history_lst(h, line);
			if (line)
				ft_strdel(&line);
		}
		close(fd);
	}
	return (h);
}
