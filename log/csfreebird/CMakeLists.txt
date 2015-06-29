add_executable(boostLogTest main.cc logger.cc)
target_link_libraries(boostLogTest ${Boost_LIBRARIES} pthread)
set_target_properties(boostLogTest PROPERTIES COMPILE_FLAGS "-DBOOST_LOG_DYN_LINK -g -save-temps")
