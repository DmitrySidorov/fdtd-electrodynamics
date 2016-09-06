/*
 * renderer.h
 *
 *  Created on: Jan 14, 2016
 *      Author: Dr. Yevgeniy Kolokoltsev
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include <memory>
#include <atomic>
#include <chrono>
#include <string>

#include <allegro5/allegro_font.h>

#include "visual_field.h"

class Renderer {
public:
	Renderer(const std::shared_ptr<VisualField>& field):Renderer() {this->field = field;};
	~Renderer();

	void initialize(int, int);
	void update_field_data();

	void render();

private:
	Renderer() : cx{0}, cy{0}, field{nullptr}, mem_bmp(nullptr), video_bmp(nullptr),
	is_scr_bmp_updated{true}, font{nullptr}, n_frames{0}, fps{0}, eps{0} {;};
	std::shared_ptr<VisualField> field;

	int cx;
	int cy;

	ALLEGRO_BITMAP * mem_bmp;
	ALLEGRO_BITMAP * video_bmp;
	std::atomic<bool> is_scr_bmp_updated;

	//FPS
	using clock_t = std::chrono::high_resolution_clock;
	std::chrono::time_point<clock_t> clock;
	int n_frames;
	double fps;
	double eps;
	ALLEGRO_FONT *font;


	std::string measure_performance();
};

#endif /* RENDERER_H_ */
