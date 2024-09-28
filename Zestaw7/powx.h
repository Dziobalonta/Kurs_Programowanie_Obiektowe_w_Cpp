#ifndef _powx_
#define _powx_

template<size_t N> double pow(double x) {
  return ((N%2)?x:1)*pow<N/2>(x*x);
}

template<> double pow<1>(double x) {return x;};

template<> double pow<0>(double x) {return 1.0;};

#endif 
