

#include "objetos.h"
using namespace cimg_library;
using namespace std;
float size;
//Implementacion punto
/**************************************************************/
_puntos3D::_puntos3D(){}
void _puntos3D::draw_puntos(float r, float g, float b, int grosor){
	glColor3f(r,g,b);
	glPointSize(grosor);
	glBegin (GL_POINTS);
      for(int i=0; i<vertices.size();i++){
              glColor3f(r,g,b);
							glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);

      }
	glEnd ( );

}

_triangulos3D::_triangulos3D(){
	ambiente_difusa=_vertex4f(1.0,1.0,1.0,1.0);
	especular=_vertex4f(1.0,1.0,1.0,1.0);
	brillo=1;
}
void _triangulos3D::draw_aristas(float r, float g, float b, int grosor){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glLineWidth(grosor);
	glColor3f(r,g,b);
	glBegin (GL_TRIANGLES);
      for(int i=0; i<caras.size();i++){
      	    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
      }
	glEnd ( );
	glLineWidth(1);
}
void  _triangulos3D::draw_solido(float r, float g, float b){
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(r,g,b);
	glBegin (GL_TRIANGLES);
      for(int i=0; i<caras.size();i++){
      	  	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
      }
	glEnd ( );
}


void  _triangulos3D::draw_solido_colores(){
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glShadeModel(GL_SMOOTH);
  glBegin (GL_TRIANGLES);
      for(int i=0; i<caras.size();i++){
            glColor3f(colores[caras[i]._0].r,colores[caras[i]._0].g,colores[caras[i]._0].b);
            glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
            glColor3f(colores[caras[i]._1].r,colores[caras[i]._1].g,colores[caras[i]._1].b);
            glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
            glColor3f(colores[caras[i]._2].r,colores[caras[i]._2].g,colores[caras[i]._2].b);
            glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
      }
  glEnd ( );
  glShadeModel( GL_FLAT);
}



void  _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin (GL_TRIANGLES);
      for(int i=0; i<caras.size();i++){
      	if(i%2!=0)
      		glColor3f(r1,g1,b1);
      	else
      		glColor3f(r2,g2,b2);
      	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
      }
	glEnd ( );
}



_cubo::_cubo(float tam){

  vertices.resize(8);
  vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
  vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
  vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=-tam;
  vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=-tam;
  vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
  vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
  vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=tam;
  vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=tam;

  caras.resize(12);
  caras[0]._0=3;caras[0]._1=4;caras[0]._2=0;
  caras[1]._0=3;caras[1]._1=0;caras[1]._2=7;
  caras[2]._0=2;caras[2]._1=5;caras[2]._2=1;
  caras[3]._0=2;caras[3]._1=1;caras[3]._2=6;
  caras[4]._0=2;caras[4]._1=5;caras[4]._2=4;
  caras[5]._0=2;caras[5]._1=4;caras[5]._2=3;
  caras[6]._0=7;caras[6]._1=0;caras[6]._2=1;
  caras[7]._0=7;caras[7]._1=1;caras[7]._2=6;
  caras[8]._0=2;caras[8]._1=3;caras[8]._2=7;
  caras[9]._0=2;caras[9]._1=7;caras[9]._2=6;
  caras[10]._0=5;caras[10]._1=4;caras[10]._2=0;
  caras[11]._0=5;caras[11]._1=0;caras[11]._2=1;

  colores.resize(8);
  colores[0].r=0.0;colores[0].g=0.2;colores[0].b=0.4;
  colores[1].r=0.2;colores[1].g=0.8;colores[1].b=0.6;
  colores[2].r=0.3;colores[2].g=0.3;colores[2].b=0.3;
  colores[3].r=0.5;colores[3].g=0.5;colores[3].b=0.8;
  colores[4].r=0.6;colores[4].g=0.9;colores[4].b=0.2;
  colores[5].r=0.8;colores[5].g=0.2;colores[5].b=0.7;
  colores[6].r=0.3;colores[6].g=0.4;colores[6].b=0.2;
  colores[7].r=0.5;colores[7].g=0.8;colores[7].b=0.8;

}

_piramide::_piramide(float tam, float al){
  vertices.resize(5);
  vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
  vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
  vertices[2].x=tam;vertices[2].y=-tam;vertices[2].z=-tam;
  vertices[3].x=-tam;vertices[3].y=-tam;vertices[3].z=-tam;
  vertices[4].x= 0;vertices[4].y=al;vertices[4].z=0;

  colores.resize(5);
  colores[0].r=0;colores[0].g=0;colores[0].b=1;
  colores[1].r=1;colores[1].g=0;colores[1].b=0;
  colores[2].r=0;colores[2].g=1;colores[2].b=0;
  colores[3].r=0.5;colores[3].g=0.5;colores[3].b=0.8;
  colores[4].r=0;colores[4].g=0;colores[4].b=0;


  caras.resize(6);
  caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
  caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
  caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
  caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
  caras[4]._0=3;caras[4]._1=0;caras[4]._2=2;
  caras[5]._0=2;caras[5]._1=0;caras[5]._2=1;

}

_objeto_ply::_objeto_ply(){

}

void _objeto_ply::parametros(const char *filename){
	_file_ply File_ply;
	float color_r;
	float color_g;
	float color_b;
	if (File_ply.open((char *)filename)){
		File_ply.read(vertices, caras);
		std::cout << "File read correctly" << std::endl;
	}else
		std::cout << "File can't be opened" << std::endl;
	int n_ver=vertices.size();
	int n_car=caras.size();
	colores.resize(vertices.size());
	for(int i=0; i<vertices.size(); i++ ){
		color_r = static_cast <float> (rand() % 10)/10;
		color_g = static_cast <float>  (rand() % 10)/10;
		color_b = static_cast <float>  (rand() % 10)/10;
		colores[i].r=color_r;colores[i].g=color_g;colores[i].b=color_b;
	}
	printf ("Número de vertices %d número de caras %d \n", n_ver, n_car);
}

//Revolucion
_revolucion::_revolucion(){

}





//Pasandole el numero de puntos  y dos puntos
void _revolucion::parametros(vector<_vertex3f> perfil, int num){
	int i,j;
	vector<_vertex3f> vertice_aux;
	vector<_vertex3i> caras_aux;
	caras_aux.resize(1);
	vertice_aux.resize(1);
	int n_aux;
	int n_vertices;
	float color_r;
	float color_g;
	float color_b;
	n_aux=perfil.size();
	vertices.resize(n_aux*num);
	int pos_inferior;
	int pos_superior;
	//Vertices
	for(j=0; j<num ; j++){
		for(i=0; i<n_aux ;i++){
				vertice_aux[0].x=perfil[i].x*cos(2.0*M_PI*j/(num*1.0))+perfil[i].z*sin(2.0*M_PI*j/(num*1.0));
				vertice_aux[0].y=perfil[i].y;
				vertice_aux[0].z=perfil[i].z*cos(2.0*M_PI*j/(num*1.0))-perfil[i].x*sin(2.0*M_PI*j/(num*1.0));
				vertices[i+j*n_aux]=vertice_aux[0];

		}
	}

/*******************************************************************************/
//Cuerpo
/**********************************************************************************/
pos_inferior=n_aux-1;
pos_superior=n_aux;
int tam_vertices_cuerpo=vertices.size();
for(int j=1; j<=pos_inferior; j++){ //Recorro los niveles de la figura
		int elemento_inicial=1*j;
		for(i=1*j; i<tam_vertices_cuerpo ;i+=n_aux){	//Recorro los vertices superiores de cada nivel
				//Grabo el triangulo inferior de la cara
				caras_aux[0]._0=i;
				caras_aux[0]._1=i-1;
				caras_aux[0]._2=(i+pos_inferior)%tam_vertices_cuerpo;
				caras.push_back(caras_aux[0]);
				//Grabo el triangulo superior de la cara
				caras_aux[0]._0=i;
				caras_aux[0]._1=(i+pos_inferior)%tam_vertices_cuerpo;
				caras_aux[0]._2=(i+pos_superior)%tam_vertices_cuerpo;
				caras.push_back(caras_aux[0]);
		}
	}

//******************************************************************************
//Tapa inferior
//******************************************************************************
vertice_aux[0].x=0.0;
vertice_aux[0].y=perfil[0].y;
vertice_aux[0].z=0.0;
vertices.push_back(vertice_aux[0]);
int tam_vertices_tapa_inferior=vertices.size();
caras_aux[0]._2=tam_vertices_tapa_inferior-1;//Para no añadir el mismo punto en el for
for(i=0; i<tam_vertices_tapa_inferior-1 ;i+=n_aux){
	caras_aux[0]._0=i;
	if (i+n_aux==tam_vertices_tapa_inferior-1)
		caras_aux[0]._1=0;
	else
		caras_aux[0]._1=i+n_aux;
	caras.push_back(caras_aux[0]);
}

//******************************************************************************
//Tapa superior
//******************************************************************************
vertice_aux[0].x=0.0;
vertice_aux[0].y=perfil[pos_inferior].y;
vertice_aux[0].z=0.0;
vertices.push_back(vertice_aux[0]);
int tam_vertices_tapa_superior=vertices.size();
int inicio=1*(pos_inferior);
caras_aux[0]._2=tam_vertices_tapa_superior-1;//Para no añadir el mismo punto en el for
for(i=inicio; i<tam_vertices_tapa_superior ;i+=n_aux){
	caras_aux[0]._0=i;
	if (i+pos_inferior>=tam_vertices_tapa_superior-1)
		caras_aux[0]._1=inicio;
	else
		caras_aux[0]._1=i+n_aux;
		caras.push_back(caras_aux[0]);


}
		//Colores
		colores.resize(vertices.size());
		for(int i=0; i<vertices.size(); i++ ){
			color_r = static_cast <float> (rand() % 10)/10;
			color_g = static_cast <float>  (rand() % 10)/10;
			color_b = static_cast <float>  (rand() % 10)/10;
			colores[i].r=color_r;colores[i].g=color_g;colores[i].b=color_b;
		}


}

void _revolucion::parametros(const char *filename, int num){
	int i,j;
	_file_ply File_ply;
	vector<_vertex3f> perfil;
	vector<_vertex3f> vertice_aux;
	vector<_vertex3i> caras_aux;
	if (File_ply.open((char *)filename)){
		File_ply.read(perfil, caras_aux);
		std::cout << "File read correctly" << std::endl;
	}else
		std::cout << "File can't be opened" << std::endl;
	caras_aux.resize(1);
	vertice_aux.resize(1);
	int n_aux;
	int n_vertices;
	float color_r;
	float color_g;
	float color_b;
	n_aux=perfil.size();
	vertices.resize(n_aux*num);
	int pos_inferior;
	int pos_superior;
	//Vertices
	for(j=0; j<num ; j++){
		for(i=0; i<n_aux ;i++){
				vertice_aux[0].x=perfil[i].x*cos(2.0*M_PI*j/(num*1.0))+perfil[i].z*sin(2.0*M_PI*j/(num*1.0));
				vertice_aux[0].y=perfil[i].y;
				vertice_aux[0].z=perfil[i].z*cos(2.0*M_PI*j/(num*1.0))-perfil[i].x*sin(2.0*M_PI*j/(num*1.0));
				vertices[i+j*n_aux]=vertice_aux[0];
}
		}
		/*******************************************************************************/
		//Cuerpo
		/**********************************************************************************/
		pos_inferior=n_aux-1;
		pos_superior=n_aux;
		int tam_vertices_cuerpo=vertices.size();
		for(int j=1; j<n_aux; j++){ //Recorro los niveles de la figura
				int elemento_inicial=1*j;
				for(i=1*j; i<tam_vertices_cuerpo ;i+=n_aux){	//Recorro los vertices superiores de cada nivel
						//Grabo el triangulo inferior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=i-1;
						caras_aux[0]._2=(i+pos_inferior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
						//Grabo el triangulo superior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=(i+pos_inferior)%tam_vertices_cuerpo;
						caras_aux[0]._2=(i+pos_superior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
				}
			}

		//******************************************************************************
		//Tapa inferior
		//******************************************************************************
		vertice_aux[0].x=0.0;
		vertice_aux[0].y=perfil[0].y;
		vertice_aux[0].z=0.0;
		vertices.push_back(vertice_aux[0]);
		int tam_vertices_tapa_inferior=vertices.size();
		caras_aux[0]._2=tam_vertices_tapa_inferior-1;//Para no añadir el mismo punto en el for
		for(i=0; i<tam_vertices_tapa_inferior-1 ;i+=n_aux){
			caras_aux[0]._0=i;
			if (i+n_aux==tam_vertices_tapa_inferior-1)
				caras_aux[0]._1=0;
			else
				caras_aux[0]._1=i+n_aux;
			caras.push_back(caras_aux[0]);
		}

		//******************************************************************************
		//Tapa superior
		//******************************************************************************
		vertice_aux[0].x=0.0;
		vertice_aux[0].y=perfil[pos_inferior].y;
		vertice_aux[0].z=0.0;
		vertices.push_back(vertice_aux[0]);
		int tam_vertices_tapa_superior=vertices.size();
		int inicio=1*(pos_inferior);
		caras_aux[0]._2=tam_vertices_tapa_superior-1;//Para no añadir el mismo punto en el for
		for(i=inicio; i<tam_vertices_tapa_superior ;i+=n_aux){
			caras_aux[0]._0=i;
			if (i+pos_inferior>=tam_vertices_tapa_superior-1)
				caras_aux[0]._1=inicio;
			else
				caras_aux[0]._1=i+n_aux;
				caras.push_back(caras_aux[0]);

		}
				//Colores
				colores.resize(vertices.size());
				for(int i=0; i<vertices.size(); i++ ){
					color_r = static_cast <float> (rand() % 10)/10;
					color_g = static_cast <float>  (rand() % 10)/10;
					color_b = static_cast <float>  (rand() % 10)/10;
					colores[i].r=color_r;colores[i].g=color_g;colores[i].b=color_b;
				}
}


void _revolucion::parametros_giro_x(vector<_vertex3f> perfil, int num){
	int i,j;
	_file_ply File_ply;
	vector<_vertex3f> vertice_aux;
	vector<_vertex3i> caras_aux;
	caras_aux.resize(1);
	vertice_aux.resize(1);
	int n_aux;
	int n_vertices;
	float color_r;
	float color_g;
	float color_b;
	n_aux=perfil.size();
	vertices.resize(n_aux*num);
	int pos_inferior;
	int pos_superior;
	//Vertices
	for(j=0; j<num ; j++){
		for(i=0; i<n_aux ;i++){
				vertice_aux[0].x=perfil[i].x;
				vertice_aux[0].y=perfil[i].y*cos(2.0*M_PI*j/(num*1.0))-perfil[i].z*sin(2.0*M_PI*j/(num*1.0));
				vertice_aux[0].z=perfil[i].z*cos(2.0*M_PI*j/(num*1.0))+perfil[i].y*sin(2.0*M_PI*j/(num*1.0));
				vertices[i+j*n_aux]=vertice_aux[0];
				//cout << vertice_aux[0].x <<" " <<vertice_aux[0].y <<" "<< vertice_aux[0].z<< endl;
}
		}
		/*******************************************************************************/
		//Cuerpo
		/**********************************************************************************/
		pos_inferior=n_aux-1;
		pos_superior=n_aux;
		int tam_vertices_cuerpo=vertices.size();

		for(int j=1; j<n_aux; j++){ //Recorro los niveles de la figura
				int elemento_inicial=1*j;
				for(i=1*j; i<tam_vertices_cuerpo ;i+=n_aux){	//Recorro los vertices superiores de cada nivel
						//Grabo el triangulo inferior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=i-1;
						caras_aux[0]._2=(i+pos_inferior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
						//Grabo el triangulo superior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=(i+pos_inferior)%tam_vertices_cuerpo;
						caras_aux[0]._2=(i+pos_superior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
				}
			}

			//******************************************************************************
			//Tapa inferior
			//******************************************************************************
			vertice_aux[0].x=perfil[0].x;
			vertice_aux[0].y=0.0;
			vertice_aux[0].z=0.0;
			vertices.push_back(vertice_aux[0]);
			int tam_vertices_tapa_inferior=vertices.size();
			caras_aux[0]._2=tam_vertices_tapa_inferior-1;//Para no añadir el mismo punto en el for
			for(i=0; i<tam_vertices_tapa_inferior-1 ;i+=n_aux){
				caras_aux[0]._0=i;
				if (i+n_aux==tam_vertices_tapa_inferior-1)
					caras_aux[0]._1=0;
				else
					caras_aux[0]._1=i+n_aux;
				caras.push_back(caras_aux[0]);
			}
			//******************************************************************************
			//Tapa superior
			//******************************************************************************
			vertice_aux[0].x=perfil[pos_inferior].x;
			vertice_aux[0].y=0.0;
			vertice_aux[0].z=0.0;
			vertices.push_back(vertice_aux[0]);
			int tam_vertices_tapa_superior=vertices.size();
			int inicio=1*(pos_inferior);
			caras_aux[0]._2=tam_vertices_tapa_superior-1;//Para no añadir el mismo punto en el for
			for(i=inicio; i<tam_vertices_tapa_superior ;i+=n_aux){
				caras_aux[0]._0=i;
				if (i+pos_inferior>=tam_vertices_tapa_superior-1)
					caras_aux[0]._1=inicio;
				else
					caras_aux[0]._1=i+n_aux;
					caras.push_back(caras_aux[0]);

			}

				//Colores
				colores.resize(vertices.size());
				for(int i=0; i<vertices.size(); i++ ){
					color_r = static_cast <float> (rand() % 10)/10;
					color_g = static_cast <float>  (rand() % 10)/10;
					color_b = static_cast <float>  (rand() % 10)/10;
					colores[i].r=color_r;colores[i].g=color_g;colores[i].b=color_b;
				}
}



void _revolucion::parametros_sin_tapas(const char *filename, int num){
	int i,j;
	_file_ply File_ply;
	vector<_vertex3f> perfil;
	vector<_vertex3f> vertice_aux;
	vector<_vertex3i> caras_aux;
	if (File_ply.open((char *)filename)){
		File_ply.read(perfil, caras_aux);
		std::cout << "File read correctly" << std::endl;
	}else
		std::cout << "File can't be opened" << std::endl;
	caras_aux.resize(1);
	vertice_aux.resize(1);
	int n_aux;
	int n_vertices;
	float color_r;
	float color_g;
	float color_b;
	n_aux=perfil.size();
	vertices.resize(n_aux*num);
	int pos_inferior;
	int pos_superior;
	//Vertices
	for(j=0; j<num ; j++){
		for(i=0; i<n_aux ;i++){
				vertice_aux[0].x=perfil[i].x*cos(2.0*M_PI*j/(num*1.0))+perfil[i].z*sin(2.0*M_PI*j/(num*1.0));
				vertice_aux[0].y=perfil[i].y;
				vertice_aux[0].z=perfil[i].z*cos(2.0*M_PI*j/(num*1.0))-perfil[i].x*sin(2.0*M_PI*j/(num*1.0));
				vertices[i+j*n_aux]=vertice_aux[0];
}
		}
		/*******************************************************************************/
		//Cuerpo
		/**********************************************************************************/
		pos_inferior=n_aux-1;
		pos_superior=n_aux;
		int tam_vertices_cuerpo=vertices.size();
		for(int j=1; j<n_aux; j++){ //Recorro los niveles de la figura
				int elemento_inicial=1*j;
				for(i=1*j; i<tam_vertices_cuerpo ;i+=n_aux){	//Recorro los vertices superiores de cada nivel
						//Grabo el triangulo inferior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=i-1;
						caras_aux[0]._2=(i+pos_inferior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
						//Grabo el triangulo superior de la cara
						caras_aux[0]._0=i;
						caras_aux[0]._1=(i+pos_inferior)%tam_vertices_cuerpo;
						caras_aux[0]._2=(i+pos_superior)%tam_vertices_cuerpo;
						caras.push_back(caras_aux[0]);
				}
			}
		}


		void circle (GLfloat radio, GLfloat cx, GLfloat cy, GLfloat cz, GLint n)
		{
			int i;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin( GL_POLYGON );
				for (i=0;i<n;i++){
					glVertex3f( cx+radio*cos(2.0*M_PI*i/n),cy+radio*sin(2.0*M_PI*i/n), cz);
				}
			glEnd();
		}



////////////////////////////ILUMINACION/////////////////////////////////////////

void _triangulos3D::calcular_normales_caras(){
	_vertex3f v1, v2, p_vect;
	vector<pair<_vertex3f,_vertex3f> > v_aux2(caras.size());
	float modulo;
	normales_caras.resize(caras.size());
	for (int i=0; i<caras.size();i++){
		v1 = vertices[caras[i]._1] - vertices[caras[i]._0];
		v2 = vertices[caras[i]._2] - vertices[caras[i]._0];
		p_vect = v1.cross_product(v2);

		modulo = sqrt(p_vect.x*p_vect.x + p_vect.y*p_vect.y + p_vect.z*p_vect.z);
		normales_caras[i] = _vertex3f(p_vect.x/modulo, p_vect.y/modulo, p_vect.z/modulo);

		// Calculo centroide
		v_aux2[i].first.x = (vertices[caras[i]._0].x + vertices[caras[i]._1].x + vertices[caras[i]._2].x)/3;
		v_aux2[i].first.y = (vertices[caras[i]._0].y + vertices[caras[i]._1].y + vertices[caras[i]._2].y)/3;
		v_aux2[i].first.z = (vertices[caras[i]._0].z + vertices[caras[i]._1].z + vertices[caras[i]._2].z)/3;
		// Calculo punto que pase por la normal y el centroide
		v_aux2[i].second.x = v_aux2[i].first.x + 0.5*normales_caras[i].x;
		v_aux2[i].second.y = v_aux2[i].first.y + 0.5*normales_caras[i].y;
		v_aux2[i].second.z = v_aux2[i].first.z + 0.5*normales_caras[i].z;
	}
	b_normales_caras=true;
	normales_caras_dibujados = v_aux2;
}

void _triangulos3D::calcular_normales_vertices(){
	_vertex3f aux(0,0,0);   // vertex nulo (posicionado en el origen)
	pair<_vertex3f,_vertex3f> aux2; aux2.first = aux; aux2.second = aux;

  normales_vertices.resize(vertices.size());
  vector<pair<_vertex3f,_vertex3f> > v_aux2(vertices.size());

  if (b_normales_caras == false)
	  calcular_normales_caras();

  for (int i=0; i<vertices.size(); i++){
	  normales_vertices[i].x = 0.0;
	  normales_vertices[i].y = 0.0;
	  normales_vertices[i].z = 0.0;
  }

  for (int i=0; i<caras.size(); i++){
	  normales_vertices[caras[i]._0] += normales_caras[i];
	  normales_vertices[caras[i]._1] += normales_caras[i];
	  normales_vertices[caras[i]._2] += normales_caras[i];
  }

  for(int i=0; i<vertices.size(); i++){
		normales_vertices[i].normalize();
		// Calculo centroide, en caso de los puntos, el propio punto
		v_aux2[i].first.x = vertices[i].x;
		v_aux2[i].first.y = vertices[i].y;
		v_aux2[i].first.z = vertices[i].z;
		// Calculo punto que pase por la normal y el centroide
		v_aux2[i].second.x = v_aux2[i].first.x + 0.5*normales_vertices[i].x;
		v_aux2[i].second.y = v_aux2[i].first.y + 0.5*normales_vertices[i].y;
		v_aux2[i].second.z = v_aux2[i].first.z + 0.5*normales_vertices[i].z;
  }
  b_normales_vertices=true;
  normales_vertices_dibujados = v_aux2;
}
void _triangulos3D::draw_normales_caras() {
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
    for(unsigned int i=0;i< normales_caras_dibujados.size();i++){
        glVertex3f(normales_caras_dibujados[i].first.x, normales_caras_dibujados[i].first.y, normales_caras_dibujados[i].first.z);
        glVertex3f(normales_caras_dibujados[i].second.x, normales_caras_dibujados[i].second.y, normales_caras_dibujados[i].second.z);
    }
    glEnd();
}

void _triangulos3D::draw_normales_vertices() {
    glColor3f(0.5,0.5,1);
    glBegin(GL_LINES);
    for(unsigned int i=0;i< normales_vertices_dibujados.size();i++){
        glVertex3f(normales_vertices_dibujados[i].first.x, normales_vertices_dibujados[i].first.y, normales_vertices_dibujados[i].first.z);
        glVertex3f(normales_vertices_dibujados[i].second.x, normales_vertices_dibujados[i].second.y, normales_vertices_dibujados[i].second.z);
    }
    glEnd();
}
void _triangulos3D::draw_iluminacion_plana(){
	ambiente_difusa=_vertex4f(1.0,0.4,0.8,0.0);
	especular=_vertex4f(0.7,0.7,0.7,1.0);
	GLfloat ambient_component[4]={1,1,1,1};
	brillo=20;
	if (b_normales_caras==false)
		calcular_normales_vertices();
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glShadeModel(GL_FLAT);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable (GL_NORMALIZE);

	//Material
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,(GLfloat *) &ambiente_difusa);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,(GLfloat *) &especular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for (int i=0;i<caras.size();i++){
			glNormal3fv((GLfloat *) &normales_caras[i]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);

	}
	glEnd();
	glDisable(GL_LIGHTING);
}

void _triangulos3D::draw_iluminacion_suave(){
	ambiente_difusa=_vertex4f(1.0,0.4,0.8,0.0);
	 especular=_vertex4f(0.7,0.7,0.7,1.0);
	 brillo=10;
	 GLfloat ambient_component[4]={1,1,1,1};
	if (b_normales_vertices==false)
		calcular_normales_vertices();
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glShadeModel(GL_SMOOTH);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable (GL_NORMALIZE);

	//Material
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,(GLfloat *) &ambiente_difusa);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,(GLfloat *) &especular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for (int i=0;i<caras.size();i++){
			glNormal3fv((GLfloat *) &normales_vertices[caras[i]._0]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
			glNormal3fv((GLfloat *) &normales_vertices[caras[i]._1]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
			glNormal3fv((GLfloat *) &normales_vertices[caras[i]._2]);
			glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
	glDisable(GL_LIGHTING);
}

//***********************************************************
// Textura
//*********************************************************
//***************************************************************************
// Textura
//***************************************************************************
_texture::_texture(){}

_texture::_texture(const char *nombreImagen){
	std::vector<unsigned char> data;

   CImg<unsigned char> logo;
   logo.load(nombreImagen);

   // empaquetamos bien los datos
   for (long y = 0; y < logo.height(); y ++)
      for (long x = 0; x < logo.width(); x ++)
      {
	 unsigned char *r = logo.data(x, y, 0, 0);
	 unsigned char *g = logo.data(x, y, 0, 1);
	 unsigned char *b = logo.data(x, y, 0, 2);
	 data.push_back(*r);
	 data.push_back(*g);
	 data.push_back(*b);
      }

   glGenTextures(1, &ident_textura);
   //glBindTexture(GL_TEXTURE_2D, ident_textura);

   // TRASFIERE LOS DATOS A GPU
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, logo.width(), logo.height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);;

}

void _triangulos3D::draw_textura(float r, float g, float b,GLuint ident_textura){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,ident_textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(1.0,1.0,1.0);
	glBegin (GL_TRIANGLES);
      for(int i=0; i<caras.size();i++){
      		if((caras[i]._0!=3 && caras[i]._1!=4 && caras[i]._2!=0) || (caras[i]._0!=3 && caras[i]._1!=0 && caras[i]._2!=7)){
      	  	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
    	}
      }
    glNormal3f( 0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3fv((GLfloat *) &vertices[3]);
	glTexCoord2f(0.0, 0.0);
	glVertex3fv((GLfloat *) &vertices[4]);
	glTexCoord2f(1.0, 0.0);
	glVertex3fv( (GLfloat *) &vertices[0]);
	glTexCoord2f(0.0, 1.0);
	glVertex3fv((GLfloat *) &vertices[3]);
	glTexCoord2f(1.0, 0.0);
	glVertex3fv( (GLfloat *) &vertices[0]);
	glTexCoord2f(1.0, 1.0);
	glVertex3fv((GLfloat *) &vertices[7]);
	glEnd ( );
	glDisable(GL_TEXTURE_2D);
}



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
  
  
  