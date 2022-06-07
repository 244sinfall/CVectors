typedef struct coordinate {
    float x;
    float y;
} Coordinate;

typedef struct vector {
    struct vector *previous;
    Coordinate start;
    Coordinate end;
    struct vector *next;
} Vector;