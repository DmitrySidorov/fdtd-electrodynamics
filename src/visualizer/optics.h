/*
 * optics.h
 *
 *  Created on: Jan 29, 2016
 *      Author: morrigan
 */

#ifndef SRC_FDTD_OPTICS_H_
#define SRC_FDTD_OPTICS_H_

namespace opcs{

bool is_pt_in_pp_plate(double cx, double cy, double width, double height, double pt_x, double pt_y);
bool is_pt_in_lp_lens(double cx, double cy, double r, double h, double H, double pt_x, double pt_y);
bool is_out_box(double cx, double cy, double width, double height, double pt_x, double pt_y);
bool is_out_box1(double cx, double cy, double r, double h,double H, double pt_x, double pt_y);

}



#endif /* SRC_FDTD_OPTICS_H_ */
