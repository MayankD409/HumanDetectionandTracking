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

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>

#include "detection.hpp"
#include "displaying.hpp"
#include "tracking.hpp"

/**
 * @brief static TrackingClass object to be used in the unit test
 * 
 */
static TrackingClass obj_("abc", "def");

/**
 * @brief Construct a new TEST object.
 * unit test for checking the initVideoStream method of class DetectionClass
 */
TEST(unit_test_initialise_VideoStream, this_should_pass) {
  DetectionClass obj("abc", "def");
  bool val = obj.initVideoStream(0);

  EXPECT_TRUE(val);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the detectFaces method of class DetectionClass
 */
TEST(unit_test_detect_faces, this_should_pass) {
  DetectionClass obj("abc", "def");
  obj.initVideoStream(0);
  cv::Mat frame;
  obj.videoCapture >> frame;
  auto val = obj.detectFaces(frame);

  EXPECT_GT(val.size(), 0);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the assignIDAndTrack method of class TrackingClass
 */
TEST(unit_test_assign_ID, this_should_pass) {
  DetectionClass obj("abc", "def");
  obj.initVideoStream(0);
  cv::Mat frame;
  obj.videoCapture >> frame;
  auto val = obj.detectFaces(frame);
  auto ids = obj_.assignIDAndTrack(val);

  EXPECT_GT(ids.size(), 0);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the distFromCamera method of class TrackingClass
 */
TEST(unit_test_dist_from_camera, this_should_pass) {
  DetectionClass obj("abc", "def");
  obj.initVideoStream(0);
  cv::Mat frame;
  obj.videoCapture >> frame;
  auto val = obj.detectFaces(frame);
  obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
  auto distCamera = obj_.distFromCamera();

  EXPECT_GT(distCamera.size(), 0);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the distFromCar method of class TrackingClass
 */
TEST(unit_test_dist_from_car, this_should_pass) {
  DetectionClass obj("abc", "def");
  obj.initVideoStream(0);
  cv::Mat frame;
  obj.videoCapture >> frame;
  auto val = obj.detectFaces(frame);
  obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
  auto distCamera = obj_.distFromCamera();
  auto distCar = obj_.distFromCar(distCamera.front().begin()->second);

  EXPECT_GT(std::get<0>(distCar) + std::get<1>(distCar) + std::get<2>(distCar),
            0);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the findDepth method of class TrackingClass
 */
TEST(unit_test_find_depth, this_should_pass) {
  DetectionClass obj("abc", "def");
  obj.initVideoStream(0);
  cv::Mat frame;
  obj.videoCapture >> frame;
  auto val = obj.detectFaces(frame);
  obj_.obstacleMapVector = obj_.assignIDAndTrack(val);
  auto depth = obj_.findDepth(1);

  EXPECT_NEAR(depth, 5, 0.001);
}

/**
 * @brief Construct a new TEST object.
 * unit test for checking the drawObjectLocations method of class DisplayClass
 */
TEST(unit_test_draw_object, this_should_pass) {
  cv::Mat rect = cv::Mat::zeros(1, 1, CV_64F);
  std::vector<std::tuple<int, cv::Rect>> draw = {{1, cv::Rect(1, 1, 5, 5)}};
  DisplayClass obj;
  auto response = obj.drawObjectLocations(rect, draw);
  auto check = cv::countNonZero(response);

  EXPECT_NE(check, 0);
}
