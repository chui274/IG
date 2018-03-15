//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos.h"
//*************Clase puntos3D****************
_puntos3D::_puntos3D(){}

//*****Función que crea circulos***********
void _puntos3D::Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLfloat cz, GLint n, GLenum modo)
{
  int i;
  if (modo==GL_LINE)
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  else if (modo==GL_FILL)
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glBegin( GL_POLYGON );
    for (i=0;i<n;i++)
      glVertex3f( cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n), cz);
  glEnd();
}


//*****Función que dibuja vertices con forma de circulos***********
void _puntos3D::draw_puntos_circulares(float r, float g, float b, int grosor){
	glColor3f(r,g,b);
	glPointSize(grosor);
	glBegin (GL_FILL);
      for(int i=0; i<vertices.size();i++){
      	      Circle(0.4,vertices[i]._0,vertices[i]._1,vertices[i]._2,20,GL_FILL);
      }
	glEnd ( );

}
/****************Dibujar puntos(Copia de draw objects)*************/
void 	_puntos3D::draw_puntos(float r, float g, float b, int grosor){
  int i;
  glPointSize(grosor);
  glColor3f(r,g,b);
  glBegin(GL_POINTS);
  for(i=0;i<vertices.size();i++){
    glVertex3fv((GLfloat *) &vertices[i]);
  }
  glEnd();
}



//***********Clase _triangulos3D****************

_triangulos3D::_triangulos3D(){}

//**************Dibujar en modo arista*************
void 	_triangulos3D::draw_aristas(float r, float g, float b, int grosor){
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glLineWidth(grosor);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for(i=0;i<caras.size();i++){
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();

}


//**************Dibujar en modo solido*************
void    _triangulos3D::draw_solido(float r, float g, float b){//terminar
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for(i=0;i<caras.size();i++){
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();

}

//**************Dibujar en modo ajedrez*************
void 	_triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){//terminar
  //Comprobar si es par poner de un color o si es impar de otro color
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glBegin(GL_TRIANGLES);

  for(i=0;i<caras.size();i++){
    if(i%2 == 0)//Si la cara es par
    glColor3f(r1,g1,b1);
  else
    glColor3f(r2,g2,b2);

    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();

}
//*****Función que dibuja las caras dependiendo el color***********
void _triangulos3D::draw_solido_colores(){
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glBegin(GL_TRIANGLES);
		for(int i = 0; i < caras.size(); i++){
      glColor3fv((GLfloat *) &color[i]);
      glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}

	glEnd();

}
//Inicializador de colores aleatorios
void _triangulos3D::inicializar_colores(){
  if (color.empty()) {
        color.resize(caras.size());

        for (unsigned i= 0; i < color.size(); ++i) {
          bool repetido = true;

          while (repetido) {
            repetido = false;
            float color1 = (float) rand() / (float) RAND_MAX;
            float color2 = (float) rand() / (float) RAND_MAX;
            float color3 = (float) rand() / (float) RAND_MAX;

            color[i].x  = color1;
            color[i].y  = color2;
            color[i].z  = color3;

            for (unsigned j = 0; j < i && !repetido; ++j)
                if (color[i] == color[j])
                    repetido = true;
          }
        }

    }

}





//********************************Clase cubo***********************************
_cubo::_cubo(float tam){
  //8 vertices
  vertices.resize(8);
  vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
  vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
  vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
  vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
  vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
  vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
  vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
  vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=-tam;

  //12 caras
  caras.resize(12);
  caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
  caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;
  caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
  caras[3]._0=5;caras[3]._1=6;caras[3]._2=2;
  caras[4]._0=5;caras[4]._1=4;caras[4]._2=6;
  caras[5]._0=4;caras[5]._1=7;caras[5]._2=6;
  caras[6]._0=0;caras[6]._1=7;caras[6]._2=4;
  caras[7]._0=0;caras[7]._1=3;caras[7]._2=7;
  caras[8]._0=3;caras[8]._1=2;caras[8]._2=7;
  caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
  caras[10]._0=0;caras[10]._1=1;caras[10]._2=4;
  caras[11]._0=1;caras[11]._1=5;caras[11]._2=4;

  color.resize(12);//Dibujamos para las 12 caras, utilizamos rand para mostrarlo aleatoriamente
  color[0].x = rand()/(RAND_MAX + 1.0); color[0].y = rand()/(RAND_MAX + 1.0); color[0].z = rand()/(RAND_MAX + 1.0);
  color[1].x = rand()/(RAND_MAX + 1.0); color[1].y = rand()/(RAND_MAX + 1.0); color[1].z = rand()/(RAND_MAX + 1.0);
  color[2].x = rand()/(RAND_MAX + 1.0); color[2].y = rand()/(RAND_MAX + 1.0); color[2].z = rand()/(RAND_MAX + 1.0);
  color[3].x = rand()/(RAND_MAX + 1.0); color[3].y = rand()/(RAND_MAX + 1.0); color[3].z = rand()/(RAND_MAX + 1.0);
  color[4].x = rand()/(RAND_MAX + 1.0); color[4].y = rand()/(RAND_MAX + 1.0); color[4].z = rand()/(RAND_MAX + 1.0);
  color[5].x = rand()/(RAND_MAX + 1.0); color[5].y = rand()/(RAND_MAX + 1.0); color[5].z = rand()/(RAND_MAX + 1.0);
  color[6].x = rand()/(RAND_MAX + 1.0); color[6].y = rand()/(RAND_MAX + 1.0); color[6].z = rand()/(RAND_MAX + 1.0);
  color[7].x = rand()/(RAND_MAX + 1.0); color[7].y = rand()/(RAND_MAX + 1.0); color[7].z = rand()/(RAND_MAX + 1.0);
  color[8].x = rand()/(RAND_MAX + 1.0); color[8].y = rand()/(RAND_MAX + 1.0); color[8].z = rand()/(RAND_MAX + 1.0);
  color[9].x = rand()/(RAND_MAX + 1.0); color[9].y = rand()/(RAND_MAX + 1.0); color[9].z = rand()/(RAND_MAX + 1.0);
  color[10].x = rand()/(RAND_MAX + 1.0); color[10].y = rand()/(RAND_MAX + 1.0); color[10].z = rand()/(RAND_MAX + 1.0);
  color[11].x = rand()/(RAND_MAX + 1.0); color[11].y = rand()/(RAND_MAX + 1.0); color[11].z = rand()/(RAND_MAX + 1.0);




  //inicializar_colores();

}

//Cubo con desplazamiento

_cubo::_cubo(float tam,int desp_x, int desp_y, int desp_z){
  vertices.resize(8);
  vertices[0].x=-tam+desp_x;vertices[0].y=-tam+desp_y;vertices[0].z=tam+desp_z;
  vertices[1].x=tam+desp_x;vertices[1].y=-tam+desp_y;vertices[1].z=tam+desp_z;
  vertices[2].x=tam+desp_x;vertices[2].y=tam+desp_y;vertices[2].z=tam+desp_z;
  vertices[3].x=-tam+desp_x;vertices[3].y=tam+desp_y;vertices[3].z=tam+desp_z;
  vertices[4].x=-tam+desp_x;vertices[4].y=-tam+desp_y;vertices[4].z=-tam+desp_z;
  vertices[5].x=tam+desp_x;vertices[5].y=-tam+desp_y;vertices[5].z=-tam+desp_z;
  vertices[6].x=tam+desp_x;vertices[6].y=tam+desp_y;vertices[6].z=-tam+desp_z;
  vertices[7].x=-tam+desp_x;vertices[7].y=tam+desp_y;vertices[7].z=-tam+desp_z;
  caras.resize(12);
  caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
  caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;
  caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
  caras[3]._0=5;caras[3]._1=6;caras[3]._2=2;
  caras[4]._0=5;caras[4]._1=4;caras[4]._2=6;
  caras[5]._0=4;caras[5]._1=7;caras[5]._2=6;
  caras[6]._0=0;caras[6]._1=7;caras[6]._2=4;
  caras[7]._0=0;caras[7]._1=3;caras[7]._2=7;
  caras[8]._0=3;caras[8]._1=2;caras[8]._2=7;
  caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
  caras[10]._0=0;caras[10]._1=1;caras[10]._2=4;
  caras[11]._0=1;caras[11]._1=5;caras[11]._2=4;

  inicializar_colores();
}

//***************************************Clase piramide*************************
	_piramide::_piramide(float tam, float al){

    //vertices
    vertices.resize(5);
    //Creamos manualmente los puntos
    vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
    vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
    vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
    vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
    vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

    //Creamos las caras
    caras.resize(6);

    caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
    caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
    caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
    caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
    caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
    caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

    inicializar_colores();
  }


  //********************* Clase Tetraedro *********************

_tetraedro::_tetraedro(float tam) {
	vertices.resize(4);
	vertices[0].x = 0; vertices[0].y = 0; vertices[0].z = (sqrt(3)*tam)/3;
	vertices[1].x = tam/2; vertices[1].y = 0; vertices[1].z = -(sqrt(3)*(tam))/3;
	vertices[2].x = -tam/2; vertices[2].y = 0; vertices[2].z = -(sqrt(3)*(tam))/3;
	vertices[3].x = 0; vertices[3].y = (sqrt(6)/3)*tam; vertices[3].z = 0;

	caras.resize(4);
	caras[0]._0 = 0; caras[0]._1 = 1; caras[0]._2 = 3;
	caras[1]._0 = 1; caras[1]._1 = 2; caras[1]._2 = 3;
	caras[2]._0 = 2; caras[2]._1 = 0; caras[2]._2 = 3;
	caras[3]._0 = 1; caras[3]._1 = 0; caras[3]._2 = 2;

  inicializar_colores();
}



//********************* Clase Tronco Piramide *********************

_tronco_piramide::_tronco_piramide(float tam, float tam2, float altura){
	vertices.resize(8);
	vertices[0].x = -tam; vertices[0].y = 0; vertices[0].z = tam;
	vertices[1].x = tam; vertices[1].y = 0; vertices[1].z = tam;
	vertices[2].x = tam; vertices[2].y = 0; vertices[2].z = -tam;
	vertices[3].x = -tam; vertices[3].y = 0; vertices[3].z = -tam;

	vertices[4].x = -tam2; vertices[4].y = altura; vertices[4].z = tam2;
	vertices[5].x = tam2; vertices[5].y = altura; vertices[5].z = tam2;
	vertices[6].x = tam2; vertices[6].y = altura; vertices[6].z = -tam2;
	vertices[7].x = -tam2; vertices[7].y = altura; vertices[7].z = -tam2;


	caras.resize(16);
	//Frente
	caras[0]._0 = 0; caras[0]._1 = 1; caras[0]._2 = 4;
	caras[1]._0 = 1; caras[1]._1 = 5; caras[1]._2 = 4;
	//Derecha
	caras[2]._0 = 1; caras[2]._1 = 2; caras[2]._2 = 5;
	caras[3]._0 = 2; caras[3]._1 = 6; caras[3]._2 = 5;
	//Izquierda
	caras[4]._0 = 3; caras[4]._1 = 0; caras[4]._2 = 7;
	caras[5]._0 = 0; caras[5]._1 = 4; caras[5]._2 = 7;
	//Detras
	caras[6]._0 = 7; caras[6]._1 = 6; caras[6]._2 = 2;
	caras[7]._0 = 7; caras[7]._1 = 2; caras[7]._2 = 3;
	//Arriba
	caras[8]._0 = 4; caras[8]._1 = 5; caras[8]._2 = 7;
	caras[9]._0 = 5; caras[9]._1 = 6; caras[9]._2 = 7;
	//Abajo
	caras[10]._0 = 0; caras[10]._1 = 3; caras[10]._2 = 2;
	caras[11]._0 = 0; caras[11]._1 = 2; caras[11]._2 = 1;

  inicializar_colores();

}
