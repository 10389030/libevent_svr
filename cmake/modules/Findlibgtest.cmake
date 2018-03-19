MESSAGE(STATUS "Using bundled Findlibgtest.cmake...")

FIND_PATH (
    LIBDB_CXX_INCLUDE_DIR
    gtest/gtest.h
    /usr/include/
    /usr/local/include/
)

FIND_LIBRARY (
    LIBDB_CXX_LIBRARIES NAMES gtest gmock
    PATHS /usr/lib/ /usr/local/lib/
)
