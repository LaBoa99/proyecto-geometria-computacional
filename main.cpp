#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include <iostream>
#include <cmath>
#include <vector>

#include "include/sprite.h"
#include "include/player.h"
#include "include/wall.h"
#include "include/utils.h"

using namespace std;

unsigned const int WIDTH = 800;
unsigned const int HEIGHT = 800;
unsigned int phase = 1;

float lastTime = 0;
float second = 0;
float seconds_passed = 0;
int millspassed = 0;
float degrees = 45;
clock_t current_ticks;

// Game opts
vector<Sprite*> things;
Player player;
// cada X segundos genera un nueva wall
unsigned int every_second_wall = 7;
unsigned int count_second_wall = 0;

void init(){
    things.push_back(new Wall());
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw Things
    // EJemplo de fondo
    // Se deja como rect si se quiere cambiar de color de manera no destructiva
    if(phase == 1)
        glColor3f(second, 0.5, 0.5);
    else if(phase == 2)
        glColor3f(1.0 - second, second, 0.5f);
    else if(phase == 3)
        glColor3f(second, 0.5f, second);
    else
        glColor3f(second, 0.5f, 1.0f - second);
    glBegin(GL_QUADS);
        glVertex2d(0, 0);
        glVertex2d(0, 1);
        glVertex2d(1, 1);
        glVertex2d(1, 0);
    glEnd();

    // Cosas
    glPushMatrix();
    glRotatef(degrees, 0, 0, -1.0);
    player.draw();
    for(Sprite* thing : things){
        thing->draw();
    }
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void idle(){
    double currentTime = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (currentTime - lastTime) / 1000.0;
    lastTime = currentTime;
    // Funcion de update;
    if(second >= 1){
        // Esto se puede aumatizar de mejor manera pero es temporal
        count_second_wall++;
        if(count_second_wall == every_second_wall){
            things.push_back(new Wall());
            count_second_wall = 0;
        }
        second = 0;
        seconds_passed++;
        phase += phase < 3 ? 1 : -3;
    }
    second += deltaTime;
    degrees = sin(second + seconds_passed);
    // Sprite* thing : things
    for(int i = 0; i < things.size(); i++){
        Sprite* thing = things[i];
        thing->update(deltaTime);
        // Nos deshacemos de los elementos no visibles y destructibles
        // Que no sea visible no signifca que tambien destructible
        if(thing->isDestructible){
            delete thing;
            things.erase(things.begin() + i);
            i--;
        }
    }
    cout << "Walls activas: " <<  things.size() << endl;
    player.update(deltaTime);
    glutPostRedisplay();
}

// EVENTS

void onMouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            player.jump();
        }
    }
    if(state == GLUT_UP){
        if(button == GLUT_LEFT_BUTTON){
           player.fall();
        }
    }
}

// END EVENTS

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
    glutMouseFunc(onMouse);
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
