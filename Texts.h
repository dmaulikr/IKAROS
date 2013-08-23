//Fonts
#define b9x15 GLUT_BITMAP_9_BY_15
#define b8x13 GLUT_BITMAP_8_BY_13
#define t10 GLUT_BITMAP_TIMES_ROMAN_10
#define t24 GLUT_BITMAP_TIMES_ROMAN_24
#define h18 GLUT_BITMAP_HELVETICA_18
#define h12 GLUT_BITMAP_HELVETICA_12
#define h10 GLUT_BITMAP_HELVETICA_10

char btn_text[][10] = {{"START"}, {"RETRY"}, {"RESTART"}, {"QUIT"}};
char luck_text[][10] = {{}, {"ONE"}, {"TWO"}, {"THREE"}};
char stat_text[][10] = {{"YOU LOST"}, {"YOU WON"}};
char res_text[][30] = {{"YOU FAILED TO HELP IKAROS"}, {"YOU HELPED IKAROS WIN"}};
char choose[50]="Press r/q to restart/quit or click below";
char names[][10] = {{"CRETE"}, {"ROME"}};

void textdisp(char *c, GLfloat *pos, void *font)
{
	glRasterPos3fv(pos);
	for(int i=0; c[i]!='\0'; i++)
		glutBitmapCharacter(font, c[i]);
}

//Startpage texts
char spage_text[][70] = {{"IKAROS - Escape from Crete"},
					{"     Long ago, the Roman prince Ikaros was a captive"},
					{"on the island prison of Crete. His attempts to escape"},
					{"failed. But now he has found a secret but dangerous"},
					{"maze of underground passages to Rome. If taken by"},
					{"surprise, Ikaros can defeat the emperor. Guide him"},
					{"to Rome before the prison guards reach there."},
					{"Use the keys g, h, y and b to move"}, 
					{"left, right, up and down respectively"},
					{"Mind the walls and race the guards to Rome"},
					{"Press s/q to start/quit or click below"}};

GLfloat spage_pos[][3]= {{100.0, 415.0, 0.0}, {40.0, 340.0, 0.0}, {40.0, 323.0, 0.0}, 
						{40.0, 306.0, 0.0}, {40.0, 289.0, 0.0}, 
						{40.0, 272.0, 0.0}, {40.0, 255.0, 0.0}, 
						{70.0, 214.0, 0.0}, {70.0, 197.0, 0.0}, 
						{70.0, 180.0, 0.0}, {80.0, 130.0, 0.0}, 
						{133.0, 85.0, 0.0}, {328.0, 85.0, 0.0}};

GLfloat spage_start_btn[4][3]= {{125.0, 78.0, -15.0}, {185.0, 78.0, -15.0}, 
						{185.0, 102.0, -15.0}, {125.0, 102.0, -15.0}};
GLfloat spage_quit_btn[4][3]= {{315.0, 78.0, -15.0}, {375.0, 78.0, -15.0}, 
						{375.0, 102.0, -15.0}, {315.0, 102.0, -15.0}};

//Playpage texts
GLfloat ppage_pos[][3]= {{6.0, 20.0, 0.0}, {458.0, 470.0, 0.0}};

//Collipage texts
char cpage_text[][50] = {{"Be carefull !!!"},
					{"There may be dangers lurking on the walls"},
					{"He gains speed as he moves"},
					{"Ikaros is hurt, but his luck can still"},
					{"save him "}, {" times"},
					{"Press a/r/q to retry/restart/quit or click below"}};

GLfloat cpage_pos[][3]= {{180.0, 380.0, 0.0}, {40.0, 300.0, 0.0}, {40.0, 283.0, 0.0},
						{40.0, 266.0, 0.0}, {40.0, 249.0, 0.0},
						{165.0, 249.0, 0.0}, {35.0, 200.0, 0.0},
						{120.0, 249.0, 0.0}, {108.0, 149.0, 0.0}, 
						{219.0, 149.0, 0.0}, {351.0, 149.0, 0.0}};

GLfloat cpage_retry_btn[4][3]= {{90.0, 142.0, -15.0}, {170.0, 142.0, -15.0}, 
						{170.0, 166.0, -15.0}, {90.0, 166.0, -15.0}};
GLfloat cpage_restart_btn[4][3]= {{210.0, 142.0, -15.0}, {290.0, 142.0, -15.0}, 
						{290.0, 166.0, -15.0}, {210.0, 166.0, -15.0}};
GLfloat cpage_quit_btn[4][3]= {{330.0, 142.0, -15.0}, {410.0, 142.0, -15.0}, 
						{410.0, 166.0, -15.0}, {330.0, 166.0, -15.0}};


//Overpage texts
char opage_text[50] = "Ikaros ran out of luck!!!"; 

GLfloat opage_pos[][3]= {{120.0, 360.0, 0.0}, {190.0, 290.0, 0.0},
						{155.0, 230.0, 0.0}, {80.0, 180.0, 0.0},
						{124.0, 137.0, 0.0}, {327.0, 137.0, 0.0}};

//Lazypage texts
char lpage_text[][45] = {{"The guards have reached Rome!!"},
					{"The emperor knows your coming"},
					{"You lose without the element of surprise"}};

GLfloat lpage_pos[][3]= {{75.0, 330.0, 0.0}, {75.0, 313.0, 0.0}, 
						{75.0, 296.0, 0.0}, {80.0, 183.0, 0.0},
						{120.0, 380.0, 0.0}, {190.0, 235.0, 0.0},
						{124.0, 137.0, 0.0}, {327.0, 137.0, 0.0}};

//Winpage texts
char wpage_text[][40] = {{"Ikaros reached Rome before the guards"},
					{"and defeated the emperor"},
					{"He is now the new emperor of Rome"}};

GLfloat wpage_pos[][3]= {{75.0, 330.0, 0.0}, {75.0, 313.0, 0.0}, 
						{75.0, 296.0, 0.0}, {80.0, 183.0, 0.0},
						{132.0, 380.0, 0.0}, {190.0, 235.0, 0.0},
						{124.0, 137.0, 0.0}, {327.0, 137.0, 0.0}};

//Buttons for over, lazy and win pages
GLfloat olwpage_restart_btn[4][3]= {{115.0, 130.0, -15.0}, {195.0, 130.0, -15.0}, 
						{195.0, 154.0, -15.0}, {115.0, 154.0, -15.0}};
GLfloat olwpage_quit_btn[4][3]= {{305.0, 130.0, -15.0}, {385.0, 130.0, -15.0}, 
						{385.0, 154.0, -15.0}, {305.0, 154.0, -15.0}};