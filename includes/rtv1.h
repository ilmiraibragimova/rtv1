
#ifndef RTV1_RTV1_H
#define RTV1_RTV1_H

#include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "libft.h"
# include "vec_op.h"
# include <SDL2/SDL.h>
# include <math.h>


#define  WIDTH  800 // ширина окна
#define  HEIGHT 800
#define V_W  40
#define V_H  40


typedef struct s_obj
{
	double radius;
	t_vec center;
	t_vec end;
	double color[3];
	double specular;
	char *name;
	double t;
}               t_obj;

typedef struct s_cam
{
	t_vec beg;
	t_vec angle;
}				t_cam;

typedef struct s_light {
	char *type;
	double intensity;
	t_vec position;
	t_vec direction;
	struct s_light *next;
} t_light;

typedef struct s_rt
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int x;
	int y;
	int d;
	t_cam cam;
	t_obj *obj;
	t_light *light;
	int count;
	int clos;
	int s;
	double shadow_t;
	double closest_t;
	int amount_obj;
}				t_rt;

void ft_render(t_rt *r);
void ft_light(char **box, t_rt *r);
void parse1(char **box, t_rt *r);
void ft_cam(char **box, t_rt *r);
void ft_parser( char *arg, t_rt *r);
void ft_sphere(char **box, t_rt *r);
double *ft_lighting1(t_rt *r, t_vec vew);
void ft_count_obj(t_rt *r, char *arg);
void ft_traceray1(t_rt *r, t_vec vew,t_vec l, double t_min, int t_max);
void	ft_plane(t_rt *r, char **box);
double	ft_ray_plane(t_vec vew, t_vec cam, t_obj obj);
t_vec ft_norm_sphere(t_vec p, t_rt *r);
double ray_sphere(t_vec vew,t_vec cam, t_obj obj);
t_vec ft_norm_plane(t_vec vew, t_vec p, t_rt *r);
double ft_get_t(double k1, double k2, double k3);
double ft_ray_con(t_vec o, t_vec dir, t_obj *obj);
t_vec ft_norm_con(t_vec vew, t_vec p, t_rt *r);
void ft_con(t_rt *r, char **box);
void ft_cylinder(t_rt *r, char **box);
t_vec ft_norm_cylinder(t_vec vew, t_vec p, t_rt *r);
double	ft_ray_cylinder(t_vec o, t_vec dir, t_obj *obj);
void ft_put_error(char *s);
int ft_valid(char **box);
void ft_clear_box(char **box, int k);
double closest_func(t_rt *r, t_vec vew, double t_min, double t_max, int i);
#endif //RTV1_RTV1_H
