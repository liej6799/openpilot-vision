#include "dmonitoringmodel.h"

DMonitoringModel::DMonitoringModel(const char* param, const char* bin)
{
    this->Net = new ncnn::Net();

    this->Net->opt.use_fp16_arithmetic = true;
    this->Net->load_param(param);
    this->Net->load_model(bin);
}