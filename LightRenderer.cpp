#include "LightRenderer.h"

LightRenderer::LightRenderer(MeshType meshType, Camera* camera)
{
	this->_camera = camera;

	switch (meshType)
	{
	case kTriangle:
		Mesh::setTriData(_vertices, _indices);
		break;

	case kQuad:
		Mesh::setQuadData(_vertices, _indices);
		break;

	case kCube:
		Mesh::setCubeData(_vertices, _indices);
		break;

	case kSphere:
		Mesh::setSphereData(_vertices, _indices);
		break;

	default:
		break;
	}

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::color)));

	glGenBuffers(1, &_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

LightRenderer::~LightRenderer()
{
}

void LightRenderer::draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), _position);

	glUseProgram(this->_program);

	GLint modelLoc = glGetUniformLocation(_program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glm::mat4 view = _camera->getViewMatrix();
	GLint vLoc = glGetUniformLocation(_program, "view");
	glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 proj = _camera->getProjectionMatrix();
	GLint pLoc = glGetUniformLocation(_program, "projection");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(proj));

	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
}

// setters
void LightRenderer::setPosition(glm::vec3 position)
{
	this->_position = position;
}

void LightRenderer::setColor(glm::vec3 color)
{
	this->_color = color;
}

void LightRenderer::setProgram(GLuint program)
{
	this->_program = program;
}

// getters
glm::vec3 LightRenderer::getPosition()
{
	return this->_position;
}

glm::vec3 LightRenderer::getColor()
{
	return this->_color;
}