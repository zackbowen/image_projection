#include <iostream>
#include <rclcpp/rclcpp.hpp>

#include <opencv4/opencv2/opencv.hpp>

// Running the code
// colcon build
// ros2 run image_projection get_homography



int main()
{
    std::cout << "Hello World" << std::endl;

    // read in images
    std::vector<cv::Mat> images;
    images.push_back(cv::imread("homography/images/im0.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("homography/images/im1.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("homography/images/im2.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("homography/images/im3.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("homography/images/im4.jpg", cv::IMREAD_COLOR));


    for(size_t i = 0; i < images.size(); ++i)
    {
        if(images[i].empty())
        {
            std::cout << "Could not read image " << i << std::endl;
            return 1;
        }
        
    }

    // SIFT feature detection

    

    // Match Descriptors
    // Homography calc
    // Ransac
    // Display

}