/**
 * @file src.cpp
 * @author Lowell Lobo
 * @author Mayank Deshpande
 * @author Kautilya Chappidi
 * @brief Class declaration for the DetectionClass
 * @version 0.1
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "detection.hpp"

/**
 * @brief Constructor for the DetectionClass.
 * @param modelPath Path to the pre-trained face detection model file.
 * @param configPath Path to the configuration file for the model.
 */
DetectionClass::DetectionClass(const std::string& modelPath,
                               const std::string& configPath)
    : faceDetectionModel(cv::dnn::readNet(modelPath, configPath)) {
  // Initialize the face detection model with the provided paths
}

/**
 * @brief Destructor for the DetectionClass.
 */
DetectionClass::~DetectionClass() { videoCapture.release(); }

/**
 * @brief Initialize the video stream from the specified camera device.
 * @param deviceID Identifier of the camera device (usually 0 for the default
 * camera).
 * @return True if the video stream is successfully opened, false otherwise.
 */
bool DetectionClass::initVideoStream(int deviceID) {
  // Initialize the video stream from the specified device (camera)
  // Return true if successfully opened, false otherwise
  if (deviceID < 0) {
    return false;
  }
  videoCapture.open(deviceID);
  return videoCapture.isOpened();
}

/**
 * @brief Detect faces in the current frame obtained from the video stream.
 * @return A vector of cv::Rect representing the detected faces' bounding boxes.
 */
std::vector<cv::Rect> DetectionClass::detectFaces(cv::Mat& frame) {
  // Process a frame from the video stream and perform face detection
  // Return a vector of cv::Rect representing detected faces
  std::vector<cv::Rect> detectedFaces;

  // Preprocess the frame and detect faces using the ResNet face detection model
  cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300),
                                        cv::Scalar(104, 117, 123));
  faceDetectionModel.setInput(blob);
  cv::Mat detections = faceDetectionModel.forward();
  // std::cerr << detections.size() << std::endl;

  cv::Mat detection_matrix(detections.size[2], detections.size[3], CV_32F,
                           detections.ptr<float>());
  std::cerr << detection_matrix.size() << std::endl;

  for (int i = 0; i < detection_matrix.rows; i++) {
    float confidence = detection_matrix.at<float>(i, 2);
    if (confidence > confidenceThreshold) {
      // Get normalized coordinates from the detection output
      int x1 = static_cast<int>(detection_matrix.at<float>(i, 3) * frame.cols);
      int y1 = static_cast<int>(detection_matrix.at<float>(i, 4) * frame.rows);
      int x2 = static_cast<int>(detection_matrix.at<float>(i, 5) * frame.cols);
      int y2 = static_cast<int>(detection_matrix.at<float>(i, 6) * frame.rows);

      cv::Rect faceRect(x1, y1, x2 - x1, y2 - y1);

      // cv::rectangle(frame, faceRect, cv::Scalar(0, 255, 0),2, 4);

      // Store the detected face's bounding box
      detectedFaces.push_back(faceRect);
    }
  }

  return detectedFaces;
}
