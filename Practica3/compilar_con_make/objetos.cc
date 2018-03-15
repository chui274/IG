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
void _triangulos3D::draw_caras_aleatorias(){
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

  inicializar_colores();
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

_objeto_ply::_objeto_ply(){}

int _objeto_ply::parametros(char *archivo){
  int n_ver,n_car;
  vector<float> ver_ply;//Array de una dimension
  vector<int> car_ply;
  _file_ply objetos_ply;
  objetos_ply.open(archivo);
	objetos_ply.read(ver_ply, car_ply);

  n_ver = ver_ply.size()/3;//Suponemos que las caras son triangulos entonces, tenemos 3 vertices
  n_car = car_ply.size()/3;

  printf("Numero de vertices=%d\n Numero de caras=%d\n",n_ver,n_car);


  vertices.resize(n_ver);//Redimensionamos a una dimension para usar funcion read
  caras.resize(n_car);

  _vertex3f ver_aux;
  _vertex3i car_aux;

  for (int i = 0; i < n_ver; i++) {
    ver_aux.x=ver_ply[i*3];
    ver_aux.y=ver_ply[i*3+1];
    ver_aux.z=ver_ply[i*3+2];
    vertices[i]=ver_aux;
  }
  for (int i = 0; i < n_car; i++) {
    car_aux.x=car_ply[i*3];
    car_aux.y=car_ply[i*3+1];
    car_aux.z=car_ply[i*3+2];
    caras[i]=car_aux;
  }
  inicializar_colores();
}

_rotacion::_rotacion(){

}
void _rotacion::parametros(vector<_vertex3f> perfil1, int num1,bool hayTapa){

  perfil = perfil1;
  num = num1;
  int i, j, num_aux;
  _vertex3f vertice_aux, tapa_arriba, tapa_abajo;
  _vertex3i cara_aux, tapa_arriba_aux, tapa_abajo_aux;
  int v1, v2, v3, v4, v5, v6;


//Tratamiento de los vertices
  num_aux = perfil.size();
  for(int i = 0; i<num; i++){
    for(int j = 0; j<num_aux; j++){
      //Introducimos los vertices del perfil en el vector de vertices y Rotamos sobre Y
      vertice_aux.x = perfil[j].x*cos(2.0*M_PI*i/(1.0*num))-perfil[j].z*sin(2.0*M_PI*i/(1.0*num));
      vertice_aux.y = perfil[j].y;
      vertice_aux.z = perfil[j].x*sin(2.0*M_PI*i/(1.0*num))+perfil[j].z*cos(2.0*M_PI*i/(1.0*num));
      vertices.push_back(vertice_aux);
    }
  }

  //Tratamiento de las caras
  for(int i = 0; i < num_aux-1; i++){
    for(int j = 0; j < num-1; j++){
      v1 = i+j*num_aux;
      v2 = i+(j+1)*num_aux;
      v3 = (i+1)+j*num_aux;
      v4 = i+1+(j+1)*num_aux;

      cara_aux._0 = v1;
      cara_aux._1 = v2;
      cara_aux._2 = v3;
      caras.push_back(cara_aux);
      cara_aux._0 = v2;
      cara_aux._1 = v4;
      cara_aux._2 = v3;
      caras.push_back(cara_aux);
    }

    cara_aux._0 = v2;
    cara_aux._1 = i;
    cara_aux._2 = v4;
    caras.push_back(cara_aux);
    cara_aux._0 = v4;
    cara_aux._1 = i;
    cara_aux._2 = i+1;
    caras.push_back(cara_aux);
  }

  tapa_arriba.x = 0;
  tapa_arriba.y = perfil[0].y;
  tapa_arriba.z = 0;

  tapa_abajo.x = 0;
  tapa_abajo.y = perfil[perfil.size()-1].y;
  tapa_abajo.z = 0;

  vertices.push_back(tapa_arriba);
  vertices.push_back(tapa_abajo);


  //Tapa superior(tapa arriba)
  if(hayTapa){
  if (fabs(perfil[num_aux-1].x) > 0.0) {
  for(int i = 0; i < num; i++){
    v5 = i*num_aux;
    v6 = (i+1)*num_aux;
    tapa_arriba_aux._0 = v5;
    tapa_arriba_aux._1 = vertices.size()-2;
    tapa_arriba_aux._2 = v6;
    caras.push_back(tapa_arriba_aux);
  }

  tapa_arriba_aux._0 = v5;
  tapa_arriba_aux._1 = vertices.size()-2;
  tapa_arriba_aux._2 = 0;
  caras.push_back(tapa_arriba_aux);
  }
}
  //Tapa inferior(tapa abajo)
  if(hayTapa){
  if (fabs(perfil[0].x) > 0.0) {
  for(int i = 0; i < num; i++){
    v5 = num_aux*i-1;
    v6 = (num_aux*(i+1))-1;
    tapa_abajo_aux._0 = v6;
    tapa_abajo_aux._1 = vertices.size()-1;
    tapa_abajo_aux._2 = v5;
    caras.push_back(tapa_abajo_aux);
  }

  tapa_abajo_aux._0 = perfil.size()-1;
  tapa_abajo_aux._1 = vertices.size()-1;
  tapa_abajo_aux._2 = v6;
  caras.push_back(tapa_abajo_aux);
}
  }
  inicializar_colores();

}

//*************************************************************************
// clase minecraft
//*************************************************************************

_robot::_robot(){
  maximo_brazos = 25;
  minimo_brazos = -25;
  maximo_piernas = 15;
  minimo_piernas = -15;
  maximo_cabeza = 20;
  minimo_cabeza = -20;
  
  
  posicion.resize(5);
  posicion.at(0) = 0; // brazo derecho
  posicion.at(1) = 0; // brazo izquierdo
  posicion.at(2) = 0; // pierna derecha
  posicion.at(3) = 0; // pierna izquierda
  posicion.at(4) = 0; // cabeza
  
  cubo = new _cubo(0.5);
}

void _robot::draw_robot(int modo, float r1, float g1, float b1,
                                float r2, float g2, float b2) {
  if (modo == 1) {
    cubo->draw_puntos(r1, g1, b1, 3);
  } else if (modo == 2) {
    cubo->draw_aristas(r1, g1, b1, 3);
  } else if (modo == 3) {
    cubo->draw_solido(r1, g1, b1);
  } else if (modo == 4) {
    cubo->draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);
  }
}

void _robot::cuerpo(int modo, float r, float g, float b) {
  
  glPushMatrix();
  glTranslatef(0, 2, 0);
  glScalef(4, 4, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}

void _robot::brazo_derecho(int modo, float r, float g, float b) {
  glColor3f(r, g, b);

  glPushMatrix();
  glTranslatef(-2.5, 0.25, 0);
  glTranslatef(0, 1.75, 0);
  glRotatef(-posicion.at(0), 1, 0, 0);
  glTranslatef(0, -1.75, 0);
  
  glScalef(1, 4, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}

void _robot::mano_derecha(int modo, float r, float g, float b) {
  glPushMatrix();
  glTranslatef(0, -2.25, 0);
  glColor3f(r, g, b);
  glScalef(1, 1, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}



void _robot::mano_izquierda(int modo, float r, float g, float b) {
  glPushMatrix();
  glTranslatef(0, -2.25, 0);
  glColor3f(r, g, b);
  glScalef(1, 1, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}



void _robot::pie_derecho(int modo, float r, float g, float b) {
  glPushMatrix();
  glTranslatef(0, -2.75, 0);
  glColor3f(r, g, b);
  glScalef(1, 1, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}
void _robot::brazo_izquierdo(int modo, float r, float g, float b) {
  glColor3f(r, g, b);
  glPushMatrix();
  glTranslatef(2.5, 0.25, 0);
  glTranslatef(0, 1.75, 0);
  glRotatef(-posicion.at(1), 1, 0, 0);
  glTranslatef(0, -1.75, 0);
  glScalef(1, 4, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}

void _robot::pierna_izquierda(int modo, float r, float g, float b) {
  glColor3f(r, g, b);
  glPushMatrix();
  
  
  glRotatef(-posicion.at(3), 1, 0, 0);
  glTranslatef(1.5, -4.25/2, 0);
  
  glScalef(1, 4.25, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}
void _robot::pierna_derecha(int modo, float r, float g, float b) {
  glColor3f(r, g, b);
  glPushMatrix();
  glRotatef(-posicion.at(2), 1, 0, 0);
  glTranslatef(-1.5, -4.25/2, 0);
  
  glScalef(1, 4.25, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}
void _robot::pie_izquierdo(int modo, float r, float g, float b) {
  glPushMatrix();
  glTranslatef(0, -2.75, 0);
  glColor3f(r, g, b);
  glScalef(1, 1, 1);
  draw_robot(modo, r, g, b, 0, 0, 0);
  glPopMatrix();
}


void _robot::cabeza(int modo, float r, float g, float b) {
  glColor3f(r, g, b);
  
  glPushMatrix();
  glRotatef(-posicion.at(4), 0, 1, 0);
  glTranslatef(0, 5, 0);
  if (modo == 3 || modo == 4) {
    glutSolidCube(2);
    
  } else if (modo == 1 || modo == 2) {
    glutWireCube(2);
    
  }


  glPopMatrix();


  
}



void _robot::munieco(int modo) {
  glPushMatrix();
  glTranslatef(0.0, 0.0, 0.0);

  cuerpo(modo, 0, 1, 1);
  brazo_derecho(modo, 0, 42, 42);
  //mano_derecha(modo, 1, 1, 0);
  brazo_izquierdo(modo, 0, 42, 42);
  //mano_izquierda(modo, 1, 1, 0);
  pierna_derecha(modo, 0, 0, 42);
  //pie_derecho(modo, 0.3, 0.4, 0.4);
  pierna_izquierda(modo, 0, 0, 42);
  //pie_izquierdo(modo, 0.3, 0.4, 0.4);
  
  cabeza(modo, 1, 1, 0);
  
  glPopMatrix();
  glFlush();
}

void _robot::aumentar_brazos(int parte) {
  if (posicion.at(parte) < maximo_brazos) {
    posicion.at(parte) += 1;
  }
}

void _robot::disminuir_brazos(int parte) {
  if (posicion.at(parte) > minimo_brazos) {
    posicion.at(parte) -= 1;
  }
}

void _robot::aumentar_piernas(int parte) {
  if (posicion.at(parte) < maximo_piernas) {
    posicion.at(parte) += 1;
  }
}

void _robot::disminuir_piernas(int parte) {
  if (posicion.at(parte) > minimo_piernas) {
    posicion.at(parte) -= 1;
  }
}

void _robot::mover_cabeza_dcha(int parte) {
  if (posicion.at(parte) < maximo_cabeza) {
    posicion.at(parte) += 1;
  }
}

void _robot::mover_cabeza_izda(int parte) {
  if (posicion.at(parte) > minimo_cabeza) {
    posicion.at(parte) -= 1;
  }
}


