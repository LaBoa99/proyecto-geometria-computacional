#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include <iostream>
#include <cmath>
#include <vector>

#include <sprite.h>

using namespace std;

unsigned const int WIDTH = 800;
unsigned const int HEIGHT = 800;


float lastTime = 0;
float second = 0;
clock_t current_ticks;

// Tetris
vector<Sprite*> things;

void init(){

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw Things
    // EJemplo de fondo
    glColor3f(0.46, 0.9, 1.0);
    glBegin(GL_QUADS);
        glVertex2d(0, 0);
        glVertex2d(0, 1);
        glVertex2d(1, 1);
        glVertex2d(1, 0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void idle(){
    double currentTime = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (currentTime - lastTime) / 1000.0;
    lastTime = currentTime;
    // Funcion de update;
    if(second >= 1){
        cout << second << endl;
        second = 0;
    }
    second += deltaTime;
    glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Con esta linea solo se hace uso de las coordenadas positivas
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

// Función principal
int main(int argc, char** argv) {


    // Inicializar GLUT y crear una ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Proyecto Geometria Computacional");

    // Registrar las funciones de retroalimentación de eventos
    init();
    glutDisplayFunc(display);

    //glutMotionFunc(onMouseMotion);
    //glutPassiveMotionFunc(onMouseMotion);
    //glutKeyboardFunc(onKeyboard);
    //glutMouseFunc(onMouse);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    // Configurar el color de fondo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Iniciar el ciclo de eventos de GLUT
    glutMainLoop();
    return 0;
}
// run with
// -lfreeglut -lsoil  -lglew32 -lopengl32 -lglu32
