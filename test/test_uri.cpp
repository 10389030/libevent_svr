#include <gtest/gtest.h>
#include "../protocal/http.h"

TEST(URI, HandleNoneZeroInput) {
    auto uri1 = protocal::http::URI("http://xjw:123@baidu.com:80/path?abc=x&y=w#aa");   
    auto uri2 = protocal::http::URI("https://example.org/absolute/URI/with/absolute/path/to/resource.txt");
    auto uri3 = protocal::http::URI("https://example.org/absolute/URI/with/absolute/path/to/resource");
    auto uri4 = protocal::http::URI("ftp://example.org/resource.txt");
    auto uri5 = protocal::http::URI("urn:ISSN:1535-3613");
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
