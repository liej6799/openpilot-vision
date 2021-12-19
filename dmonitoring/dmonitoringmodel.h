

#include <net.h>
#include <opencv2/core/core.hpp>

class DMonitoringModel
{
    public:
        DMonitoringModel(const char* param, const char* bin);
        ncnn::Net* Net;

};