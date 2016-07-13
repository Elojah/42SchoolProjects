#include "scop.h"

static void			render_obj(t_object *obj)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, obj->tex_id);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ARRAY_BUFFER, obj->tex_buffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ve_index_buffer);
	glDrawElements(
		GL_TRIANGLES,
		obj->index_buffer_size * 3,
		GL_UNSIGNED_INT,
		BUFFER_OFFSET(0)
	);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void				render(t_window *w)
{
	glUseProgram(w->prog_id);
	glUniformMatrix4fv(w->cam.mvp_id, 1, GL_FALSE, (float *)(w->cam.vp));
	render_obj(&(w->obj));
}
