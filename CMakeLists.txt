cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
include (ExternalProject)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# disable now to wa boost bug chriskohlhoff/asio#533
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories (${DBUSINTERFACE_LIBRARIES})

find_package (PkgConfig REQUIRED)

pkg_check_modules (SYSTEMD libsystemd REQUIRED)
include_directories (${SYSTEMD_INCLUDE_DIRS})
link_directories (${SYSTEMD_LIBRARY_DIRS})

# import sdbusplus
pkg_check_modules (SDBUSPLUSPLUS sdbusplus REQUIRED)
include_directories (${SDBUSPLUSPLUS_INCLUDE_DIRS})
link_directories (${SDBUSPLUSPLUS_LIBRARY_DIRS})
find_program (SDBUSPLUSPLUS sdbus++)

# phosphor-dbus-interfaces
pkg_check_modules (DBUSINTERFACE phosphor-dbus-interfaces REQUIRED)
include_directories (${DBUSINTERFACE_INCLUDE_DIRS})
link_directories (${DBUSINTERFACE_LIBRARY_DIRS})

# boost
include_directories (SYSTEM ${CMAKE_BINARY_DIR}/boost-src)
set (CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/boost-src ${CMAKE_PREFIX_PATH})
add_definitions (-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions (-DBOOST_SYSTEM_NO_DEPRECATED)
add_definitions (-DBOOST_ALL_NO_LIB)
add_definitions (-DBOOST_NO_RTTI)
add_definitions (-DBOOST_NO_TYPEID)
add_definitions (-DBOOST_ASIO_DISABLE_THREADS)

#set (SRC_FILES src/mdrv2.cpp src/mdrv2_main.cpp src/cpu.cpp src/dimm.cpp
#     src/system.cpp src/pcieslot.cpp src/pcie.cpp)
set (SRC_FILES src/mdrv2.cpp src/pcie.cpp)

include_directories (${CMAKE_CURRENT_BINARY_DIR})

add_executable (pciemdrv2app ${SRC_FILES})
target_link_libraries (pciemdrv2app ${SYSTEMD_LIBRARIES})
target_link_libraries (pciemdrv2app ${DBUSINTERFACE_LIBRARIES})
target_link_libraries (pciemdrv2app ${SDBUSPLUSPLUS_LIBRARIES})
target_link_libraries (pciemdrv2app phosphor_logging)

if (NOT DEFINED SYSTEMD_SYSTEM_UNIT_DIR)
    pkg_get_variable(SYSTEMD_SYSTEM_UNIT_DIR systemd systemdsystemunitdir)
endif()

install (TARGETS pciemdrv2app DESTINATION bin)

install (FILES  ${PROJECT_SOURCE_DIR}/service_files/pcie-mdrv2.service
    DESTINATION "${SYSTEMD_SYSTEM_UNIT_DIR}")

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/src/pcie-ipmi-blobs)
add_library (pciestore SHARED src/pcie-ipmi-blobs/handler.cpp
             src/pcie-ipmi-blobs/main.cpp)
set_target_properties (pciestore PROPERTIES VERSION "0.0.0")
set_target_properties (pciestore PROPERTIES SOVERSION "0")
target_link_libraries (pciestore sdbusplus)
target_link_libraries (pciestore phosphor_logging)
install (TARGETS pciestore DESTINATION /usr/lib/ipmid-providers)
