#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <opencv2/opencv.hpp>
#include <iostream> // for input/output operations
#include <vector>   // for using std::vector

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
     * @param deviceID Identifier of the camera device (usually 0 for the default camera).
     * @return True if the video stream is successfully opened, false otherwise.
     */
    bool initVideoStream(int deviceID);

    /**
     * @brief Detect faces in the current frame obtained from the video stream.
     * @return A vector of cv::Rect representing the detected faces' bounding boxes.
     */
    std::vector<cv::Rect> detectFaces();

private:
    cv::dnn::Net faceDetectionModel; ///< Deep learning face detection model.
    cv::VideoCapture videoCapture;   ///< Video capture object for accessing frames from the camera.
};

#endif // DETECTION_HPP
