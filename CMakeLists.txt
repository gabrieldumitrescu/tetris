cmake_minimum_required(VERSION 2.8)
project("Tetris")

set(SOURCES Brick.cc Tetrimino.cc Game.cc main.cc) 


add_executable(MyTetris ${SOURCES})
										 
target_link_libraries(MyTetris SDL2)
