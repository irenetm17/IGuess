#version 330 core


uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normal;

in vec3 inPos;
in vec3 inNormal;

out vec3 vPos;
out vec3 vNorm;



void main()
{
	//como se que la coord homogénea no varia valen xyz
	vPos = (modelView * vec4(inPos, 1)).xyz; //como Pos es vec3 le ponemos coord homogénea 1 porque es matriz
	//vNorm = inverse(transpose(modelView)) * vec4(inNormal, 0); //como Normal es vec3 le ponemos coord homogénea 0 porque es vector
	vNorm = (normal * vec4(inNormal, 0)).xyz; 
	gl_Position = modelViewProj * vec4(inPos, 1.); //sabemos que es una variable de vértices porque es la psoición
}