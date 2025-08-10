#ifndef PARSER_H
#define PARSER_H
<<<<<<< HEAD
#include "network.h"

#ifdef __cplusplus
extern "C" {
#endif
network parse_network_cfg(char *filename);
network parse_network_cfg_custom(char *filename, int batch, int time_steps);
void save_network(network net, char *filename);
void save_weights(network net, char *filename);
void save_weights_upto(network net, char *filename, int cutoff, int save_ema);
void save_weights_double(network net, char *filename);
void load_weights(network *net, char *filename);
void load_weights_upto(network *net, char *filename, int cutoff);

#ifdef __cplusplus
}
#endif
=======
#include "darknet.h"
#include "network.h"

void save_network(network net, char *filename);
void save_weights_double(network net, char *filename);

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#endif
