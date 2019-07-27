#include "transformer"
namespace yfmao {
  int perspective_transform(std::vector<cv::Point2f> &src_pts, std::vector<cv::Point2f> &dst_pts,
                            cv::Mat &src_img, cv::Mat &dst_img, cv::Size size) {
    cv::Mat H = cv::findHomography(src_pts, dst_pts, RANSAC);//计算透视矩阵
    cv::warpPerspective(src_img, dst_img, H, dst_img.size());//图像透视变换
  }
}