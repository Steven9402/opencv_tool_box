add_executable(p_trans_ex p_trans_ex.cpp)
target_link_libraries(p_trans_ex util_transform ${OpenCV_LIBS})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})