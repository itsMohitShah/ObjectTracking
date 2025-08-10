#ifndef BATCHNORM_LAYER_H
#define BATCHNORM_LAYER_H

#include "image.h"
#include "layer.h"
#include "network.h"

<<<<<<< HEAD
#ifdef __cplusplus
extern "C" {
#endif
layer make_batchnorm_layer(int batch, int w, int h, int c, int train);
void forward_batchnorm_layer(layer l, network_state state);
void backward_batchnorm_layer(layer l, network_state state);
void update_batchnorm_layer(layer l, int batch, float learning_rate, float momentum, float decay);

void resize_batchnorm_layer(layer *l, int w, int h);

#ifdef GPU
void forward_batchnorm_layer_gpu(layer l, network_state state);
void backward_batchnorm_layer_gpu(layer l, network_state state);
void update_batchnorm_layer_gpu(layer l, int batch, float learning_rate_init, float momentum, float decay, float loss_scale);
=======
layer make_batchnorm_layer(int batch, int w, int h, int c);
void forward_batchnorm_layer(layer l, network net);
void backward_batchnorm_layer(layer l, network net);

#ifdef GPU
void forward_batchnorm_layer_gpu(layer l, network net);
void backward_batchnorm_layer_gpu(layer l, network net);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
void pull_batchnorm_layer(layer l);
void push_batchnorm_layer(layer l);
#endif

<<<<<<< HEAD
#ifdef __cplusplus
}
#endif
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#endif
