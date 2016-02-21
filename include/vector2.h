#ifndef VECTOR2_H
#define VECTOR2_H
class vector2
{
    public:
        vector2();
        virtual ~vector2();
        void set(int, int);
        void setv(vector2);
        int x, y;
};
#endif
