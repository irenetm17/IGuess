#version 330 core

 
uniform mat4 modelViewProj;

//defino variable variante a la que asigno las coordenadas "vtexcoord"
out vec2 vtexcoord;
in vec2 inTexCoord;
in vec3 inPos;



void main()
{
	vtexcoord = inTexCoord;

	gl_Position = modelViewProj * vec4(inPos, 1.); //sabemos que es una variable de vértices porque es la psoición
}