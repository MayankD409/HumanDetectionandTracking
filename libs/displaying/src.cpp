/**
 * @file src.cpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class declaration for the DisplayClass
 * @version 0.1
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "displaying.hpp"

/**
 * @brief Default constructor.
 */
DisplayClass::DisplayClass() {
  // Constructor implementation
}

/**
 * @brief Default destructor.
 */
DisplayClass::~DisplayClass() {
  // Destructor implementation
}

/**
 * @brief Draws object locations and additional information on the video frame.
 * @param frame The input video frame.
 * @param objectLocations Vector of tuples containing object ID, bounding box
 * @return Modified video frame with bounding boxes and object information.
 */
cv::Mat DisplayClass::drawObjectLocations(
    const cv::Mat& frame,
    const std::vector<std::tuple<int, cv::Rect>>& objectLocations) {
  cv::Mat resultFrame = frame.clone();

  // Placeholder implementation: Add your logic here to draw object information
  // on the frame. Loop through objectLocations and draw information on
  // resultFrame.

  return resultFrame;
}
