/**
 * @file src.cpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class Decleration for the TrackingClass
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "tracking.hpp"

/**
 * @brief Default constructor.
 */
TrackingClass::TrackingClass(const std::string& modelPath, const std::string& configPath) : image(const std::string& modelPath, const std::string& configPath) {}

/**
 * @brief Default Destructor.
 */
TrackingClass::~TrackingClass() {}

/**
 * @brief Finds the depth of an object in the scene.
 * @return The depth of the object in meters.
 */
double TrackingClass::findDepth() { return 0.0; }

/**
 * @brief Assigns IDs to objects in the scene.
 * @return A map of object IDs to object names.
 */
std::vector<std::map<int, cv::Rect>> TrackingClass::assignIDAndTrack(const std::vector<cv::Rect> &detections) {
  return std::vector<std::map<int, cv::Rect>>();
}

/**
 * @brief Calculates the distance between an object and the camera.
 *
 * @return A tuple containing the object ID, distance in meters, and object
 * name.
 */
std::tuple<int, double, std::string> TrackingClass::distFromCamera() {
  return std::tuple<int, double, std::string>();
}

/**
 * @brief Calculates the distance between an object and the car.
 *
 * @param inputTuple A tuple containing the object ID, distance in meters, and
 * object name of the other object.
 * @param intOffset An offset to add to the object ID.
 * @param doubleOffset An offset to add to the distance in meters.
 *
 * @return A tuple containing the object ID, distance in meters, and object name
 * of the object being calculated.
 */
std::tuple<int, double, std::string> TrackingClass::distFromCar(
    const std::tuple<double, double, double> &inputTuple) {
  return std::tuple<int, double, std::string>();
}

