cmake_minimum_required(VERSION 2.8.3)

project(rqt_openvri_view)
# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS rqt_gui rqt_gui_cpp sensor_msgs  geometry_msgs  config_server)

find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)

include(${QT_USE_FILE})

set(rqt_openvri_view_SRCS
  src/rqt_openvri_view/openvri_view.cpp
  src/rqt_openvri_view/ratio_layouted_frame.cpp
  src/rqt_openvri_view/parameteritem.cpp
  src/rqt_openvri_view/parametertuner.cpp
)

set(rqt_openvri_view_HDRS
  include/rqt_openvri_view/openvri_view.h
  include/rqt_openvri_view/ratio_layouted_frame.h
  include/rqt_openvri_view/parameteritem.h
  include/rqt_openvri_view/parametertuner.h
)

set(rqt_openvri_view_RESOURCES resources/images.qrc)
set(rqt_openvri_view_UIS
  resources/openvri_view.ui
  resources/parametertuner.ui
)

set(rqt_openvri_view_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS rqt_gui rqt_gui_cpp
)
catkin_python_setup()

qt4_wrap_cpp(rqt_openvri_view_MOCS ${rqt_openvri_view_HDRS})
qt4_wrap_ui(rqt_openvri_view_UIS_H ${rqt_openvri_view_UIS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(${rqt_openvri_view_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS})
add_library(${PROJECT_NAME} ${rqt_openvri_view_SRCS} ${rqt_openvri_view_MOCS} ${rqt_openvri_view_UIS_H})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

find_package(class_loader)
class_loader_hide_library_symbols(${PROJECT_NAME})

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(PROGRAMS scripts/rqt_openvri_view
  DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
install(PROGRAMS scripts/rqt_openvri_view
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
