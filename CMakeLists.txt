cmake_minimum_required(VERSION 3.11)
project(kurs)

set(CMAKE_CXX_STANDARD 11)

add_executable(kurs main.cpp MainMenu.cpp Employee.h Teacher.h Professor.h Docent.h SeniorTeacher.h Assistant.h TeachSupport.h Engineer.h LabAssistant.h Division.h IT.h Kib.h FTI.h)