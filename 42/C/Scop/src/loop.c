#include "scop.h"

static void	set_center_obj(t_object *obj)
{
	t_point				max;
	t_point				min;
	unsigned int	i;

	max.x = max.y = max.z = i = 0;
	min.x = min.y = min.z = 0xFFFFFFFF;
	while (i < obj->vertex_buffer_size)
	{
		if (obj->vertex_buffer_data[i].x > max.x)
			max.x = obj->vertex_buffer_data[i].x;
		else if (obj->vertex_buffer_data[i].x < min.x)
			min.x = obj->vertex_buffer_data[i].x;
		if (obj->vertex_buffer_data[i].y > max.y)
			max.y = obj->vertex_buffer_data[i].y;
		else if (obj->vertex_buffer_data[i].y < min.y)
			min.y = obj->vertex_buffer_data[i].y;
		if (obj->vertex_buffer_data[i].z > max.z)
			max.z = obj->vertex_buffer_data[i].z;
		else if (obj->vertex_buffer_data[i].z < min.z)
			min.z = obj->vertex_buffer_data[i].z;
		i++;
	}
	obj->center.x = min.x + ABS(max.x - min.x) / 2;
	obj->center.y = min.y + ABS(max.y - min.y) / 2;
	obj->center.z = min.z + ABS(max.z - min.z) / 2;
}

static void	prepare_obj(t_object *obj)
{
	glGenTextures(1, &(obj->tex_id));
	glBindTexture(GL_TEXTURE_2D, obj->tex_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, obj->bmp.width, obj->bmp.height, 0
		, GL_BGR, GL_UNSIGNED_BYTE, obj->bmp.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
}

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	set_center_obj(&(w->obj));
	refresh(w);
	render(w);
	prepare_obj(&(w->obj));
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME)
			continue ;
		glfwPollEvents();
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render(w);
		glfwSwapBuffers(w->window);
	}
}
