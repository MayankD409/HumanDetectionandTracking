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
#include <utility>
#include "detection.hpp"
#include "tracking.hpp"

static TrackingClass obj_("abc", "def");

TEST(unit_test_initialise_VideoStream, this_should_pass) {
    DetectionClass obj("abc", "def");
    bool val = obj.initVideoStream(0);
    
    EXPECT_TRUE(val); 
}

TEST(unit_test_detect_faces, this_should_pass) {
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    
    EXPECT_GT(val.size(), 0); 
}

TEST(unit_test_assign_ID, this_should_pass){
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    auto ids = obj_.assignIDAndTrack(val);

    EXPECT_GT(ids.size(), 0);
}

TEST(unit_test_dist_from_camera, this_should_pass){
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
    auto distCamera = obj_.distFromCamera();

    EXPECT_GT(distCamera.size(), 0);
}

TEST(unit_test_dist_from_car, this_should_pass){
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
    auto distCamera = obj_.distFromCamera();
    auto distCar = obj_.distFromCar(distCamera.front().begin()->second);

    EXPECT_GT(std::tuple_size<decltype(distCar)>::value, 0);
}

TEST(unit_test_find_depth, this_should_pass){
    DetectionClass obj("abc", "def");
    obj.initVideoStream(0);
    auto val = obj.detectFaces();
    obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
    auto depth = obj_.findDepth(1);

    EXPECT_NEAR(depth, 5, 0.001);
}