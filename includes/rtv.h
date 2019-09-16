/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:51:51 by mmasyush          #+#    #+#             */
/*   Updated: 2019/09/16 13:12:26 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H

# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
#ifdef __APPLE__
# include "../frameworks/SDL2.framework/Headers/SDL.h"
#else
# include <SDL.h>
#endif

# define WIN_W 1280
# define WIN_H 720
# define D 1
# define FOW 60
# define PI 3.14159265
# define FOW_RAD FOW * PI / 180
# define T_MIN 0
# define T_MAX 2147483647 // int max

typedef struct s_sdl    t_sdl;
typedef struct s_rtv    t_rtv;
typedef struct s_vector t_vector;
typedef struct s_vector t_map;
typedef struct s_sphere t_sphere;

typedef union u_obj     t_obj;

union   s_obj
{
    
};

struct  s_map
{
   int          obj_num;
};

struct  s_sdl
{
    SDL_Window  *window;
    SDL_Surface *surface;
};

struct  s_vector
{
    double      x;
    double      y;
    double      z;
};

struct s_rtv
{
    t_sdl       sdl;
    t_map       map;
};


/*
**main.c
*/
int             main(int argc, char **argv);
/*
**sdl.c
*/
int				init_sdl(t_sdl  *sdl);
/*
**print.c
*/
int			    error(char *message);
int			    usage(void);
/*
**main.c
*/

/*
**main.c
*/

#endif
