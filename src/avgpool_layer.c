#include "avgpool_layer.h"
<<<<<<< HEAD
#include "dark_cuda.h"
#include "utils.h"
=======
#include "cuda.h"
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#include <stdio.h>

avgpool_layer make_avgpool_layer(int batch, int w, int h, int c)
{
<<<<<<< HEAD
    fprintf(stderr, "avg                          %4d x%4d x%4d ->   %4d\n",  w, h, c, c);
    avgpool_layer l = { (LAYER_TYPE)0 };
=======
    fprintf(stderr, "avg                     %4d x%4d x%4d   ->  %4d\n",  w, h, c, c);
    avgpool_layer l = {0};
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    l.type = AVGPOOL;
    l.batch = batch;
    l.h = h;
    l.w = w;
    l.c = c;
    l.out_w = 1;
    l.out_h = 1;
    l.out_c = c;
    l.outputs = l.out_c;
    l.inputs = h*w*c;
    int output_size = l.outputs * batch;
<<<<<<< HEAD
    l.output = (float*)xcalloc(output_size, sizeof(float));
    l.delta = (float*)xcalloc(output_size, sizeof(float));
=======
    l.output =  calloc(output_size, sizeof(float));
    l.delta =   calloc(output_size, sizeof(float));
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    l.forward = forward_avgpool_layer;
    l.backward = backward_avgpool_layer;
    #ifdef GPU
    l.forward_gpu = forward_avgpool_layer_gpu;
    l.backward_gpu = backward_avgpool_layer_gpu;
    l.output_gpu  = cuda_make_array(l.output, output_size);
    l.delta_gpu   = cuda_make_array(l.delta, output_size);
    #endif
    return l;
}

void resize_avgpool_layer(avgpool_layer *l, int w, int h)
{
    l->w = w;
    l->h = h;
    l->inputs = h*w*l->c;
}

<<<<<<< HEAD
void forward_avgpool_layer(const avgpool_layer l, network_state state)
=======
void forward_avgpool_layer(const avgpool_layer l, network net)
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
{
    int b,i,k;

    for(b = 0; b < l.batch; ++b){
        for(k = 0; k < l.c; ++k){
            int out_index = k + b*l.c;
            l.output[out_index] = 0;
            for(i = 0; i < l.h*l.w; ++i){
                int in_index = i + l.h*l.w*(k + b*l.c);
<<<<<<< HEAD
                l.output[out_index] += state.input[in_index];
=======
                l.output[out_index] += net.input[in_index];
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
            }
            l.output[out_index] /= l.h*l.w;
        }
    }
}

<<<<<<< HEAD
void backward_avgpool_layer(const avgpool_layer l, network_state state)
=======
void backward_avgpool_layer(const avgpool_layer l, network net)
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
{
    int b,i,k;

    for(b = 0; b < l.batch; ++b){
        for(k = 0; k < l.c; ++k){
            int out_index = k + b*l.c;
            for(i = 0; i < l.h*l.w; ++i){
                int in_index = i + l.h*l.w*(k + b*l.c);
<<<<<<< HEAD
                state.delta[in_index] += l.delta[out_index] / (l.h*l.w);
=======
                net.delta[in_index] += l.delta[out_index] / (l.h*l.w);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
            }
        }
    }
}
<<<<<<< HEAD
=======

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
