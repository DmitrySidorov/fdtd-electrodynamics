/*
 * visadapter.h
 *
 *  Created on: Jan 28, 2016
 *      Author: morrigan
 */

#ifndef SRC_FDTD_VISUAL_FIELD_H_
#define SRC_FDTD_VISUAL_FIELD_H_

#include <mutex>
#include <vector>

#include "emfield.h"

class Renderer;

//Adapter template
class VisualField : public EMField{
public:

	friend Renderer;

	VisualField(int, int);

	void evaluate();
	void calc_energy();

private:

	std::vector<std::vector<double>> e_energy;
	std::vector<std::vector<double>> m_energy;

	int Nx;
	int Ny;

	double lambda;

	double e_energy_cutoff;
	double m_energy_cutoff;

	int eval_cnt;

	std::mutex public_mtx;
};

#endif /* SRC_FDTD_VISUAL_FIELD_H_ */
