#version 330 core

uniform sampler2D colorTex;
out vec4 outColor;

in vec2 vtexcoord; //acceso a textura

void main()
{
	//outColor = vec4 (vtexcoord.xy, 1, 1);
	outColor = texture(colorTex, vtexcoord.xy); 
	//necesito coordenadas de textura "vtexcoord" se puede dar el nombre que se quiera
	//las herramientas de texturado crean unas coords para cada vértice y entran en el 
	//cauce gráfico como atributos a partir del shader de vértices

	if (outColor.g > 0.8) discard; //se va el verde
}