#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
  cv::VideoCapture capture(0);
  if (!capture.isOpened())
  {
    return EXIT_FAILURE;
  }

  //cv::Size videoSize = cv::Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));

  cv::namedWindow("OpenCV Test", cv::WINDOW_AUTOSIZE);

  cv::Mat frame;

  while (true)
  {
    capture >> frame;

    if (frame.empty())
    {
      break;
    }

    cv::imshow("OpenCV Test", frame);

    if (cv::waitKey(33) == 27)
    {
      break;
    }
  }

  return EXIT_SUCCESS;
}