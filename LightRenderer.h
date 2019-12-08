#pragma once
#include <GL/glew.h>

#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"

#include "Mesh.h"
#include "ShaderLoader.h"
#include "Camera.h"

class LightRenderer
{
public:
	LightRenderer(MeshType meshType, Camera* camera);
	~LightRenderer();

	void draw();

	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);
	void setProgram(GLuint program);

	glm::vec3 getPosition();
	glm::vec3 getColor();

private: 
	Camera* _camera;

	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;

	glm::vec3 _position;
	glm::vec3 _color;

	GLuint _vbo;
	GLuint _ebo;
	GLuint _vao;
	GLuint _program;

};

