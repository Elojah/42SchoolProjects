#include "scop.h"
#include <math.h>

static void	normalize(t_point *p)
{
	float	norm;

	norm = sqrt(SQ(p->x) + SQ(p->y) + SQ(p->z));
	if (norm == 1.0f)
		return ;
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;
}

static void	refresh_vp(t_window *w)
{
	static float	vp[4][4];
	short			i;
	short			j;
	short			n;

	i = -1;
	if (w->cam.vp == 0x0)
	{
		w->cam.vp = ((float ***)&vp);
		w->cam.mvp_id = glGetUniformLocation(w->prog_id, "vp");
	}
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			vp[j][i] = 0.0f;
			n = -1;
			while(++n < 4)
				vp[j][i] += w->cam.proj[i][n] * w->cam.view[n][j];
		}
	}
}

static void	refresh_eye(float row[4], t_point *eye)
{
	row[3] = -row[0] * eye->x - row[1] * eye->y - row[2] * eye->z + 1;
}

static void	refresh_view(t_camera *cam)
{
	cam->forward.x = cam->center.x - cam->eye.x;
	cam->forward.y = cam->center.y - cam->eye.y;
	cam->forward.z = cam->center.z - cam->eye.z;
	normalize(&(cam->forward));
	normalize(&(cam->up));
	cam->right.x = (cam->forward.y * cam->up.z) - (cam->forward.z * cam->up.y);
	cam->right.y = (cam->forward.z * cam->up.x) - (cam->forward.x * cam->up.z);
	cam->right.z = (cam->forward.x * cam->up.y) - (cam->forward.y * cam->up.x);
	normalize(&(cam->right));
	cam->view[0][0] = cam->right.x;
	cam->view[0][1] = cam->right.y;
	cam->view[0][2] = cam->right.z;
	cam->view[1][0] = cam->up.x =
		(cam->right.y * cam->forward.z) - (cam->right.z * cam->forward.y);
	cam->view[1][1] = cam->up.y =
		(cam->right.z * cam->forward.x) - (cam->right.x * cam->forward.z);
	cam->view[1][2] = cam->up.z =
		(cam->right.x * cam->forward.y) - (cam->right.y * cam->forward.x);
	cam->view[2][0] = -cam->forward.x;
	cam->view[2][1] = -cam->forward.y;
	cam->view[2][2] = -cam->forward.z;
	cam->view[0][3] = cam->view[1][3] = cam->view[2][3] = 0.0f;
}

static void	refresh_cam(t_camera *cam)
{
	refresh_view(cam);
	refresh_eye(cam->view[0], &(cam->center));
	refresh_eye(cam->view[1], &(cam->center));
	refresh_eye(cam->view[2], &(cam->center));
}

void	refresh(t_window *w)
{
	refresh_cam(&(w->cam));
	refresh_vp(w);
}
