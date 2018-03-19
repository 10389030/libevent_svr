MESSAGE(STATUS "Using bundled Findlibglog.cmake...")

FIND_PATH (
    LIBDB_CXX_INCLUDE_DIR
    glog/logging.h
    /usr/include/
    /usr/local/include/
    /usr/local/Cellar/glog/0.3.5_3/include
)

FIND_LIBRARY (
    LIBDB_CXX_LIBRARIES NAMES glog
    PATHS /usr/lib/ /usr/local/lib/ /usr/local/Cellar/glog/0.3.5_3/lib/
)
