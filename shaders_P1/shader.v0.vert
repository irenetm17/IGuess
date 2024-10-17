#version 330 core

in vec3 inPos;		

void main()
{
	mat4 model = mat4(1.0);
	mat4 view = mat4(1.0);
	mat4 proj = mat4(0.0);

	view[3].z = -3.0;

	float n = 1.;
	float f = 10.;

	proj[0][0] = 1.732;							//también vale proj[0].x
	proj[1][1] = 1.732;
	//proj[2][2] = (f+n)/(n-f);
	proj[3][2] = 2.*f*n/(n-f);
	//proj[2][3] = -1.;
	proj[2].zw = vec2((f+n)/(n-f), -1.);		//forma alterna de hacerlo

	gl_Position = proj * view * model * vec4(inPos, 1.);
}
