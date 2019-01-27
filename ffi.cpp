extern "C" {
void make_twice_ptr(int n, float* p) {
  for (int i = 0; i < n; ++i) {
    p[i] *= 2.0;
  }
}
}
