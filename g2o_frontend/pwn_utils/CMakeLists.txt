INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS})
LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

ADD_LIBRARY(pwn_utils
  pwn_file_format_converter.h
  pwn_utils.h
)

SET_TARGET_PROPERTIES(pwn_utils PROPERTIES OUTPUT_NAME ${LIB_PREFIX}_pwn_utils)
TARGET_LINK_LIBRARIES(pwn_utils pwn_core boss ${OpenCV_LIBS} ${PCL_LIBRARIES})