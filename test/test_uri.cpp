#include <gtest/gtest.h>
#include "protocal/http1.1/http.h"

TEST(URI, HandleNoneZeroInput) {
    auto uri = protocal::http::URI("http://baidu.com");   
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
