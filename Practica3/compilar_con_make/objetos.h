//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#ifdef __MACH__ // Incluimos las librerías necesarias para que funcione en OSX
	#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "vertex.h"
#include <stdlib.h>
#include <random>
#include "file_ply_stl.h"
#include <cmath>
#include <ctime>
#include "math.h"
using namespace std;

const float AXIS_SIZE=5000;
typedef enum {POINTS,EDGES,SOLID,SOLID_CHESS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLfloat cz, GLint n, GLenum modo);
void 	draw_puntos(float r, float g, float b, int grosor);
void draw_puntos_circulares(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
//Pruebas practica2
void draw_pares(float r1, float g1, float b1, float r2, float g2, float b2);
void draw_franjas(float r1, float g1, float b1, float r2, float g2, float b2);

//Pruebas
void draw_caras_aleatorias();
void inicializar_colores();
vector<_vertex3i> caras;
vector<_vertex3f> color;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
	_cubo(float tam,int desp_x, int desp_y, int desp_z);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);

};


//*************************************************************************
// clase tetraedro
//*************************************************************************

class _tetraedro : public _triangulos3D {
	public:
		_tetraedro(float tam=0.5);
};

//*************************************************************************
// clase tronco_piramide
//*************************************************************************

class _tronco_piramide : public _triangulos3D {
	public:
		_tronco_piramide(float tam=1, float tam2=0.3, float altura=1);
};

//*************************************************************************
// clase objeto_ply
//*************************************************************************

class _objeto_ply : public _triangulos3D{
public:
	_objeto_ply();
	int parametros(char *archivo);//Metodo para construir objeto vacio y asignar caras y vertices correspondientes
};

//*************************************************************************
// clase solido revolucion
//*************************************

class _rotacion : public _triangulos3D{
public:
	_rotacion();
	void parametros(vector<_vertex3f> perfil1, int num1,bool hayTapa);//Le pasamos el perfil y el numero de caras a la hora de crear el objeto con revolucion
//El giro se lo hacemos sobre el eje de la Y


	vector<_vertex3f> perfil;
	int num;
};

//*************************************************************************
// clase Robot 
//*************************************

class _robot: public _triangulos3D{
private:
	float maximo_brazos;
	float minimo_brazos;
	float maximo_piernas;
	float minimo_piernas;
	float maximo_cabeza;
	float minimo_cabeza;
	
	vector<float> posicion;
	_cubo *cubo;
  
  public:
	_robot();
  
	void draw_robot(int modo, float r1, float g1, float b1, float r2,
						float g2, float b2);
  
	void cuerpo(int modo, float r, float g, float b);
	void brazo_derecho(int modo, float r, float g, float b);
	void mano_derecha(int modo, float r, float g, float b);
	void brazo_izquierdo(int modo, float r, float g, float b);
	void mano_izquierda(int modo, float r, float g, float b);
	void pierna_derecha(int modo, float r, float g, float b);
	void pie_derecho(int modo, float r, float g, float b);
	void pierna_izquierda(int modo, float r, float g, float b);
	void pie_izquierdo(int modo, float r, float g, float b);
	void cabeza(int modo, float r, float g, float b);
	
	
	void munieco(int modo);
	void aumentar_brazos(int valor);
	void disminuir_brazos(int valor);
	void aumentar_piernas(int valor);
	void disminuir_piernas(int valor);
	void mover_cabeza_dcha(int valor);
	void mover_cabeza_izda(int valor);
	
};
