#include <cstring>

#include "dmonitoring.h"
#include "../runners/onnxmodel.h"

#define MODEL_WIDTH 320
#define MODEL_HEIGHT 640
#define FULL_W 852 // should get these numbers from camerad

#if defined(QCOM) || defined(QCOM2)
#define input_lambda(x) (x - 128.f) * 0.0078125f
#else
#define input_lambda(x) x // for non SNPE running platforms, assume keras model instead has lambda layer
#endif

void dmonitoring_init(DMonitoringModelState* s) {
    int runtime = 2;
    s->m = new ONNXModel("../../models/dmonitoring_model.dlc" , &s->output[0], OUTPUT_SIZE, runtime);
}