## Problems with Raw Pointers
- Memory leaks, dangling pointers, double delete, exception safety.
- Smart pointers address this by providing automatic memory management and enhanced ownership semantics.

## Enter Smart Pointers
- <memory> header in C++ std lib.
- std::unique_ptr, std::shared_ptr, std::weak_ptr (which is a non-owning reference to an object managed bu a std::shared_ptr, by breaking circular references)

## std::unique_ptr (exclusive ownership)
- std::unique_ptr, at any given time, only one unique_ptr can point to a specific object. When it is destroyed, the object it was managing also gets deleted.


