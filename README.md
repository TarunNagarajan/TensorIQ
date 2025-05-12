# TensorIQ
**SIMD-Aware Quantization & Mapping Engine for CPUs**

TensorIQ is a CPU-optimized quantized inference engine built from scratch in C++. It supports:
- INT8 quantization (symmetric/asymmetric)
- SIMD-tiled GEMM kernels (AVX2/NEON)
- ONNX model parsing for MLPs and ConvNets
- Layer-wise runtime execution
- Hardware-aware tile tuning and benchmarking

## 🧱 Structure

- `include/`: Public headers for quantization, runtime, and SIMD kernels
- `src/`: Core engine source
- `tests/`: Unit tests
- `models/`: Test ONNX models
- `benchmarks/`: Reports and tuning logs

## 📦 Build

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
