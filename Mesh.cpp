#include "Mesh.h"

void Mesh::setTriData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	std::vector<Vertex> _vertices = 
	{
		{
			{ 0.0f, -1.0f, 0.0f },	// Position
			{ 0.0f,  0.0f, 1.0f },	// Normal
			{ 1.0f,  0.0f, 0.0f },	// Color
			{ 0.0f,  1.0f }			// Texture Coordination
		}, //0
		{
			{ 1.0f,  1.0f, 0.0f },	// Position
			{ 0.0f,  0.0f, 1.0f },	// Normal
			{ 0.0f,  1.0f, 0.0f },	// Color
			{ 0.0f,  0.0f }			// Texture Coordination
		}, //1
		{
			{-1.0f,  1.0f, 0.0f },	// Position
			{ 0.0f,  0.0f, 1.0f },	// Normal
			{ 1.0f,  0.0f, 1.0f },	// Color
			{ 1.0f,  0.0f }			// Texture Coordination
		}  //2
	};

	std::vector<uint32_t> _indices =
	{
		0, 1, 2
	};

	vertices.clear();
	indices.clear();

	vertices = _vertices;
	indices = _indices;

}