//
// Created by wills on 2/15/2019.
//
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "min_max.h"

#define SIZE 5
#define MIN 'n'
#define MAX 'x'

void add_child_node(minMaxNode parent, minMaxNode child){

    if (parent != NULL) {
        if (parent->numberChildren % SIZE == 0) {
            minMaxNode *newChildArray = calloc(parent->numberChildren + SIZE, sizeof(minMaxNode));
            if (parent->numberChildren > 0) {
                for (uint8_t i = 0; i < parent->numberChildren; i++) {
                    newChildArray[i] = parent->children[i];
                }
                free(parent->children);
            }
            parent->children = newChildArray;
        }
        parent->children[parent->numberChildren] = child;
        parent->numberChildren++;
    }
    child->parent = parent;
}

char get_min_or_max(char minOrMax){
    if (minOrMax == MIN){
        return MAX;
    }else{
        return MIN;
    }
}

void restructure_min_max_tree(minMaxNode parent, minMaxNode child){
    if (parent == NULL || parent->minORMax == MIN){
        child->minORMax = MAX;
    }else{
        child->minORMax = MIN;
    }
    for (uint8_t i = 0; i < child->numberChildren; i++){
        restructure_min_max_tree(child, child->children[i]);
    }
}

minMaxNode build_min_max_node(minMaxNode parent) {
    minMaxNode newNode = calloc(1, sizeof(struct min_max_node));
    newNode->highestScore = 127;
    newNode->lowestScore = -128;
    newNode->numberChildren = 0;
    add_child_node(parent, newNode);
    return newNode;
}

minMaxNode build_min_max_node_scored(minMaxNode parent, int8_t score){
    minMaxNode newNode = calloc(1, sizeof(struct min_max_node));
    newNode->highestScore = score;
    newNode->lowestScore = score;
    newNode->numberChildren = 0;
    add_child_node(parent, newNode);
    return newNode;
}

minMaxNode biuld_min_max_tree(unsigned int size, int8_t *numbers, uint16_t childrenNumber){
    if (size > childrenNumber){

        minMaxNode parent = build_min_max_node(NULL);
        for (uint8_t childNumber = 0; childNumber < childrenNumber - 1; childNumber++){
            minMaxNode child = biuld_min_max_tree(size / childrenNumber,
                                                  childNumber * (size / childrenNumber) + numbers, childrenNumber);
            add_child_node(parent, child);
        }
        minMaxNode child = biuld_min_max_tree((size - (childrenNumber - 1) * (size / childrenNumber)),
                                              (childrenNumber - 1) * (size / childrenNumber) + numbers, childrenNumber);
        add_child_node(parent, child);
        return parent;
    }else{
        minMaxNode parent = build_min_max_node(NULL);

        for (uint8_t childNumber = 0; childNumber < size; childNumber++){
            build_min_max_node_scored(parent, numbers[childNumber]);
        }

        return parent;
    }
}

minMaxNode biuld_min_max_tree_binary(int size, int8_t *numbers){
    if (size > 2){
        minMaxNode parent = build_min_max_node(NULL);

        minMaxNode left = biuld_min_max_tree_binary(size / 2, numbers);
        minMaxNode right = biuld_min_max_tree_binary(size - (size / 2), numbers + (size / 2));

        add_child_node(parent, left);
        add_child_node(parent, right);
        return parent;
    }else{
        minMaxNode parent = build_min_max_node(NULL);

        build_min_max_node_scored(parent, numbers[0]);
        build_min_max_node_scored(parent, numbers[1]);
        return parent;
    }
}

void print_min_max_tree(minMaxNode tree, int depth){
        for (uint8_t i = 0; i < depth; i++){
            printf("\t");
        }
        if (tree->lowestScore == tree->highestScore){
            printf("%d\n", tree->lowestScore);
        }else{
            printf("%c %d %d\n", tree->minORMax, tree->highestScore, tree->lowestScore);
        }
        for (uint8_t i = 0; i < tree->numberChildren; i++){
            print_min_max_tree(tree->children[i], depth + 1);
        }
}

void reset_min_max(minMaxNode tree){
    for (uint8_t i = 0; i < tree->numberChildren; i++) {
        tree->highestScore = 127;
        tree->lowestScore = -128;
        if (tree->children[i] != 0){
            reset_min_max(tree->children[i]);
        }
    }
}

int8_t run_min_max(minMaxNode tree){
    for (uint8_t i = 0; i < tree->numberChildren; i++){
        int8_t out = run_min_max(tree->children[i]);
        if (tree->minORMax == MIN){
            if (tree->highestScore > out){
                tree->highestScore = out;
            }
        }else{
            if (tree->lowestScore < out){
                tree->lowestScore = out;
            }
        }
    }
    if (tree->minORMax == MIN){
        tree->lowestScore = tree->highestScore;
        return tree->highestScore;
    }else{
        tree->highestScore = tree->lowestScore;
        return tree->lowestScore;
    }
}

int8_t run_alpha_beta(minMaxNode tree, int8_t top, int8_t bottom){
    for (uint8_t i = 0; i < tree->numberChildren; i++){
        int8_t out = run_alpha_beta(tree->children[i], top, bottom);
        if (tree->minORMax == MIN){
            if (bottom > out){
                tree->lowestScore = out;
                tree->highestScore = top;
                return out;
            }

            if (tree->highestScore > out){
                tree->highestScore = out;
            }
            if (top > out){
                top = out;
            }
        }else{
            if (top < out){
                tree->lowestScore = bottom;
                tree->highestScore = out;
                return out;
            }

            if (tree->lowestScore < out){
                tree->lowestScore = out;
            }

            if (bottom < out){
                bottom = out;
            }
        }
    }
    if (tree->minORMax == MIN){
        tree->lowestScore = tree->highestScore;
        return tree->highestScore;
    }else{
        tree->highestScore = tree->lowestScore;
        return tree->lowestScore;
    }
}

int8_t treeless_alpha_beta(unsigned int size,
                           int8_t *numbers, uint16_t childrenNumber,
                           char minOrMax,
                           int8_t top, int8_t bottom){
    if (size > childrenNumber){
        for (uint16_t childNumber = 0; childNumber < childrenNumber - 1; childNumber++){
            int8_t out = treeless_alpha_beta(size / childrenNumber,
                                             childNumber * (size / childrenNumber) + numbers,
                                             childrenNumber, get_min_or_max(minOrMax), top, bottom);
            if (minOrMax == MIN){
                if (bottom > out){
                    return out;
                }

                if (top > out){
                    top = out;
                }
                if (top > out){
                    top = out;
                }
            }else{
                if (top < out){
                    return out;
                }

                if (bottom < out){
                    bottom = out;
                }

                if (bottom < out){
                    bottom = out;
                }
            }
        }

        int8_t out = treeless_alpha_beta(size - (childrenNumber - 1) * (size / childrenNumber),
                                         (childrenNumber - 1) * (size / childrenNumber) + numbers,
                                         childrenNumber, get_min_or_max(minOrMax), top, bottom);
        if (minOrMax == MIN){
            if (bottom > out){
                return out;
            }

            if (top > out){
                top = out;
            }
        }else{
            if (top < out){
                return out;
            }

            if (bottom < out){
                bottom = out;
            }
        }

        if (minOrMax == MIN){
            return top;
        }else{
            return bottom;
        }
    }else if (size > 1){
        for (uint16_t childNumber = 0; childNumber < size; childNumber++){
            int8_t out = treeless_alpha_beta(1, childNumber + numbers, childrenNumber, get_min_or_max(minOrMax), top,
                                             bottom);
            if (minOrMax == MIN){
                if (bottom > out){
                    return out;
                }

                if (top > out){
                    top = out;
                }
            }else{
                if (top < out){
                    return out;
                }

                if (bottom < out){
                    bottom = out;
                }
            }
        }

        if (minOrMax == MIN){
            return top;
        }else{
            return bottom;
        }
    }else{
        return numbers[0];
    }
}