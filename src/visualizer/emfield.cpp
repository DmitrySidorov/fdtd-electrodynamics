/*
 * emfield.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: Dr. Yevgeniy Kolokoltsev
 */

#include <cmath>
#include <iostream>
#include <thread>
#include <random>

#include <gsl/gsl_sf_bessel.h>

#include "emfield.h"
#include "optics.h"

EMField::EMField(int Nx, int Ny):
Nx{Nx}, Ny{Ny}, t{0}, epsilon {10}, mu {10}, dl {1}
{
	lambda = dl*std::min(Nx,Ny)/10;
	dt = lambda*sqrt(epsilon*mu)/(2*ndt);

	field.resize(Nx);
	for(auto& x : field) x.resize(Ny);

#if FDTD_EMFIELD_MULTI == 1
	ncores = std::thread::hardware_concurrency();
	if(!ncores) ncores = 1;

	thread_cells.resize(ncores);
	for(int i = 0; i < Nx; i++)
		for(int j = 0; j < Ny; j++)
			thread_cells[rand() % ncores].push_back(std::pair<int,int>(i,j));
#endif

	//create optical elements
	/*for(int i = 0; i < Nx; i++)
		for(int j = 0; j < Ny; j++){
			                         //cx,  cy,  r, h, H,x,y
			if(opcs::is_pt_in_lp_lens(200,Ny/2,250,230,200,i,j))
				field[i][j].epsilon_mult = 3.7;
		}*/
}

//account for boundary conditions
EMField::TECell& EMField::c(int i, int j){
	if(i < 0 || i >= Nx || j < 0 || j >= Ny) return boudary;
	return field[i][j];
}

void EMField::eval_cell_E(int i, int j){

	TECell& cij = field[i][j];
	TECell& cij1 = c(i,j-1);
	TECell& ci1j = c(i-1,j);

	cij.Ex += (dt/dl*(1/epsilon))*( (cij.Hz/cij.epsilon_mult - cij1.Hz/cij1.epsilon_mult) ) - cij.Ex*cij.sigmax*dt/(cij.epsilon_mult*epsilon)  ;
	cij.Ey += (dt/dl*(-1/epsilon))*( (cij.Hz/cij.epsilon_mult - ci1j.Hz/ci1j.epsilon_mult)  - cij.Ex*cij.sigmay*dt/cij.epsilon_mult*epsilon);
}

void EMField::eval_cell_H(int i, int j){

	TECell& cij = field[i][j];
	TECell& cij1 = c(i,j+1);
	TECell& ci1j = c(i+1,j);

	cij.Hzx += (dt/dl*(1/mu))*( - (ci1j.Ey/ci1j.mu_mult - cij.Ey/cij.mu_mult) );
	cij.Hzy += (dt/dl*(1/mu))*( (cij1.Ex/cij1.mu_mult - cij.Ex/cij.mu_mult) );
}

void EMField::apply_source(){

	//Gaussian source
	if(sources.size() == 0){
		SRC src;
		double k = 2*M_PI/lambda;

		for(int y = 0; y < Ny; y++){
			src = SRC(0,y);
			//Gaussian
			//src.mag = std::exp(-std::pow((y-Ny/2)/(4*lambda),2));
			src.mag = std::exp(-std::pow((y-Ny/2)/(lambda),2))*std::pow(std::cos(2*M_PI*(y-Ny/2)/(1.414213562*lambda)),2);

			double intpart;
			sources.insert(src);
		}

        // One simple source
       /* src.i = 0;
        src.j = 0;
        src.mag = 10;
        sources.insert(src);*/
	}

	//apply sources (at each evaluation run)
	for(auto& src : sources)
		field[src.i][src.j].Hz = src.mag*std::sin(M_PI*t/(ndt*dt) + src.phase);
}

void EMField::evaluate(){

#if FDTD_EMFIELD_MULTI == 1
	std::vector<std::thread> threads;

	for(int i = 0; i < ncores; i++)
		threads.push_back(std::thread(eval_thread,this,eval_cell_ptr(&EMField::eval_cell_E),i));
	for(auto& x : threads) x.join();

	apply_source();

	for(int i = 0; i < ncores; i++)
		threads[i] = std::thread(eval_thread,this,eval_cell_ptr(&EMField::eval_cell_H),i);
	for(auto& x : threads) x.join();

	apply_source();

#else
	//E-field step
	for(int i = 0; i < Nx; i++)
		for(int j = 0; j < Ny; j++)
			eval_cell_E(i,j);

	apply_source(); //replace any E fields with sources

	//H-field step
	for(int i = 0; i < Nx; i++)
		for(int j = 0; j < Ny; j++)
			eval_cell_H(i,j);

	apply_source(); //replace any H fields with sources
#endif

	t += dt;
}

#if FDTD_EMFIELD_MULTI == 1
void EMField::eval_thread(EMField* em_field, eval_cell_ptr eval_cell, int target){
	for(auto& cell_ids : em_field->thread_cells[target]){
		(em_field->*eval_cell)(cell_ids.first,cell_ids.second);
	}
}
#endif
