
#ifndef RNN_LAYER_H
#define RNN_LAYER_H

#include "activations.h"
#include "layer.h"
#include "network.h"
#define USET

<<<<<<< HEAD
#ifdef __cplusplus
extern "C" {
#endif
layer make_rnn_layer(int batch, int inputs, int hidden, int outputs, int steps, ACTIVATION activation, int batch_normalize, int log);

void forward_rnn_layer(layer l, network_state state);
void backward_rnn_layer(layer l, network_state state);
void update_rnn_layer(layer l, int batch, float learning_rate, float momentum, float decay);

#ifdef GPU
void forward_rnn_layer_gpu(layer l, network_state state);
void backward_rnn_layer_gpu(layer l, network_state state);
void update_rnn_layer_gpu(layer l, int batch, float learning_rate, float momentum, float decay, float loss_scale);
=======
layer make_rnn_layer(int batch, int inputs, int outputs, int steps, ACTIVATION activation, int batch_normalize, int adam);

void forward_rnn_layer(layer l, network net);
void backward_rnn_layer(layer l, network net);
void update_rnn_layer(layer l, update_args a);

#ifdef GPU
void forward_rnn_layer_gpu(layer l, network net);
void backward_rnn_layer_gpu(layer l, network net);
void update_rnn_layer_gpu(layer l, update_args a);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
void push_rnn_layer(layer l);
void pull_rnn_layer(layer l);
#endif

<<<<<<< HEAD
#ifdef __cplusplus
}
#endif

#endif
=======
#endif

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
