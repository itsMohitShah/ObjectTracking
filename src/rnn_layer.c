#include "rnn_layer.h"
#include "connected_layer.h"
#include "utils.h"
<<<<<<< HEAD
#include "dark_cuda.h"
=======
#include "cuda.h"
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#include "blas.h"
#include "gemm.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void increment_layer(layer *l, int steps)
{
    int num = l->outputs*l->batch*steps;
    l->output += num;
    l->delta += num;
    l->x += num;
    l->x_norm += num;

#ifdef GPU
    l->output_gpu += num;
    l->delta_gpu += num;
    l->x_gpu += num;
    l->x_norm_gpu += num;
#endif
}

<<<<<<< HEAD
layer make_rnn_layer(int batch, int inputs, int hidden, int outputs, int steps, ACTIVATION activation, int batch_normalize, int log)
{
    fprintf(stderr, "RNN Layer: %d inputs, %d outputs\n", inputs, outputs);
    batch = batch / steps;
    layer l = { (LAYER_TYPE)0 };
    l.batch = batch;
    l.type = RNN;
    l.steps = steps;
    l.hidden = hidden;
    l.inputs = inputs;
    l.out_w = 1;
    l.out_h = 1;
    l.out_c = outputs;

    l.state = (float*)xcalloc(batch * hidden * (steps + 1), sizeof(float));

    l.input_layer = (layer*)xcalloc(1, sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.input_layer) = make_connected_layer(batch, steps, inputs, hidden, activation, batch_normalize);
    l.input_layer->batch = batch;
    if (l.workspace_size < l.input_layer->workspace_size) l.workspace_size = l.input_layer->workspace_size;

    l.self_layer = (layer*)xcalloc(1, sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.self_layer) = make_connected_layer(batch, steps, hidden, hidden, (log==2)?LOGGY:(log==1?LOGISTIC:activation), batch_normalize);
    l.self_layer->batch = batch;
    if (l.workspace_size < l.self_layer->workspace_size) l.workspace_size = l.self_layer->workspace_size;

    l.output_layer = (layer*)xcalloc(1, sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.output_layer) = make_connected_layer(batch, steps, hidden, outputs, activation, batch_normalize);
    l.output_layer->batch = batch;
    if (l.workspace_size < l.output_layer->workspace_size) l.workspace_size = l.output_layer->workspace_size;
=======
layer make_rnn_layer(int batch, int inputs, int outputs, int steps, ACTIVATION activation, int batch_normalize, int adam)
{
    fprintf(stderr, "RNN Layer: %d inputs, %d outputs\n", inputs, outputs);
    batch = batch / steps;
    layer l = {0};
    l.batch = batch;
    l.type = RNN;
    l.steps = steps;
    l.inputs = inputs;

    l.state = calloc(batch*outputs, sizeof(float));
    l.prev_state = calloc(batch*outputs, sizeof(float));

    l.input_layer = malloc(sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.input_layer) = make_connected_layer(batch*steps, inputs, outputs, activation, batch_normalize, adam);
    l.input_layer->batch = batch;

    l.self_layer = malloc(sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.self_layer) = make_connected_layer(batch*steps, outputs, outputs, activation, batch_normalize, adam);
    l.self_layer->batch = batch;

    l.output_layer = malloc(sizeof(layer));
    fprintf(stderr, "\t\t");
    *(l.output_layer) = make_connected_layer(batch*steps, outputs, outputs, activation, batch_normalize, adam);
    l.output_layer->batch = batch;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    l.outputs = outputs;
    l.output = l.output_layer->output;
    l.delta = l.output_layer->delta;

    l.forward = forward_rnn_layer;
    l.backward = backward_rnn_layer;
    l.update = update_rnn_layer;
#ifdef GPU
    l.forward_gpu = forward_rnn_layer_gpu;
    l.backward_gpu = backward_rnn_layer_gpu;
    l.update_gpu = update_rnn_layer_gpu;
<<<<<<< HEAD
    l.state_gpu = cuda_make_array(l.state, batch*hidden*(steps+1));
    l.output_gpu = l.output_layer->output_gpu;
    l.delta_gpu = l.output_layer->delta_gpu;
=======
    l.state_gpu = cuda_make_array(0, batch*outputs);
    l.prev_state_gpu = cuda_make_array(0, batch*outputs);
    l.output_gpu = l.output_layer->output_gpu;
    l.delta_gpu = l.output_layer->delta_gpu;
#ifdef CUDNN
    cudnnSetTensor4dDescriptor(l.input_layer->dstTensorDesc, CUDNN_TENSOR_NCHW, CUDNN_DATA_FLOAT, batch, l.input_layer->out_c, l.input_layer->out_h, l.input_layer->out_w); 
    cudnnSetTensor4dDescriptor(l.self_layer->dstTensorDesc, CUDNN_TENSOR_NCHW, CUDNN_DATA_FLOAT, batch, l.self_layer->out_c, l.self_layer->out_h, l.self_layer->out_w); 
    cudnnSetTensor4dDescriptor(l.output_layer->dstTensorDesc, CUDNN_TENSOR_NCHW, CUDNN_DATA_FLOAT, batch, l.output_layer->out_c, l.output_layer->out_h, l.output_layer->out_w); 
#endif
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#endif

    return l;
}

<<<<<<< HEAD
void update_rnn_layer(layer l, int batch, float learning_rate, float momentum, float decay)
{
    update_connected_layer(*(l.input_layer), batch, learning_rate, momentum, decay);
    update_connected_layer(*(l.self_layer), batch, learning_rate, momentum, decay);
    update_connected_layer(*(l.output_layer), batch, learning_rate, momentum, decay);
}

void forward_rnn_layer(layer l, network_state state)
{
    network_state s = {0};
    s.train = state.train;
    s.workspace = state.workspace;
=======
void update_rnn_layer(layer l, update_args a)
{
    update_connected_layer(*(l.input_layer),  a);
    update_connected_layer(*(l.self_layer),   a);
    update_connected_layer(*(l.output_layer), a);
}

void forward_rnn_layer(layer l, network net)
{
    network s = net;
    s.train = net.train;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int i;
    layer input_layer = *(l.input_layer);
    layer self_layer = *(l.self_layer);
    layer output_layer = *(l.output_layer);

    fill_cpu(l.outputs * l.batch * l.steps, 0, output_layer.delta, 1);
<<<<<<< HEAD
    fill_cpu(l.hidden * l.batch * l.steps, 0, self_layer.delta, 1);
    fill_cpu(l.hidden * l.batch * l.steps, 0, input_layer.delta, 1);
    if(state.train) fill_cpu(l.hidden * l.batch, 0, l.state, 1);

    for (i = 0; i < l.steps; ++i) {

        s.input = state.input;
=======
    fill_cpu(l.outputs * l.batch * l.steps, 0, self_layer.delta, 1);
    fill_cpu(l.outputs * l.batch * l.steps, 0, input_layer.delta, 1);
    if(net.train) fill_cpu(l.outputs * l.batch, 0, l.state, 1);

    for (i = 0; i < l.steps; ++i) {
        s.input = net.input;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
        forward_connected_layer(input_layer, s);

        s.input = l.state;
        forward_connected_layer(self_layer, s);

        float *old_state = l.state;
<<<<<<< HEAD
        if(state.train) l.state += l.hidden*l.batch;
        if(l.shortcut){
            copy_cpu(l.hidden * l.batch, old_state, 1, l.state, 1);
        }else{
            fill_cpu(l.hidden * l.batch, 0, l.state, 1);
        }
        axpy_cpu(l.hidden * l.batch, 1, input_layer.output, 1, l.state, 1);
        axpy_cpu(l.hidden * l.batch, 1, self_layer.output, 1, l.state, 1);
=======
        if(net.train) l.state += l.outputs*l.batch;
        if(l.shortcut){
            copy_cpu(l.outputs * l.batch, old_state, 1, l.state, 1);
        }else{
            fill_cpu(l.outputs * l.batch, 0, l.state, 1);
        }
        axpy_cpu(l.outputs * l.batch, 1, input_layer.output, 1, l.state, 1);
        axpy_cpu(l.outputs * l.batch, 1, self_layer.output, 1, l.state, 1);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

        s.input = l.state;
        forward_connected_layer(output_layer, s);

<<<<<<< HEAD
        state.input += l.inputs*l.batch;
=======
        net.input += l.inputs*l.batch;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
        increment_layer(&input_layer, 1);
        increment_layer(&self_layer, 1);
        increment_layer(&output_layer, 1);
    }
}

<<<<<<< HEAD
void backward_rnn_layer(layer l, network_state state)
{
    network_state s = {0};
    s.train = state.train;
    s.workspace = state.workspace;
=======
void backward_rnn_layer(layer l, network net)
{
    network s = net;
    s.train = net.train;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int i;
    layer input_layer = *(l.input_layer);
    layer self_layer = *(l.self_layer);
    layer output_layer = *(l.output_layer);

    increment_layer(&input_layer, l.steps-1);
    increment_layer(&self_layer, l.steps-1);
    increment_layer(&output_layer, l.steps-1);

<<<<<<< HEAD
    l.state += l.hidden*l.batch*l.steps;
    for (i = l.steps-1; i >= 0; --i) {
        copy_cpu(l.hidden * l.batch, input_layer.output, 1, l.state, 1);
        axpy_cpu(l.hidden * l.batch, 1, self_layer.output, 1, l.state, 1);
=======
    l.state += l.outputs*l.batch*l.steps;
    for (i = l.steps-1; i >= 0; --i) {
        copy_cpu(l.outputs * l.batch, input_layer.output, 1, l.state, 1);
        axpy_cpu(l.outputs * l.batch, 1, self_layer.output, 1, l.state, 1);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

        s.input = l.state;
        s.delta = self_layer.delta;
        backward_connected_layer(output_layer, s);

<<<<<<< HEAD
        l.state -= l.hidden*l.batch;
        /*
           if(i > 0){
           copy_cpu(l.hidden * l.batch, input_layer.output - l.hidden*l.batch, 1, l.state, 1);
           axpy_cpu(l.hidden * l.batch, 1, self_layer.output - l.hidden*l.batch, 1, l.state, 1);
           }else{
           fill_cpu(l.hidden * l.batch, 0, l.state, 1);
=======
        l.state -= l.outputs*l.batch;
        /*
           if(i > 0){
           copy_cpu(l.outputs * l.batch, input_layer.output - l.outputs*l.batch, 1, l.state, 1);
           axpy_cpu(l.outputs * l.batch, 1, self_layer.output - l.outputs*l.batch, 1, l.state, 1);
           }else{
           fill_cpu(l.outputs * l.batch, 0, l.state, 1);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
           }
         */

        s.input = l.state;
<<<<<<< HEAD
        s.delta = self_layer.delta - l.hidden*l.batch;
        if (i == 0) s.delta = 0;
        backward_connected_layer(self_layer, s);

        copy_cpu(l.hidden*l.batch, self_layer.delta, 1, input_layer.delta, 1);
        if (i > 0 && l.shortcut) axpy_cpu(l.hidden*l.batch, 1, self_layer.delta, 1, self_layer.delta - l.hidden*l.batch, 1);
        s.input = state.input + i*l.inputs*l.batch;
        if(state.delta) s.delta = state.delta + i*l.inputs*l.batch;
=======
        s.delta = self_layer.delta - l.outputs*l.batch;
        if (i == 0) s.delta = 0;
        backward_connected_layer(self_layer, s);

        copy_cpu(l.outputs*l.batch, self_layer.delta, 1, input_layer.delta, 1);
        if (i > 0 && l.shortcut) axpy_cpu(l.outputs*l.batch, 1, self_layer.delta, 1, self_layer.delta - l.outputs*l.batch, 1);
        s.input = net.input + i*l.inputs*l.batch;
        if(net.delta) s.delta = net.delta + i*l.inputs*l.batch;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
        else s.delta = 0;
        backward_connected_layer(input_layer, s);

        increment_layer(&input_layer, -1);
        increment_layer(&self_layer, -1);
        increment_layer(&output_layer, -1);
    }
}

#ifdef GPU

void pull_rnn_layer(layer l)
{
    pull_connected_layer(*(l.input_layer));
    pull_connected_layer(*(l.self_layer));
    pull_connected_layer(*(l.output_layer));
}

void push_rnn_layer(layer l)
{
    push_connected_layer(*(l.input_layer));
    push_connected_layer(*(l.self_layer));
    push_connected_layer(*(l.output_layer));
}

<<<<<<< HEAD
void update_rnn_layer_gpu(layer l, int batch, float learning_rate, float momentum, float decay, float loss_scale)
{
    update_connected_layer_gpu(*(l.input_layer), batch, learning_rate, momentum, decay, loss_scale);
    update_connected_layer_gpu(*(l.self_layer), batch, learning_rate, momentum, decay, loss_scale);
    update_connected_layer_gpu(*(l.output_layer), batch, learning_rate, momentum, decay, loss_scale);
}

void forward_rnn_layer_gpu(layer l, network_state state)
{
    network_state s = {0};
    s.train = state.train;
    s.workspace = state.workspace;
=======
void update_rnn_layer_gpu(layer l, update_args a)
{
    update_connected_layer_gpu(*(l.input_layer),  a);
    update_connected_layer_gpu(*(l.self_layer),   a);
    update_connected_layer_gpu(*(l.output_layer), a);
}

void forward_rnn_layer_gpu(layer l, network net)
{
    network s = {0};
    s.train = net.train;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int i;
    layer input_layer = *(l.input_layer);
    layer self_layer = *(l.self_layer);
    layer output_layer = *(l.output_layer);

<<<<<<< HEAD
    fill_ongpu(l.outputs * l.batch * l.steps, 0, output_layer.delta_gpu, 1);
    fill_ongpu(l.hidden * l.batch * l.steps, 0, self_layer.delta_gpu, 1);
    fill_ongpu(l.hidden * l.batch * l.steps, 0, input_layer.delta_gpu, 1);
    if(state.train) fill_ongpu(l.hidden * l.batch, 0, l.state_gpu, 1);

    for (i = 0; i < l.steps; ++i) {

        s.input = state.input;
        forward_connected_layer_gpu(input_layer, s);

        s.input = l.state_gpu;
        forward_connected_layer_gpu(self_layer, s);

        float *old_state = l.state_gpu;
        if(state.train) l.state_gpu += l.hidden*l.batch;
        if(l.shortcut){
            copy_ongpu(l.hidden * l.batch, old_state, 1, l.state_gpu, 1);
        }else{
            fill_ongpu(l.hidden * l.batch, 0, l.state_gpu, 1);
        }
        axpy_ongpu(l.hidden * l.batch, 1, input_layer.output_gpu, 1, l.state_gpu, 1);
        axpy_ongpu(l.hidden * l.batch, 1, self_layer.output_gpu, 1, l.state_gpu, 1);

        s.input = l.state_gpu;
        forward_connected_layer_gpu(output_layer, s);

        state.input += l.inputs*l.batch;
=======
    fill_gpu(l.outputs * l.batch * l.steps, 0, output_layer.delta_gpu, 1);
    fill_gpu(l.outputs * l.batch * l.steps, 0, self_layer.delta_gpu, 1);
    fill_gpu(l.outputs * l.batch * l.steps, 0, input_layer.delta_gpu, 1);

    if(net.train) {
        fill_gpu(l.outputs * l.batch * l.steps, 0, l.delta_gpu, 1);
        copy_gpu(l.outputs*l.batch, l.state_gpu, 1, l.prev_state_gpu, 1);
    }

    for (i = 0; i < l.steps; ++i) {
        s.input_gpu = net.input_gpu;
        forward_connected_layer_gpu(input_layer, s);

        s.input_gpu = l.state_gpu;
        forward_connected_layer_gpu(self_layer, s);

        fill_gpu(l.outputs * l.batch, 0, l.state_gpu, 1);
        axpy_gpu(l.outputs * l.batch, 1, input_layer.output_gpu, 1, l.state_gpu, 1);
        axpy_gpu(l.outputs * l.batch, 1, self_layer.output_gpu, 1, l.state_gpu, 1);

        s.input_gpu = l.state_gpu;
        forward_connected_layer_gpu(output_layer, s);

        net.input_gpu += l.inputs*l.batch;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
        increment_layer(&input_layer, 1);
        increment_layer(&self_layer, 1);
        increment_layer(&output_layer, 1);
    }
}

<<<<<<< HEAD
void backward_rnn_layer_gpu(layer l, network_state state)
{
    network_state s = {0};
    s.train = state.train;
    s.workspace = state.workspace;
=======
void backward_rnn_layer_gpu(layer l, network net)
{
    network s = {0};
    s.train = net.train;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int i;
    layer input_layer = *(l.input_layer);
    layer self_layer = *(l.self_layer);
    layer output_layer = *(l.output_layer);
    increment_layer(&input_layer,  l.steps - 1);
    increment_layer(&self_layer,   l.steps - 1);
    increment_layer(&output_layer, l.steps - 1);
<<<<<<< HEAD
    l.state_gpu += l.hidden*l.batch*l.steps;
    for (i = l.steps-1; i >= 0; --i) {

        s.input = l.state_gpu;
        s.delta = self_layer.delta_gpu;
        backward_connected_layer_gpu(output_layer, s);

        l.state_gpu -= l.hidden*l.batch;

        copy_ongpu(l.hidden*l.batch, self_layer.delta_gpu, 1, input_layer.delta_gpu, 1);    // the same delta for Input and Self layers

        s.input = l.state_gpu;
        s.delta = self_layer.delta_gpu - l.hidden*l.batch;
        if (i == 0) s.delta = 0;
        backward_connected_layer_gpu(self_layer, s);

        //copy_ongpu(l.hidden*l.batch, self_layer.delta_gpu, 1, input_layer.delta_gpu, 1);
        if (i > 0 && l.shortcut) axpy_ongpu(l.hidden*l.batch, 1, self_layer.delta_gpu, 1, self_layer.delta_gpu - l.hidden*l.batch, 1);
        s.input = state.input + i*l.inputs*l.batch;
        if(state.delta) s.delta = state.delta + i*l.inputs*l.batch;
        else s.delta = 0;
=======
    float *last_input = input_layer.output_gpu;
    float *last_self = self_layer.output_gpu;
    for (i = l.steps-1; i >= 0; --i) {
        fill_gpu(l.outputs * l.batch, 0, l.state_gpu, 1);
        axpy_gpu(l.outputs * l.batch, 1, input_layer.output_gpu, 1, l.state_gpu, 1);
        axpy_gpu(l.outputs * l.batch, 1, self_layer.output_gpu, 1, l.state_gpu, 1);

        s.input_gpu = l.state_gpu;
        s.delta_gpu = self_layer.delta_gpu;
        backward_connected_layer_gpu(output_layer, s);

        if(i != 0) {
            fill_gpu(l.outputs * l.batch, 0, l.state_gpu, 1);
            axpy_gpu(l.outputs * l.batch, 1, input_layer.output_gpu - l.outputs*l.batch, 1, l.state_gpu, 1);
            axpy_gpu(l.outputs * l.batch, 1, self_layer.output_gpu - l.outputs*l.batch, 1, l.state_gpu, 1);
        }else {
            copy_gpu(l.outputs*l.batch, l.prev_state_gpu, 1, l.state_gpu, 1);
        }

        copy_gpu(l.outputs*l.batch, self_layer.delta_gpu, 1, input_layer.delta_gpu, 1);

        s.input_gpu = l.state_gpu;
        s.delta_gpu = (i > 0) ? self_layer.delta_gpu - l.outputs*l.batch : 0;
        if (i == 0) s.delta_gpu = 0;
        backward_connected_layer_gpu(self_layer, s);

        s.input_gpu = net.input_gpu + i*l.inputs*l.batch;
        if(net.delta_gpu) s.delta_gpu = net.delta_gpu + i*l.inputs*l.batch;
        else s.delta_gpu = 0;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
        backward_connected_layer_gpu(input_layer, s);

        increment_layer(&input_layer,  -1);
        increment_layer(&self_layer,   -1);
        increment_layer(&output_layer, -1);
    }
<<<<<<< HEAD
=======
    fill_gpu(l.outputs * l.batch, 0, l.state_gpu, 1);
    axpy_gpu(l.outputs * l.batch, 1, last_input, 1, l.state_gpu, 1);
    axpy_gpu(l.outputs * l.batch, 1, last_self, 1, l.state_gpu, 1);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}
#endif
