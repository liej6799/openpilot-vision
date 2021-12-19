// my first program in C++
#include <iostream>
#include "opencv2/opencv.hpp"
#include "dmonitoringmodel.h"

using namespace std;
using namespace cv;


int main()
{

    string VideoPath = getenv("VIDEOPATH");
    string ModelPath = getenv("MODELPATH");
    string ModelParamPath = ModelPath + "dmonitoring_model-opt-fp16.param";
    string ModelBinPath = ModelPath + "dmonitoring_model-opt-fp16.bin";
    

    DMonitoringModel detector = DMonitoringModel(ModelParamPath.c_str(), ModelBinPath.c_str());

    // Enable Opencv Video Captur

    Mat image;
    VideoCapture cap(VideoPath);

    while(1){

        cap >> image;

        auto result = detector.detect(image);
        // Display the resulting frame
        imshow( "image", image );

        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        if(c==27)
        break;
    }
 
  // When everything done, release the video capture object
  cap.release();

  // Closes all the frames
  destroyAllWindows();
	
  return 0;



}