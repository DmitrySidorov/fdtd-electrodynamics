/*
 * visadapter.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: morrigan
 */

#include <cmath>
#include <thread>

#include "visual_field.h"

VisualField::VisualField(int Nx, int Ny): EMField(Nx, Ny),
e_energy_cutoff{0}, m_energy_cutoff {0}, eval_cnt{0},
Nx{Nx}, Ny{Ny}{

	e_energy.resize(Nx);
	for(auto& x : e_energy) x.resize(Ny);

	m_energy.resize(Nx);
	for(auto& x : m_energy) x.resize(Ny);

	this->lambda = EMField::getLambda();
}

void VisualField::evaluate() {
	public_mtx.lock();
	EMField::evaluate();
	eval_cnt++;
	public_mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
}

//TODO: extend multithreading to this function, it locks evaluation
void VisualField::calc_energy() {
	public_mtx.lock();
	double int_e_energy = 0;
	double int_m_energy = 0;
	for(int i = 0; i < Nx; i++)
		for(int j = 0; j < Ny; j++){
			e_energy[i][j] = std::sqrt(EMField::getField()[i][j].Ex*EMField::getField()[i][j].Ex + EMField::getField()[i][j].Ey*EMField::getField()[i][j].Ey);
			m_energy[i][j] = std::sqrt(EMField::getField()[i][j].Hz*EMField::getField()[i][j].Hz);

			if(EMField::getSources().count(SRC(i,j)) == 0){
				int_e_energy += e_energy[i][j];
				int_m_energy += m_energy[i][j];
			}
		}

	e_energy_cutoff = 10*int_e_energy/(Nx*Ny);
	m_energy_cutoff = 10*int_m_energy/(Nx*Ny);

	public_mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
}
