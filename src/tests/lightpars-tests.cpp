#include "gtest/gtest.h"
#include "lightpars.hpp"

using namespace lightparse;

TEST(Instantiation, ParserClass)
{
    ASSERT_NO_THROW(Parser());
}

TEST(CmdlineParsing, ArgumentsSplit1)
{
    int argc = 3;
    const char *argv[] = {"./program", "-v", "28"};
    Parser p;
    p.parseCmdline(argc, argv);
    const Parser::KeyValsArray& arr = p.keyValsArray();
    ASSERT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0].first,  "-v");
    EXPECT_EQ(arr[0].second, "28");
}

TEST(CmdlineParsing, ArgumentsSplit2)
{
    int argc = 7;
    const char *argv[] = {
        "./program",
        "-v", "28",
        "--good-value", "qwe",
        "--disable-anything",
        "--other-value=3.1415",
    };
    Parser p;
    p.parseCmdline(argc, argv);
    const Parser::KeyValsArray& arr = p.keyValsArray();
    ASSERT_EQ(arr.size(), 4);
    EXPECT_EQ(arr[0].first,  "-v");                  EXPECT_EQ(arr[0].second, "28");
    EXPECT_EQ(arr[0].first,  "--good-value");        EXPECT_EQ(arr[0].second, "qwe");
    EXPECT_EQ(arr[0].first,  "--disable-anything");  EXPECT_EQ(arr[0].second, "");
    EXPECT_EQ(arr[0].first,  "--other-value");       EXPECT_EQ(arr[0].second, "3.1415");
}
