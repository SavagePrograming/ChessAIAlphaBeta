//
// Created by wills on 2/15/2019.
//

#ifndef CHESS_MIN_MAX_H
#define CHESS_MIN_MAX_H

#define MIN 'n'
#define MAX 'x'
#define MIN_VALUE_DEFAULT -128
#define MAX_VALUE_DEFAULT 127

/**
 * A minMax node
 * numberChildren is the number of children the node has
 * highestScore is the highest score the node can have
 * lowestScore is the lowest score the node can have
 * children is the array of pointers to this nodes children
 * parent is the parent of this node
 */
typedef struct min_max_node{
    uint8_t numberChildren;
    int8_t highestScore;
    int8_t lowestScore;
    struct min_max_node ** children;
    struct min_max_node * parent;
    char minORMax;
} * minMaxNode;

char get_min_or_max(char min_or_max);

void add_child_node(minMaxNode parent, minMaxNode child);

minMaxNode build_min_max_node(minMaxNode parent);

void restructure_min_max_tree(minMaxNode parent, minMaxNode child);

minMaxNode build_min_max_node_scored(minMaxNode parent, int8_t score);

minMaxNode biuld_min_max_tree_binary(int size, int8_t *numbers);

void print_min_max_tree(minMaxNode tree, int depth);

int8_t run_min_max(minMaxNode tree);

int8_t run_alpha_beta(minMaxNode tree, int8_t top, int8_t bottom);

void reset_min_max(minMaxNode tree);

minMaxNode biuld_min_max_tree(unsigned int size, int8_t *numbers, uint16_t children_number);

int8_t treeless_alpha_beta(unsigned int size, int8_t *numbers, uint16_t children_number,
                           char min_or_max, int8_t top, int8_t bottom);

#endif //CHESS_MIN_MAX_H
