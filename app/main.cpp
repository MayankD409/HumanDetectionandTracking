/**
 * @file main.cpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief The main application of the project, will be used to test the
 * implementation in the future.
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <opencv2/imgcodecs.hpp>

#include "tracking.hpp"

/**
 * @brief The main method of the file used to test and check whether the library
 * works as intended
 *
 * @return int
 */
int main() {
  /**
   * @brief variables used to get the natural configuration of camera and car
   *
   */
  double x, y, z, th, tv;
  std::cout << "Enter x offset distance in inches: ";
  std::cin >> x;
  std::cout << std::endl << "Enter y offset distance in inches: ";
  std::cin >> y;
  std::cout << std::endl << "Enter z offset distance in inches: ";
  std::cin >> z;
  std::cout << std::endl << "Enter horizontal field of view angle in radians: ";
  std::cin >> th;
  std::cout << std::endl << "Enter vertical field of view angle in radians: ";
  std::cin >> tv;

  /**
   * @brief Initialise a tracker class to be used for tracking obstacles
   *
   */
  TrackingClass tracker(
      "models/res10_300x300_ssd_iter_140000_fp16.caffemodel",
      "models/deploy.prototxt", x, y, z, th, tv);

  /**
   * @brief Initialise the video
   *
   */
  if (!tracker.image.initVideoStream(0)) {
    return 0;
  }

  /**
   * @brief Initialise a frame
   *
   */
  cv::Mat frame;

  while (true) {
    tracker.image.videoCapture >> frame;

    /**
     * @brief Get detections and store in variable rectangles
     *
     */
    auto rectangles = tracker.image.detectFaces(frame);

    /**
     * @brief Assign IDs to the detections
     *
     */
    tracker.obstacleMapVector = tracker.assignIDAndTrack(rectangles);

    /**
     * @brief Find distance from camera frame
     *
     */
    auto cameraDistance = tracker.distFromCamera(frame.cols, frame.rows);

    /**
     * @brief Find distance from car frame in inches
     *
     */
    auto carDistance = tracker.distFromCar(cameraDistance);

    cv::Scalar color(0, 105, 205);

    /**
     * @brief Draw rectangles for the detections and the distances
     *
     */
    for (const auto& r : tracker.obstacleMapVector) {
      cv::rectangle(frame, r.second, color, 4);
      cv::putText(frame,
                  std::to_string(r.first) + ": (" +
                      std::to_string(
                          static_cast<int>(std::get<0>(carDistance[r.first]))) +
                      ", " +
                      std::to_string(
                          static_cast<int>(std::get<1>(carDistance[r.first]))) +
                      ", " +
                      std::to_string(
                          static_cast<int>(std::get<2>(carDistance[r.first]))) +
                      ")",
                  cv::Point(r.second.x, r.second.y - 5),
                  cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(255, 0, 0), 2);
    }

    /**
     * @brief Display the frame
     *
     */
    imshow("Image", frame);
    int esc_key = 27;
    if (cv::waitKey(10) == esc_key) {
      break;
    }
  }

  cv::destroyAllWindows();
}
