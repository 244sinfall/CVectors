typedef struct coordinate {
    float x;
    float y;
} Coordinate;

typedef struct vector {
    struct vector *previous;
    struct coordinate start;
    struct coordinate end;
    struct vector *next;
} Vector;