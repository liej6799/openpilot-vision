

#include <net.h>
#include <opencv2/core/core.hpp>
#include <iostream>

class DMonitoringModel
{
    public:
        DMonitoringModel(const char* param, const char* bin);
        ncnn::Net* Net;
        std::string detect(cv::Mat image);

};