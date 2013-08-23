//Header file inclusions
#include <GL/glut.h>
#include <stdio.h>

#include "Globals.h"
#include "Vertpos.h"
#include "Texts.h"
#include "Textures.h"
#include "Drawfunc.h"
#include "Disppages.h"
#include "Playfunc.h"
#include "Events.h"

//Makes the image into a texture, and returns the id of the texture
GLuint loadtexture(Image* image) 
{
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

//Load appropriate images
void callimageload()
{
	//Page backgrounds
	Image *spimage = loadBMP("Images/sback.bmp");
	Image *ppimage = loadBMP("Images/pback.bmp");
	Image *colpimage = loadBMP("Images/colback.bmp");
	Image *wpimage = loadBMP("Images/wback.bmp");
	spid = loadtexture(spimage);
	ppid = loadtexture(ppimage);
	colpid = loadtexture(colpimage);
	wpid = loadtexture(wpimage);

	//Buttons
	Image *stbtntimage = loadBMP("Images/stbtn.bmp");
	Image *rtbtntimage = loadBMP("Images/rtbtn.bmp");
	Image *qtbtntimage = loadBMP("Images/qtbtn.bmp");
	stbtntid = loadtexture(stbtntimage);
	rtbtntid = loadtexture(rtbtntimage);
	qtbtntid = loadtexture(qtbtntimage);

	//Objects
	Image *ctimage = loadBMP("Images/crete.bmp");
	Image *ttimage = loadBMP("Images/timer.bmp");
	Image *rtimage = loadBMP("Images/rome.bmp");
	Image *hwtimage = loadBMP("Images/hwall.bmp");
	Image *vwtimage = loadBMP("Images/vwall.bmp");
	ctid = loadtexture(ctimage);
	ttid = loadtexture(ttimage);
	rtid = loadtexture(rtimage);
	hwtid = loadtexture(hwtimage);
	vwtid = loadtexture(vwtimage);
}

//Intialize the rendering
void render()
{
	//Enable features
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Set light source properties
	GLfloat lightIntensity[] = {0.75, 0.75, 0.77, 1.0};
	GLfloat light_position[] = {1.0, 1.0, 5.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glLineWidth(3.0);
}

//Main function
void main(int argc, char** argv)
{
	//Initialize GLUT and window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 100);
	glutCreateWindow("IKAROS - Escape from Crete");

	//Initialize rendering
	render();
	callimageload();

	//Set handler functions
	glutReshapeFunc(redraw);
	glutDisplayFunc(draw);
	glutKeyboardFunc(key);
	glutMouseFunc(mouse);
	glutTimerFunc(move_timer, move, 0);

	printf ("Thank You for playing Ikaros\n");
	printf ("Hope you enjoyed playing it as much as we did developing it!!\n\n");
	printf ("Thanks and Regards,\n");
	printf ("Deepak AR and shashank Kumar Sharma\n");
	printf ("VI CS A, Sir MVIT\n");
	
	glutMainLoop();
}