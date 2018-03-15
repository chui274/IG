//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#ifdef __MACH__ // Incluimos las librerías necesarias para que funcione en OSX
	#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "vertex.h"
#include <stdlib.h>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;

const float AXIS_SIZE=5000;

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

//Examen
void inicializar_colores();
void draw_solido_colores();
vector<_vertex3f> color;

vector<_vertex3i> caras;

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
