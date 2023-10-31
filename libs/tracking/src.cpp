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
TrackingClass::TrackingClass(const std::string& detectModelPath,
                             const std::string& detectConfigPath)
    : image(detectModelPath, detectConfigPath) {}

/**
 * @brief Default Destructor.
 */
TrackingClass::~TrackingClass() {}

/**
 * @brief Finds the depth of an object in the scene.
 * @return The depth of the object in meters.
 */
double TrackingClass::findDepth(int id) { return 0.0; }

/**
 * @brief Assigns IDs to objects in the scene.
 * 
 * @param detections A vector containing all the detected faces in image frame
 * @return std::map<int, cv::Rect> A map of object IDs to object names.
 */
std::map<int, cv::Rect> TrackingClass::assignIDAndTrack(
    const std::vector<cv::Rect>& detections) {
  std::map<int, cv::Rect> assignedID;

  return assignedID;
}

/**
 * @brief 
 * 
 * @param frameWidth The pixel width of the image frame
 * @param frameHeight The pixel height of the image frame
 * @return std::map<int, std::tuple<double, double, double>> A map containing the object ID and tuple containing distance in meters
 */
std::map<int, std::tuple<double, double, double>>
TrackingClass::distFromCamera(int frameWidth, int frameHeight) {
  std::map<int, std::tuple<double, double, double>> distances;

  return distances;
}

/**
 * @brief Calculates the distance between an object and the car.
 *
 * @param input A map with containing the object ID, and tuple containing distance in meters
 * 
 *
 * @return A map with containing the object ID, and tuple containing distance in meters
 * 
 */
std::map<int, std::tuple<double, double, double>> TrackingClass::distFromCar(
    const std::map<int, std::tuple<double, double, double>>& input) {
  std::map<int, std::tuple<double, double, double>> distances;

  return distances;
}
