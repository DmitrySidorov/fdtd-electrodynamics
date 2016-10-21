/*
 * optics.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: morrigan
 */

#include <cmath>

#include "optics.h"

namespace opcs{

bool is_pt_in_pp_plate(double cx, double cy, double width, double height, double pt_x, double pt_y){
	return ((std::abs(pt_x - cx) <= width/2) && (std::abs(pt_y - cy) <= height/2));
}

bool is_pt_in_lp_lens(double cx, double cy, double r, double h, double H, double pt_x, double pt_y){
	pt_x -= cx+h;
	pt_y -= cy;

	if(pt_x > -h) return false;
	if(std::abs(pt_y) > H/2) return false;

	if(std::sqrt(pt_x*pt_x + pt_y*pt_y) > r) return false;

	return true;
}

	bool is_out_box(double cx, double cy, double width, double height, double pt_x, double pt_y){
        return ((std::abs(pt_x - cx) <= width/2) && (std::abs(pt_y - cy) <= height/2));
	}


    bool is_out_box1(double cx, double cy, double r, double h, double pt_x, double H,double pt_y){
        pt_x -= cx+h;
        pt_y -= cy;

        if(pt_x > -h) return false;
        if(std::abs(pt_y) > H/2) return false;

        if(std::sqrt(pt_x*pt_x + pt_y*pt_y) > r) return false;

        return true;
    }

}

