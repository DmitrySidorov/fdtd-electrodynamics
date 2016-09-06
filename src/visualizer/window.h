/*
 * window.h
 *
 *  Created on: Jan 13, 2016
 *      Author: Dr. Yevgeniy Kolokoltsev
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <thread>
#include <memory>
#include <mutex>

#include <allegro5/allegro.h>

#include "renderer.h"

class Window {
public:
	~Window();

	/**
	 * Create window object, initialize it and start message processing thread
	 */
	static std::shared_ptr<Window> create_window(std::unique_ptr<Renderer>&&,int,int);

	void update_field_data();
	void reset_renderer(std::unique_ptr<Renderer>&&);
	bool is_running();

private:
	/**
	 * Private constructor prevents from direct object creation.
	 */
	Window();

	static bool is_al_initialized;

	static void run(std::shared_ptr<Window>);
	static void rendering_loop(std::shared_ptr<Window>);
	void initialize();
	void start_msg_queue();
	void cleanup();

	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;

	int cx;
	int cy;

	std::unique_ptr<std::thread> win_msg_proc;

	std::unique_ptr<Renderer> renderer;
};

#endif /* WINDOW_H_ */
