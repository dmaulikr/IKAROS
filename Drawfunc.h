//Line loop display function
void loop_disp(GLfloat pos[4][3])
{
	glColor3fv(black);
	glBegin(GL_LINE_LOOP);
		glVertex3fv(pos[0]);
		glVertex3fv(pos[1]);
		glVertex3fv(pos[2]);
		glVertex3fv(pos[3]);
	glEnd();
}

//Quad display function
void quad_disp(GLfloat pos[4][3], GLuint tid, GLfloat tpos[4][2])
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tid);
	//Blacky texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_QUADS);
		glTexCoord2fv(tpos[0]);
		glVertex3fv(pos[0]);
		glTexCoord2fv(tpos[1]);
		glVertex3fv(pos[1]);
		glTexCoord2fv(tpos[2]);
		glVertex3fv(pos[2]);
		glTexCoord2fv(tpos[3]);
		glVertex3fv(pos[3]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//Display ikaros
void ikarosdisp()
{
	glPushMatrix();
	glTranslatef(ikarosp[4][0], ikarosp[4][1], ikarosp[4][2]);
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(-ikarosp[4][0], -ikarosp[4][1], -ikarosp[4][2]);
	glBegin(GL_POLYGON);
		glColor3fv(blue);
		glVertex3fv(ikarosp[0]);
		glColor3fv(white);
		glVertex3fv(ikarosp[1]);
		glColor3fv(green);
		glVertex3fv(ikarosp[2]);
		glColor3fv(red);
		glVertex3fv(ikarosp[3]);
	glEnd();
	glColor3fv(black);
	loop_disp(ikarosp);
	glPopMatrix();
}

//Border draw function
void draw_border()
{
	loop_disp(rome);
	loop_disp(walla);
	loop_disp(walld);
	loop_disp(crete);
	glBegin(GL_LINE_LOOP);
		glVertex3fv(wallb1[0]);
		glVertex3fv(wallb1[1]);
		glVertex3fv(wallb2[0]);
		glVertex3fv(wallb2[1]);
		glVertex3fv(wallb2[2]);
		glVertex3fv(wallb2[3]);
		glVertex3fv(wallb1[2]);
		glVertex3fv(wallb3[3]);
		glVertex3fv(wallb3[0]);
		glVertex3fv(wallb3[1]);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3fv(wallc4[3]);
		glVertex3fv(wallc3[0]);
		glVertex3fv(wallc3[1]);
		glVertex3fv(wallc2[0]);
		glVertex3fv(wallc1[3]);
		glVertex3fv(wallc1[0]);
		glVertex3fv(wallc1[1]);
		glVertex3fv(wallc1[2]);
		glVertex3fv(wallc2[1]);
		glVertex3fv(wallc2[2]);
		glVertex3fv(wallc4[1]);
		glVertex3fv(wallc4[2]);
	glEnd();
}