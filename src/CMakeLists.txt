include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${OPENGL_INCLUDE_DIRS}
  ${GLUT_INCLUDE_DIRS}
  ${GTK3_INCLUDE_DIRS}
)

message (STATUS ${GTK_INCLUDE_DIRS})

set( EXE_NAME Snake )

set( LIB_Engine Engine )

set (LIB_Boxer Boxer )

set(SOURCE_FILES main.cpp boxer.cpp Engine.cpp)

add_library(
  ${LIB_Engine}
  Engine.cpp Engine.h 
)
target_compile_definitions(${LIB_Engine} PUBLIC)

add_library(
  ${LIB_Boxer}
  Boxer.cpp Boxer.h
)
target_compile_definitions(${LIB_Boxer} PUBLIC )

add_executable( ${EXE_NAME} ${SOURCE_FILES} )

target_link_libraries(
  ${EXE_NAME}
  ${LIB_Engine}
  ${LIB_Boxer}
  ${GTK3_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLUT_LIBRARY}
 )
 
 target_link_libraries(${LIB_Boxer})

