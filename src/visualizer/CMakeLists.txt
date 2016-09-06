set(VISUALIZER_LIBS_OK TRUE)

find_package(Allegro)
if(!ALLEGRO_FOUND)
    set(VISUALIZER_LIBS_OK FALSE)
    message("Library Allegro not found")
endif(!ALLEGRO_FOUND)

find_package(Threads)
if(!Threads_FOUND)
    set(VISUALIZER_LIBS_OK FALSE)
    message("Library Threads not found")
endif(!Threads_FOUND)

find_package(GSL)
if(!GSL_FOUND)
	set(VISUALIZER_LIBS_OK FALSE)
    message("Library GSL not found")
endif(!GSL_FOUND)

if(VISUALIZER_LIBS_OK)
    file(GLOB FDTD_SRC "*.cpp")
    add_executable (fdtd ${FDTD_SRC})
    
    include_directories (fdtd ${ALLEGRO_INCLUDE_DIR})
    
    target_link_libraries(fdtd ${ALLEGRO_LIBRARIES})
    target_link_libraries(fdtd ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(fdtd ${ARMADILLO_LIBRARIES})
    target_link_libraries(fdtd ${GSL_LIBRARIES})
    
else(VISUALIZER_LIBS_OK)
    message(FATAL_ERROR "FDTD: missing dependencies, omitting")
endif(VISUALIZER_LIBS_OK)

