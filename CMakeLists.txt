cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(angleDeficit)

find_package(VTK)
include(${VTK_USE_FILE})

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(QWT_INCLUDE_DIR "/usr/include/qwt" )
set(QWT_LIBRARIES "qwt" )

if("${VTK_QT_VERSION}" STREQUAL "")
  message(FATAL_ERROR "VTK was not built with Qt")
endif()

set( Srcs main.cxx MainWindow.cxx )

set( Hdrs MainWindow.h )

set( MOC_Hdrs MainWindow.h )

set( UIs MainWindow.ui )

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets)
qt5_wrap_ui(UI_Srcs ${UIs})

add_executable(angleDeficit ${Srcs} ${Hdrs} ${UI_Srcs} ${MOC_Hdrs})
qt5_use_modules(angleDeficit Core Gui Widgets)
target_link_libraries(angleDeficit ${VTK_LIBRARIES} ${QWT_LIBRARIES})
target_include_directories(angleDeficit PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR} ${EIGEN3_INCLUDE_DIRS} ${QWT_INCLUDE_DIR})
