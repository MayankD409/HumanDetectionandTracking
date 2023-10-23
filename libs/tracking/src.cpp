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
TrackingClass::TrackingClass() {}

/**
 * @brief Default Destructor.
 */
TrackingClass::~TrackingClass() {}

/**
 * @brief Finds the depth of an object in the scene.
 * @return The depth of the object in meters.
 */
double TrackingClass::find_depth() { return 0.0; }

/**
 * @brief Assigns IDs to objects in the scene.
 * @return A map of object IDs to object names.
 */
std::map<int, std::string> TrackingClass::assignID() {
  return std::map<int, std::string>();
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
    const std::tuple<int, double, std::string> &inputTuple, int intOffset,
    double doubleOffset) {
  return std::tuple<int, double, std::string>();
}

/**
 * @brief Tracks objects in the scene.
 */
void TrackingClass::track() {}
