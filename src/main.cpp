#include "types.h"
#include "Engine.h"
#include "boxer.h"
#include <cstdlib>
#include <cstdlib>
#include <cstring>

extern Dirs sDir;
bool GAMEOVER = false;
int score = 0;


void message_callback(){}

void keyboard_callback(int key, int, int){
	switch(key){
	case GLUT_KEY_UP:
		if(sDir!=Dirs::DOWN)
			sDir = Dirs::UP;
		break;
	case GLUT_KEY_DOWN:
		if(sDir!=Dirs::UP)
			sDir = Dirs::DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if(sDir!=Dirs::LEFT)
			sDir = Dirs::RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if(sDir!=Dirs::RIGHT)
			sDir = Dirs::LEFT;
		break;
	}
}

void timer_callback(int){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer_callback, 0);
}

void display_callback(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if(GAMEOVER){
		glutOverlayDisplayFunc(message_callback);
		std::string S = "GAME OVER: Score " + std::to_string(score);
		boxer::show(S.c_str(),"GAMEOVER");
		exit(0);
	}
}
void reshape_callback(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, ROWS,0.0, COLUMNS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

// background color
void glInit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("SIMPLE SNAKE BY DAMOON");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0, timer_callback, 0);
	glutSpecialFunc(keyboard_callback);
	glInit();
	glutMainLoop();
	return 0;

}
