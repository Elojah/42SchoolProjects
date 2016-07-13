// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:27:53 by hdezier           #+#    #+#             //
//   Updated: 2015/05/23 18:00:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AObject.hpp"

AObject::AObject(void) {}
AObject::~AObject(void)
{
	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteBuffers(1, &_indexBuffer);
	glDeleteVertexArrays(1, &_vertexArrayID);
	glDeleteProgram(_progID);
}

void		AObject::draw(void) const
{
	glBindVertexArray(_vertexArrayID);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
void		AObject::refresh(Camera const &cam)
{
	mvp = cam.getViewProj() * glm::mat4(1.0f);
	_matrixID = glGetUniformLocation(_progID, "mvp");
}
