/*
 * renderer.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: morrigan
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "renderer.h"
#include "optics.h"

Renderer::~Renderer() {
	al_destroy_bitmap(video_bmp);
	al_destroy_bitmap(mem_bmp);
	al_destroy_font(font);
}

void Renderer::initialize(int cx, int cy) {
	this->cx = cx;
	this->cy = cy;

	//al_set_new_bitmap_format(ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA);

	al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	video_bmp = al_create_bitmap(cx,cy);

	al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	mem_bmp = al_create_bitmap(field->Nx, field->Ny);

	clock = clock_t::now();
	n_frames = 0;
	fps = 0;
	eps = 0;
	font  = al_create_builtin_font();
}

void Renderer::update_field_data(){

	if(!mem_bmp || !is_scr_bmp_updated) return;

	ALLEGRO_DISPLAY * display = al_get_current_display();
	al_set_target_bitmap(mem_bmp);

	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));

	unsigned char color_e;
	unsigned char color_m;
	int Nx = al_get_bitmap_width(mem_bmp), Ny = al_get_bitmap_height(mem_bmp);
	for(int x = 0; x < Nx; x++)
		for(int y = 0; y < Ny; y++){

			if(field->e_energy[x][y] <= field->e_energy_cutoff){
				color_e = 255*field->e_energy[x][y]/field->e_energy_cutoff;
			}else{
				color_e = 255;
			}

			if(field->m_energy[x][y] <= field->m_energy_cutoff){
				color_m = 255*field->m_energy[x][y]/field->m_energy_cutoff;
			}else{
				color_m = 255;
			}

			al_put_pixel(x,y,al_map_rgb(0, color_e, color_m));

			if(field->getField()[x][y].epsilon_mult != 1)
				al_put_blended_pixel(x,y,al_map_rgba(20, 20, 20,100));

		}

	al_draw_line(0,Ny-1,field->lambda,Ny-1,al_map_rgb(255,0,0),0);

	al_set_target_bitmap(al_get_backbuffer(display));
	is_scr_bmp_updated = false;
}

void Renderer::render() {

	field->calc_energy();
	update_field_data();

	if(!is_scr_bmp_updated){
		ALLEGRO_DISPLAY * display = al_get_current_display();
		al_set_target_bitmap(video_bmp);

		int mem_w = al_get_bitmap_width(mem_bmp);
		int vid_w = al_get_bitmap_width(video_bmp);
		int mem_h = al_get_bitmap_height(mem_bmp);
		int vid_h = al_get_bitmap_height(video_bmp);

		int dx, dy;
		double aspect;

		if(vid_w/mem_w > vid_h/mem_h){
			aspect = (double)vid_h/mem_h;
			dy = 0;
			dx = (vid_w - aspect*mem_w)/2;
		}else{
			aspect = (double)vid_w/mem_w;
			dy = (vid_h - aspect*mem_h)/2;
			dx = 0;
		}

		al_clear_to_color(al_map_rgb(100, 100, 100));

		al_draw_scaled_bitmap(mem_bmp,
		   0, 0, mem_w, mem_h,
		   dx, dy, aspect*mem_w, aspect*mem_h,0);

		al_set_target_bitmap(al_get_backbuffer(display));

		is_scr_bmp_updated = true;
	}

	al_draw_bitmap(video_bmp, 0, 0, 0);

	std::istringstream iss(measure_performance());
	int y = 10;
	for(std::string line; std::getline(iss, line);){
		al_draw_text(font,al_map_rgb(255,0,0),5,y,0,line.c_str());
		y += 10;
	}

	al_flip_display();
}

std::string Renderer::measure_performance(){
	double time = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> >> (clock_t::now() - clock).count();
	if(time > 1){
		fps = n_frames/time;
		eps = field->eval_cnt/time;

		field->eval_cnt = 0; //thread unsafe but.. to hell
		n_frames = 0;
		clock = clock_t::now();
	}

	std::ostringstream out;
	out << "Frames per second: " << std::setprecision(4) << fps << std::endl;
	out << "Field evaluations per second: " << std::setprecision(4) << eps << std::endl;

	n_frames++;
	return out.str();
}


