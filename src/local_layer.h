#ifndef LOCAL_LAYER_H
#define LOCAL_LAYER_H

<<<<<<< HEAD
#include "dark_cuda.h"
=======
#include "cuda.h"
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#include "image.h"
#include "activations.h"
#include "layer.h"
#include "network.h"

typedef layer local_layer;

<<<<<<< HEAD
#ifdef __cplusplus
extern "C" {
#endif
#ifdef GPU
void forward_local_layer_gpu(local_layer layer, network_state state);
void backward_local_layer_gpu(local_layer layer, network_state state);
void update_local_layer_gpu(local_layer layer, int batch, float learning_rate, float momentum, float decay, float loss_scale);
=======
#ifdef GPU
void forward_local_layer_gpu(local_layer layer, network net);
void backward_local_layer_gpu(local_layer layer, network net);
void update_local_layer_gpu(local_layer layer, update_args a);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

void push_local_layer(local_layer layer);
void pull_local_layer(local_layer layer);
#endif

local_layer make_local_layer(int batch, int h, int w, int c, int n, int size, int stride, int pad, ACTIVATION activation);

<<<<<<< HEAD
void forward_local_layer(const local_layer layer, network_state state);
void backward_local_layer(local_layer layer, network_state state);
void update_local_layer(local_layer layer, int batch, float learning_rate, float momentum, float decay);
=======
void forward_local_layer(const local_layer layer, network net);
void backward_local_layer(local_layer layer, network net);
void update_local_layer(local_layer layer, update_args a);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

void bias_output(float *output, float *biases, int batch, int n, int size);
void backward_bias(float *bias_updates, float *delta, int batch, int n, int size);

<<<<<<< HEAD
#ifdef __cplusplus
}
#endif

#endif
=======
#endif

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
