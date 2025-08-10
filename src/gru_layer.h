
#ifndef GRU_LAYER_H
#define GRU_LAYER_H

#include "activations.h"
#include "layer.h"
#include "network.h"

<<<<<<< HEAD
#ifdef __cplusplus
extern "C" {
#endif
layer make_gru_layer(int batch, int inputs, int outputs, int steps, int batch_normalize);

void forward_gru_layer(layer l, network_state state);
void backward_gru_layer(layer l, network_state state);
void update_gru_layer(layer l, int batch, float learning_rate, float momentum, float decay);

#ifdef GPU
void forward_gru_layer_gpu(layer l, network_state state);
void backward_gru_layer_gpu(layer l, network_state state);
void update_gru_layer_gpu(layer l, int batch, float learning_rate, float momentum, float decay, float loss_scale);
=======
layer make_gru_layer(int batch, int inputs, int outputs, int steps, int batch_normalize, int adam);

void forward_gru_layer(layer l, network state);
void backward_gru_layer(layer l, network state);
void update_gru_layer(layer l, update_args a);

#ifdef GPU
void forward_gru_layer_gpu(layer l, network state);
void backward_gru_layer_gpu(layer l, network state);
void update_gru_layer_gpu(layer l, update_args a);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
void push_gru_layer(layer l);
void pull_gru_layer(layer l);
#endif

<<<<<<< HEAD
#ifdef __cplusplus
}
#endif

#endif
=======
#endif

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
