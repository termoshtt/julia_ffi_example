#include <iostream>
#include <julia/julia.h>

extern "C" {

void make_twice_ptr(int n, float *p) {
  for (int i = 0; i < n; ++i) {
    p[i] *= 2.0;
  }
}

void make_twice_array(jl_value_t *ptr) {
  if (jl_is_array_type(ptr) != 0) {
    std::cerr << "This is not an array." << std::endl;
    return; // TODO Error handling
  }
  auto array = reinterpret_cast<jl_array_t *>(ptr);

  std::clog << "length   : " << array->length << std::endl;
  std::clog << "nrows    : " << array->nrows << std::endl;
  std::clog << "elsize   : " << array->elsize << std::endl;

  if (array->elsize != sizeof(float)) {
    std::cerr << "This is not a float array." << std::endl;
    return; // TODO Error handling
  }

  float *data = reinterpret_cast<float *>(array->data);

  for (size_t i = 0; i < array->length; ++i) {
    data[i] *= 2.0;
  }

  auto flags = array->flags;
  std::clog << "how      : " << flags.how << std::endl;
  std::clog << "ndims    : " << flags.ndims << std::endl;
  std::clog << "pooled   : " << flags.pooled << std::endl;
  std::clog << "ptrarray : " << flags.ptrarray << std::endl;
  std::clog << "isshared : " << flags.isshared << std::endl;
  std::clog << "isaligned: " << flags.isaligned << std::endl;
  // TODO check ndim
}
} // extern C
