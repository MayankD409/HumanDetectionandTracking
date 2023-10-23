/**
 * @file tracking.hpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class Definition for the TrackingClass
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 */

#ifndef TRACKING_HPP
#define TRACKING_HPP

#include <map>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>

/**
 * @class TrackingClass
 * @brief A class for Tracking Subjects on the Frame.
 *
 * This class takes the Image Frames as an inout and will
 * track any Human subjects as and when they are detected in the frame
 */
class TrackingClass {
 public:
  /**
   * @brief Constructor for TrackingClass.
   */
  TrackingClass();

  /**
   * @brief Destructor for TrackingClass.
   */
  ~TrackingClass();

  /**
   * @brief Finds the depth of an object.
   * @return Depth value.
   */
  double find_depth();

 private:
  /**
   * @brief Assigns IDs to objects.
   * @return A map containing object IDs and descriptions.
   */
  std::map<int, std::string> assignID();

  /**
   * @brief Calculates the distance of an object from the camera.
   * @return A tuple containing object ID, distance, and description.
   */
  std::tuple<int, double, std::string> distFromCamera();

  /**
   * @brief Calculates the distance of an object from a car.
   * @param inputTuple Input tuple containing object information.
   * @param intOffset Integer offset.
   * @param doubleOffset Double offset.
   * @return A tuple containing object ID, distance, and description.
   */
  std::tuple<int, double, std::string> distFromCar(
      const std::tuple<int, double, std::string>& inputTuple, int intOffset,
      double doubleOffset);

  /**
   * @brief Starts object tracking.
   */
  void track();
};

#endif