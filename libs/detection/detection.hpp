/**
 * @file detection.hpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class Definition for DetectionClass
 * @version 0.1
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <iostream>  // for input/output operations
#include <opencv2/opencv.hpp>
#include <vector>  // for using std::vector

/**
 * @class DetectionClass
 * @brief A class for performing face detection using a deep learning model.
 *
 * This class initializes a face detection model and provides functions to
 * initialize a video stream from a camera and detect faces in the frames
 * obtained from the video stream.
 */
class DetectionClass {
 public:
  /**
   * @brief Constructor to initialize the DetectionClass object.
   * @param modelPath Path to the pre-trained face detection model file.
   * @param configPath Path to the configuration file for the model.
   */
  DetectionClass(const std::string& modelPath, const std::string& configPath);

  /**
   * @brief Destructor to release resources used by DetectionClass.
   */
  ~DetectionClass();

  /**
   * @brief Initialize the video stream from the specified camera device.
   * @param deviceID Identifier of the camera device (usually 0 for the default
   * camera).
   * @return True if the video stream is successfully opened, false otherwise.
   */
  bool initVideoStream(int deviceID);

  /**
   * @brief Detect faces in the current frame obtained from the video stream.
   * @return A vector of cv::Rect representing the detected faces' bounding
   * boxes and draw rectangle.
   */
  std::vector<cv::Rect> detectFaces(cv::Mat& frame);
  cv::VideoCapture videoCapture;  ///< Video capture object for accessing frames
                                  ///< from the camera.

 private:
  cv::dnn::Net faceDetectionModel;  ///< Deep learning face detection model.
  float confidenceThreshold = 0.5;
};

#endif  // DETECTION_HPP
