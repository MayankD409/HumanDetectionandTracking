![CICD Workflow status](https://github.com/MayankD409/Human_Tracking_CPP/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/MayankD409/Human_Tracking_CPP/graph/badge.svg?token=WUFHUBTG05)](https://codecov.io/gh/MayankD409/Human_Tracking_CPP) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


This repository consists of deliverables for the Midterm Project for,
 - Lowell Lobo (120095719)
 - Kautilya Chappidi (120380204)
 - Mayank Deshpande (120387333)

# Project Overview

Perception is essential for object detection, environmental awareness, path planning and control; through perception, a system can truly be considered autonomous. Acme requires the development of a perception component in its autonomous car system, and a human obstacle detection and tracking module needs to be built.
The aim is to build a perception module to detect human objects and track their location directly into the robot reference frame.
The location will first be found with respect to the camera's reference frame and then using a transformation, the location with respect to the robot reference frame will be found.
The module is built such that, the system that implements it will consists of a camera mounted on a car that will keep track of human motion within the camera’s field of view. But the module will be unable to handle occlusion cases.

## Assumption

The camera used for perception will be placed on the top of the car. The camera reference frame is taken such that the z-axis is pointing out of the lens, the x-axis is to the right, and the y-axis is pointing downward. The robot reference frame is at the centre of mass where the z-axis points upward, and the x-axis is to the right, and the y-axis points straight ahead. We assume the camera is monocular, and the user must input most of the configuration information

## Features

 - Detection of human obstacles and tracking using monocular camera
 - Location of human obstacle with respect to robot reference frame
 - DisplayClass to implement and test the module

## Deliverables

 - C++ library/API for human obstacle and tracking
 - GitHub Repository with CI and CodeCov
 - UML and Dependency Diagrams
 - Doxygen Documentation

## Constraints

The module uses a monocular camera and is unable to handle occlusions. Also, the monocular camera cannot perform precise depth calculation and thus would require a deep learning model for accurate estimation. The runtime fps and memory management depend on the physical constraints of the system.


# Personnel

Kautilya Chappiddi:-
<br>
Graduate Student in Enginnering - Robotics at University of Maryland, College Park

Lowell Lobo:-
<br>
Graduate Student in Enginnering - Robotics at University of Maryland, College Park

Mayank Deshpande:-
<br>
Graduate Student in Enginnering - Robotics at University of Maryland, College Park


# Process

The project development will be executed using pair programming concepts. For all specific tasks, driver and navigator roles will be swapped. 
The project will follow AIP concepts and be performed using Pair Programming. The module works such that a video is fed into the system using the monocular camera. 
The program then converts the video stream into image frames and performs human obstacle detection. 
Once obstacles are found in the image frame, unique IDs are assigned to the objects, which will hold the calculated current location with respect to the robot reference frame. 
The process is repeated over time for tracking of obstacle movement.
Testing of components is performed using GoogleTest, and system testing will be performed every iteration for overall functionality verification.


# AIP Methodology

The project was implemented using Agile Iterative Process (AIP) along with pair programming and a test-driven development approach. Product backlog, iteration backlogs for each phase and work log have been created.
Each iteration started with a meeting to discuss the agenda and ends with a sprint review.


# Links
[AIP Google Sheet](https://docs.google.com/spreadsheets/d/17q5Q-qL-ZU2LQK8llQSjsIJ8_037MAFyNenNofpY_PI/edit#gid=0)

[Sprint Notes](https://docs.google.com/document/d/1UX6oGidNdux2FeOGgIjD-ivvmi8oCiHlf1OJARla3Ro/edit)


# Dependencies
The project uses the OpenCV library to read video frame, perform image processing and run inference.
<br>
Together with OpenCV, a pretrained ResNet Caffemodel is used in the implementation.

# Installing Dependencies
OpenCV can be installed as follows,
```bash
  sudo apt install libopencv-dev
```

# API Information
The API contains three libraries,
<br>

### 1 - detection library
<br>
The library is used to initialise and access the Video Stream and runs face detection to find human obstacles in the image frame.

It consists of two method and a constructor:-
<br>
 - initVideoStream()
 - detectFaces()
<br>
  -- Constructor
 <br>
    The constructor initialises the detection model in OpenCV using the readNet() method
<br>
<br>
  -- initVideoStream()
<br>
    The VideoStream is initialised to constantly read image frames from the camera setup.
<br>
<br>
  -- detectFaces()
    Uses the model that was initialised to detect faces in the image frame and return bounding boxes above a confidence level in the format cv::Rect
<br>
<br>

### 2 - tracking library
<br>
The library is used to find the (x, y, z) coordinates of the obstacle with respect to the robot reference frame. The library also tracks the motion of obstacles by assigning a unique ID to each object.

It consists of four methods:-
<br>
 - assignIDAndTrack()
 - distFromCamera()
 - distFromCar()
 - findDepth()
<br>
  -- assignIDAndTrack()
<br>
    This method receives the bounding boxes and returns the bounding boxes with a unique ID assigned to them.
    If there are no IDs assigned, the algorithm assigns IDs to each detection.
    If the number of detections are equal to the number of IDs assigned, the algorithm computes and assigns IDs based on minimum Euclidean distance between detection. This consists the tracking feature.
    If the number of detections are greater than the number of assigned IDs, then the algorithm reassigns the correct IDs to the corresponding detection and assigns new IDs to the new detections.
    If the number of detections are lesser than the number of assigned IDs, 
    if the detection is near the edge and the minimum Euclidean distance is greater than a specific value then the ID is deallocated. But if the detection is lost in the center of the frame, false detection is assumed, and the detection with ID is retained. If all conditions above are not met, the ID is reassigned.
<br>
<br>
  -- distFromCamera()
<br>
    This method takes in the the IDs mapped to the bounding boxes and returns the (x, y, z) pixel distance of the obstacle from the camera reference frame using geometry.
<br>
<br>
  -- distFromCar()
<br>
    This method takes in (x, y, z) pixel distance of the obstacle from the camera reference frame and returns the (x, y, z) distance of the obstacle from the car reference frame in inches. Rotation, Translation and geometry are used to find the distance in inches.
<br>
<br>
  -- findDepth()
<br>
    This method takes in the ID and returns the z distance in inches.
    The z distance is found analytically by using sampling and linearising the conversion function.
 
# Running the Application
## Build via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/

# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose

# Alternate method to build the project:
  # build compile_commands.json from scratch
  bear -- cmake --build build/ --clean-first
  # or, update the existing compile_commands.json
  bear --append -- cmake --build build/

# Run program for testing the actual application:
  ./build/app/human-tracker

# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

## Running Unit Tests
```bash
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
```

## Generate Documentation
### Method 1
```bash
# Download doxygen
  sudo apt-get install doxygen
# Build documentation
  doxygen dconfig
```
### Method 2
```bash
# Build docs:
  cmake --build build/ --target docs
```

### View Documentation
```bash
# open a web browser to browse the doc
  open docs/html/index.html
```

# Building for code coverage

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *human-tracker* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```


## compile_commands.json Errors
In case of error regarding the generation of compile_commands.json file,
Delete the compile_commands.json file and run the following
```bash
  bear -- cmake --build build/ --clean-first
```
