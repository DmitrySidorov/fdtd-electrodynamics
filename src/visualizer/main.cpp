//============================================================================
// Name        : worker.cpp
// Author      : Dr. Yevgeniy Kolokoltsev
// Version     : 0.0.0
// Copyright   :
// Description : Worm visualizer GUI program
//============================================================================

#include <iostream>
#include <memory>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "window.h"
#include "renderer.h"

int main(int argc, char** argv) {

	std::shared_ptr<VisualField> field(new VisualField(300,300));

	auto w = Window::create_window(std::unique_ptr<Renderer>(new Renderer(field)),300,300);

	int i = 0;
	while(1){
		if(!w->is_running()) break;
		field->evaluate();

		//std::cout << field->eval_cnt << std::endl;
		//i++;
	}

	std::cout << "exit" << std::endl;

	return 0;
}
