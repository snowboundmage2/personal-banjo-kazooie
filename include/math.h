#ifndef BANJO_KAZOOIE_MATH_H
#define BANJO_KAZOOIE_MATH_H

#include <math.h>

static inline float sq(float x) {
    return x * x;
}

static inline void tuple_assign(float out[3], float a, float b, float c) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}

static inline void tuple_copy(float dst[3], const float src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static inline void tuple_add(float dst[3], const float vec[3]) {
    dst[0] += vec[0];
    dst[1] += vec[1];
    dst[2] += vec[2];
}

static inline void tuple_add_copy(float dst[3], const float vec1[3], const float vec2[3]) {
    dst[0] = vec1[0] + vec2[0];
    dst[1] = vec1[1] + vec2[1];
    dst[2] = vec1[2] + vec2[2];
}

static inline void tuple_diff(float dst[3], const float vec[3]) {
    dst[0] -= vec[0];
    dst[1] -= vec[1];
    dst[2] -= vec[2];
}

static inline void tuple_diff_copy(float dst[3], const float vec1[3], const float vec2[3]) {
    dst[0] = vec1[0] - vec2[0];
    dst[1] = vec1[1] - vec2[1];
    dst[2] = vec1[2] - vec2[2];
}

static inline void tuple_multiply_copy(float dst[3], const float vec1[3], const float vec2[3]) {
    dst[0] = vec1[0] * vec2[0];
    dst[1] = vec1[1] * vec2[1];
    dst[2] = vec1[2] * vec2[2];
}

static inline void tuple_scale(float vec[3], float value) {
    vec[0] *= value;
    vec[1] *= value;
    vec[2] *= value;
}

static inline void tuple_scale_copy(float dst[3], const float vec[3], float value) {
    dst[0] = vec[0] * value;
    dst[1] = vec[1] * value;
    dst[2] = vec[2] * value;
}

static inline void tuple_cross_product(float dst[3], const float vec1[3], const float vec2[3]) {
    dst[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    dst[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    dst[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

static inline float length_sq_vec3f(const float v[3]) {
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

static inline float length_vec3f(const float v[3]) {
    return sqrtf(length_sq_vec3f(v));
}

static inline float tuple_dot_product(const float vec1[3], const float vec2[3]) {
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

#endif // BANJO_KAZOOIE_MATH_H
