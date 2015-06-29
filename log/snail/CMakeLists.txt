add_library(snaillog log.cc user_log_testspy.cc)
target_link_libraries(snaillog ${Boost_LIBRARIES} pthread)
set_target_properties(snaillog PROPERTIES COMPILE_FLAGS "-DBOOST_LOG_DYN_LINK")

add_executable(snail main.cc modulea.cc moduleb.cc modulec.cc moduleaa.cc)
target_link_libraries(snail snaillog)

add_executable(snailtest log_test.cc)
target_link_libraries(snailtest snaillog)
