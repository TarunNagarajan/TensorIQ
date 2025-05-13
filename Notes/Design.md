# Having to define Shape, Convenience methods while creating tensor.hpp
For design questions like deciding where the data should live, it's necessary to break down the problem
into constraints, trade-offs, and use-cases.

## Constraints
- Performance: Data alignment on 32, 64 byte boundaries (SIMD)? Stack, Heap allocation overhead?
- Flexibility: Arbitrary tensor dimenstions at runtime, or fixed small ranks?
- Safety: Simplicity worth a bit of extra overhead?
- When and where do I pay the alignment and allocation cost? Should every tensor be SIMD aligned  by default, or just in critical kernels?
  
