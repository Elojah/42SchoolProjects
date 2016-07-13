#include "scop.h"
#include <math.h>

static void	init_projection(t_camera *cam)
{
	float			depth;
	short			i;
	short			j;

	i = -1;
	depth = 1.0f / (VIEW_NEAR - VIEW_FAR);
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
			cam->proj[i][j] = 0.0f;
	}
	cam->proj[1][1] = 1.0f / (float)tan(RAD(VIEW_FOV / 2.0f));
	cam->proj[0][0] = cam->proj[1][1] / VIEW_ASPECT;
	cam->proj[2][2] = (VIEW_FAR + VIEW_NEAR) * depth;
	cam->proj[2][3] = 2 * VIEW_FAR * VIEW_NEAR * depth;
	cam->proj[3][2] = -1.0f;
}

void		init_camera(t_camera *cam)
{
	cam->center = (t_point){0.0f, 0.0f, 0.0f};
	cam->eye = (t_point){10.0f, 10.0f, 0.0f};
	cam->up = (t_point){0.0f, 0.0f, 1.0f};
	init_projection(cam);
	cam->view[3][0] = cam->view[3][1] = cam->view[3][2] = 0.0f;
	cam->view[3][3] = 1.0f;
	cam->vp = 0x0;
}
