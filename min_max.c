//
// Created by wills on 2/15/2019.
// Contains functions used in the developemnt and testing of:
//      Alpha-Beta
//      Min-Max
//      Min-Max using a tree
//      Generating a min max tree
//
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "min_max.h"

#define SIZE 5

/**
 * Adds a minMax node as a child to a parent
 * @param parent The parent who will get a child
 * @param child  The child to be added
 */
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

/**
 * Gets the max character given min
 * Or the min character given max
 * @param min_or_max The current minMax character
 * @return The opposite of @param min_or_max
 */
char get_min_or_max(char min_or_max){
    if (min_or_max == MIN){
        return MAX;
    }else{
        return MIN;
    }
}

/**
 * Sets each minMax node to it's proper minMax state
 * @param parent The current parent
 * @param child The child who needs to be setup
 */
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

/**
 * Makes a new minMax node
 * @param parent The parent of the current node
 * @return A new minMax node
 */
minMaxNode build_min_max_node(minMaxNode parent) {
    minMaxNode newNode = calloc(1, sizeof(struct min_max_node));
    newNode->highestScore = MAX_VALUE_DEFAULT;
    newNode->lowestScore = MIN_VALUE_DEFAULT;
    newNode->numberChildren = 0;
    add_child_node(parent, newNode);
    return newNode;
}

/**
 * Builds a new minMax node with a score
 * @param parent The parent of the current node
 * @param score The score of the current node
 * @return A new node set up with a score
 */
minMaxNode build_min_max_node_scored(minMaxNode parent, int8_t score){
    minMaxNode newNode = calloc(1, sizeof(struct min_max_node));
    newNode->highestScore = score;
    newNode->lowestScore = score;
    newNode->numberChildren = 0;
    add_child_node(parent, newNode);
    return newNode;
}

/**
 * Builds a new minMax tree from an array of numbers
 * @param size The size of the array
 * @param numbers The array of numbers to make into a tree
 * @param children_number The number of children each node can have
 * @return A minMax node with children representing the @param numbers
 */
minMaxNode biuld_min_max_tree(unsigned int size, int8_t *numbers, uint16_t children_number){
    if (size > children_number){

        minMaxNode parent = build_min_max_node(NULL);
        for (uint8_t childNumber = 0; childNumber < children_number - 1; childNumber++){
            minMaxNode child = biuld_min_max_tree(size / children_number,
                                                  childNumber * (size / children_number) + numbers, children_number);
            add_child_node(parent, child);
        }
        minMaxNode child = biuld_min_max_tree((size - (children_number - 1) * (size / children_number)),
                                              (children_number - 1) * (size / children_number) + numbers, children_number);
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

/**
 * Builds a binary minMax tree from an array of numbers
 * @param size The size of the array
 * @param numbers The array of numbers
 * @return A minMax node with children representing @param numbers
 */
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

/**
 * Prints a minMax tree
 * @param tree The minMax tree to print
 * @param depth the current depth in the tree
 */
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

/**
 * Sets a minMax tree up with the default values again
 * @param tree The tree to reset
 */
void reset_min_max(minMaxNode tree){
    for (uint8_t i = 0; i < tree->numberChildren; i++) {
        tree->highestScore = MAX_VALUE_DEFAULT;
        tree->lowestScore = MIN_VALUE_DEFAULT;
        if (tree->children[i] != 0){
            reset_min_max(tree->children[i]);
        }
    }
}

/**
 * Runs the minMax algorithm on a minMax tree
 * @param tree The tree to run min max on
 * @return The maximum or minimum of all the children Tree
 */
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

/**
 * Runs the alpha-Beta algorithm on a minMax tree
 * @param tree The tree to run alpha beta on
 * @param top The largest value possible
 * @param bottom The smallest value possible
 * @return The maximum or minimum of all the children Tree
 */
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

/**
 * Runs alpha beta on a tree represented by an array without building the tree
 * @param size The current size of the array
 * @param numbers The current array of numbers
 * @param children_number The number of children a minMax node could have
 * @param min_or_max The min or max value of the current level
 * @param top The largest value possible
 * @param bottom The smallest value possible
 * @return The maximum or minimum of all the children Tree
 */
int8_t treeless_alpha_beta(unsigned int size,
                           int8_t *numbers, uint16_t children_number,
                           char min_or_max,
                           int8_t top, int8_t bottom){
    if (size > children_number){
        for (uint16_t childNumber = 0; childNumber < children_number - 1; childNumber++){
            int8_t out = treeless_alpha_beta(size / children_number,
                                             childNumber * (size / children_number) + numbers,
                                             children_number, get_min_or_max(min_or_max), top, bottom);
            if (min_or_max == MIN){
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

        int8_t out = treeless_alpha_beta(size - (children_number - 1) * (size / children_number),
                                         (children_number - 1) * (size / children_number) + numbers,
                                         children_number, get_min_or_max(min_or_max), top, bottom);
        if (min_or_max == MIN){
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

        if (min_or_max == MIN){
            return top;
        }else{
            return bottom;
        }
    }else if (size > 1){
        for (uint16_t childNumber = 0; childNumber < size; childNumber++){
            int8_t out = treeless_alpha_beta(1, childNumber + numbers, children_number, get_min_or_max(min_or_max), top,
                                             bottom);
            if (min_or_max == MIN){
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

        if (min_or_max == MIN){
            return top;
        }else{
            return bottom;
        }
    }else{
        return numbers[0];
    }
}