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

| **Day**                                               | **Task**                                                        |
| ----------------------------------------------------- | --------------------------------------------------------------- |
| **Week 1 – Project Setup & Quantization Foundations** |                                                                 |
| 1                                                     | Setup project repo, folder structure, `CMakeLists.txt`          |
| 2                                                     | Define tensor and fixed-point types (`tensor.hpp`, `fixed.hpp`) |
| 3                                                     | Implement basic symmetric INT8 quantization (per-tensor)        |
| 4                                                     | Implement dequantization and clamping logic                     |
| 5                                                     | Add per-channel asymmetric quantization                         |
| 6                                                     | Write test cases for quantization logic                         |
| 7                                                     | Benchmark quantization error using simple matrices              |
| **Week 2 – Fixed-Point Math + Validation**            |                                                                 |
| 8                                                     | Implement int8 × int8 → int32 matmul with scalar loops          |
| 9                                                     | Add requantization (scaling + rounding to INT8)                 |
| 10                                                    | Add saturation-aware bias addition (bias in FP32/INT32)         |
| 11                                                    | Implement ReLU and Softmax for int8                             |
| 12                                                    | Compare with FP32 output for correctness (small MLP)            |
| 13                                                    | Write unit tests for int8 matmul, ReLU, Softmax                 |
| 14                                                    | Milestone: End-to-end quantized MLP (manual weights)            |
| **Week 3 – SIMD Intro + Intrinsics Setup**            |                                                                 |
| 15                                                    | Setup SIMD backend: AVX2 (x86) / NEON (ARM) abstraction         |
| 16                                                    | Implement int8 SIMD load/store wrappers                         |
| 17                                                    | Implement int8 dot-product using intrinsics                     |
| 18                                                    | Build microkernel: 4×4 or 8×8 matmul tile with SIMD             |
| 19                                                    | Write fallback scalar version for unsupported machines          |
| 20                                                    | Test and compare SIMD vs scalar speed                           |
| 21                                                    | Benchmark kernel with random matrices (e.g., 64×64)             |
| **Week 4 – Tiled GEMM with SIMD**                     |                                                                 |
| 22                                                    | Implement outer tiling logic for large matrices                 |
| 23                                                    | Handle edge tiles and remainder handling                        |
| 24                                                    | Add multi-threaded tiling (OpenMP or C++ threads)               |
| 25                                                    | Add cache-aware tile size selection heuristics                  |
| 26                                                    | Validate numerical correctness with tiled GEMM                  |
| 27                                                    | Benchmark large matrix multiply (e.g., 512×512)                 |
| 28                                                    | Milestone: Quantized Tiled GEMM working                         |
| **Week 5 – ONNX Loader for Linear Layers**            |                                                                 |
| 29                                                    | Parse ONNX file for Linear layer (weights, bias)                |
| 30                                                    | Extract tensor shapes, check model validity                     |
| 31                                                    | Load weights and quantize to INT8 format                        |
| 32                                                    | Load input tensor and preprocess (normalize → quantize)         |
| 33                                                    | Add basic ONNX ReLU parsing                                     |
| 34                                                    | Write helper functions for loading simple graphs                |
| 35                                                    | Milestone: Run single-layer ONNX model (Linear + ReLU)          |
| **Week 6 – Model Execution Runtime**                  |                                                                 |
| 36                                                    | Implement tensor memory layout and buffer allocator             |
| 37                                                    | Add layer execution interface: `execute(layer, input)`          |
| 38                                                    | Traverse ONNX graph and execute in order                        |
| 39                                                    | Add intermediate buffer reuse (greedy reuse)                    |
| 40                                                    | Add support for activation layers: ReLU, Softmax                |
| 41                                                    | Write tests for runtime execution path                          |
| 42                                                    | Run simple 2-layer MLP from ONNX                                |
| **Week 7 – Convolution Support**                      |                                                                 |
| 43                                                    | Parse ONNX Conv2D layers (weight, bias, padding)                |
| 44                                                    | Implement im2col for conv→GEMM transform                        |
| 45                                                    | Quantize conv weights + input patches                           |
| 46                                                    | Use existing GEMM for convolution execution                     |
| 47                                                    | Add channel-last to channel-first layout converters             |
| 48                                                    | Test with CNN ONNX model (e.g., simple LeNet)                   |
| 49                                                    | Milestone: Quantized ConvNet inference working                  |
| **Week 8 – Profiling & Tuning**                       |                                                                 |
| 50                                                    | Integrate `perf` or `rdtsc`-based timers                        |
| 51                                                    | Add latency measurement for each layer                          |
| 52                                                    | Collect SIMD utilization, cache misses via `perf stat`          |
| 53                                                    | Visualize layer-by-layer timing in CSV/Markdown                 |
| 54                                                    | Add CLI flags: `--threads`, `--tile-size`, `--quant-mode`       |
| 55                                                    | Sweep tile sizes and threading modes for best performance       |
| 56                                                    | Write tuning report: which tile sizes worked best on hardware   |
| **Week 9 – Final Integration and Cleanup**            |                                                                 |
| 57                                                    | Add `main.cpp` entrypoint: load model, run inference            |
| 58                                                    | Add CLI to specify model path and input tensor                  |
| 59                                                    | Add JSON config for model metadata (scale, zero-point)          |
| 60                                                    | Add logger + debug macros                                       |
| 61                                                    | Polish error messages, argument validation                      |
| 62                                                    | Add usage documentation in `README.md`                          |
| 63                                                    | Finalize tests for quantization, GEMM, runtime                  |
| **Week 10 – Real Model Benchmarks + Write-up**        |                                                                 |
| 64                                                    | Test with TinyML model (e.g., keyword spotting MLP)             |
| 65                                                    | Test with conv-based model (e.g., LeNet)                        |
| 66                                                    | Compare INT8 inference vs FP32 baseline                         |
| 67                                                    | Generate benchmark report: speedup, accuracy loss               |
| 68                                                    | Add performance charts to `benchmarks/report.md`                |
| 69                                                    | Write developer guide (`CONTRIBUTING.md`)                       |
| 70                                                    | Polish, refactor, final test sweep                              |
| **Week 11–12 – Stretch Goals / Wrap-Up**              |                                                                 |
| 71–75                                                 | Add tiling autotuner (try 4×4, 8×8, 16×16 based on perf)        |
| 76–80                                                 | Add support for quantized depthwise conv (MobileNet)            |
| 81–85                                                 | Add runtime INT4 support (optional)                             |
| 86–90                                                 | Demo video, final GitHub polish, write blog/report              |
