//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************
#include "objetos.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <file_ply_stl.h>
#include "vertex.h"


using namespace std;
// tamaño de los ejes
//const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;
//QImage Imagen;

//**************************************************************************
//
//***************************************************************************

_cubo cubo(5);
_piramide piramide(5,10);
int opcion=0;
int objeto=0;
_objeto_ply figura;
_revolucion revolucion;
_tachikoma tachikoma;
_texture textura;
void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{
	if(objeto==1){

		if (opcion==1) //puntos
			cubo.draw_puntos(0.5,0.3,0.7,5);
		else if (opcion==2) //linea
			cubo.draw_aristas(0,0,0,2);
		else if (opcion==3) //Relleno
			cubo.draw_solido_colores();
		else if (opcion==4) //Visualizar ajedrez
			cubo.draw_solido_ajedrez(0.6,0.1,0.7,0,0,0);
		else if (opcion==15){ //Iluminación
			cubo.draw_iluminacion_suave();
		}else if (opcion==16) //Iluminación
			cubo.draw_iluminacion_plana();
		else if (opcion==17) //Relleno
			cubo.draw_textura(0.5,0.3,0.7,textura.ident_textura);
		else
			cubo.draw_puntos(0.5,0.3,0.7,5);

	}else if(objeto==2){
		if (opcion==1) //puntos
			piramide.draw_puntos(0.5,0.3,0.7,5);
		else if (opcion==2) //linea
			piramide.draw_aristas(0,0,0,2);
		else if (opcion==3) //Relleno
			piramide.draw_solido_colores();
		else if (opcion==4) //Visualizar ajedrez
			piramide.draw_solido_ajedrez(0.6,0.1,0.7,0,0,0);
		else if (opcion==15){ //Iluminación
			piramide.draw_iluminacion_suave();
		}else if (opcion==16) //Iluminación
			piramide.draw_iluminacion_plana();
		else
			piramide.draw_puntos(0.5,0.3,0.7,5);
	}
	else if(objeto==4){
		if (opcion==1) //puntos
			revolucion.draw_puntos(0.5,0.3,0.7,5);
		else if (opcion==2) //linea
			revolucion.draw_aristas(0,0,0,2);
		else if (opcion==3) //Relleno
			revolucion.draw_solido(0.137255,0.419608,0.556863);
		else if (opcion==4) //Visualizar ajedrez
			revolucion.draw_solido_ajedrez(0.6,0.1,0.7,0,0,0);
		else if (opcion==15){ //Iluminación
			revolucion.draw_iluminacion_suave();
		}
		else if (opcion==16) //Iluminación
			revolucion.draw_iluminacion_plana();
		else
			revolucion.draw_puntos(0.5,0.3,0.7,5);
	}else if(objeto==5){
		if (opcion==1) //puntos
			figura.draw_puntos(0.5,0.3,0.7,5);
		else if (opcion==2) //linea
			figura.draw_aristas(0,0,0,2);
		else if (opcion==3) //Relleno
			figura.draw_solido_colores();
		else if (opcion==4) //Visualizar ajedrez
			figura.draw_solido_ajedrez(0.6,0.1,0.7,0,0,0);
		else if (opcion==15){ //Visualizar ajedrez
			figura.draw_iluminacion_suave();
		}
		else if (opcion==16) //Iluminación
			figura.draw_iluminacion_plana();
			else if (opcion==17) //Relleno
				figura.draw_textura(0.5,0.3,0.7,textura.ident_textura);
		else
			figura.draw_puntos(0.5,0.3,0.7,5);
	}else if(objeto==6){
		if(opcion==18){//Normal vertices
		figura.draw_normales_vertices();
		figura.draw_iluminacion_suave();
	}
	else if(opcion==19){
		figura.draw_normales_caras();
		figura.draw_iluminacion_plana();
	}
	}
}


//******************************
//Luz
//*******************************
void luces( )
{

	GLfloat luz_difusa[]={1.0,1.0,1.0,1.0 },
	luz_especular[]={1.0,1.0,1.0,1.0 },
	luz_posicion[]={2.0, 4.0, 10.0 , 1.0};
	GLfloat luz_ambiente[] = {0.4, 0.4, 0.4, 1.0};
	glLightfv (GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv (GL_LIGHT0, GL_SPECULAR, luz_especular);
	glLightfv (GL_LIGHT0, GL_POSITION, luz_posicion);
}
//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
// Activamos la iluminacion
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{
if (toupper(Tecla1)=='Q')
	exit(0);
else if (toupper(Tecla1)=='P') //puntos
	opcion=1;
else if (toupper(Tecla1)=='L') //linea
	opcion=2;
else if (toupper(Tecla1)=='F') //Relleno
	opcion=3;
else if (toupper(Tecla1)=='C') //Visualizar ajedrez
	opcion=4;
else if (toupper(Tecla1)=='I') //iluminación suave
		opcion=15;
else if (toupper(Tecla1)=='J') //iluminación plana
		opcion=16;
else if (toupper(Tecla1)=='T') //Textura
		opcion=17;
else if(toupper(Tecla1)=='N') //Normal vertices
	opcion=18;
else if(toupper(Tecla1)=='M') //Normal caras
		opcion=19;
else if (toupper(Tecla1)=='1') //cubo
	objeto=1;
else if (toupper(Tecla1)=='2') //tetraedro
	objeto=2;
else if (toupper(Tecla1)=='3') //robot
		objeto=3;
else if (toupper(Tecla1)=='4') //revolucion
		objeto=4;
else if (toupper(Tecla1)=='5') //objeto-ply
	objeto=5;
	else if (toupper(Tecla1)=='6') //cubo de nuevo
		objeto=6;
glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
glutPostRedisplay();
}


//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=5;
Window_height=5;
Front_plane=10;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
glClearDepth (1.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
luces();
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

if (argc == 3){
	// se llama a la inicialización de glut
	glutInit(&argc, argv);

	// se indica las caracteristicas que se desean para la visualización con OpenGL
	// Las posibilidades son:
	// GLUT_SIMPLE -> memoria de imagen simple
	// GLUT_DOUBLE -> memoria de imagen doble
	// GLUT_INDEX -> memoria de imagen con color indizado
	// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
	// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
	// GLUT_DEPTH -> memoria de profundidad o z-bufer
	// GLUT_STENCIL -> memoria de estarcido
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	// posicion de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

	// tamaño de la ventana (ancho y alto)
	glutInitWindowSize(UI_window_width,UI_window_height);

	// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
	// al bucle de eventos)
	glutCreateWindow("Práctica 4");

	// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);
	// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(change_window_size);
	// asignación de la funcion llamada "tecla_normal" al evento correspondiente
	glutKeyboardFunc(normal_keys);
	// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_keys);
	figura.parametros("beethoven.ply");
	vector<_vertex3f> vertices;
	vertices.resize(4);
	vertices[0].x=0;vertices[0].y=3;vertices[0].z=3;
	vertices[1].x=5;vertices[1].y=3;vertices[1].z=3;
	vertices[2].x=10;vertices[2].y=3;vertices[2].z=3;
	vertices[3].x=15;vertices[3].y=3;vertices[3].z=4;
	//vertices[4].x=2;vertices[4].y=20;vertices[4].z=3;
	revolucion.parametros(argv[1], 12);
	_texture textura(argv[2]);
	//revolucion.parametros(vertices,25 );
	//revolucion.parametros_giro_x(vertices,10 );
	// funcion de inicialización
	initialize();

	// inicio del bucle de eventos
	glutMainLoop();
}else{
	cout << "Faltan parámetros un ejemplo de uso sería: " <<endl;
	cout << "./practica4 objeto.ply textura.jpg" << endl;
}


return 0;
}
