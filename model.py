
import onnxruntime
import numpy as np
import os
import sys

def read(sz):
  dd = []
  gt = 0
  while gt < sz * 4:
    st = os.read(0, sz * 4 - gt)
    assert(len(st) > 0)
    dd.append(st)
    gt += len(st)
  return np.frombuffer(b''.join(dd), dtype=np.float32)

def run_loop(m):
  ishapes = [[1]+ii.shape[1:] for ii in m.get_inputs()]
  keys = [x.name for x in m.get_inputs()]
  print("ready to run onnx model", keys, ishapes, file=sys.stderr)
  inputs = []
  for shp in ishapes:
    ts = np.product(shp)
    print(read(ts))
   # inputs.append(read(ts).reshape(shp))
  #ret = m.run(None, dict(zip(keys, inputs)))
  #print(ret)


os.environ["OMP_NUM_THREADS"] = "4"
# ort_session = onnxruntime.InferenceSession("/data/Models/openpilot/supercombo.onnx")
# ort_inputs = {ort_session.get_inputs()[0].name: np.random.rand(1),
#               ort_session.get_inputs()[1].name: np.random.rand(12),
#               ort_session.get_inputs()[2].name: np.random.rand(128),
#               ort_session.get_inputs()[3].name: np.random.rand(256)}
#import sys
# ort_outs = ort_session.run(None, ort_inputs)
options = onnxruntime.SessionOptions()
options.intra_op_num_threads = 4
options.inter_op_num_threads = 8
options.execution_mode = onnxruntime.ExecutionMode.ORT_SEQUENTIAL
options.graph_optimization_level = onnxruntime.GraphOptimizationLevel.ORT_ENABLE_ALL
ort_session = onnxruntime.InferenceSession("/data/Models/openpilot/supercombo.onnx", options)
run_loop(ort_session)

print(onnxruntime.get_available_providers())