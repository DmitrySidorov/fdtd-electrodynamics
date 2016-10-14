/*
 * emfield.h
 *
 *  Created on: Jan 26, 2016
 *      Author: morrigan
 */

#ifndef SRC_FDTD_EMFIELD_H_
#define SRC_FDTD_EMFIELD_H_

#define FDTD_EMFIELD_MULTI 1

#include <vector>
#include <set>
#include <memory>

class EMField {
public:
	EMField(int, int);
	void evaluate();

protected:

	struct TECell{
		TECell(): Ex{0}, Ey{0}, Hz {0},Hzx{0}, Hzy {0}, epsilon_mult{1}, mu_mult{1}, sigmax{0}, sigmay{0}, sigmam_x {0},
		sigmam_y {0} {;}

		double Ex;
		double Ey;
		double Hzx;
        double Hzy;
        double Hz;
		double epsilon_mult;
		double mu_mult;
		double sigmax;
		double sigmay;
		double sigmam_x;
		double sigmam_y;
	};

	class SRC{
	public:
		SRC(): i{0}, j{0}, mag{0}, phase{0} {;}
		SRC(int i, int j): i{i}, j{j}, mag{0}, phase{0} {;}
		int i;
		int j;
		double mag;
		double phase;

		bool operator< (const SRC& x) const
		{ if(i != x.i) return i < x.i; return j < x.j; }
	};

	double getEpsilon() const { return epsilon; }
	double getLambda() const { return lambda; }
	double getMu() const { return mu; }

	const std::set<SRC>& getSources() const { return sources; }
	const std::vector<std::vector<TECell> >& getField() const { return field; }

private:

	//field evaluation routines
	void eval_cell_E(int, int);
	void eval_cell_H(int, int);
	inline TECell& c(int, int);
	void apply_source();

	//multi-thread computation routines
#if FDTD_EMFIELD_MULTI == 1
	typedef void (EMField::*eval_cell_ptr)(int,int);
	static void eval_thread(EMField*,eval_cell_ptr,int);
	std::vector<std::vector<std::pair<int,int>>> thread_cells;
	unsigned int ncores;
#endif

	//main data
	std::vector<std::vector<TECell>> field;
	std::set<SRC> sources;
	TECell boudary;

	double lambda;
	double epsilon;
	double mu;

	int Nx, Ny;

	double t;
	double dt;
	double dl;

	const double ndt = 50; //period T = ndt*dt
};

#endif /* SRC_FDTD_EMFIELD_H_ */
