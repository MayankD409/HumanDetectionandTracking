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

class DetectionClass;
/**
 * @class TrackingClass
 * @brief A class for Tracking Subjects on the Frame.
 *
 * This class takes the Image Frames as an inout and will
 * track any Human subjects as and when they are detected in the frame
 */
class TrackingClass {
 public:
  std::vector<std::map<int, cv::Rect>> obstacleMapVector;
  /**
   * @brief Constructor for TrackingClass.
   */
  TrackingClass(const std::string& detectModelPath, const std::string& detectConfigPath);

  /**
   * @brief Destructor for TrackingClass.
   */
  ~TrackingClass();

  /**
   * @brief Finds the depth of an object.
   * The function will be called by distFromCamera() to get the 
   * @param id The ID of the bounding box whose depth needs to be found
   * @return Depth value.
   */
  double findDepth(int id);

 private:
  DetectionClass image;

  /**
   * @brief Assigns IDs to objects.
   * @return A map containing object IDs and descriptions.
   * The function is called after face detection.
   * The function assigns unique IDs in the first iteration of face detection.
   * In subsequent iterations, the function will compare the the current obstacleMapVector with the
   * new face detection and assign IDs to the new bounding box based on minimum Euclidean Distance
   */
 std::vector<std::map<int, cv::Rect>> assignIDAndTrack(const std::vector<cv::Rect>& detections);

  /**
   * @brief Calculates the distance of an object from the camera.
   * @return A vector containing the ID and a tuple containing x distance, y distance, and z distance
   * of the corresponding ID.
   * The function computes the x and y distance and calls findDepth() to get the z distance.
   */
  std::vector<int, std::tuple<double, double, double>> distFromCamera();

  /**
   * @brief Calculates the distance of an object from a car.
   * The function takes in distance from camera frame and performs a transformation to get the distance
   * from robot frame.
   * @param inputTuple Input tuple containing object information.
   * @return A tuple containing x distance, y distance, and z distance from robot reference frame.
   */
  std::tuple<double, double, double> distFromCar(
      const std::tuple<double, double, double>& inputTuple);
};

#endif