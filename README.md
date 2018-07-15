# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

[//]: # (Image References)
[img1]: ./img/pid.png

## Project Summary
This is my submission for Udacity self-driving Nanodegree PID controller project. A PID controller is implemented and tuned to drive a self-driving car around a lake track. The tuned controller can drive the car to follow the road center reasonably well without oscillating around. 

### Effect of P, I, and D terms
PID controller is a simple yet effect controller to control dynamical systems. With much knowledge of the model, we can quickly design and implement a PID controller for self driving car. The P terms is directly proportionally to the cross-track-error (CTE), so it is the most important term to correct the tracking error. Large P term corresponds to quick reaction to the CTE, but also leads to overshoot. The D term on the other hand can use the derivative of the CTE to predict the changes in CTE, and mitigate the overshoot of the controller. When there is a constant bias in the system (by inaccurate model, or the disturbance), it can be addressed by the I term, which integrates the error and eliminates the drift.


### Hyper Parameter Tuning
The hyper parameters for this project are tuned manually. Although other auto-tuning method like twiddle and SGD can be used, I found manually tuning to be easy and effective. I started by setting I and D terms to zero. The P term is adjusted such that the car can stay on road, and oscillations are expected and allowed in this early stage. With an appropriate P term, I started increasing the D gain such that the overshoot behavior is gradually eliminated. It is also observed that the D term cannot be too large. Large D will cancel out the effect of P term, and the car will stop move to the lane center before it actually reaches the lane center. With the appropriate P and D gains, the car can already follow the lane center pretty well. But understeering is observed at the high curvature part of the road. A small I term is then added to make the behavior at the turns work better. Too large I term will integrate the error too much and cause oscillations as well. The tuned final PID gains I use are:
```
P gain: 0.15; I gain: 5e-3; D gain 3.
```
As evidenced by the final video, the tuned PID controller can drive the car to follow lane center very well without much oscillation.

### Final video (click on the image to view the youtube video)
[![pid_video][img1]](https://youtu.be/remtNaEYCFU)

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

