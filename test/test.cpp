/**
 * @file test.cpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Defines unit tests to be run and verified using GitHub Actions
 * It helpes in testing detection, displaying and tracking classes
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "detection.hpp"

TEST(unit_test_initialise_VideoStream, this_should_pass) {
    DetectionClass obj("abc", "def");
    bool val = obj.initVideoStream(0);
    
    EXPECT_TRUE(val); 
}

TEST(dummy_test, this_should_pass) {
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    
    EXPECT_GT(val.size(), 0); 
}