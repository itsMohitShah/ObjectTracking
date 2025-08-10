#ifndef DARKNET_API
#define DARKNET_API
<<<<<<< HEAD

#if defined(_MSC_VER) && _MSC_VER < 1900
#define inline __inline
#endif

#if defined(DEBUG) && !defined(_CRTDBG_MAP_ALLOC)
#define _CRTDBG_MAP_ALLOC
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <pthread.h>

#ifndef LIB_API
#ifdef LIB_EXPORTS
#if defined(_MSC_VER)
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __attribute__((visibility("default")))
#endif
#else
#if defined(_MSC_VER)
#define LIB_API
#else
#define LIB_API
#endif
#endif
#endif

#define SECRET_NUM -1234

typedef enum { UNUSED_DEF_VAL } UNUSED_ENUM_TYPE;

#ifdef GPU

#include <cuda_runtime.h>
#include <curand.h>
#include <cublas_v2.h>

#ifdef CUDNN
#include <cudnn.h>
#endif  // CUDNN
#endif  // GPU
=======
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#ifdef GPU
    #define BLOCK 512

    #include "cuda_runtime.h"
    #include "curand.h"
    #include "cublas_v2.h"

    #ifdef CUDNN
    #include "cudnn.h"
    #endif
#endif
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

#ifdef __cplusplus
extern "C" {
#endif

<<<<<<< HEAD
struct network;
typedef struct network network;

struct network_state;
typedef struct network_state network_state;

struct layer;
typedef struct layer layer;

struct image;
typedef struct image image;

struct detection;
typedef struct detection detection;

struct load_args;
typedef struct load_args load_args;

struct data;
typedef struct data data;

struct metadata;
typedef struct metadata metadata;

struct tree;
typedef struct tree tree;

extern int gpu_index;

// option_list.h
typedef struct metadata {
=======
#define SECRET_NUM -1234
extern int gpu_index;

typedef struct{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int classes;
    char **names;
} metadata;

<<<<<<< HEAD

// tree.h
typedef struct tree {
=======
metadata get_metadata(char *file);

typedef struct{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int *leaf;
    int n;
    int *parent;
    int *child;
    int *group;
    char **name;

    int groups;
    int *group_size;
    int *group_offset;
} tree;
<<<<<<< HEAD


// activations.h
typedef enum {
    LOGISTIC, RELU, RELU6, RELIE, LINEAR, RAMP, TANH, PLSE, REVLEAKY, LEAKY, ELU, LOGGY, STAIR, HARDTAN, LHTAN, SELU, GELU, SWISH, MISH, HARD_MISH, NORM_CHAN, NORM_CHAN_SOFTMAX, NORM_CHAN_SOFTMAX_MAXVAL
}ACTIVATION;

// parser.h
typedef enum {
    IOU, GIOU, MSE, DIOU, CIOU
} IOU_LOSS;

// parser.h
typedef enum {
    DEFAULT_NMS, GREEDY_NMS, DIOU_NMS, CORNERS_NMS
} NMS_KIND;

// parser.h
typedef enum {
    YOLO_CENTER = 1 << 0, YOLO_LEFT_TOP = 1 << 1, YOLO_RIGHT_BOTTOM = 1 << 2
} YOLO_POINT;

// parser.h
typedef enum {
    NO_WEIGHTS, PER_FEATURE, PER_CHANNEL
} WEIGHTS_TYPE_T;

// parser.h
typedef enum {
    NO_NORMALIZATION, RELU_NORMALIZATION, SOFTMAX_NORMALIZATION
} WEIGHTS_NORMALIZATION_T;

// image.h
=======
tree *read_tree(char *filename);

typedef enum{
    LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR, HARDTAN, LHTAN, SELU
} ACTIVATION;

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
typedef enum{
    PNG, BMP, TGA, JPG
} IMTYPE;

<<<<<<< HEAD
// activations.h
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
typedef enum{
    MULT, ADD, SUB, DIV
} BINARY_ACTIVATION;

<<<<<<< HEAD
// blas.h
typedef struct contrastive_params {
    float sim;
    float exp_sim;
    float P;
    int i, j;
    int time_step_i, time_step_j;
} contrastive_params;


// layer.h
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
typedef enum {
    CONVOLUTIONAL,
    DECONVOLUTIONAL,
    CONNECTED,
    MAXPOOL,
<<<<<<< HEAD
    LOCAL_AVGPOOL,
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    SOFTMAX,
    DETECTION,
    DROPOUT,
    CROP,
    ROUTE,
    COST,
    NORMALIZATION,
    AVGPOOL,
    LOCAL,
    SHORTCUT,
<<<<<<< HEAD
    SCALE_CHANNELS,
    SAM,
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    ACTIVE,
    RNN,
    GRU,
    LSTM,
<<<<<<< HEAD
    CONV_LSTM,
    HISTORY,
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    CRNN,
    BATCHNORM,
    NETWORK,
    XNOR,
    REGION,
    YOLO,
<<<<<<< HEAD
    GAUSSIAN_YOLO,
    ISEG,
    REORG,
    REORG_OLD,
    UPSAMPLE,
    LOGXENT,
    L2NORM,
    EMPTY,
    BLANK,
    CONTRASTIVE,
    IMPLICIT
} LAYER_TYPE;

// layer.h
=======
    ISEG,
    REORG,
    UPSAMPLE,
    LOGXENT,
    L2NORM,
    BLANK
} LAYER_TYPE;

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
typedef enum{
    SSE, MASKED, L1, SEG, SMOOTH,WGAN
} COST_TYPE;

<<<<<<< HEAD
// layer.h
typedef struct update_args {
=======
typedef struct{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int batch;
    float learning_rate;
    float momentum;
    float decay;
    int adam;
    float B1;
    float B2;
    float eps;
    int t;
} update_args;

<<<<<<< HEAD
// layer.h
struct layer {
    LAYER_TYPE type;
    ACTIVATION activation;
    ACTIVATION lstm_activation;
    COST_TYPE cost_type;
    void(*forward)   (struct layer, struct network_state);
    void(*backward)  (struct layer, struct network_state);
    void(*update)    (struct layer, int, float, float, float);
    void(*forward_gpu)   (struct layer, struct network_state);
    void(*backward_gpu)  (struct layer, struct network_state);
    void(*update_gpu)    (struct layer, int, float, float, float, float);
    layer *share_layer;
    int train;
    int avgpool;
    int batch_normalize;
    int shortcut;
    int batch;
    int dynamic_minibatch;
=======
struct network;
typedef struct network network;

struct layer;
typedef struct layer layer;

struct layer{
    LAYER_TYPE type;
    ACTIVATION activation;
    COST_TYPE cost_type;
    void (*forward)   (struct layer, struct network);
    void (*backward)  (struct layer, struct network);
    void (*update)    (struct layer, update_args);
    void (*forward_gpu)   (struct layer, struct network);
    void (*backward_gpu)  (struct layer, struct network);
    void (*update_gpu)    (struct layer, update_args);
    int batch_normalize;
    int shortcut;
    int batch;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int forced;
    int flipped;
    int inputs;
    int outputs;
<<<<<<< HEAD
    float mean_alpha;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int nweights;
    int nbiases;
    int extra;
    int truths;
<<<<<<< HEAD
    int h, w, c;
    int out_h, out_w, out_c;
    int n;
    int max_boxes;
    int truth_size;
    int groups;
    int group_id;
    int size;
    int side;
    int stride;
    int stride_x;
    int stride_y;
    int dilation;
    int antialiasing;
    int maxpool_depth;
    int maxpool_zero_nonmax;
    int out_channels;
    float reverse;
    int coordconv;
=======
    int h,w,c;
    int out_h, out_w, out_c;
    int n;
    int max_boxes;
    int groups;
    int size;
    int side;
    int stride;
    int reverse;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int flatten;
    int spatial;
    int pad;
    int sqrt;
    int flip;
    int index;
<<<<<<< HEAD
    int scale_wh;
    int binary;
    int xnor;
    int peephole;
    int use_bin_output;
    int keep_delta_gpu;
    int optimized_memory;
    int steps;
    int history_size;
    int bottleneck;
    float time_normalizer;
    int state_constrain;
=======
    int binary;
    int xnor;
    int steps;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int hidden;
    int truth;
    float smooth;
    float dot;
<<<<<<< HEAD
    int deform;
    int grad_centr;
    int sway;
    int rotate;
    int stretch;
    int stretch_sway;
    float angle;
    float jitter;
    float resize;
=======
    float angle;
    float jitter;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float saturation;
    float exposure;
    float shift;
    float ratio;
    float learning_rate_scale;
    float clip;
<<<<<<< HEAD
    int focal_loss;
    float *classes_multipliers;
    float label_smooth_eps;
    int noloss;
    int softmax;
    int classes;
    int detection;
    int embedding_layer_id;
    float *embedding_output;
    int embedding_size;
    float sim_thresh;
    int track_history_size;
    int dets_for_track;
    int dets_for_show;
    float track_ciou_norm;
=======
    int noloss;
    int softmax;
    int classes;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int coords;
    int background;
    int rescore;
    int objectness;
<<<<<<< HEAD
    int does_cost;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int joint;
    int noadjust;
    int reorg;
    int log;
    int tanh;
    int *mask;
    int total;
<<<<<<< HEAD
    float bflops;

    int adam;
    float B1;
    float B2;
    float eps;

    int t;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    float alpha;
    float beta;
    float kappa;

    float coord_scale;
    float object_scale;
    float noobject_scale;
    float mask_scale;
    float class_scale;
    int bias_match;
<<<<<<< HEAD
    float random;
    float ignore_thresh;
    float truth_thresh;
    float iou_thresh;
=======
    int random;
    float ignore_thresh;
    float truth_thresh;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float thresh;
    float focus;
    int classfix;
    int absolute;
<<<<<<< HEAD
    int assisted_excitation;

    int onlyforward;
    int stopbackward;
    int train_only_bn;
    int dont_update;
    int burnin_update;
=======

    int onlyforward;
    int stopbackward;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int dontload;
    int dontsave;
    int dontloadscales;
    int numload;

    float temperature;
    float probability;
<<<<<<< HEAD
    float dropblock_size_rel;
    int dropblock_size_abs;
    int dropblock;
    float scale;

    int receptive_w;
    int receptive_h;
    int receptive_w_scale;
    int receptive_h_scale;

=======
    float scale;

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    char  * cweights;
    int   * indexes;
    int   * input_layers;
    int   * input_sizes;
<<<<<<< HEAD
    float **layers_output;
    float **layers_delta;
    WEIGHTS_TYPE_T weights_type;
    WEIGHTS_NORMALIZATION_T weights_normalization;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int   * map;
    int   * counts;
    float ** sums;
    float * rand;
    float * cost;
<<<<<<< HEAD
    int *labels;
    int *class_ids;
    int contrastive_neg_max;
    float *cos_sim;
    float *exp_cos_sim;
    float *p_constrastive;
    contrastive_params *contrast_p_gpu;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * state;
    float * prev_state;
    float * forgot_state;
    float * forgot_delta;
    float * state_delta;
    float * combine_cpu;
    float * combine_delta_cpu;

<<<<<<< HEAD
    float *concat;
    float *concat_delta;

    float *binary_weights;

    float *biases;
    float *bias_updates;

    float *scales;
    float *scale_updates;

    float *weights_ema;
    float *biases_ema;
    float *scales_ema;

    float *weights;
    float *weight_updates;

    float scale_x_y;
    int objectness_smooth;
    int new_coords;
    int show_details;
    float max_delta;
    float uc_normalizer;
    float iou_normalizer;
    float obj_normalizer;
    float cls_normalizer;
    float delta_normalizer;
    IOU_LOSS iou_loss;
    IOU_LOSS iou_thresh_kind;
    NMS_KIND nms_kind;
    float beta_nms;
    YOLO_POINT yolo_point;

    char *align_bit_weights_gpu;
    float *mean_arr_gpu;
    float *align_workspace_gpu;
    float *transposed_align_workspace_gpu;
    int align_workspace_size;

    char *align_bit_weights;
    float *mean_arr;
    int align_bit_weights_size;
    int lda_align;
    int new_lda;
    int bit_align;

    float *col_image;
    float * delta;
    float * output;
    float * activation_input;
    int delta_pinned;
    int output_pinned;
=======
    float * concat;
    float * concat_delta;

    float * binary_weights;

    float * biases;
    float * bias_updates;

    float * scales;
    float * scale_updates;

    float * weights;
    float * weight_updates;

    float * delta;
    float * output;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * loss;
    float * squared;
    float * norms;

    float * spatial_mean;
    float * mean;
    float * variance;

    float * mean_delta;
    float * variance_delta;

    float * rolling_mean;
    float * rolling_variance;

    float * x;
    float * x_norm;

    float * m;
    float * v;
<<<<<<< HEAD

=======
    
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * bias_m;
    float * bias_v;
    float * scale_m;
    float * scale_v;


    float *z_cpu;
    float *r_cpu;
    float *h_cpu;
<<<<<<< HEAD
    float *stored_h_cpu;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * prev_state_cpu;

    float *temp_cpu;
    float *temp2_cpu;
    float *temp3_cpu;

    float *dh_cpu;
    float *hh_cpu;
    float *prev_cell_cpu;
    float *cell_cpu;
    float *f_cpu;
    float *i_cpu;
    float *g_cpu;
    float *o_cpu;
    float *c_cpu;
<<<<<<< HEAD
    float *stored_c_cpu;
    float *dc_cpu;

    float *binary_input;
    uint32_t *bin_re_packed_input;
    char *t_bit_input;
=======
    float *dc_cpu; 

    float * binary_input;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    struct layer *input_layer;
    struct layer *self_layer;
    struct layer *output_layer;

    struct layer *reset_layer;
    struct layer *update_layer;
    struct layer *state_layer;

    struct layer *input_gate_layer;
    struct layer *state_gate_layer;
    struct layer *input_save_layer;
    struct layer *state_save_layer;
    struct layer *input_state_layer;
    struct layer *state_state_layer;

    struct layer *input_z_layer;
    struct layer *state_z_layer;

    struct layer *input_r_layer;
    struct layer *state_r_layer;

    struct layer *input_h_layer;
    struct layer *state_h_layer;
<<<<<<< HEAD

=======
	
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    struct layer *wz;
    struct layer *uz;
    struct layer *wr;
    struct layer *ur;
    struct layer *wh;
    struct layer *uh;
    struct layer *uo;
    struct layer *wo;
<<<<<<< HEAD
    struct layer *vo;
    struct layer *uf;
    struct layer *wf;
    struct layer *vf;
    struct layer *ui;
    struct layer *wi;
    struct layer *vi;
=======
    struct layer *uf;
    struct layer *wf;
    struct layer *ui;
    struct layer *wi;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    struct layer *ug;
    struct layer *wg;

    tree *softmax_tree;

    size_t workspace_size;

<<<<<<< HEAD
//#ifdef GPU
    int *indexes_gpu;

    int stream;
    int wait_stream_id;

    float *z_gpu;
    float *r_gpu;
    float *h_gpu;
    float *stored_h_gpu;
    float *bottelneck_hi_gpu;
    float *bottelneck_delta_gpu;
=======
#ifdef GPU
    int *indexes_gpu;

    float *z_gpu;
    float *r_gpu;
    float *h_gpu;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    float *temp_gpu;
    float *temp2_gpu;
    float *temp3_gpu;

    float *dh_gpu;
    float *hh_gpu;
    float *prev_cell_gpu;
<<<<<<< HEAD
    float *prev_state_gpu;
    float *last_prev_state_gpu;
    float *last_prev_cell_gpu;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float *cell_gpu;
    float *f_gpu;
    float *i_gpu;
    float *g_gpu;
    float *o_gpu;
    float *c_gpu;
<<<<<<< HEAD
    float *stored_c_gpu;
    float *dc_gpu;

    // adam
=======
    float *dc_gpu; 

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float *m_gpu;
    float *v_gpu;
    float *bias_m_gpu;
    float *scale_m_gpu;
    float *bias_v_gpu;
    float *scale_v_gpu;

    float * combine_gpu;
    float * combine_delta_gpu;

<<<<<<< HEAD
=======
    float * prev_state_gpu;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * forgot_state_gpu;
    float * forgot_delta_gpu;
    float * state_gpu;
    float * state_delta_gpu;
    float * gate_gpu;
    float * gate_delta_gpu;
    float * save_gpu;
    float * save_delta_gpu;
    float * concat_gpu;
    float * concat_delta_gpu;

<<<<<<< HEAD
    float *binary_input_gpu;
    float *binary_weights_gpu;
    float *bin_conv_shortcut_in_gpu;
    float *bin_conv_shortcut_out_gpu;

    float * mean_gpu;
    float * variance_gpu;
    float * m_cbn_avg_gpu;
    float * v_cbn_avg_gpu;
=======
    float * binary_input_gpu;
    float * binary_weights_gpu;

    float * mean_gpu;
    float * variance_gpu;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    float * rolling_mean_gpu;
    float * rolling_variance_gpu;

    float * variance_delta_gpu;
    float * mean_delta_gpu;

<<<<<<< HEAD
    float * col_image_gpu;

=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * x_gpu;
    float * x_norm_gpu;
    float * weights_gpu;
    float * weight_updates_gpu;
<<<<<<< HEAD
    float * weight_deform_gpu;
    float * weight_change_gpu;

    float * weights_gpu16;
    float * weight_updates_gpu16;

=======
    float * weight_change_gpu;

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float * biases_gpu;
    float * bias_updates_gpu;
    float * bias_change_gpu;

    float * scales_gpu;
    float * scale_updates_gpu;
    float * scale_change_gpu;

<<<<<<< HEAD
    float * input_antialiasing_gpu;
    float * output_gpu;
    float * output_avg_gpu;
    float * activation_input_gpu;
    float * loss_gpu;
    float * delta_gpu;
    float * cos_sim_gpu;
    float * rand_gpu;
    float * drop_blocks_scale;
    float * drop_blocks_scale_gpu;
    float * squared_gpu;
    float * norms_gpu;

    float *gt_gpu;
    float *a_avg_gpu;

    int *input_sizes_gpu;
    float **layers_output_gpu;
    float **layers_delta_gpu;
#ifdef CUDNN
    cudnnTensorDescriptor_t srcTensorDesc, dstTensorDesc;
    cudnnTensorDescriptor_t srcTensorDesc16, dstTensorDesc16;
    cudnnTensorDescriptor_t dsrcTensorDesc, ddstTensorDesc;
    cudnnTensorDescriptor_t dsrcTensorDesc16, ddstTensorDesc16;
    cudnnTensorDescriptor_t normTensorDesc, normDstTensorDesc, normDstTensorDescF16;
    cudnnFilterDescriptor_t weightDesc, weightDesc16;
    cudnnFilterDescriptor_t dweightDesc, dweightDesc16;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionFwdAlgo_t fw_algo, fw_algo16;
    cudnnConvolutionBwdDataAlgo_t bd_algo, bd_algo16;
    cudnnConvolutionBwdFilterAlgo_t bf_algo, bf_algo16;
    cudnnPoolingDescriptor_t poolingDesc;
#else   // CUDNN
    void* srcTensorDesc, *dstTensorDesc;
    void* srcTensorDesc16, *dstTensorDesc16;
    void* dsrcTensorDesc, *ddstTensorDesc;
    void* dsrcTensorDesc16, *ddstTensorDesc16;
    void* normTensorDesc, *normDstTensorDesc, *normDstTensorDescF16;
    void* weightDesc, *weightDesc16;
    void* dweightDesc, *dweightDesc16;
    void* convDesc;
    UNUSED_ENUM_TYPE fw_algo, fw_algo16;
    UNUSED_ENUM_TYPE bd_algo, bd_algo16;
    UNUSED_ENUM_TYPE bf_algo, bf_algo16;
    void* poolingDesc;
#endif  // CUDNN
//#endif  // GPU
};


// network.h
typedef enum {
    CONSTANT, STEP, EXP, POLY, STEPS, SIG, RANDOM, SGDR
} learning_rate_policy;

// network.h
typedef struct network {
    int n;
    int batch;
    uint64_t *seen;
    float *badlabels_reject_threshold;
    float *delta_rolling_max;
    float *delta_rolling_avg;
    float *delta_rolling_std;
    int weights_reject_freq;
    int equidistant_point;
    float badlabels_rejection_percentage;
    float num_sigmas_reject_badlabels;
    float ema_alpha;
    int *cur_iteration;
    float loss_scale;
=======
    float * output_gpu;
    float * loss_gpu;
    float * delta_gpu;
    float * rand_gpu;
    float * squared_gpu;
    float * norms_gpu;
#ifdef CUDNN
    cudnnTensorDescriptor_t srcTensorDesc, dstTensorDesc;
    cudnnTensorDescriptor_t dsrcTensorDesc, ddstTensorDesc;
    cudnnTensorDescriptor_t normTensorDesc;
    cudnnFilterDescriptor_t weightDesc;
    cudnnFilterDescriptor_t dweightDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionFwdAlgo_t fw_algo;
    cudnnConvolutionBwdDataAlgo_t bd_algo;
    cudnnConvolutionBwdFilterAlgo_t bf_algo;
#endif
#endif
};

void free_layer(layer);

typedef enum {
    CONSTANT, STEP, EXP, POLY, STEPS, SIG, RANDOM
} learning_rate_policy;

typedef struct network{
    int n;
    int batch;
    size_t *seen;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int *t;
    float epoch;
    int subdivisions;
    layer *layers;
    float *output;
    learning_rate_policy policy;
<<<<<<< HEAD
    int benchmark_layers;
    int *total_bbox;
    int *rewritten_bbox;

    float learning_rate;
    float learning_rate_min;
    float learning_rate_max;
    int batches_per_cycle;
    int batches_cycle_mult;
=======

    float learning_rate;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float momentum;
    float decay;
    float gamma;
    float scale;
    float power;
    int time_steps;
    int step;
    int max_batches;
<<<<<<< HEAD
    int num_boxes;
    int train_images_num;
    float *seq_scales;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float *scales;
    int   *steps;
    int num_steps;
    int burn_in;
<<<<<<< HEAD
    int cudnn_half;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    int adam;
    float B1;
    float B2;
    float eps;

    int inputs;
    int outputs;
    int truths;
    int notruth;
    int h, w, c;
    int max_crop;
    int min_crop;
    float max_ratio;
    float min_ratio;
    int center;
<<<<<<< HEAD
    int flip; // horizontal flip 50% probability augmentaiont for classifier training (default = 1)
    int gaussian_noise;
    int blur;
    int mixup;
    float label_smooth_eps;
    int resize_step;
    int attention;
    int adversarial;
    float adversarial_lr;
    float max_chart_loss;
    int letter_box;
    int mosaic_bound;
    int contrastive;
    int contrastive_jit_flip;
    int contrastive_color;
    int unsupervised;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float angle;
    float aspect;
    float exposure;
    float saturation;
    float hue;
    int random;
<<<<<<< HEAD
    int track;
    int augment_speed;
    int sequential_subdivisions;
    int init_sequential_subdivisions;
    int current_subdivision;
    int try_fix_nan;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c

    int gpu_index;
    tree *hierarchy;

    float *input;
    float *truth;
    float *delta;
    float *workspace;
    int train;
    int index;
    float *cost;
    float clip;

<<<<<<< HEAD
//#ifdef GPU
    //float *input_gpu;
    //float *truth_gpu;
    float *delta_gpu;
    float *output_gpu;

    float *input_state_gpu;
    float *input_pinned_cpu;
    int input_pinned_cpu_flag;

    float **input_gpu;
    float **truth_gpu;
    float **input16_gpu;
    float **output16_gpu;
    size_t *max_input16_size;
    size_t *max_output16_size;
    int wait_stream;

    void *cuda_graph;
    void *cuda_graph_exec;
    int use_cuda_graph;
    int *cuda_graph_ready;

    float *global_delta_gpu;
    float *state_delta_gpu;
    size_t max_delta_gpu_size;
//#endif  // GPU
    int optimized_memory;
    int dynamic_minibatch;
    size_t workspace_size_limit;
} network;

// network.h
typedef struct network_state {
    float *truth;
    float *input;
    float *delta;
    float *workspace;
    int train;
    int index;
    network net;
} network_state;

//typedef struct {
//    int w;
//    int h;
//    float scale;
//    float rad;
//    float dx;
//    float dy;
//    float aspect;
//} augment_args;

// image.h
typedef struct image {
=======
#ifdef GPU
    float *input_gpu;
    float *truth_gpu;
    float *delta_gpu;
    float *output_gpu;
#endif

} network;

typedef struct {
    int w;
    int h;
    float scale;
    float rad;
    float dx;
    float dy;
    float aspect;
} augment_args;

typedef struct {
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int w;
    int h;
    int c;
    float *data;
} image;

<<<<<<< HEAD
//typedef struct {
//    int w;
//    int h;
//    int c;
//    float *data;
//} image;

// box.h
typedef struct box {
    float x, y, w, h;
} box;

// box.h
typedef struct boxabs {
    float left, right, top, bot;
} boxabs;

// box.h
typedef struct dxrep {
    float dt, db, dl, dr;
} dxrep;

// box.h
typedef struct ious {
    float iou, giou, diou, ciou;
    dxrep dx_iou;
    dxrep dx_giou;
} ious;


// box.h
typedef struct detection{
    box bbox;
    int classes;
    int best_class_idx;
=======
typedef struct{
    float x, y, w, h;
} box;

typedef struct detection{
    box bbox;
    int classes;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float *prob;
    float *mask;
    float objectness;
    int sort_class;
<<<<<<< HEAD
    float *uc; // Gaussian_YOLOv3 - tx,ty,tw,th uncertainty
    int points; // bit-0 - center, bit-1 - top-left-corner, bit-2 - bottom-right-corner
    float *embeddings;  // embeddings for tracking
    int embedding_size;
    float sim;
    int track_id;
} detection;

// network.c -batch inference
typedef struct det_num_pair {
    int num;
    detection *dets;
} det_num_pair, *pdet_num_pair;

// matrix.h
typedef struct matrix {
=======
} detection;

typedef struct matrix{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int rows, cols;
    float **vals;
} matrix;

<<<<<<< HEAD
// data.h
typedef struct data {
=======

typedef struct{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int w, h;
    matrix X;
    matrix y;
    int shallow;
    int *num_boxes;
    box **boxes;
} data;

<<<<<<< HEAD
// data.h
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
typedef enum {
    CLASSIFICATION_DATA, DETECTION_DATA, CAPTCHA_DATA, REGION_DATA, IMAGE_DATA, COMPARE_DATA, WRITING_DATA, SWAG_DATA, TAG_DATA, OLD_CLASSIFICATION_DATA, STUDY_DATA, DET_DATA, SUPER_DATA, LETTERBOX_DATA, REGRESSION_DATA, SEGMENTATION_DATA, INSTANCE_DATA, ISEG_DATA
} data_type;

<<<<<<< HEAD
// data.h
typedef struct load_args {
=======
typedef struct load_args{
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int threads;
    char **paths;
    char *path;
    int n;
    int m;
    char **labels;
    int h;
    int w;
<<<<<<< HEAD
    int c; // color depth
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int out_w;
    int out_h;
    int nh;
    int nw;
    int num_boxes;
<<<<<<< HEAD
    int truth_size;
=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int min, max, size;
    int classes;
    int background;
    int scale;
    int center;
    int coords;
<<<<<<< HEAD
    int mini_batch;
    int track;
    int augment_speed;
    int letter_box;
    int mosaic_bound;
    int show_imgs;
    int dontuse_opencv;
    int contrastive;
    int contrastive_jit_flip;
    int contrastive_color;
    float jitter;
    float resize;
    int flip;
    int gaussian_noise;
    int blur;
    int mixup;
    float label_smooth_eps;
=======
    float jitter;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    float angle;
    float aspect;
    float saturation;
    float exposure;
    float hue;
    data *d;
    image *im;
    image *resized;
    data_type type;
    tree *hierarchy;
} load_args;

<<<<<<< HEAD
// data.h
typedef struct box_label {
    int id;
    int track_id;
    float x, y, w, h;
    float left, right, top, bottom;
} box_label;

// list.h
//typedef struct node {
//    void *val;
//    struct node *next;
//    struct node *prev;
//} node;

// list.h
//typedef struct list {
//    int size;
//    node *front;
//    node *back;
//} list;
// -----------------------------------------------------


// parser.c
LIB_API network *load_network(char *cfg, char *weights, int clear);
LIB_API network *load_network_custom(char *cfg, char *weights, int clear, int batch);
LIB_API void free_network(network net);
LIB_API void free_network_ptr(network* net);

// network.c
LIB_API load_args get_base_args(network *net);

// box.h
LIB_API void do_nms_sort(detection *dets, int total, int classes, float thresh);
LIB_API void do_nms_obj(detection *dets, int total, int classes, float thresh);
LIB_API void diounms_sort(detection *dets, int total, int classes, float thresh, NMS_KIND nms_kind, float beta1);

// network.h
LIB_API float *network_predict(network net, float *input);
LIB_API float *network_predict_ptr(network *net, float *input);
#ifdef CUDA_OPENGL_INTEGRATION
LIB_API float *network_predict_gl_texture(network *net, uint32_t texture_id);
#endif // CUDA_OPENGL_INTEGRATION

LIB_API void set_batch_network(network *net, int b);
LIB_API detection *get_network_boxes(network *net, int w, int h, float thresh, float hier, int *map, int relative, int *num, int letter);
LIB_API det_num_pair* network_predict_batch(network *net, image im, int batch_size, int w, int h, float thresh, float hier, int *map, int relative, int letter);
LIB_API void free_detections(detection *dets, int n);
LIB_API void free_batch_detections(det_num_pair *det_num_pairs, int n);
LIB_API void fuse_conv_batchnorm(network net);
LIB_API void calculate_binary_weights(network net);
LIB_API char *detection_to_json(detection *dets, int nboxes, int classes, char **names, long long int frame_id, char *filename);

LIB_API layer* get_network_layer(network* net, int i);
//LIB_API detection *get_network_boxes(network *net, int w, int h, float thresh, float hier, int *map, int relative, int *num, int letter);
LIB_API detection *make_network_boxes(network *net, float thresh, int *num);
LIB_API void reset_rnn(network *net);
LIB_API float *network_predict_image(network *net, image im);
LIB_API float *network_predict_image_letterbox(network *net, image im);
LIB_API float validate_detector_map(char *datacfg, char *cfgfile, char *weightfile, float thresh_calc_avg_iou, const float iou_thresh, const int map_points, int letter_box, network *existing_net);
LIB_API void train_detector(char *datacfg, char *cfgfile, char *weightfile, int *gpus, int ngpus, int clear, int dont_show, int calc_map, float thresh, float iou_thresh, int mjpeg_port, int show_imgs, int benchmark_layers, char* chart_path, int mAP_epochs);
LIB_API void test_detector(char *datacfg, char *cfgfile, char *weightfile, char *filename, float thresh,
    float hier_thresh, int dont_show, int ext_output, int save_labels, char *outfile, int letter_box, int benchmark_layers);
LIB_API int network_width(network *net);
LIB_API int network_height(network *net);
LIB_API void optimize_picture(network *net, image orig, int max_layer, float scale, float rate, float thresh, int norm);

// image.h
LIB_API void make_image_red(image im);
LIB_API image make_attention_image(int img_size, float *original_delta_cpu, float *original_input_cpu, int w, int h, int c, float alpha);
LIB_API image resize_image(image im, int w, int h);
LIB_API void quantize_image(image im);
LIB_API void copy_image_from_bytes(image im, char *pdata);
LIB_API image letterbox_image(image im, int w, int h);
LIB_API void rgbgr_image(image im);
LIB_API image make_image(int w, int h, int c);
LIB_API image load_image_color(char *filename, int w, int h);
LIB_API void free_image(image m);
LIB_API image crop_image(image im, int dx, int dy, int w, int h);
LIB_API image resize_min(image im, int min);

// layer.h
LIB_API void free_layer_custom(layer l, int keep_cudnn_desc);
LIB_API void free_layer(layer l);

// data.c
LIB_API void free_data(data d);
LIB_API pthread_t load_data(load_args args);
LIB_API void free_load_threads(void *ptr);
LIB_API pthread_t load_data_in_thread(load_args args);
LIB_API void *load_thread(void *ptr);

// dark_cuda.h
LIB_API void cuda_pull_array(float *x_gpu, float *x, size_t n);
LIB_API void cuda_pull_array_async(float *x_gpu, float *x, size_t n);
LIB_API void cuda_set_device(int n);
LIB_API void *cuda_get_context();

// utils.h
LIB_API void free_ptrs(void **ptrs, int n);
LIB_API void top_k(float *a, int n, int k, int *index);

// tree.h
LIB_API tree *read_tree(char *filename);

// option_list.h
LIB_API metadata get_metadata(char *file);


// http_stream.h
LIB_API void delete_json_sender();
LIB_API void send_json_custom(char const* send_buf, int port, int timeout);
LIB_API double get_time_point();
void start_timer();
void stop_timer();
double get_time();
void stop_timer_and_show();
void stop_timer_and_show_name(char *name);
void show_total_time();

LIB_API void set_track_id(detection *new_dets, int new_dets_num, float thresh, float sim_thresh, float track_ciou_norm, int deque_size, int dets_for_track, int dets_for_show);
LIB_API int fill_remaining_id(detection *new_dets, int new_dets_num, int new_track_id, float thresh);


// gemm.h
LIB_API void init_cpu();

#ifdef __cplusplus
}
#endif  // __cplusplus
#endif  // DARKNET_API
=======
typedef struct{
    int id;
    float x,y,w,h;
    float left, right, top, bottom;
} box_label;


network *load_network(char *cfg, char *weights, int clear);
load_args get_base_args(network *net);

void free_data(data d);

typedef struct node{
    void *val;
    struct node *next;
    struct node *prev;
} node;

typedef struct list{
    int size;
    node *front;
    node *back;
} list;

pthread_t load_data(load_args args);
list *read_data_cfg(char *filename);
list *read_cfg(char *filename);
unsigned char *read_file(char *filename);
data resize_data(data orig, int w, int h);
data *tile_data(data orig, int divs, int size);
data select_data(data *orig, int *inds);

void forward_network(network *net);
void backward_network(network *net);
void update_network(network *net);


float dot_cpu(int N, float *X, int INCX, float *Y, int INCY);
void axpy_cpu(int N, float ALPHA, float *X, int INCX, float *Y, int INCY);
void copy_cpu(int N, float *X, int INCX, float *Y, int INCY);
void scal_cpu(int N, float ALPHA, float *X, int INCX);
void fill_cpu(int N, float ALPHA, float * X, int INCX);
void normalize_cpu(float *x, float *mean, float *variance, int batch, int filters, int spatial);
void softmax(float *input, int n, float temp, int stride, float *output);

int best_3d_shift_r(image a, image b, int min, int max);
#ifdef GPU
void axpy_gpu(int N, float ALPHA, float * X, int INCX, float * Y, int INCY);
void fill_gpu(int N, float ALPHA, float * X, int INCX);
void scal_gpu(int N, float ALPHA, float * X, int INCX);
void copy_gpu(int N, float * X, int INCX, float * Y, int INCY);

void cuda_set_device(int n);
void cuda_free(float *x_gpu);
float *cuda_make_array(float *x, size_t n);
void cuda_pull_array(float *x_gpu, float *x, size_t n);
float cuda_mag_array(float *x_gpu, size_t n);
void cuda_push_array(float *x_gpu, float *x, size_t n);

void forward_network_gpu(network *net);
void backward_network_gpu(network *net);
void update_network_gpu(network *net);

float train_networks(network **nets, int n, data d, int interval);
void sync_nets(network **nets, int n, int interval);
void harmless_update_network_gpu(network *net);
#endif
image get_label(image **characters, char *string, int size);
void draw_label(image a, int r, int c, image label, const float *rgb);
void save_image(image im, const char *name);
void save_image_options(image im, const char *name, IMTYPE f, int quality);
void get_next_batch(data d, int n, int offset, float *X, float *y);
void grayscale_image_3c(image im);
void normalize_image(image p);
void matrix_to_csv(matrix m);
float train_network_sgd(network *net, data d, int n);
void rgbgr_image(image im);
data copy_data(data d);
data concat_data(data d1, data d2);
data load_cifar10_data(char *filename);
float matrix_topk_accuracy(matrix truth, matrix guess, int k);
void matrix_add_matrix(matrix from, matrix to);
void scale_matrix(matrix m, float scale);
matrix csv_to_matrix(char *filename);
float *network_accuracies(network *net, data d, int n);
float train_network_datum(network *net);
image make_random_image(int w, int h, int c);

void denormalize_connected_layer(layer l);
void denormalize_convolutional_layer(layer l);
void statistics_connected_layer(layer l);
void rescale_weights(layer l, float scale, float trans);
void rgbgr_weights(layer l);
image *get_weights(layer l);

void demo(char *cfgfile, char *weightfile, float thresh, int cam_index, const char *filename, char **names, int classes, int frame_skip, char *prefix, int avg, float hier_thresh, int w, int h, int fps, int fullscreen);
void get_detection_detections(layer l, int w, int h, float thresh, detection *dets);

char *option_find_str(list *l, char *key, char *def);
int option_find_int(list *l, char *key, int def);
int option_find_int_quiet(list *l, char *key, int def);

network *parse_network_cfg(char *filename);
void save_weights(network *net, char *filename);
void load_weights(network *net, char *filename);
void save_weights_upto(network *net, char *filename, int cutoff);
void load_weights_upto(network *net, char *filename, int start, int cutoff);

void zero_objectness(layer l);
void get_region_detections(layer l, int w, int h, int netw, int neth, float thresh, int *map, float tree_thresh, int relative, detection *dets);
int get_yolo_detections(layer l, int w, int h, int netw, int neth, float thresh, int *map, int relative, detection *dets);
void free_network(network *net);
void set_batch_network(network *net, int b);
void set_temp_network(network *net, float t);
image load_image(char *filename, int w, int h, int c);
image load_image_color(char *filename, int w, int h);
image make_image(int w, int h, int c);
image resize_image(image im, int w, int h);
void censor_image(image im, int dx, int dy, int w, int h);
image letterbox_image(image im, int w, int h);
image crop_image(image im, int dx, int dy, int w, int h);
image center_crop_image(image im, int w, int h);
image resize_min(image im, int min);
image resize_max(image im, int max);
image threshold_image(image im, float thresh);
image mask_to_rgb(image mask);
int resize_network(network *net, int w, int h);
void free_matrix(matrix m);
void test_resize(char *filename);
int show_image(image p, const char *name, int ms);
image copy_image(image p);
void draw_box_width(image a, int x1, int y1, int x2, int y2, int w, float r, float g, float b);
float get_current_rate(network *net);
void composite_3d(char *f1, char *f2, char *out, int delta);
data load_data_old(char **paths, int n, int m, char **labels, int k, int w, int h);
size_t get_current_batch(network *net);
void constrain_image(image im);
image get_network_image_layer(network *net, int i);
layer get_network_output_layer(network *net);
void top_predictions(network *net, int n, int *index);
void flip_image(image a);
image float_to_image(int w, int h, int c, float *data);
void ghost_image(image source, image dest, int dx, int dy);
float network_accuracy(network *net, data d);
void random_distort_image(image im, float hue, float saturation, float exposure);
void fill_image(image m, float s);
image grayscale_image(image im);
void rotate_image_cw(image im, int times);
double what_time_is_it_now();
image rotate_image(image m, float rad);
void visualize_network(network *net);
float box_iou(box a, box b);
data load_all_cifar10();
box_label *read_boxes(char *filename, int *n);
box float_to_box(float *f, int stride);
void draw_detections(image im, detection *dets, int num, float thresh, char **names, image **alphabet, int classes);

matrix network_predict_data(network *net, data test);
image **load_alphabet();
image get_network_image(network *net);
float *network_predict(network *net, float *input);

int network_width(network *net);
int network_height(network *net);
float *network_predict_image(network *net, image im);
void network_detect(network *net, image im, float thresh, float hier_thresh, float nms, detection *dets);
detection *get_network_boxes(network *net, int w, int h, float thresh, float hier, int *map, int relative, int *num);
void free_detections(detection *dets, int n);

void reset_network_state(network *net, int b);

char **get_labels(char *filename);
void do_nms_obj(detection *dets, int total, int classes, float thresh);
void do_nms_sort(detection *dets, int total, int classes, float thresh);

matrix make_matrix(int rows, int cols);

#ifdef OPENCV
void *open_video_stream(const char *f, int c, int w, int h, int fps);
image get_image_from_stream(void *p);
void make_window(char *name, int w, int h, int fullscreen);
#endif

void free_image(image m);
float train_network(network *net, data d);
pthread_t load_data_in_thread(load_args args);
void load_data_blocking(load_args args);
list *get_paths(char *filename);
void hierarchy_predictions(float *predictions, int n, tree *hier, int only_leaves, int stride);
void change_leaves(tree *t, char *leaf_list);

int find_int_arg(int argc, char **argv, char *arg, int def);
float find_float_arg(int argc, char **argv, char *arg, float def);
int find_arg(int argc, char* argv[], char *arg);
char *find_char_arg(int argc, char **argv, char *arg, char *def);
char *basecfg(char *cfgfile);
void find_replace(char *str, char *orig, char *rep, char *output);
void free_ptrs(void **ptrs, int n);
char *fgetl(FILE *fp);
void strip(char *s);
float sec(clock_t clocks);
void **list_to_array(list *l);
void top_k(float *a, int n, int k, int *index);
int *read_map(char *filename);
void error(const char *s);
int max_index(float *a, int n);
int max_int_index(int *a, int n);
int sample_array(float *a, int n);
int *random_index_order(int min, int max);
void free_list(list *l);
float mse_array(float *a, int n);
float variance_array(float *a, int n);
float mag_array(float *a, int n);
void scale_array(float *a, int n, float s);
float mean_array(float *a, int n);
float sum_array(float *a, int n);
void normalize_array(float *a, int n);
int *read_intlist(char *s, int *n, int d);
size_t rand_size_t();
float rand_normal();
float rand_uniform(float min, float max);

#ifdef __cplusplus
}
#endif
#endif
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
