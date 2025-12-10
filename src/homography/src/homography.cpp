#include <filesystem>
#include <iostream>
#include <rclcpp/rclcpp.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Running the code
// colcon build
// ros2 run image_projection get_homography



int main()
{
    std::cout << "Hello World" << std::endl;

    std::cout << std::filesystem::current_path() <<std::endl;

    // read in images
    // TODO improve
    std::vector<cv::Mat> images;
    images.push_back(cv::imread("src/homography/images/im0.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("src/homography/images/im1.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("src/homography/images/im2.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("src/homography/images/im3.jpg", cv::IMREAD_COLOR));
    images.push_back(cv::imread("src/homography/images/im4.jpg", cv::IMREAD_COLOR));


    for(size_t i = 0; i < images.size(); ++i)
    {
        if(images[i].empty())
        {
            std::cout << "Could not read image " << i << std::endl;
            return 1;
        }

        std::cout << "Image " << i << std::endl;

        // SIFT feature detection
        cv::Ptr<cv::SiftFeatureDetector> detector = cv::SiftFeatureDetector::create();
        std::vector<cv::KeyPoint> keypoints;
        detector->detect(images[i], keypoints);

    }

    // view
    // std::string window_name = "main";

    // cv::namedWindow(window_name);

    // cv::Mat output;
    // cv::drawKeypoints(images[0], keypoints, output);
    // cv::imshow(window_name, output);
    // cv::waitKey(0);

    

    // Match Descriptors
    // Homography calc
    // Ransac
    // Display

}