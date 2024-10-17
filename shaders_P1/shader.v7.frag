#version 330 core

uniform sampler2D colorTex;
out vec4 outColor;

in vec3 vPos;
in vec3 vNorm;

void main()
{
	//outColor = vPos.rgbb; //añado cuarta coord "b" para que los vectores sean compatibles
	//outColor = vec4(vPos.xy, 0, 0);
	outColor = vec4(vNorm, 0);
}