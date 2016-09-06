/*
 * window.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: Dr. Yevgeniy Kolokoltsev
 */

#include <stdexcept>
#include <chrono>

#include <allegro5/allegro_primitives.h>

#include "window.h"

bool Window::is_al_initialized = false;

Window::Window() : cx{0},cy{0} {
	display = nullptr;
	event_queue = nullptr;

	win_msg_proc = nullptr;
	renderer = nullptr;
}

Window::~Window() {
	cleanup();
}

std::shared_ptr<Window> Window::create_window(std::unique_ptr<Renderer>&& renderer, int width, int height){
	if(width <= 0 || height <= 0) throw  std::runtime_error("invalid window size");

	if(!is_al_initialized){
		if (!al_init())
			throw std::runtime_error("failed to initialize allegro");

		if (!al_init_primitives_addon())
			throw std::runtime_error(
					"failed to initialize allegro primitives addon");
		is_al_initialized = true;
	}

	std::shared_ptr<Window> w(new Window());
	w->cx = width;
	w->cy = height;
	w->renderer = std::move(renderer);
	w->win_msg_proc.reset(new std::thread(Window::run, w));
	return w;
}

void Window::run(std::shared_ptr<Window> w) {
	w->initialize();
	w->start_msg_queue();
	w->cleanup();
}

void Window::initialize() {

	display = al_create_display(cx, cy);
	if (!display)
		throw std::runtime_error("failed to create display");

	event_queue = al_create_event_queue();
	if (!event_queue)
		throw std::runtime_error("failed to create event_queue");
	renderer->initialize(cx,cy);
}

void Window::start_msg_queue() {

	al_register_event_source(event_queue, al_get_display_event_source(display));

	ALLEGRO_EVENT ev;

	while (1) {
		while(al_get_next_event(event_queue, &ev))
			if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) goto stop;

		renderer->render();
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}

	stop: return;
}

void Window::cleanup() {
	if (display != nullptr){
		al_destroy_display(display);
		display = nullptr;
	}

	if (event_queue != nullptr){
		al_destroy_event_queue(event_queue);
		event_queue = nullptr;
	}

	win_msg_proc.release();
}

bool Window::is_running(){
	return (bool) win_msg_proc;
}

void Window::update_field_data(){
	renderer->update_field_data();
}
