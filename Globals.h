//Global Variables
GLfloat offset=0.0, move_timer=25.0, theta;
GLuint regcode, pflag, luck=3;

//Texture ids
GLuint spid, ppid, colpid, wpid, stbtntid, rtbtntid, qtbtntid, rtid, ttid, ctid, hwtid, vwtid;

//Texture types
GLfloat single[4][2]={{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}};
GLfloat ver20[4][2]={{0.0, 0.0}, {1.0, 0.0}, {1.0, 20.0}, {0.0, 20.0}};
GLfloat hor4[4][2]={{0.0, 0.0}, {4.0, 0.0}, {4.0, 1.0}, {0.0, 1.0}};
GLfloat hor3_75[4][2]={{0.0, 0.0}, {3.75, 0.0}, {3.75, 1.0}, {0.0, 1.0}};
GLfloat hor7_75[4][2]={{0.0, 0.0}, {7.75, 0.0}, {7.75, 1.0}, {0.0, 1.0}};
GLfloat ver10[4][2]={{0.0, 0.0}, {1.0, 0.0}, {1.0, 10.0}, {0.0, 10.0}};
GLfloat hor6_5[4][2]={{0.0, 0.0}, {6.5, 0.0}, {6.5, 1.0}, {0.0, 1.0}};
GLfloat ver9_5[4][2]={{0.0, 0.0}, {1.0, 0.0}, {1.0, 9.5}, {0.0, 9.5}};
GLfloat hor5[4][2]={{0.0, 0.0}, {5.0, 0.0}, {5.0, 1.0}, {0.0, 1.0}};

//Colors
GLfloat black[3]={0.0, 0.0, 0.0}, gray[3]={0.7, 0.7, 0.7}, white[3]={1.0, 1.0, 1.0};
GLfloat red[3]={1.0, 0.0, 0.0}, lred[3]={1.0, 0.4, 0.4}, vlred[3]={1.0, 0.8, 0.8};
GLfloat green[3]={0.0, 1.0, 0.0}, lgreen[3]={4.0, 1.0, 0.4}, vlgreen[3]={0.8, 1.0, 0.8};
GLfloat blue[3]={0.0, 0.0, 1.0}, lblue[3]={0.4, 0.4, 1.0}, vlblue[3]={0.8, 0.8, 1.0};
GLfloat yellow[3]={1.0, 1.0, 0.0}, lyellow[3]={1.0, 1.0, 0.4}, vlyellow[3]={1.0, 1.0, 0.8};
GLfloat brown[3]={0.7, 0.3, 0.2}, lbrown[3]={0.8, 0.6, 0.5}, vlbrown[3]={0.9, 0.7, 0.6};
GLfloat cyan[3]={0.0, 1.0, 1.0}, magenta[3]={1.0, 0.0, 1.0};