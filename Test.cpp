/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {
    CHECK(snowman(33232124) == string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    /* Add more checks here */
}
TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11161111));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11181111));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11111117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(15111112));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111115));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111112));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111678));
    /* Add more checks here */
}
/* Add more test cases here */
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11116786));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(1178971117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111111112));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11146117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11154353));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(111543517));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(17));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(146117));
    /* Add more checks here */
}
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(1116456467));
    /* Add more checks here */
}
