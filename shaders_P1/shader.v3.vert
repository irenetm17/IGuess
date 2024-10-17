#version 330 core


uniform mat4 modelViewProj;
in vec3 inColor;
in vec3 inPos;

out vec3 vColor;

void main()
{
	vColor = inColor;
	gl_Position = modelViewProj * vec4(inPos, 1.); //sabemos que es una variable de vértices porque es la psoición
}