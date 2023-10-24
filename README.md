
# Overview

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
Graduate Student in Enginnering - Robotics at University of Maryland, College Park

Lowell Lobo:-
Graduate Student in Enginnering - Robotics at University of Maryland, College Park

Mayank Deshpande:-
Graduate Student in Enginnering - Robotics at University of Maryland, College Park

# Links
[AIP Google Sheet](https://docs.google.com/spreadsheets/d/17q5Q-qL-ZU2LQK8llQSjsIJ8_037MAFyNenNofpY_PI/edit#gid=0)

[Sprint Notes](https://docs.google.com/document/d/1UX6oGidNdux2FeOGgIjD-ivvmi8oCiHlf1OJARla3Ro/edit)


# Process

The project development will be executed using pair programming concepts. For all specific tasks, driver and navigator roles will be swapped. 
The project will follow AIP concepts and be performed using Pair Programming. The module works such that a video is fed into the system using the monocular camera. 
The program then converts the video stream into image frames and performs human obstacle detection. 
Once obstacles are found in the image frame, unique IDs are assigned to the objects, which will hold the calculated current location with respect to the robot reference frame. 
The process is repeated over time for tracking of obstacle movement.
Testing of components is performed using GoogleTest, and system testing will be performed every iteration for overall functionality verification.


# API Information
The API contains three libraries,
<br>
1 - detection library
<br>
The library is used to initialise and access the Video Stream and runs face detection to find human obstacles in the image frame.

It consists of two method:-
<br>
 - initVideoStream()
 - detectFaces()
<br>
2 - tracking library
<br>
The library is used to find the (x, y, z) coordinates of the obstacle with respect to the robot reference frame. The library also tracks the motion of obstacles by assigning a unique ID to each object.

It consists of four methods:-
<br>
 - assignIDAndTrack()
 - distFromCamera()
 - distFromCar()
 - findDepth()
<br>
3 - displaying library
<br>
The library is used to interface with the tracking library and output a video showing the tracking of objstacles.

It consists of one method:-
<br>
 - drawObjectLocations()
 

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

# Run program:
  ./build/app/human-tracker
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

## Alternate method to make & view Doxygen Documentation
# Download & Build Doxygen
```bash
# Download doxygen
  sudo apt-get install doxygen
# To build documentation
  doxygen dconfig
```


## Building for code coverage (for assignments beginning in Week 4)

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