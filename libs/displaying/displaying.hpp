/**
 * @file displaying.hpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class Definition for the DisplayClass
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <opencv2/core.hpp>
#include <string>
#include <tuple>
#include <vector>

/**
 * @class DisplayClass
 * @brief A class for displaying object locations and additional information on
 * the video stream.
 *
 * This class provides functions to draw bounding boxes around detected objects
 * and display additional information on top of the bounding boxes.
 */
class DisplayClass {
 public:
  /**
   * @brief Default constructor.
   */
  DisplayClass();

  /**
   * @brief Default destructor.
   */
  ~DisplayClass();

  /**
   * @brief Draws object locations and additional information on the video
   * frame.
   * @param frame The input video frame.
   * @param objectLocations Vector of tuples containing object ID, bounding box
   * @return Modified video frame with bounding boxes and object information.
   */
  cv::Mat drawObjectLocations(
      const cv::Mat& frame,
      const std::vector<std::tuple<int, cv::Rect>>& objectLocations);
};

#endif  // DISPLAY_HPP
