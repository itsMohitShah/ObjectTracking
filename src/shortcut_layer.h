#ifndef SHORTCUT_LAYER_H
#define SHORTCUT_LAYER_H

#include "layer.h"
#include "network.h"

<<<<<<< HEAD
#ifdef __cplusplus
extern "C" {
#endif
layer make_shortcut_layer(int batch, int n, int *input_layers, int* input_sizes, int w, int h, int c,
    float **layers_output, float **layers_delta, float **layers_output_gpu, float **layers_delta_gpu, WEIGHTS_TYPE_T weights_type, WEIGHTS_NORMALIZATION_T weights_normalization,
    ACTIVATION activation, int train);
void forward_shortcut_layer(const layer l, network_state state);
void backward_shortcut_layer(const layer l, network_state state);
void update_shortcut_layer(layer l, int batch, float learning_rate_init, float momentum, float decay);
void resize_shortcut_layer(layer *l, int w, int h, network *net);

#ifdef GPU
void forward_shortcut_layer_gpu(const layer l, network_state state);
void backward_shortcut_layer_gpu(const layer l, network_state state);
void update_shortcut_layer_gpu(layer l, int batch, float learning_rate_init, float momentum, float decay, float loss_scale);
void pull_shortcut_layer(layer l);
void push_shortcut_layer(layer l);
#endif

#ifdef __cplusplus
}
#endif
=======
layer make_shortcut_layer(int batch, int index, int w, int h, int c, int w2, int h2, int c2);
void forward_shortcut_layer(const layer l, network net);
void backward_shortcut_layer(const layer l, network net);
void resize_shortcut_layer(layer *l, int w, int h);

#ifdef GPU
void forward_shortcut_layer_gpu(const layer l, network net);
void backward_shortcut_layer_gpu(const layer l, network net);
#endif

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#endif
