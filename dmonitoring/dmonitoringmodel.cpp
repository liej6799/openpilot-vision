#include "dmonitoringmodel.h"

DMonitoringModel::DMonitoringModel(const char* param, const char* bin)
{
    this->Net = new ncnn::Net();

    this->Net->opt.use_fp16_arithmetic = true;
    this->Net->load_param(param);
    this->Net->load_model(bin);
}

std::string DMonitoringModel::detect(cv::Mat image)
{
    ncnn::Mat input;
    std::cout << "Processing" << std::endl;

    int img_w = image.cols;
    int img_h = image.rows;

    input = ncnn::Mat::from_pixels(image.data, ncnn::Mat::PIXEL_BGR, img_w, img_h);

    auto ex = this->Net->create_extractor();
    ex.set_light_mode(false);
    ex.set_num_threads(4);

    ex.input("input_img", input);

    ncnn::Mat out;
	ex.extract("outputs", out);
    std::cout << out.h << std::endl;

    return "Processing";
}
