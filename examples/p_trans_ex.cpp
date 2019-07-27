#include  "transformer.h"

#include<opencv2/xfeatures2d.hpp>
using namespace cv;
using namespace xfeatures2d;
using namespace std;

vector<Point2f> srcTri(4);
vector<Point2f> dstTri(4);
int clickTimes = 0;  //在图像上单击次数
Mat src,dst;

void onMouse(int event, int x, int y, int flags, void *utsc) {
  if (event == CV_EVENT_LBUTTONUP) {
    circle(src, Point(x, y), 2, Scalar(0, 0, 255), 2);  //标记选中点
    imshow("wait ", src);
    srcTri[clickTimes].x = x;
    srcTri[clickTimes].y = y;
    clickTimes++;
  }
  if (clickTimes == 4) {
    dstTri[0].x = 0;
    dstTri[0].y = 0;	
    dstTri[1].x = 282;
    dstTri[1].y = 0;
    dstTri[2].x = 282 ;
    dstTri[2].y = 438;
    dstTri[3].x = 0;
    dstTri[3].y = 438;

    yfmao::perspective_transform(srcTri, dstTri, src, dst, Size(282, 438));
    imshow("output", dst);
  }
}

int main(int argc, char* argv[]) {
  
  src = imread("../../images/src_img.jpg");
  namedWindow("src", CV_WINDOW_AUTOSIZE);
  imshow("src", src);	
  setMouseCallback("src", onMouse);
  waitKey();
  return 0;
}