#include <iostream>
#include <opencv2/opencv.hpp>

// Function to simulate laser cutting
void cutCircle(cv::Mat& image, cv::Point center, int radius) {
    cv::circle(image, center, radius, cv::Scalar(0, 0, 255), -1); // Draw a red filled circle
}

// Function to simulate drilling a hole
void drillHole(cv::Mat& image, cv::Point center, int radius) {
    cv::circle(image, center, radius, cv::Scalar(255, 255, 255), -1); // Draw a white filled circle
}

int main() {
    // Simulation parameters
    int diskRadius = 200;
    int circleRadius = 50;
    int holeRadius = 10;
    cv::Point circleCenter(diskRadius, diskRadius);
    cv::Point holeCenter(diskRadius, diskRadius);

    // Create a black image to simulate the disk
    cv::Mat disk = cv::Mat::zeros(2 * diskRadius, 2 * diskRadius, CV_8UC3);

    // Simulate camera capturing
    cv::imshow("Disk with circle", disk);
    cv::waitKey(0);

    // Simulate laser cutting
    cutCircle(disk, circleCenter, circleRadius);

    // Simulate drilling a hole
    drillHole(disk, holeCenter, holeRadius);

    // Show the result after laser cutting and drilling
    cv::imshow("Disk with circle cut out and hole drilled", disk);
    cv::waitKey(0);

    // Save the result to a file
    cv::imwrite("disk_with_circle_cut_out_and_hole_drilled.png", disk);

    return 0;
}
