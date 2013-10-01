#include <stdlib.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

/* начальная ширина и высота окна */
GLint Width = 512, Height = 512;

/* размер куба */
const int CubeSize = 200;

/* эта функция управляет всем выводом на экран */
void Display(void)
{
	unsigned char data[32*32*4];

		for( int i=0; i< sizeof(data); ++i) data[i]=rand();
		// Don't forget to #include <stdlib.h>

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA , 32, 32, 0, GL_RGBA , GL_UNSIGNED_BYTE, (GLvoid *)data );
    glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;

    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

    if( key == ESCAPE )
        exit(0);
}

/* Главный цикл приложения */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("grot");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();
}