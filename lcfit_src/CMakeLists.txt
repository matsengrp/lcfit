cmake_minimum_required (VERSION 2.8)

# Build the LCFIT C library
project(liblcfit C)

# Find GSL
include(FindGsl)
find_package(Gsl REQUIRED)
include_directories(SYSTEM ${GSL_INCLUDE_DIRS})

set(LCFIT_LIB_C_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit_select.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2_gsl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2_nlopt.h)
set(LCFIT_LIB_C_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit_select.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2_gsl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lcfit2_nlopt.c)
add_library(lcfit-static STATIC ${LCFIT_LIB_C_FILES})
add_library(lcfit SHARED ${LCFIT_LIB_C_FILES})
target_link_libraries(lcfit-static
  ${GSL_LIBRARIES}
  nlopt)
target_link_libraries(lcfit
  ${GSL_LIBRARIES}
  nlopt)

install(TARGETS lcfit DESTINATION lib)
install(FILES ${LCFIT_LIB_C_HEADERS} DESTINATION include)
