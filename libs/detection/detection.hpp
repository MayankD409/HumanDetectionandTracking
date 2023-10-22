#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <opencv2/opencv.hpp>
#include <iostream> // for input/output operations
#include <vector>   // for using std::vector
class DetectionClass {
public:
    DetectionClass(const std::string& modelPath, const std::string& configPath);
    ~DetectionClass();
    bool initVideoStream(int deviceID);  // Initialize video stream from camera
    std::vector<cv::Rect> detectFaces(); // Detect faces in the current frame

private:
    cv::dnn::Net faceDetectionModel;
    cv::VideoCapture videoCapture;
};

#endif // DETECTION_HPP
