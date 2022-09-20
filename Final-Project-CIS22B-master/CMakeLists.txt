cmake_minimum_required(VERSION 3.15)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)



add_executable(FinalProject src/main.cpp
			   src/Classes/Source/book.cpp
			   src/Classes/Headers/book.h
			   src/Classes/Source/cashierModule.cpp
			   src/Classes/Headers/cashierModule.h
			   src/Classes/Source/baseModule.cpp
			   src/Classes/Headers/baseModule.h
			   src/Classes/Headers/storage.h
			   src/Classes/Source/reportModule.cpp
			   src/Classes/Headers/reportModule.h
			   src/Classes/Source/inventoryModule.cpp
			   src/Classes/Headers/inventoryModule.h)