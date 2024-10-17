#version 330 core

out vec4 outColor;


void main()
{
	if (mod(gl_PrimitiveID, 2) == 0)
	{
		outColor = vec4(1.0f);
	} else{
		outColor = vec4(0.9, vec3(0.4, 0.6, 1.0));  
	}
}