# TensorIQ
**SIMD-Aware Quantization & Mapping Engine for CPUs**

TensorIQ is a CPU-optimized quantized inference engine built from scratch in C++. It supports:
- INT8 quantization (symmetric/asymmetric)
- SIMD-tiled GEMM kernels (AVX2/NEON)
- ONNX model parsing for MLPs and ConvNets
- Layer-wise runtime execution
- Hardware-aware tile tuning and benchmarking

---

## Repository Structure
TensorIQ/
├── include/
│   ├── quantize.hpp
│   ├── fixedpoint.hpp
│   ├── simd_gemm.hpp
│   ├── profiler.hpp
│   ├── onnx_loader.hpp
│   ├── runtime.hpp
│   └── tensor.hpp
│
├── src/
│   ├── quantize.cpp
│   ├── fixedpoint.cpp
│   ├── simd_gemm.cpp
│   ├── profiler.cpp
│   ├── onnx_loader.cpp
│   ├── runtime.cpp
│   └── main.cpp
│
├── tests/
│   ├── test_quant.cpp
│   ├── test_simd.cpp
│   └── test_runtime.cpp
│
├── models/
│   ├── tinyml_mlp.onnx
│   └── convnet_test.onnx
│
├── benchmarks/
│   └── report.md
│
├── CMakeLists.txt
├── README.md
├── CONTRIBUTING.md
├── TODO.md
└── LICENSE
