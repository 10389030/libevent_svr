MESSAGE(STATUS "Using bundled Findlibevent.cmake...")

FIND_PATH (
    LIBDB_CXX_INCLUDE_DIR
    event.h
    /usr/include/
    /usr/local/include/
    /usr/local/Cellar/libevent/2.0.22/include/
)

FIND_LIBRARY (
    LIBDB_CXX_LIBRARIES NAMES event
    PATHS /usr/lib/ /usr/local/lib/ /usr/local/Cellar/libevent/2.0.22/lib/
)
