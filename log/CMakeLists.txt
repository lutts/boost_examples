file (GLOB SRC_FILES *.cpp)
foreach(SRC_FILE ${SRC_FILES})
  string(REGEX REPLACE ".*log/\(.*\)[.]cpp$" "\\1" TGT_NAME ${SRC_FILE})
  add_executable(${TGT_NAME} ${SRC_FILE})
  target_link_libraries(${TGT_NAME} ${BoostCommonLibs})
endforeach(SRC_FILE)

#set_source_files_properties(expressions_channel_severity_filter.cpp
#  PROPERTIES COMPILE_FLAGS "-g -save-temps")

add_subdirectory(csfreebird)
add_subdirectory(snail)
