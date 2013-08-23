//Redisplay handler function
void redraw(int w, int h)
{
	//Set the viewport position and size
	glViewport(0, 0, w, h);
	
	//Set the camera perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -25.0, 25.0);

	//Go back to model view matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

//Display handler function
void draw()
{	
	//Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Decide which page to display
	switch(pflag)
	{
		case 0: startpage();
				break;
		case 1: playpage();
				break;
		case 2: if(luck)
					collipage();
				else
				{
					pflag=3;
					glutPostRedisplay();
				}
				break;
		case 3: overpage();
				break;
		case 4: lazypage();
				break;
		case 5: winpage();
	}
	glutSwapBuffers();
}

//Keyboard handler function
void key(unsigned char key, int x, int y)
{    
	switch (key)
	{
		//key is g=left
		case 103: move_left();
				  theta=90.0;
				  break;

		//key is h=right
		case 104: move_right();
				  theta=-90.0;
				  break;

		//key is y=top
		case 121: move_top();
				  theta=0.0;
				  break;

		//key is b=down
		case 98: move_down();
				 theta=180.0;
				 break;

		//key is a=try again
		case 97: if(pflag==2) restart(1);
				 break;

	    //key is r=restart
		case 114: restart(0);
				  break;

		//key is s=start
		case 115: if(pflag==0) restart(0);
				  break;

		//key is q=quit
		case 113: exit(0);
	}

	if(theta>360.0) theta-=360.0;
	glutPostRedisplay();
}

//Mouse handler function
void mouse(int btn, int state, int x, int y) 
{
	GLint viewport[4], y1;
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			glGetIntegerv(GL_VIEWPORT, viewport);
			y1 = viewport[3] - (GLint)y - 1; //viewport[3]= window height
			switch (pflag)
			{
				case 0: if(x>125.0 && x<185.0 && y1>78.0 && y1<102.0)
							restart(0);
						else if(x>315.0 && x<375.0 && y1>78.0 && y1<102.0)
							exit(0);
						break;
				case 2: if(x>90.0 && x<170.0 && y1>142.0 && y1<166.0)
							restart(1);
						else if(x>210.0 && x<290.0 && y1>142.0 && y1<166.0)
							restart(0);
						else if(x>330.0 && x<410.0 && y1>142.0 && y1<166.0)
							exit(0);
						break;
				case 3:
				case 4:
				case 5: if(x>115.0 && x<195.0 && y1>130.0 && y1<154.0)
							restart(0);
						else if(x>305.0 && x<385.0 && y1>130.0 && y1<154.0)
							exit(0);
						break;
			}
	}
}

//Move objects after every move_timer milli seconds 
void move(int value) 
{
	//Decide if needed to move
	if(pflag==1)
	{
		for(int i=0; i<5; i++)
		for( int j=0; j<3; j++)
		{
			//Move ikaros
			ikarosp[i][j] += ikarosv[j];

			//Move Timer
			offset+=1.0;
			if(offset>10.0)
			{
				ikarosv[i] *=1.005;
				timerp[i][j] += timerv[j];
				offset=0.0;
			}
		}
		upregcode();
		collicheck();
	}

	//Redisplay
	glutPostRedisplay();
	glutTimerFunc(move_timer, move, 0);
}