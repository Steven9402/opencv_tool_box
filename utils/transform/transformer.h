#ifndef TRANSFORMER_H_
#define TRANSFORMER_H_
#include <vector>
#include "opencv2/opencv.hpp"

namespace yfmao {
  int perspective_transform(std::vector<cv::Point2f> &src_pts, std::vector<cv::Point2f> &dst_pts,
                            cv::Mat &src_img, cv::Mat &dst_img, cv::Size size);
}

#endif