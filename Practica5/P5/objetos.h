//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GLUT/glut.h>
#include "vertex.h"
#include <stdlib.h>
#include <file_ply_stl.h>
#include <time.h>       /* time */
#include "CImg.h"
using namespace cimg_library;
using namespace std;

const float AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);
void Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLfloat cz, GLint n);
vector<_vertex3f> vertices;
vector<_vertex3f> colores;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{

private:
	vector<_vertex3f> normales_caras;
	vector<_vertex3f> normales_vertices;
	bool b_normales_caras;
	bool b_normales_vertices;
	_vertex4f ambiente_difusa;
	_vertex4f especular;
	float brillo;
	vector<pair<_vertex3f,_vertex3f> > normales_caras_dibujados, normales_vertices_dibujados;	
public:
	vector<_vertex3i> caras;
	_triangulos3D();
void draw_aristas(float r, float g, float b, int grosor);
void draw_solido(float r, float g, float b);
void draw_solido_colores();
void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void draw_iluminacion_suave();
void draw_iluminacion_plana();
void calcular_normales_vertices();
void calcular_normales_caras();
void draw_textura(float r, float g, float b,GLuint ident_textura);
void draw_normales_vertices();
void draw_normales_caras();
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
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
// clase circunferencia
//*************************************************************************

class _circunferencia: public _triangulos3D
{
public:

	_circunferencia(float tam=0.5, float al=0.75);
};

//***************************************************************************
// Class objeto-ply
//***************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
	_objeto_ply();
  void parametros(const char *filename);
};

//***************************************************************************
// Class objeto-ply
//**************************************************************************

class _revolucion: public _triangulos3D
{
public:
	_revolucion();
	void parametros(vector<_vertex3f> perfil, int num);
	void parametros(const char *filename, int num);
	void parametros_giro_x(vector<_vertex3f> perfil, int num);
	void parametros_sin_tapas(const char *filename, int num);
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


//***************************************************************************
// Class texture
//****************************************************************************
class _texture: public _triangulos3D
{
	private:
		CImg<unsigned char> imagen;
	public:
	GLuint ident_textura;
	_texture();
 	_texture(const char *nombreImagen);
};
//***************************************************************************
// Class camara
//****************************************************************************
class camara{
public:
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

GLfloat Window_width,Window_height,Front_plane,Back_plane;
void setObservador(){
   glTranslatef(0,0,-Observer_distance);
   glRotatef(Observer_angle_x,1,0,0);
   glRotatef(Observer_angle_y,0,1,0);
}
};
