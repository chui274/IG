//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/glut.h>
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
//***************************************************************************
// Class tachikoma
//**************************************************************************

class _tachikoma: public _triangulos3D{
	private:
		_objeto_ply puerta_derecha;
		_objeto_ply puerta_izquierda;
		_objeto_ply compuerta;
		_objeto_ply cabina;
		_revolucion cuerpo;
		_revolucion aro_cuerpo;
		_revolucion cuerpo_inferior;
		_objeto_ply pierna;
		_revolucion antena;
		_revolucion canhon;
		_revolucion brazo;
		_revolucion rueda;
		float abrirPuertas=0;
		float gradoY=0;
		float gradoXZ=0;
		float avance_en_x=0;
		float gradoZ=0;
	public:
		_tachikoma();
		void dibujar_figura(float r, float g, float b,int modo);
		void dibujar_cabina(float r, float g, float b, float abrirPuertas);
		void dibujar_piernas(float r, float g, float b);
		void dibujar_cuerpo(float r, float g, float b, float gradoY, float gradoXZ);
		void dibujar_canhon_brazos(float r, float g, float b);
		void pintarOjo(float r, float g, float b);
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
