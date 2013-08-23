//Display components of start page
void startpage()
{
	glColor3fv(vlbrown);
	quad_disp(back, spid, single);
	
	glColor3fv(black);
	textdisp(spage_text[0], spage_pos[0], t24);
	for(int i=1; i<10; i++)
		textdisp(spage_text[i], spage_pos[i], b8x13);
	textdisp(spage_text[10], spage_pos[10], b9x15);

	loop_disp(spage_start_btn);
	loop_disp(spage_quit_btn);
	glColor3fv(vlgreen);
	quad_disp(spage_start_btn, stbtntid, single);
	glColor3fv(vlred);
	quad_disp(spage_quit_btn, qtbtntid, single);

	glColor3fv(white);
	textdisp(btn_text[0], spage_pos[11], b9x15);
	textdisp(btn_text[3], spage_pos[12], b9x15);
}

//Display components of play page
void playpage()
{
	glColor3fv(lbrown);
	quad_disp(back, ppid, single);

	//Display terminals
	glColor3fv(vlblue);
	quad_disp(crete, ctid, single);
	glColor3fv(vlgreen);
	quad_disp(rome, rtid, single);
	
	glColor3fv(white);
	textdisp(names[0], ppage_pos[0], h12);
	textdisp(names[1], ppage_pos[1], h12);
	textdisp(btn_text[4], ppage_pos[2], h12);

	//Draw maze
	glColor3fv(brown);
	quad_disp(walla, hwtid, hor5);
	quad_disp(wallb1, vwtid, ver20);
	quad_disp(wallb2, hwtid, hor4);
	quad_disp(wallb3, hwtid, hor3_75);
	quad_disp(wallc1, hwtid, hor7_75);
	quad_disp(wallc2, vwtid, ver10);
	quad_disp(wallc3, hwtid, hor6_5);
	quad_disp(wallc4, vwtid, ver9_5);
	quad_disp(walld, hwtid, hor5);

	//Display timer
	glColor3fv(black);
	quad_disp(timers, ttid, single);
	glColor3fv(yellow);
	quad_disp(timerp, ttid, single);
	loop_disp(timerp);

	ikarosdisp();
	draw_border();
}

//Display components of collision error page
void collipage()
{
	glColor3fv(white);
	quad_disp(back, colpid, single);

	glColor3fv(black);
	textdisp(cpage_text[0], cpage_pos[0], t24);
	for(int i=1; i<7; i++)
		textdisp(cpage_text[i], cpage_pos[i], b9x15);
	textdisp(luck_text[luck], cpage_pos[7], b9x15);
	
	loop_disp(cpage_retry_btn);
	loop_disp(cpage_restart_btn);
	loop_disp(cpage_quit_btn);

	glColor3fv(vlgreen);
	quad_disp(cpage_retry_btn, rtbtntid, single);
	glColor3fv(vlyellow);
	quad_disp(cpage_restart_btn, stbtntid, single);
	glColor3fv(vlred);
	quad_disp(cpage_quit_btn, qtbtntid, single);

	glColor3fv(white);
	for(int i=8, j=1; i<10, j<4; i++, j++)
		textdisp(btn_text[j], cpage_pos[i], b9x15);
}

//Display components of game over page
void overpage()
{
	glColor3fv(gray);
	quad_disp(back, colpid, single);

	glColor3fv(black);
	textdisp(res_text[0], opage_pos[0], h18);
	textdisp(stat_text[0], opage_pos[1], t24);
	textdisp(opage_text, opage_pos[2], h18);
	textdisp(choose, opage_pos[3], b9x15);

	loop_disp(olwpage_restart_btn);
	loop_disp(olwpage_quit_btn);

	glColor3fv(green);
	quad_disp(olwpage_restart_btn, stbtntid, single);
	glColor3fv(red);
	quad_disp(olwpage_quit_btn, qtbtntid, single);

	glColor3fv(white);
	textdisp(btn_text[2], opage_pos[4], b9x15);
	textdisp(btn_text[3], opage_pos[5], b9x15);
}

//Display components of time over page
void lazypage()
{
	glColor3fv(gray);
	quad_disp(back, colpid, single);

	glColor3fv(black);
	textdisp(res_text[0], lpage_pos[4], h18);
	textdisp(stat_text[0], lpage_pos[5], t24);
	for(int i=0; i<3; i++)
		textdisp(lpage_text[i], lpage_pos[i], b9x15);
	textdisp(choose, lpage_pos[3], b9x15);

	loop_disp(olwpage_restart_btn);
	loop_disp(olwpage_quit_btn);

	glColor3fv(green);
	quad_disp(olwpage_restart_btn, stbtntid, single);
	glColor3fv(red);
	quad_disp(olwpage_quit_btn, qtbtntid, single);

	glColor3fv(white);
	textdisp(btn_text[2], lpage_pos[6], b9x15);
	textdisp(btn_text[3], lpage_pos[7], b9x15);
}

//Display components of game won page
void winpage()
{
	//Magenta background
	glColor3fv(vlblue);
	quad_disp(back, wpid, single);

	glColor3fv(black);
	textdisp(res_text[1], wpage_pos[4], h18);
	textdisp(stat_text[1], wpage_pos[5], t24);
	for(int i=0; i<3; i++)
		textdisp(wpage_text[i], wpage_pos[i], b9x15);
	textdisp(choose, wpage_pos[3], b9x15); 

	loop_disp(olwpage_restart_btn);
	loop_disp(olwpage_quit_btn);

	glColor3fv(white);
	textdisp(btn_text[2], wpage_pos[6], b9x15);
	textdisp(btn_text[3], wpage_pos[7], b9x15);

	glColor3fv(green);
	quad_disp(olwpage_restart_btn, rtbtntid, single);
	glColor3fv(red);
	quad_disp(olwpage_quit_btn, qtbtntid, single);
} 