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

- **TensorIQ/**  
  - **include/** — Public headers  
    - `quantize.hpp`        — INT8 quantization logic  
    - `fixedpoint.hpp`      — Fixed-point operations (requantization, saturation)  
    - `simd_gemm.hpp`       — SIMD-tiled matrix kernels  
    - `profiler.hpp`        — Timing & performance tools  
    - `onnx_loader.hpp`     — ONNX parsing (Linear, Conv layers)  
    - `runtime.hpp`         — Layer execution & memory manager  
    - `tensor.hpp`          — Tensor class, shapes & layouts  
  - **src/** — Core engine implementation  
    - `quantize.cpp`  
    - `fixedpoint.cpp`  
    - `simd_gemm.cpp`  
    - `profiler.cpp`  
    - `onnx_loader.cpp`  
    - `runtime.cpp`  
    - `main.cpp`            — Model loading, inference & benchmarks  
  - **tests/** — Unit tests  
    - `test_quant.cpp`  
    - `test_simd.cpp`  
    - `test_runtime.cpp`  
  - **models/** — Sample ONNX models  
    - `tinyml_mlp.onnx`  
    - `convnet_test.onnx`  
  - **benchmarks/** — Benchmark reports & tuning logs  
    - `report.md`  
  - `CMakeLists.txt`        — Build configuration  
  - `README.md`             — Project overview & instructions  
  - `CONTRIBUTING.md`       — Contribution guidelines  
  - `TODO.md`               — 90-day task breakdown & roadmap  
  - `LICENSE`               — MIT or Apache 2.0 license  

---
