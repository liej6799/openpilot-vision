#pragma once

#include <vector>
#include <cstdint>
#include "../runners/runmodel.h"

#define OUTPUT_SIZE 38

typedef struct DMonitoringResult {
    float face_orientation[3];
    float face_orientation_meta[3];
    float face_position[2];
    float face_position_meta[2];
    float face_prob;
    float left_eye_prob;
    float right_eye_prob;
    float left_blink_prob;
    float right_blink_prob;
    float sg_prob;
    float poor_vision;
    float partial_face;
    float distracted_pose;
    float distracted_eyes;
    float dsp_execution_time;
} DMonitoringResult;

typedef struct DMonitoringModelState {
    RunModel *m;
    bool is_rhd;
    float output[OUTPUT_SIZE];
    std::vector<uint8_t> resized_buf;
    std::vector<uint8_t> cropped_buf;
    std::vector<uint8_t> premirror_cropped_buf;
    std::vector<float> net_input_buf;
} DMonitoringModelState;

void dmonitoring_init(DMonitoringModelState* s);

