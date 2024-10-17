#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


//Idenficadores de los objetos de la escena
int objId =-1;

//Declaraci�n de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);


int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));// acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v7.vert", "../shaders_P1/shader.v7.frag"))
		return -1;
   
	//Se ajusta la c�mara
	//Si no se da valor se cojen valores por defecto
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view =  glm::mat4(1.0f);
	glm::mat4 proj =  glm::mat4(0.0f);

	view[3].z = -6.f;

	float n = 1.f;
	float f = 10.f;

	proj[0][0] = 1.732f;							//tambi�n vale proj[0].x
	proj[1][1] = 1.732f;
	proj[2][2] = (f+n)/(n-f);
	proj[3][2] = 2.f * f * n / (n - f);
	proj[2][3] = -1.f;

	IGlib::setProjMat(proj);
	IGlib::setViewMat(view);

	//Creamos el objeto que vamos a visualizar
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, 
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);
		
	glm::mat4 modelMat = glm::mat4(1.0f);
	IGlib::setModelMat(objId, modelMat);
	//Incluir texturas aqu�.
	IGlib::addColorTex(objId, "../img/color.png");
	


  //CBs
  IGlib::setResizeCB(resizeFunc);
  IGlib::setIdleCB(idleFunc);
  IGlib::setKeyboardCB(keyboardFunc);
  IGlib::setMouseCB(mouseFunc);
  IGlib::setMouseMoveCB(mouseMotionFunc);

	
	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height) //ancho y alto en p�xeles
{
	//Ajusta el aspect ratio al tama�o de la venta
}

void idleFunc()
{
	static float angle = 0;		//variable est�tica mantiene el valor hasta que cambia (es 0 hasta que se modifica)
	angle = (angle < 6.28318530718)? angle + 0.0005f : 0.0f;
	glm::mat4 rot =  glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.8f, 0.5f, 0.0f));
	IGlib::setModelMat(objId, rot);
}

void keyboardFunc(unsigned char key, int x, int y) //te dice que tecla se ha pulsado
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el bot�n ";
	else
		std::cout << "Se ha soltado el bot�n ";
	
	if (button == 0) std::cout << "de la izquierda del rat�n " << std::endl;
	if (button == 1) std::cout << "central del rat�n " << std::endl;
	if (button == 2) std::cout << "de la derecha del rat�n " << std::endl;

	std::cout << "en la posici�n " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
}
